#include <stdio.h>
#include <locale.h>
#include <conio.h>
int main()
{
	setlocale(LC_ALL,"Turkish");
	int m1[3][3],m2[3][3],s[3][3];
	
	for(int i = 0;i<3;i++)
	{
		for(int j = 0; j< 3;j++)
		{
			printf("1. Matrisin %d. satırının %d. sütununa değer giriniz : ",i+1,j+1);
			scanf("%d",&m1[i][j]);
		}
	}
	
	for(int i = 0;i<3;i++)
	{
		for(int j = 0; j< 3;j++)
		{
			printf("2. Matrisin %d. satırının %d. sütununa değer giriniz : ",i+1,j+1);
			scanf("%d",&m2[i][j]);
			s[i][j] = m1[i][j]+m2[i][j]; 
		}
	}
	printf("1.Matris\n");
	for(int i = 0;i<3;i++)
	{
		for(int j = 0; j< 3;j++)
		{
			printf("%d ",m1[i][j]);
		}
		printf("\n");
	}
	
	printf("2.Matris\n");
	for(int i = 0;i<3;i++)
	{
		for(int j = 0; j< 3;j++)
		{
			printf("%d ",m2[i][j]);
		}
		printf("\n");
	}
	
	printf("\n2 Matrisin Toplamı\n");	
	
	for(int i = 0;i<3;i++)
	{
		for(int j = 0; j< 3;j++)
		{
			printf("%d ",s[i][j]);
		}
		printf("\n");
	}
	
	
	
	getch();
	
	return 0;
}
