#include <stdio.h>
#include <locale.h>
void BastanBoslukluYildiz(int);
void KumSaati(int);
void KumSaati2(int);
/*
//BAÞTAN BOÞKUKLU YILDIZ

	*
   **
  ***
 ****
*****

*/

/*   
	KUM SAATÝ 
	
	*************
	 ***********
	  *********
	   *******
	    *****
		 ***
		  *
		 ***
		*****
	   *******
	  *********
	 ***********
	*************


*/

int main()
{
	setlocale(LC_ALL,"Turkish");
	int satir;
	printf("kaç satýrdan oluþsun : ");
	scanf("%d",&satir);
	//BastanBoslukluYildiz(satir);
	KumSaati2(satir);
	return 0;
}

void KumSaati2(int satir)
{
	int yildiz=0,bosluk = 0;
	if(satir % 2 == 0) satir+=1;
	yildiz= satir;
	
	for(int i = 0;i<satir;i++)
	{
		
		for(int k = 0;k<yildiz;k++)
		{
			printf("*");
		}
		printf("\n");
		if( i < satir/2)
		{
			yildiz-=2;
			bosluk++;
		}
		else
		{
			yildiz+=2;
			bosluk--;
		}
		
		for(int j = 0;j<bosluk;j++)
		{
			printf(" ");
		}
		
		
	}
	
	
}

void KumSaati(int satir)
{
	if(satir % 2 == 0) satir+=1;
	int yildiz = satir,bosluk = 0;
	for(int i = 0;i<satir/2+1;i++)
	{
		for(int k = 0;k<bosluk;k++)
		{
			printf(" ");
		}
		for(int j = 0;j<yildiz;j++)
		{
			printf("*");
		}
		printf("\n");
	
		bosluk++;
		yildiz-=2;
	}
	yildiz+=4;
	bosluk = satir/2 - 1 ;
	
	for(int i = 0;i<satir/2;i++)
	{
		for(int k = 0;k<bosluk;k++)
		{
			printf(" ");
		}
		for(int j = 0;j<yildiz;j++)
		{
			printf("*");
		}
		
		printf("\n");
		bosluk--;
		yildiz+=2;
	}
	
}

void BastanBoslukluYildiz(int satir)
{
	for(int i = 0;i<satir;i++)
	{
		for(int j = 0;j<satir;j++)
		{
			if(i+j >= satir-1)
			{
				printf("*");
			}
			else printf(" ");
		}
		printf("\n");
	}
	
}
