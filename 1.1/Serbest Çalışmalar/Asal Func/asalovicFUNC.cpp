#include <stdio.h>
#include <math.h>


int Asalmi(int x)
{
	int i,j,c=0;
	for(int i = 2;i<=x;i++)
	{
		if(x == i) 
		{
			//printf("Asaldir");
			return 1;
		}
		else if(x % i == 0) 
		{
			//printf("Asal degildir");
			break;
		}
		
	}
	
	
}


void AsalToplam(int a,int b)
{
	int toplam = 0;
	for(a;a<b;a++)
	{
		if(Asalmi(a))
			toplam+=a;

	}
	printf("%d",toplam);
	
}

int main()
{
	/*int s;
	printf("sayi giriniz : ");
	scanf("%d",&s);
	Asalmi(s);*/
	
	int r1,r2;
	printf("kactan ");
	scanf("%d",&r1);
	printf("kaca ");
	scanf("%d",&r2);
	AsalToplam(r1,r2);
	
	return 0;
}
