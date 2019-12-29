#include <stdio.h>
#include <locale.h>

int Muhtesem(int x)
{
	int i = 1,top=0;
	while(i<x)
	{
		if(!(x % i)) top+=i;
		i++;
	}
	if(x == top) return 1;
	else return 0;
}

int main()
{
	setlocale(LC_ALL,"Turkish");
	int a;
	printf("Sayý giriniz : ");
	scanf("%d",&a);
	if(Muhtesem(a)) printf("Muhteþem sayýdýr.");
	else printf("Muhteþem sayý deðildir.");
	return 0;
}
