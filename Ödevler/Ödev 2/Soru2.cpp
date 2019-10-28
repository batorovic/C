#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Turkish");
	
	int sayi = 0,toplam=0,sayac=0;
	printf("Sayıyı giriniz :");
	scanf("%d",&sayi);
	
	for(int i = 0; i<sayi;i++)
	{
		if(i % 2 == 0) 
		{
			toplam+=i; 
			sayac++;
		}
		
	}
	
	printf("Girilen sayıya kadar olan çift sayıların;\nToplamı:%d\nOrtalaması:%d",toplam,toplam/sayac);
	
	return 0 ;
}
