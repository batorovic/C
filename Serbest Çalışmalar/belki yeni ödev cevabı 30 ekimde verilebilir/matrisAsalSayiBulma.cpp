#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL,"Turkish");
	//10'a 10 matris random deðer at asallarý bul ekrana yaz;
	int matris[10][10],kontrol=0,i,j;
	
	
	
	
	for( i = 0;i<10;i++)
	{
		for( j = 0; j< 10; j++)
		{
			kontrol = 0;
			matris[i][j] = 1+rand()%100;
			for(int k =2;k<matris[i][j];k++)
			{
				if(matris[i][j] % k == 0)
				{
					kontrol = 1;
				}
			}
			if(kontrol == 0) printf("[%d][%d] = %d asaldýr.\n",i,j,matris[i][j]);
		}

	}
	
	
	for( i = 0;i<10;i++)
	{
		for( j = 0; j< 10; j++)
		{
			printf("%d ",matris[i][j]);
		}
		printf("\n");
	}
	
	
	
	
	
	
	return 0;
}
