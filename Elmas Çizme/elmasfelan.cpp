#include <stdio.h>

int main()
{
	int bosluk,genislik=0,yildiz=2;
	printf("Genislik");
	scanf("%d",&genislik);
	bosluk = genislik - 1;
	for(int i = 0;i < genislik; i++)
	{
		for(int j = 0;j<bosluk;j++)
		{
			printf(" ");
		}
		
		
		for(int k = 0; k<yildiz;k++)
		{
			if(k == 0) printf("/");
			else if(k == yildiz - 1 )
			{
				printf("\\");
			}
			else printf("*");
		}
		
		printf("\n");
		bosluk--;
		yildiz+=2;
	}
	
	yildiz-=2;;
	bosluk=0;
	for(int i = 0;i < genislik; i++)
	{
		for(int j = 0;j<bosluk;j++)
		{
			printf(" ");
		}		
		
		for(int k = 0; k<yildiz;k++)
		{
			if(k == 0) printf("\\");
			else if(k == yildiz - 1 )
			{
				printf("/");
			}
			else printf("*");
		}
		
		printf("\n");
		bosluk++;
		yildiz-=2;
	}
	
	return 0;
}


