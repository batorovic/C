#include <stdio.h>
#include <locale.h>

int main()
{
	int d[5],i=0,max=0,sayac=0;
	while(i<5)
	{
		printf("Sayý : ");
		scanf("%d",&d[i]); 
		if(d[i] == max) sayac++;
		if(d[i] % 2 == 0)
		{
			if(d[i] >= max)
			{
				max = d[i];
			}
			
		}
		i++;
	}
	printf("%d",sayac+1);
	return 0;
}
