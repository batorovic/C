#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(NULL));
	int dizi[5],i=0,toplam = 0,t2=0;
	while(i<5)
	{
		dizi[i] = 1 + rand()%50;
		printf("%d ",dizi[i]);
		toplam+=dizi[i];
		i++;
	}	
	i = 0;
	printf("\n");
	float ort = (float) toplam / 5;
	while(i<5)
	{
		if(dizi[i] <ort) t2+=dizi[i];
		i++;
	}
	printf("%d",t2);
	
}
