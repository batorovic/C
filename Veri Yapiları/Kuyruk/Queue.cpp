#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct Bliste
{
  int oncelik;
  char isim[100];
  Bliste *sonraki;

} Bliste;

Bliste *kuyrukHead = NULL, *kuyrukSon = NULL;
Bliste *geciciKuyrukHead = NULL, *geciciKuyrukSon = NULL;

int BlisteDolumu();
int BlisteBosmu();
int kacSiraVar(char *);

void aktar();
void temizle(Bliste **);
void geciciKuyrukEle(Bliste **, Bliste *);
void kuyrugaEkle(Bliste *);
void kuyruguListele();

int main()
{
  char secim;
  char *isim = (char *)malloc(sizeof(char) * 100);

  FILE *fp = NULL;
  if ((fp = fopen("veriler.txt", "r")) == NULL)
  {
    printf("Dosya acilamadi");
    return 1;
  }

  Bliste *node = (Bliste *)malloc(sizeof(Bliste));

  while (!feof(fp))
  {

    node = (Bliste *)malloc(sizeof(Bliste));
    node->sonraki = NULL;
    fscanf(fp, "%d %s", &node->oncelik, node->isim);
    kuyrugaEkle(node);
  }

  while (1)
  {
    printf("\n");
    printf("e)Ekleme\na)Arama\nl)Listele\nc)Cikis\n\n");
    fflush(stdin);
    secim = getchar();

    switch (secim)
    {
    case 'e':
      node = (Bliste *)malloc(sizeof(Bliste));
      node->sonraki = NULL;
      printf("Oncelik : ");
      scanf("%d", &node->oncelik);
      printf("Isim : ");
      scanf("%s", node->isim);
      kuyrugaEkle(node);
      printf("%d %s basariyla kuyruga eklendi.\n", node->oncelik, node->isim);
      break;
    case 'a':
      printf("\n");
      printf("Aranacak isim : ");
      scanf("%s", isim);
      kacSiraVar(isim) == 0 ? printf("Kuyrukta Yok\n") : printf("%d sira vardir.\n", kacSiraVar(isim) - 1);
      break;
    case 'l':
      printf("\n");
      kuyruguListele();
      break;
    case 'c':
      free(isim);
      temizle(&kuyrukHead);
      return 0;
    default:
      printf("\nGecerli secim yapiniz.\n");
      break;
    }
  }
}

void kuyruguListele()
{
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
