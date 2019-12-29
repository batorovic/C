#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*69. Kendisine parametre olarak verilen 3X3 l�k matrisin elemanlar�n� b�y�kten k����e do�ru s�ralayan bir fonksiyon yaz�n�z. 
Matrisin sol �st k��esi en b�y�k say�y� i�ermelidir. Sa� alt k��esi ise en k���k say�y� i�ermelidir.
18  12  11
9    8     5
3    2     0
*/

void Yazdir(int dizi[3][3])
{
	for(int i = 0;i<3;i++)
	{
		for(int j = 0;j<3;j++)
		{
			printf("%d ",dizi[i][j]);
		}
		printf("\n");
	}
}
void MaxtoMin(int m[3][3])
{
/*
	int m[9],sayac = 0,temp=0;
	for(int i = 0;i<3;i++)
	{
		for(int j = 0;j<3;j++)
		{
			m[sayac] = dizi[i][j];
			sayac++;
		}
	}
	
	for(int i = 0;i<9;i++)
	{
		for(int j = 0;j<9;j++)
		{
			if(m[i] > m[j])
			{
				temp = m[i];
				m[i]=m[j];
				m[j] = temp;
			}	
		}
					
	}	

	
	
	int j = 0;
	while(j<9)
	{
		printf("%d ",m[j]);
		j++;
	}*/
	
	int temp;
	for(int i = 0;i<3;i++)
	{
		for(int j = 0;j<3;j++)
		{
			for(int k = 0;k<3;k++)
			{
				for(int z = 0;z<3;z++)
				{
					if(m[i][j] > m[k][z])
					{
						temp = m[i][j];
						m[i][j]=m[k][z];
						m[k][z] = temp;
					}		
				}
			}	
		}
	}
	
			
}

int main()
{
	//srand(time(NULL));
	int m[3][3];
	int i=0,j;
	while(i<3)
	{
		j=0;
		while(j<3)
		{
			m[i][j] = 1+rand()%50;
			j++;
		}
		i++;
	}
	
	Yazdir(m);
	printf("\n\n");
	MaxtoMin(m);
	Yazdir(m);
	srand(time(NULL));
	return 0;
}
