#include <stdio.h>
#include <locale.h>
int main()
{
	//Negatif girilene kadar Toplam ve Ortalama Bulma
	setlocale(LC_ALL,"Turkish");	
	int sayi = 0,tp=0,say=0;
	while(1)
	{
		printf("Sayıyı giriniz ");
		scanf("%d",&sayi);
		if(sayi < 0) break;
		else
		{
			tp+=sayi;
			say++;
		}
	}
	printf("Sayıların Toplamı : %d   Sayıların Ortalaması: %.2f ",tp,(float)tp/say);

	return 0;
}
