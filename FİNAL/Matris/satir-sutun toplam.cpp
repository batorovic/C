#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(NULL));
	//5*5 lik bir matrisin sat�r ve s�tun toplamlar�n� ekran yazd�ran bir program yaz�n�z
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
	printf("\nSat�r Toplam� : %d \nS�tun Toplam� : %d",satir,sutun);
	
	
	
		
	return 0;
}

