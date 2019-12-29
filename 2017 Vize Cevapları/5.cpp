#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Turkish");
	int m1sa,m1su,m2sa,m2su;
	printf("1.matris satýr : ");
	scanf("%d",&m1sa);
	printf("2.matris satýr : ");
	scanf("%d",&m1su);
	printf("2.matris satýr : ");
	scanf("%d",&m2sa);
	printf("2.matris sütün : ");
	scanf("%d",&m2su);
	
	if(m1su != m2sa) return 0;
	
	int m1[m1sa][m1su];
	int m2[m2sa][m2su];
	
	for(int i = 0;i<m1sa;i++)
	{
		for(int j = 0;j<m1su;j++)
		{
			printf("1. matrisin %d. satýrýnýn %d. sutununa deger giriniz : ",i+1,j+1);
			scanf("%d",&m1[i][j]);
		}
	}
	
	for(int i = 0;i<m2sa;i++)
	{
		for(int j = 0;j<m2su;j++)
		{
			printf("2. matrisin %d. satýrýnýn %d. sutununa deger giriniz : ",i+1,j+1);
			scanf("%d",&m2[i][j]);
		}
	}
	
	printf("1.MATRÝS : \n");
	for(int i = 0;i<m1sa;i++)
	{
		for(int j = 0;j<m1su;j++)
		{
			printf("%d ",m1[i][j]);
		}
		printf("\n");
	}
	printf("2.MATRÝS : \n");
	for(int i = 0;i<m2sa;i++)
	{
		for(int j = 0;j<m2su;j++)
		{
			printf("%d ",m2[i][j]);
		}
		printf("\n");
	}
	
	

	int carpimMatris[m1sa][m2su]={};
	
	for(int i = 0;i<m1sa;i++)
	{
		for(int j = 0;j<m2su;j++)
		{
			for(int k  = 0;k<m1su;k++)
			{
				carpimMatris[i][j] += m1[i][k] * m2[k][j];	
			}
			
		}
	}
	
	printf("ÇARPIM MATRÝS : \n");
	for(int i = 0;i<m1sa;i++)
	{
		for(int j = 0;j<m2su;j++)
		{
			printf("%d ",carpimMatris[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
