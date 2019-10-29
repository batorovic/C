#include <stdio.h>
#include <locale.h>
#include <math.h>
int main()
{
	setlocale(LC_ALL,"Turkish");
	//sayýyý tersten yazdýrma
	int sayi,ters=0;
	printf("Lütfen sayýyý giriniz : ");
	scanf("%d",&sayi);
	
	while(sayi != 0)
	{
		ters*=10;
		ters += sayi % 10;
		sayi/=10;
	
	}
	
	printf("Tersten: %d",ters);
	

	
	
	return 0;
}
