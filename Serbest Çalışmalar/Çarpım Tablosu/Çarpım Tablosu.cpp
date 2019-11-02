#include <stdio.h>
#include <locale.h>
int main()
{
	//Çarpım Tablosu
	setlocale(LC_ALL,"Turkish");	
	for(int i = 1;i<10;i++)
	{
		for(int j = 1;j<10;j++)
		{
			printf("%d X %d = %d\n",i,j,i*j);
		}
		printf("\n");
	}
	
	


	return 0;
}
