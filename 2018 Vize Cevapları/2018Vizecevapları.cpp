#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void soru1()
{
	//kullan�c� pozitif tam say� girdi�i s�rece ka� tanesinin tek ve 5e tam b�l�nd���n� bulan program.
	int sayi,sayac=0;
	while(1)
	{
		printf("Say�y� giriniz. ");
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
	
	printf("%d adet tek ve 5'e b�l�nen say� girilmi�tir.",sayac);
	
}

void soru2()
{
	//10 boyutlu 2 adet diziye klavyeden say� girilsin.
	//ilk dizideki �ift indis de�erleri
	//ikinci dizideki tek indis de�erleriyle de�i�tir.
	
	
	int dizi1[4],dizi2[4],tut=0;
	
	for(int i = 0; i<4;i++)
	{
		printf("1.dizinin %d. de�erine de�er giriniz: ",i+1);
		scanf("%d",&dizi1[i]);
	}
	
	for(int i = 0; i<4;i++)
	{
		printf("2.dizinin %d. de�erine de�er giriniz: ",i+1);
		scanf("%d",&dizi2[i]);
		//�iftleri 2.diziye tekleri 1.diziye almak.
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
	//ilk dizideki �ift indis de�erleri
	//ikinci dizideki tek indis de�erleriyle de�i�tir.
	
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
	//girilen 100 say�dan bir sonrakinin yar�s� olan ka� say� vard�r? ! 100 hari� !
	
	int i = 0,tut=0,sayi,sayac=0;
	while(i<5)
	{
	
		printf("Say�y� giriniz : ");
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
	//10x10luk matrisin transpozu (sat�rlar sutun haline gelir.)
	// 2 3
	// 4 5
	// transpoz olursa:
	// 2 4
	// 3 5 	

	//random i�in <stdlib.h> k�t�phanesi eklenir.
	//her seferinde farkl� say�lar �retmesi i�in #include <time.h> k�t�phanesi eklenir. srand(time(NULL)); komutu koda eklenir.
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
	//soru4 fonksiyon ne oldu�unu anlamad�m soru yok
	//soru5();
	return 0;
}

