#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL,"Turkish");
	//matristeki(3-3) en büyük sayı kaç kere tekrar etti
	int matris[3][3],max=0,sayac=0;
	for(int i = 0; i<3;i++)
	{
		for(int j = 0;j<3;j++)
		{
			matris[i][j] = rand()%10;
			if(max < matris[i][j])
			{
				max = matris[i][j];
			}
		}
	}
	for(int i = 0; i<3;i++)
	{
		for(int j = 0;j<3;j++)
		{
			printf("%d ",matris[i][j]);
			if(max == matris[i][j])
			{
				sayac++;
			}
		}
		printf("\n");
	}	
	
	printf("%d rakamı %d kere tekrar etti.",max,sayac);	
	return 0;
}
