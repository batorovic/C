#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct Liste
{
  char ad[100];
  char soyAd[100];
  int no;

  Liste *sonraki;
} Bliste;

Bliste *ilk = NULL, *son = NULL, *onceki = NULL;
// son haneleri tutmak icin 10 elemanli int tipinden bir dizi olusturdum ekleme yaparken mod 10'unu aldım ve iligli indisin degerini bir attirdim. Silme islemi yaparken ilgili indisi degerini bir azalttim. Bu sekilde son hane bilgileriyle kiyaslama yapabildim.
int birlerBasamagi[10] = {0};

void listeyeEkle(Bliste *);
void listeyiYazdir();
bool listedenSil(int);
void listeDuzenle();
void dosyayaYaz();
int listedeArama(int);

int main()
{

  FILE *fp = NULL;
  if ((fp = fopen("veriler.txt", "r")) == NULL)
  {
    printf("Dosya acilamadı");
    return 1; // dosya acilamaz ise hatali cikis.
  }

  //Ornek girdilerin bulundugu veriler.txt'yi okuyup. Tek yonlu listeye atiyorum.
  while (!feof(fp))
  {
    Bliste *node = (Bliste *)malloc(sizeof(Bliste));
    fscanf(fp, "%d %s %s", &node->no, node->ad, node->soyAd);
    node->sonraki = NULL;
    listeyeEkle(node);
  }

  char secim;

  while (1)
  {

    Bliste *node = (Bliste *)malloc(sizeof(Bliste));
    node->sonraki = NULL;
    printf("\ne)Ekleme\na)Arama\nl)Listeleme\ns)Silme\nc)Cikis\n\n");
    fflush(stdin);
    secim = getchar();
    switch (secim)
    {
    case 'e':
      printf("Ogr No : ");
      scanf("%d", &node->no);
      printf("Ogr Ad : ");
      scanf("%s", node->ad);
      printf("Ogr Soyad : ");
      scanf("%s", node->soyAd);
      listeyeEkle(node);
      break;

    case 'a':
      int arananNo;
      printf("Aranacak No : ");
      scanf("%d", &arananNo);
      !listedeArama(arananNo) ? printf("Listede bulunamamıştır.") : printf("%d adimda ulasilmistir. ", listedeArama(arananNo) + 1);
      break;
    case 'l':
      printf("\n");
      listeyiYazdir();
      break;
    case 's':
      int silenecekNo;
      printf("Silinecek No : ");
      scanf("%d", &silenecekNo);
      if (listedenSil(silenecekNo))
      {
        printf("Listeden silinmistir.");
        listeDuzenle();
      }
      break;
    case 'c':
      fclose(fp);
      dosyayaYaz();
      return 0;
      break;
    default:
      printf("Gecerli secim yapiniz: ");
      break;
    }
  }
}

