#include <math.h>
#include <stdio.h>

int BasamakSayisi(int);
int ArmstrongKontrol(int);


int BasamakSayisi(int a)
{
	int c=0;
	while(a>0)
	{
		a = a / 10;
		c++;
	}
	
	return c;
}

int ArmstrongKontrol(int x)
{
	int basamak = BasamakSayisi(x),toplam = 0,temp;
	
	temp = x;
	while(x>0)
	{
		toplam += pow((x % 10),basamak);
		x = x / 10;
	}
	
	return temp == toplam;
}


int main()
{
	//1-50.0000 arasý armstrong sayýlarý bulmak
	//printf("%d",BasamakSayisi(1234));
	for(int i = 1;i<50000;i++)
	{
		if(ArmstrongKontrol(i))
			printf("%d\n",i);
	}
	return 0;
}
