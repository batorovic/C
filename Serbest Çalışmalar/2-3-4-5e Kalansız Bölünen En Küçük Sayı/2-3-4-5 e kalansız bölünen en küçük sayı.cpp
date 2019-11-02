#include <stdio.h>
#include <locale.h>
int main()
{
	//2-3-4-5e kalansız bölünen en küçük sayi
	setlocale(LC_ALL,"Turkish");	
	for(int i =1;;i++)
	{
		if(i % 2 == 0 && i % 3 == 0 && i % 4 == 0 && i % 5 == 0)
		{
			printf("%d ",i);
			break;
		}
	}
	
	


	return 0;
}
