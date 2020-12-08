#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Kendisine parametre olarak gelen iki sayýnný yerini degistiren fonksiyon.
void Swap(int *a, int *b) 
{ 
    int gecici = *a; 
    *a = *b; 
    *b = gecici; 
} 
  


void SelectionSort(int *p,int uzunluk)//SelectionSort Algoritmasýnýn Indisi Tek Olanlari Kucukten Buyuge Olarak Siralamayi Gerceklestirdigi Fonskiyon.
{
	int i, j, minIndex; 
	

    for (i = 0; i < uzunluk-1; i++) 
    { 
        minIndex = i; 
        
        for (j = i+1; j < uzunluk; j++) 
          if (*(p+j) < *(p+minIndex)) 
            minIndex = j; 
  
        Swap(&*(p+minIndex), &*(p+i)); 
    } 
}

void InsertionSort(int *p,int uzunluk) //InsertionSort Algoritmasýnýn Indisi Cift Olanlari Buyukten Kucuge Olarak Siralamayi Gerceklestirdigi Fonskiyon.
{
	int j,gecici;
	for(int i =1; i < uzunluk;i++)
	{
		j = i;
		
		while(j >= 0 && *(p+j-1) < *(p+j))
		{
			Swap(&*(p+j-1),&*(p+j));
			j--;
		}
	}
}


int main()
{
	srand(time(NULL));
	
	//random olarak gelen 100 sayiyi tutmak icin RAM'den yer ayirdim.
	int *dizi = (int*)malloc(sizeof(int)*100);
	
	//Indisi tek ve cift olan sayilari dinamik bir dizide tutmak icin tanýmladým.
	int *tDizi = NULL;
	int *cDizi = NULL;
	
	// Dizinin dinamikligini saglamak icin boyut degiskenleri olusturdum.
	int tBoyut = 1;
	int cBoyut = 1;
	
	int i=0;
	
	printf("Dizinin elemanlari : \n");
	
	while(i < 100)//Dizinin indisi; ciftse cDizide, Tek ise tDizide veriler tutuluyor. Ve dinamik olarak diziler genisliyor .
	{
		*(dizi+i) = rand() % 1000;
		
		printf("[%d] = %d\n",i,*(dizi+i)); //Siralanmamis dizinin elemanlarini donguden cikana kadar tek tek ekrana basiyorum.
		
		//Indise gore dinamik olarak boyutu ayarlama ve sarta gore ilgili diziye atama islemleri.
		if(i % 2 == 0)
		{
			cDizi = (int *)realloc(cDizi,sizeof(int)*cBoyut);
			*(cDizi+cBoyut-1) = *(dizi+i);
			cBoyut++;
			
		}
		else
		{
			tDizi = (int *)realloc(tDizi,sizeof(int)*tBoyut);
			*(tDizi+tBoyut-1) = *(dizi+i);
			tBoyut++;
		}
		
		i++;
	}
	

	//Tek ve Cift indise gore ayarladigim dizileri siralanmasi icin ilgili fonksiyonlara gonderiyorum.
	SelectionSort(tDizi,tBoyut-1);
	InsertionSort(cDizi,cBoyut-1);
	
	printf("\nSonuc Dizisi : \nTek indisler, kucukten buyuge\nCift indisler, buyukten kucuge siralanmistir\n");
	
	i=0; // i sayacýmý 0'lýyorum.
	
	//Bu degiskenlerin amaci, tek ve cift indiste bulunan sayilarin tutuldugu dizilerde gezinme yapmak icin.
	int tekSayac=0;
	int ciftSayac=0;
	
	int *sonucDizisi = (int*)malloc(sizeof(int)*100); //100 adet sayimiz oldugu icin RAM'den gerektiði kadar yer ayirdim.
	
	while(i<100)//sonucDizisinin tek indislerine tDizi'sinin siralanmis halini, cift indislerine cDizi'sinin siralanmis halini atýyorum. 
	{
		if(i % 2 == 0)
		{
			*(sonucDizisi+i) = *(cDizi+ ciftSayac);
			ciftSayac++;
		}
		else
		{
			*(sonucDizisi+i) = *(tDizi+ tekSayac);
			tekSayac++;
		}
		
		printf("[%d] = %d\n",i,*(sonucDizisi+i));
		i++;
	
	}

	//Islem bittigi icin gerekli temizlikleri yapýyorum.
	free(sonucDizisi);
	free(dizi);
	free(tDizi);
	free(cDizi);
	
	return 0;
}