//Listeye ekleme yapan fonskiyon.
void listeyeEkle(Bliste *node)
{

  Bliste *onceki = NULL, *gecici = NULL;
  birlerBasamagi[node->no % 10]++;

  //Liste bos ise atama.Bu if'in degilinde listenin 2.elemanina atama yapma islemi.
  if (ilk == NULL)
  {
    ilk = node;
    son = ilk;
    onceki = son;
    return;
  }
  else if (ilk->sonraki == NULL)
  {
    son->sonraki = node;
    son = node;
    return;
  }

  //Yerlestirilecek sayinin listede yerini bulup ekleme islemi.
  else
  {

    onceki = ilk;
    gecici = ilk->sonraki;

    if (gecici->sonraki == NULL && gecici->no % 10 != node->no % 10)
    {
      gecici->sonraki = node;
      return;
    }

    if (ilk->sonraki->sonraki == NULL && (birlerBasamagi[gecici->no % 10] == birlerBasamagi[node->no % 10]))
    {
      if (node->no % 10 == ilk->no % 10)
      {
        gecici->sonraki = node;
        return;
      }
      ilk = ilk->sonraki;
      ilk->sonraki = node;
      node->sonraki = onceki;
      onceki->sonraki = NULL;
      return;
    }

    while (gecici != NULL)
    {
      if (birlerBasamagi[gecici->no % 10] >= birlerBasamagi[node->no % 10])
      {

        onceki = onceki->sonraki;
        gecici = gecici->sonraki;
      }
      else
        break;
    }

    if (gecici == NULL)
    {
      onceki->sonraki = node;
      son = node;
    }

    // hanesi kucuk olanlari ve buyuk olanlari gosteren iki ayri pointer olusturdum.Ve
    // eklenen Node'u uygun yere yerlestirip, hanesi buyuk olanlarin kucuk olanlari
    // gostermesini sagladim.
    else
    {

      Bliste *headTempBuyuk = NULL, *tempBuyuk = NULL, *tempKucukler = NULL, *headTempKucukler = NULL;
      Bliste *temp = onceki->sonraki;
      Bliste *tempGecici = gecici;
      if (temp->sonraki == NULL)
      {
        onceki->sonraki = node;
        onceki = node;
        node->sonraki = temp;
        return;
      }

      while (tempGecici)
      {
        if (tempGecici->no % 10 == node->no % 10)
        {
          if (tempBuyuk == NULL)
          {

            tempBuyuk = tempGecici;
            headTempBuyuk = tempBuyuk;
            tempGecici = tempGecici->sonraki;
            tempBuyuk->sonraki = NULL;
          }
          else
          {
            tempBuyuk->sonraki = tempGecici;
            tempBuyuk = tempGecici;
            tempGecici = tempGecici->sonraki;
            tempBuyuk->sonraki = NULL;
          }
        }
        else
        {
          if (tempKucukler == NULL)
          {

            tempKucukler = tempGecici;
            headTempKucukler = tempKucukler;
            tempGecici = tempGecici->sonraki;
            tempKucukler->sonraki = NULL;
          }
          else
          {

            tempKucukler->sonraki = tempGecici;
            tempKucukler = tempGecici;
            tempGecici = tempGecici->sonraki;
            tempKucukler->sonraki = NULL;
          }
        }
      }

      if (!tempBuyuk)
      {
        onceki->sonraki = node;
        node->sonraki = headTempKucukler;
        return;
      }

      if (birlerBasamagi[ilk->no % 10] < birlerBasamagi[node->no % 10])
      {
        Bliste *kaydirma = ilk;
        tempBuyuk->sonraki = node;

        kaydirma->sonraki = headTempKucukler;
        node->sonraki = kaydirma;

        ilk = headTempBuyuk;
      }

      else
      {
        tempBuyuk->sonraki = node;
        node->sonraki = headTempKucukler;
        onceki->sonraki = headTempBuyuk;
      }

      //son eleman
      while (tempKucukler->sonraki)
      {
        tempKucukler = tempKucukler->sonraki;
      }

      son = tempKucukler;

      return;
    }
  }
}

//Listeyi ekrana yazdiran fonksiyon.
void listeyiYazdir()
{
  Bliste *gecici = ilk;

  if (gecici == NULL)
  {
    printf("Liste Boş");
    return;
  }
  while (gecici != NULL)
  {
    printf("%d %s %s\n", gecici->no, gecici->ad, gecici->soyAd);
    gecici = gecici->sonraki;
  }
}

//Listede arama gerceklestirip kac adimda ulasildigini geri donduren bir fonksiyon.
int listedeArama(int no)
{
  int sayac = 0;
  Bliste *gecici = ilk;
  while (gecici)
  {
    if (gecici->no == no)
    {
      return sayac;
    }
    gecici = gecici->sonraki;
    sayac++;
  }
}

