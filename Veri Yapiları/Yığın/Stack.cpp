#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define yiginBoyut 100

int yiginDolumu();
int yiginBosmu();

void yigindanSil();
void yiginaEkle();
void yiginYazdir();
void geriAl();

typedef struct Stack
{
  int index;
  int veriler[yiginBoyut];
} Stack;

typedef struct GeriStack
{
  int satir;
  int sutun;
  int *veriler[yiginBoyut][2];
} GeriStack;

Stack islemStack;
GeriStack geriStack;

/*

  GeriStack'in dizisini 2 boyutlu olarak tanimladim.
  0.sutunlarda silinenler, 1.sutunlarda silinenlerden bir once girilen sayinin adresini tuttum
  (oncekilerin neden adresini tuttugumu 50.satirdan itibaren acikladim).

  Ornegin:
      5 4 3 2 1 stackimiz olsun. Bu stack'e sayilar sirasi ile eklenirken 2 ve 4 silinsin.
            silinen          onceki
          4 -> (1,0)     3'un adresi(1,1)
          2 -> (0,0)     1'in adresi(0,1)

    
  Sildigim sayinin bir onceki degerini geri alirken bilmem gerekiyordu.
  Nereden silindigini kaybetmemek ve dogru yerde "islemStack"in top'ina eklemek icin.


  Bir onceki degeride integer tipinden tuttugumda sorun yasadim.

  Ornegin stack 50 30 oldugunda.
  50 silinsin.
  80 eklensin
  80 30 olur.
  Tekrar 30 eklensin.
  Son hali 30 80 30 oluyor.

  Geri alma islemi gerceklestirildiginde
  oncekileri, girilen sayi uzerinden karsilastirinca yanlis oluyordu cunku 50'nin onceki
  stack'e ilk eklenen 30'du. Bunun icin "geriStack"in veriler dizisini pointer olarak tanimladım ve onceki degerlerin 
  adreslerini dizinin ilgili satir, 1.sutununda tuttum. Ve bu sekilde oncekileri adres üzerinden karsilastirmayi yaptım.

*/

void yiginYazdir()
{
  printf("EKRANA YAZDIRILDI: ");
  int i = islemStack.index;
  while (i >= 0)
  {
    printf("%d ", islemStack.veriler[i]);
    i--;
  }
}

int yiginDolumu(Stack stack)
{
  if (stack.index >= yiginBoyut - 1)
    return 1;
  else
    return 0;
}
int yiginBosmu(int index)
{
  if (index == -1)
    return 1;
  else
    return 0;
}

void yiginaEkle(int veri)
{
  if (yiginDolumu(islemStack) == 1)
  {
    printf("Yigin Dolu\n");
  }
  else
  {
    islemStack.index++;
    islemStack.veriler[islemStack.index] = veri;
  }
}

void yigindanSil()
{
  if (yiginBosmu(islemStack.index) == true)
  {
    printf("Yigin Bos\n");
    return;
  }
  else
  {
    int silinen = islemStack.veriler[islemStack.index];

    islemStack.index--;
    geriStack.satir++;

    //  0.sutunlarda silinenler, 1.sutunlarda silinenlerden bir önce girilen sayiyi tuttum.
    //  silinen degeri atama yapmak icin ram'den yer aliyorum ve silineni ilgili yere koyuyorum.
    //  son olarak ise ilgili satir, 1.sutuna silinenden onceki degerin adresini veriyorum.

    geriStack.veriler[geriStack.satir][0] = (int *)malloc(sizeof(int));
    *(geriStack.veriler[geriStack.satir][0]) = silinen;
    geriStack.veriler[geriStack.satir][1] = &islemStack.veriler[islemStack.index];
  }
}

void geriAl()
{

  printf("\n");

  if (!yiginBosmu(islemStack.index) || !yiginBosmu(geriStack.satir))
  {
    //Geristack bos ise silinen eleman yoktur. Eklenen geri aliniyor.
    if (geriStack.satir == -1)
    {
      printf("%d EKLEME ISLEMI GERI ALINDI", islemStack.veriler[islemStack.index]);
      islemStack.index--;
    }
    //  Silinen sayinin onceki adresi ile islemStack'in top elemaninin adresi karsilastiriliyor.
    //  birbirlerine esit degiler ise ekleme isleminin geri alinmasi gerceklesiyor.
    else if (geriStack.veriler[geriStack.satir][1] != &(islemStack.veriler[islemStack.index]))
    {
      printf("%d EKLEME ISLEMI GERI ALINDI", islemStack.veriler[islemStack.index]);
      islemStack.index--;
    }
    //  Adresler birbirine esit ise silinme isleminin geri alinma islemi gerceklestiriliyor.
    else
    {
      printf("%d SILINME ISLEMI GERI ALINDI ", *(geriStack.veriler[geriStack.satir][0]));
      islemStack.index++;
      islemStack.veriler[islemStack.index] = *(geriStack.veriler[geriStack.satir][0]);

      free(geriStack.veriler[geriStack.satir][0]);

      geriStack.satir--;
    }
  }
  else
  {
    printf("Yigin Bos !");
  }
}

int main()
{

  islemStack.index = -1;
  geriStack.satir = -1;

  int sayi;
  char secim;
  while (1)
  {
    printf("\n\ne)Ekleme\ns)Silme\ny)Yazdir\nr)Geri Al\nc)Cikis\n\n");
    fflush(stdin);
    secim = getchar();
    printf("\n");
    switch (secim)
    {
    case 'e':
      printf("Ekle : ");
      scanf("%d", &sayi);
      yiginaEkle(sayi);
      printf("%d DEGERI EKLENDI", sayi);
      break;
    case 's':
      if (yiginBosmu(islemStack.index))
      {
        printf("Yigin Bos islem yapilamiyor !");
      }
      else
      {
        printf("%d SILINDI \n", islemStack.veriler[islemStack.index]);
        yigindanSil();
      }
      break;
    case 'r':

      printf("\n");
      geriAl();
      break;

    case 'y':
      if (yiginBosmu(islemStack.index))
        printf("Yigin Bos !");
      else
        yiginYazdir();
      break;
    case 'c':
      return 0;

    default:
      printf("Gecerli Secim yapiniz : ");
      break;
    }
  }
  yiginYazdir();
  return 0;
}
