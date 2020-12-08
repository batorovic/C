#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void soru1()
{
	//kullanýcý pozitif tam sayý girdiði sürece kaç tanesinin tek ve 5e tam bölündüðünü bulan program.
	int sayi,sayac=0;
	while(1)
	{
		printf("Sayýyý giriniz. ");
		scanf("%d",&sayi);			
		if(sayi > 0)
		{
			if(sayi % 5 == 0 && sayi % 2 != 0)
			{
				sayac++;
			}
		}
		else break;
	}
	
	printf("%d adet tek ve 5'e bölünen sayý girilmiþtir.",sayac);
	
}

void soru2()
{
	//10 boyutlu 2 adet diziye klavyeden sayý girilsin.
	//ilk dizideki çift indis deðerleri
	//ikinci dizideki tek indis deðerleriyle deðiþtir.
	
	
	int dizi1[4],dizi2[4],tut=0;
	
	for(int i = 0; i<4;i++)
	{
		printf("1.dizinin %d. deðerine deðer giriniz: ",i+1);
		scanf("%d",&dizi1[i]);
	}
	
	for(int i = 0; i<4;i++)
	{
		printf("2.dizinin %d. deðerine deðer giriniz: ",i+1);
		scanf("%d",&dizi2[i]);
		//çiftleri 2.diziye tekleri 1.diziye almak.
		/*if(dizi2[i] % 2 != 0)
		{
			for(int k = 0;k<10;k++)
			{
				if(dizi1[k] % 2 == 0)
				{
					tut = dizi2[i];
					dizi2[i] = dizi1[k];
					dizi1[k] = tut;
				}
				
			}
		
		}*/
	}
	
	for(int i = 0;i<4;i+=2)
	{
	//ilk dizideki çift indis deðerleri
	//ikinci dizideki tek indis deðerleriyle deðiþtir.
	
		tut = dizi2[i+1];
		dizi2[i+1] = dizi1[i];
		dizi1[i]=tut;
	}
	
	
	for(int i = 0; i<4;i++)
	{
		printf("%d ",dizi1[i]);
	}
	printf("\n");
	for(int i = 0; i<4;i++)
	{
		printf("%d ",dizi2[i]);
	}


// 1 2 3 4
// 5 6 7 8
	
}

void soru3()
{
	//girilen 100 sayýdan bir sonrakinin yarýsý olan kaç sayý vardýr? ! 100 hariç !
	
	int i = 0,tut=0,sayi,sayac=0;
	while(i<5)
	{
	
		printf("Sayýyý giriniz : ");
		scanf("%d",&sayi);
		if((float)sayi / 2 == tut)
		{
			sayac++;
		}
		i++;
		tut = sayi;

	}
	
	printf("%d",sayac);
}


void soru5()
{
	//10x10luk matrisin transpozu (satýrlar sutun haline gelir.)
	// 2 3
	// 4 5
	// transpoz olursa:
	// 2 4
	// 3 5 	

	//random için <stdlib.h> kütüphanesi eklenir.
	//her seferinde farklý sayýlar üretmesi için #include <time.h> kütüphanesi eklenir. srand(time(NULL)); komutu koda eklenir.
	srand(time(NULL));
	
	int matris[10][10];
	
	for(int i = 0;i < 10;i++)
	{
		for(int j =0;j<10;j++)
		{
			matris[i][j] = 1+rand()%100;
		}
	}
	for(int i = 0;i < 10;i++)
	{
		for(int j =0;j<10;j++)
		{
			printf("%d ",matris[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	

	for(int i = 0;i < 10;i++)
	{
		for(int j =0;j<10;j++)
		{
			printf("%d ",matris[j][i]);
		}
		printf("\n");
	}	
	
}

int main()
{
	setlocale(LC_ALL,"Turkish");
	//soru1();
	soru2();
	//soru3();
	//soru4 fonksiyon ne olduðunu anlamadým soru yok
	//soru5();
	return 0;
}

