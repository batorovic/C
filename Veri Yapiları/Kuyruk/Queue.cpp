#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct Bliste
{
  int oncelik;
  char isim[100];
  Bliste *sonraki;
};

typedef struct Bliste Bliste;

Bliste *kuyrukHead = NULL, *kuyrukSon = NULL;
Bliste *geciciKuyrukHead = NULL, *geciciKuyrukSon = NULL;

char menuEkrani();

int BlisteDolumu();
int BlisteBosmu();
int kacSiraVar(char *);

void aktar();
void temizle(Bliste **);
void geciciKuyrukEle(Bliste **, Bliste *);
void kuyrugaEkle(Bliste *);
void kuyruguListele();
void dosyadanKuyrugaEkle();

//Menu
void ekle();
void listele();
void cikis();
void arama();

//

Bliste *dosyadanVeriyiOku(FILE *);
Bliste *getNewNode();

int main()
{
  char secim;

  dosyadanKuyrugaEkle();

  while (1)
  {
    secim = menuEkrani();

    switch (secim)
    {
    case 'e':
      ekle();
      break;
    case 'a':
      arama();
      break;
    case 'l':
      kuyruguListele();
      break;
    case 'c':
      temizle(&kuyrukHead);
      return 0;
    default:
      printf("\nGecerli secim yapiniz.\n");
      break;
    }
  }
}

char menuEkrani()
{
  printf("\n");
  printf("e)Ekleme\na)Arama\nl)Listele\nc)Cikis\n\n");
  fflush(stdin);
  return getchar();
}

void ekle()
{
  Bliste *node = getNewNode();
  node->sonraki = NULL;
  printf("Oncelik : ");
  scanf("%d", &node->oncelik);
  printf("Isim : ");
  scanf("%s", node->isim);
  kuyrugaEkle(node);
  printf("%d %s basariyla kuyruga eklendi.\n", node->oncelik, node->isim);
}

void arama()
{
  char *isim = (char *)malloc(sizeof(char) * 100);
  printf("\n");
  printf("Aranacak isim : ");
  scanf("%s", isim);
  kacSiraVar(isim) == 0 ? printf("Kuyrukta Yok\n") : printf("%d sira vardir.\n", kacSiraVar(isim) - 1);
  free(isim);
}

void dosyadanKuyrugaEkle()
{
  FILE *fp;
  if ((fp = fopen("veriler.txt", "r")) == NULL)
  {
    printf("Dosya acilamadi");
    exit(1);
  }

  while (!feof(fp))
    kuyrugaEkle(dosyadanVeriyiOku(fp));

  fclose(fp);
}

Bliste *dosyadanVeriyiOku(FILE *fp)
{
  Bliste *newNode = getNewNode();
  newNode->sonraki = NULL;
  fscanf(fp, "%d %s", &newNode->oncelik, newNode->isim);

  return newNode;
}
Bliste *getNewNode()
{
  return (Bliste *)malloc(sizeof(Bliste));
}

void kuyruguListele()
{
  printf("\n");

  Bliste *gecici = kuyrukHead;

  while (gecici)
  {
    printf("%d %s\n", gecici->oncelik, gecici->isim);
    gecici = gecici->sonraki;
  }
}

int kacSiraVar(char *isim)
{
  Bliste *gecici = kuyrukHead;
  int sayac = 0;
  while (gecici)
  {
    if (strcmp(isim, gecici->isim) == 0)
    {
      return sayac + 1;
    }
    gecici = gecici->sonraki;
    sayac++;
  }
  return 0;
}
void geciciKuyrukEle(Bliste **nodeRef, Bliste *node)
{
  Bliste *yeniNode = (Bliste *)malloc(sizeof(Bliste));
  strcpy(yeniNode->isim, node->isim);
  yeniNode->oncelik = node->oncelik;
  yeniNode->sonraki = NULL;

  *nodeRef = yeniNode;
}

void kuyrugaEkle(Bliste *node)
{

  Bliste *gecici = kuyrukHead;

  if (kuyrukHead == NULL)
  {
    kuyrukHead = node;
    kuyrukSon = kuyrukHead;
  }
  else
  {
    if (kuyrukSon->oncelik <= node->oncelik)
    {
      kuyrukSon->sonraki = node;
      kuyrukSon = node;
    }
    //  Kuyrugun en sonuna yerlesemedigi icin aralarda bir yerde bir oncelik girilmis oluyor bundan dolayi
    //  kuyrugun hepsini sirasina gore gecici bir kuyruga atiyorum. Ilgili yer geldiginde girilen
    //  veriyi de gecici kuyruguma ekliyorum. Daha sonra girilen veriden sonraki verileride kuyruktan
    //  gecici kuyruguma ekliyorum. Kuyrugumu istenen sekilde siralamis oluyorum ve sirali
    //  gecici kuyrugumu ana kuyruguma aktariyorum. Aktarma islemi bittikten sonra gecici kuyrugumu
    //  ram'den temizliyorum.
    else
    {
      while (gecici->oncelik <= node->oncelik)
      {
        if (geciciKuyrukHead == NULL)
        {
          geciciKuyrukEle(&geciciKuyrukHead, gecici);
          geciciKuyrukSon = geciciKuyrukHead;
        }
        else
        {
          geciciKuyrukEle(&geciciKuyrukSon->sonraki, gecici);
          geciciKuyrukSon = geciciKuyrukSon->sonraki;
        }
        gecici = gecici->sonraki;
      }

      //kuyruga eklenen yeni degeri ekliyorum
      geciciKuyrukEle(&geciciKuyrukSon->sonraki, node);
      geciciKuyrukSon = geciciKuyrukSon->sonraki;

      //eklenen degerden sonraki onceliklileri ekiyorum
      while (gecici)
      {
        geciciKuyrukEle(&geciciKuyrukSon->sonraki, gecici);
        geciciKuyrukSon = geciciKuyrukSon->sonraki;
        gecici = gecici->sonraki;
      }
      aktar();
    }
  }
}

void aktar()
{
  Bliste *gecici = kuyrukHead;
  Bliste *aktar = geciciKuyrukHead;
  //gecicilistemden kuyruga aktarma yapıyorum.
  while (gecici->sonraki)
  {
    strcpy(gecici->isim, aktar->isim);
    gecici->oncelik = aktar->oncelik;
    gecici = gecici->sonraki;
    aktar = aktar->sonraki;
  }

  //  Aktarma islemini ana kuyruktaki veri sayisina gore yaptigim icin en son 2 deger icin
  //  asagidaki kontrolleri gerceklestirdim. Cunku her zaman en sonuncu degerin ram'de yeri yok.
  //  ram'den yer ayirmak zorundayim.
  Bliste *onceki;
  while (aktar)
  {
    if (gecici == NULL)
    {
      gecici = (Bliste *)malloc(sizeof(Bliste));
      strcpy(gecici->isim, aktar->isim);
      gecici->oncelik = aktar->oncelik;
      onceki->sonraki = gecici;
      aktar = aktar->sonraki;
      gecici->sonraki = NULL;
      kuyrukSon = gecici;
    }
    else
    {
      onceki = gecici;
      strcpy(gecici->isim, aktar->isim);
      gecici->oncelik = aktar->oncelik;
      gecici = gecici->sonraki;
      aktar = aktar->sonraki;
    }
  }
  temizle(&geciciKuyrukHead);
}

void temizle(Bliste **headRef)
{
  Bliste *gecici = *headRef;
  while (*headRef)
  {
    *headRef = (*headRef)->sonraki;
    free(gecici);
    gecici = *headRef;
  }
}
