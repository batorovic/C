#include <stdio.h>
#include <locale.h>
#include <math.h>
int main()
{
	setlocale(LC_ALL,"Turkish");
	/*
	//sayÄ±yÄ± tersten yazdÄ±rma
	int sayi,ters=0;
	printf("LÃ¼tfen sayÄ±yÄ± giriniz : ");
	scanf("%d",&sayi);
	
	while(sayi != 0)
	{
		ters*=10;
		ters += sayi % 10;
		sayi/=10;
	
	}
	
	printf("Tersten: %d",ters);*/

	
	/*
	for(int i = 1;i<=5;i++)
	{
		for(int j = 1;j<=5;j++)
		{
			if((i+j) == 6 || i==j)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}*/
	
	//kare çizme
	int k = 0;
	printf("kenar kaç birim olsun ");
	scanf("%d",&k);
	
	
	
	/*
	  ******
	  *    *
	  *    *
	  *    *
	  *    *   
	  ******
	  
	
	
	*/

	
	for(int i = 1;i<=k;i++)
	{
		for(int j = 1; j<=k;j++)
		{
			if(j == 1 || i == k || j == k || i == 1)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	

































	
	
	return 0;
}