//cikis yapinca listenin son halini yeni txt dosyasina yazma
void dosyayaYaz()
{
  FILE *siraliFp = NULL;
  if ((siraliFp = fopen("en_son_veriler.txt", "w")) == NULL)
  {
    printf("Dosya acilamadı");
    return; // dosya acilamaz ise Cik
  }

  Bliste *gecici = ilk;

  while (gecici)
  {
    fprintf(siraliFp, "%d %s %s\n", gecici->no, gecici->ad, gecici->soyAd);
    gecici = gecici->sonraki;
  }

  fclose(siraliFp);
}

//Listeden bir eleman silindikten sonra listeyi tekrardan istenen sirali haline getiren fonksiyon.
void listeDuzenle()
{
  Bliste *gecici = ilk;
  Bliste *onceki = ilk;

  while (gecici)
  {
    //son eleman null ise
    if (gecici->sonraki == NULL)
    {
      son = gecici;
      break;
    }

    //degil ise
    else if (birlerBasamagi[gecici->no % 10] < birlerBasamagi[gecici->sonraki->no % 10])
    {
      Bliste *ilkleriEkle = ilk;
      Bliste *ilkleriEkleHead = ilkleriEkle;

      Bliste *oneAl;
      Bliste *oncekiHead = onceki;

      oneAl = gecici->sonraki;
      Bliste *oneAlHead = oneAl;

      // one alinan sayilarin sonuncusuna gitme.
      while (oneAl->sonraki->no % 10 == oneAl->no % 10)
      {

        oneAl = oneAl->sonraki;

        if (oneAl->sonraki == NULL)
        {
          break;
        }
      }

      //one alinan sayilarin kimin ardindan gelecegini bulma.
      while (onceki->sonraki->no % 10 == onceki->no % 10)
      {
        onceki = onceki->sonraki;
      }

      //eger ilk sayilar one alinacak sayilarin adetinden kucukse yer degistir ve head degistir.
      if (birlerBasamagi[ilk->no % 10] < birlerBasamagi[oneAlHead->no % 10])
      {
        oncekiHead = ilk;
        onceki->sonraki = oneAl->sonraki;
        oneAl->sonraki = oncekiHead;

        ilk = oneAlHead;
      }

      //aralari duzenle
      else
      {
        onceki = ilk;
        while (onceki->sonraki->no % 10 != gecici->no % 10)
        {
          onceki = onceki->sonraki;
        }
        while (oneAlHead->no % 10 != ilkleriEkle->sonraki->no % 10)
        {

          if (ilkleriEkle->no % 10 != gecici->no % 10)
          {
            ilkleriEkleHead = ilkleriEkle;
          }

          ilkleriEkle = ilkleriEkle->sonraki;
        }
        ilkleriEkleHead = ilkleriEkleHead->sonraki;

        ilkleriEkle->sonraki = oneAl->sonraki;
        oneAl->sonraki = ilkleriEkleHead;
        onceki->sonraki = oneAlHead;
      }

      gecici = ilk;
    }
    onceki = gecici;
    gecici = gecici->sonraki;
  }
}

//silme fonksiyonu. Son ve ilkler icin ayri bir if'le kontrol edildi.
bool listedenSil(int silenecekNo)
{
  birlerBasamagi[silenecekNo % 10]--;
  Bliste *gecici = ilk;
  Bliste *tut = ilk->sonraki;
  if (ilk->no == silenecekNo)
  {
    ilk = ilk->sonraki;
  }
  else if (gecici->sonraki == NULL)
  {
    gecici->sonraki = NULL;
    free(gecici);
  }
  else
  {
    while (gecici)
    {
      if (gecici->no == silenecekNo)
      {
        tut->sonraki = tut->sonraki->sonraki;
        free(gecici);
        return true;
      }

      tut = gecici;
      gecici = gecici->sonraki;
    }
  }

  if (!gecici)
  {
    printf("Listede olmadigi icin silinememistir.");
    return false;
  }
}
