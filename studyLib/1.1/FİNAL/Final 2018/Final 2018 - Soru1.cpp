#include <stdio.h>
#include <locale.h>
int Asal(int x)
{
	//sadece while kullan.
	/*
	int i=2,j=2,sayac=0;
	while(1)
	{
		while(j<=i)
		{
			if( i == j)
			{
				sayac++;
				break;	
			}
			else if( i % j == 0)
			{
				break;	
			} 
			j++;
		}
		if(sayac == x) return i;
		i++;
		j=2;
	}*/
	
	
	//do-while
	
	do
	{
		int i=2,j=2,sayac=0;
		while(1)
		{
			while(j<=i)
			{
				if( i == j)
				{
					sayac++;
					break;	
				}
				else if( i % j == 0)
				{
					break;	
				} 
				j++;
			}
			if(sayac == x) return i;
			i++;
			j=2;
		}	
	
	}while(1);
}
int main()
{
	setlocale(LC_ALL,"Turkish");
	int a=0;
	printf("Kaçýncý sýradaki asal sayýyý öðrenmek istersiniz ? : ");
	scanf("%d",&a);
	printf("%d. sýradaki asal sayý : %d ",a,Asal(a));	
	return 0;
}
