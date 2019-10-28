#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
void soru3()
{
	//3 basamaklý asal sayýlar ve armstrong sayýlarý bulma
	int kontrol = 0,i=100,j=0,yuzler=0,onlar=0,birler=0;
	while(i<1000)
	{
		kontrol=0;
		for(j = 2; j<i;j++)
		{
			if(i % j == 0)
			{
				kontrol = 1;
			}
		}
		if(kontrol == 0)
		{
			printf("%d\n",i);	
		}
		birler = i % 10;
		onlar = (i / 10) % 10;
		yuzler = i / 100;
		if(pow(birler,3)+pow(onlar,3)+pow(yuzler,3) == i)
		{
			printf("%d Armstrong sayýsýdýr\n",i);
		}
		i++;
	}
}

void soru5()
{
	//5x5 matrisin çarpýmýnýn köþegen elemanlarýnýn toplamý !sadece köþegen yapayým ben !
	
	int m[5][5],koseT=0,k=4;
	srand(time(NULL));
	for(int i =0;i<5;i++)
	{
		for(int j =0;j<5;j++)
		{
			m[i][j] = 1+rand()%100;
		}
		
	}
	for(int i =0;i<5;i++)
	{
		for(int j =0;j<5;j++)
		{
			printf("%d ",m[i][j]);
		}
		koseT+=m[i][k];
		k--;
	
		printf("\n");
	}
	
		
	printf("\nKöþegen eleman toplamý : %d",koseT);
}

int main()
{
	setlocale(LC_ALL,"Turkish");
	soru5();
	return 0;
}


