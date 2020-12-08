#include <stdio.h>
#include <locale.h>
int main()
{
	//while ile
	/*
	setlocale(LC_ALL,"Turkish");
	//0 1 1 2 3 5 8 13...
	int i = 0,adim,a=0,b=1,c=0;
	printf("Kaç adım gitsin : ");
	scanf("%d",&adim);
	while(i<adim)
	{
		printf("%d ",a);
		c = a + b;
		a = b;
		b = c;	
		i++;
	}*/
	
	//for ile
	
	int adim,a=0,b=1,c=0;
	printf("Kaç adım gitsin : "); 
	scanf("%d",&adim);
	
	for(int i = 0;i<adim;i++)
	{
		printf("%d ",a);
		c = a+b;
		a = b;
		b = c;
	}	
	return 0;
}
