#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(NULL));
	//5*5 lik bir matrisin satýr ve sütun toplamlarýný ekran yazdýran bir program yazýnýz
	setlocale(LC_ALL,"Turkish");
	int m[5][5]={},satir=0,sutun=0;
	
	for(int i = 0;i<5;i++)
	{
		for(int j = 0;j<5;j++)
		{
			m[i][j] = 1+rand()%10;
			satir+=m[i][j];
		}
	}
	
	for(int i = 0;i<5;i++)
	{
		for(int j = 0;j<5;j++)
		{
			printf("%d ",m[i][j]);
			sutun+=m[j][i];
		}
		printf("\n");
	}
	printf("\nSatýr Toplamý : %d \nSütun Toplamý : %d",satir,sutun);
	
	
	
		
	return 0;
}

