#include <stdio.h>
#include <locale.h>
int main()
{
	//100e kadar olan asal sayılar
	setlocale(LC_ALL,"Turkish");	
	int kontrol = 0;
	for(int i = 2;i<100;i++)
	{
		kontrol = 0;
		for(int j = 2;j<i;j++)
		{
			if(i % j == 0) kontrol = 1;
		}
		
		if(kontrol == 0) printf("%d\n",i);
	}
	
	


	return 0;
}
