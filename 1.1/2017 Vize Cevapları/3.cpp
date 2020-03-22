#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <math.h>
int AsalMi(int a)
{
	for(int i = 2;i<=a;i++)
	{
		if(a == i) return 1;
		else if(a % i == 0) break;
	}
}

void Armstrong3()
{
	int toplam=0,b=0,o=0,y=0;
	for(int i = 100;i<1000;i++)
	{
		b = i % 10;
		o = (i/10)%10;
		y = i/100;
		
		if((int)pow(b,3) + (int)pow(o,3) + (int)pow(y,3) == i)
		{
			printf("%d\n",i);
			if(AsalMi(i)) printf("Armstrong Ve Asal Sayýdýr.");
		}
	}
}
int main()
{
	int a = 3;
	//printf("%d",(int)pow(a,3));
	
	Armstrong3();
	return 0;
}
