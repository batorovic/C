/*
Tek boyutlu bir dizideki N. Elemaný bulan bir fonksiyon yazýnýz. 
Eðer N deðeri 5 ise fonksiyonunuz en küçük 5. Elemaný bulsun. .
Fonksiyon prototipi aþaðýdaki gibidir.

Ýnt enKucukNinciElemaniBul (int dizi[] , int elemanSayisi,int n);

*/


#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int Bulucu(int d[],int n,int eleman)
{
	int min = d[0];
	for(int i = 0;i<eleman;i++)
	{
		if(n == i)
		{
			for(int j = 0;j<eleman;j++)
			{
				if(min > d[j])
				{
					min = d[j];
				}
			}
			return min;
		}
	}
	
}


int main()
{
	srand(time(NULL));
	int a[10]={1,2,3,4,5,6,7,8,9,-5};
	printf("%d",Bulucu(a,4,10));
	return 0;
}

