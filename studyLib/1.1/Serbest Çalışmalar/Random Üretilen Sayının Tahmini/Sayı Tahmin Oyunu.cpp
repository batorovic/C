#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	srand(time(NULL));
	//Random sayı türet kullanının tahmin etmesini bekle do-while kulllan
	setlocale(LC_ALL,"Turkish");
	
	int sayi = 0,tahmin = 0,sayac=1,secim = 1;
	sayi =  1+rand()%100;
	printf("%d",sayi);
	do
	{
		printf("Sayı giriniz : ");
		scanf("%d",&tahmin);

		if(sayi == tahmin)
		{
			sayi =  1+rand()%100;
			printf("Tebrikler %d. denemenizde bildiniz.\nDevam Etmek için 1.\nÇıkmak için 0 ",sayac); 
			scanf("%d",&secim);
			if(secim == 0)
			{
				break;
			}
		
		}
		
		else if(sayi > tahmin) printf("Az yukarı xD\n");
		else printf("Az aşağı xD\n");
		sayac++;
	}while(secim != 0);

	
	


	return 0;
}
