


#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
/*
1  1   1   1   1
1  0  1  0  1
1   1   1   1  1
1  0  1  0  1
1   1   1   1  1
sekil 1 
*/


void sekil1()
{
	int m[5][5];
	for(int i = 0;i<5;i++)
	{
		for(int j = 0;j<5;j++)
		{
			if(i % 2 == 0)
			{
				m[i][j] = 1;
			}
			else
			{
				if((i+j) % 2 == 1)
				{
					m[i][j] = 1;
				}
				else
				{
					m[i][j] = 0;
				}
			}
			printf("%d ",m[i][j]);
		}
		printf("\n");
		
	}
}

//sekil2
/*
1  0  0  0  0
1  2  0  0  0
1  2  3  0  0
1  2  3  4  0
1  2  3  4  5*/
void sekil2()
{
	int m[5][5]={};
	
	int koyucu = 1;
	for(int i = 0;i<5;i++)
	{
		
		for(int j = 0;j<5;j++)
		{
			m[j][i] = koyucu;
			printf("%d ",m[i][j]);

		}
		koyucu++;
		printf("\n");

	}
		
}

void dizi(int n)
{
	int sayilar[10] =  {25,22,17,19,47,3,98,5,124,10};
	int temp = 0;
	for(int i = 0;i<10;i++)
	{
		for(int j = 0;j<10;j++)
		{
			if(sayilar[i] < sayilar[j])
			{
				temp = sayilar[i];
				sayilar[i] = sayilar[j];
				sayilar[j] = temp;
			}
		}
	}
	
	for(int i = 0;i<10;i++)
	{
		printf("%d ",sayilar[i]);
	}
	printf("\n%d",sayilar[n-1]);
}
	



int main()
{
	srand(time(NULL));
	//sekil1();	
	/*
	int sayac;
	for(int i =0 ;i<5;i++)
	{
		sayac=1;
		for(int k =0;k<=i;k++)
		{
			printf("%d ",sayac);
			sayac++;
		}
		printf("\n");
	}*/
	//sekil2();
	dizi(10);
	return 0;
}

