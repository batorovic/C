#include <stdio.h>

int Fibonacci(int n)
{
	int sayac = 1;
	int c=0,b=1,a=0;
	while(1)
	{
		
		c = a+b;
		a = b;
		b = c;
		if(sayac == n) return c;
		sayac++;
	}
}
int main()
{	
	//1, 1, 2, 3, 5, 8, 13, 21, 34, 55
	printf("%d ",Fibonacci(1));	
	return 0;
}
