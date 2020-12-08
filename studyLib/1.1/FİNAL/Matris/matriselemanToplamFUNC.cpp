#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int MatrisElemanToplam(int m[][5],int satir,int sutun)
{
	int toplam = 0;
	for(int i = 0;i<satir;i++)
	{
		for(int j = 0;j<sutun;j++)
		{
			printf("%d ",m[i][j]);
			toplam +=m[i][j];
		}
		printf("\n");
	}
	printf("\n--\n");
	return toplam;
}



int main()
{
	srand(time(NULL));
	setlocale(LC_ALL,"Turkish");
	int m[5][5];
	/*Kendisi ve boyutlar� bilinen matrisin t�m elemanlar�n�n toplam�n� veren bir fonksiyon yaz�n�z. 
	5 s�t�ndan olu�an bir matris i�in fonksiyonun prototipi a�a��daki gibi olabilir.
	�nt enKucukElemaniBul (int matris[][5] , int satir, sutun);*
	*/
	
	for(int i = 0;i<5;i++)
	{
		for(int j = 0;j<5;j++)
		{
			m[i][j] = 1+rand()%10;		
		}
	}
	
	for(int i = 0;i<5;i++)
	{
		for(int j = 0;j<5;j++)
		{
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("%d",MatrisElemanToplam(m,5,5));
}

