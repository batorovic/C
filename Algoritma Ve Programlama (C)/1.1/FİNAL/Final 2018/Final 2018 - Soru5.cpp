#include <stdio.h>

int main()
{
	int satir = 0;
	printf("Satýr : ");
	scanf("%d",&satir);
	for(int i = 0;i<satir;i++)
	{
		for(int j = 0;j<satir;j++)
		{
			if(i+j >= satir-1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
