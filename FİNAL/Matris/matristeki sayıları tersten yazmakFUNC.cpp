#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int IndistekiSayilariTerstenYaz(int m[3][3])
{
	int temp = 0,ters;
	for(int i = 0;i<3;i++)
	{
		for(int j = 0;j<3;j++)
		{
			temp = m[i][j];
			ters = 0;
			while(temp > 0)
			{
				ters *= 10;
				ters += temp % 10;
				temp /= 10; 
			}
			m[i][j] = ters;	
		}
	}		
	return m[3][3];
}

int main()
{
	
	int matris[3][3];
	for(int i = 0;i<3;i++)
	{
		for(int j = 0;j<3;j++)
		{
			matris[i][j] = 1+rand()%100;
		}
	}

	for(int i = 0;i<3;i++)
	{
		for(int j = 0;j<3;j++)
		{
			printf("%d ",matris[i][j]);
		}
		printf("\n");
	}
	printf("\n-------------\n");
	IndistekiSayilariTerstenYaz(matris);

	for(int i = 0;i<3;i++)
	{
		for(int j = 0;j<3;j++)
		{
			printf("%d ",matris[i][j]);
		}
		printf("\n");
	}

	return 0;
}
