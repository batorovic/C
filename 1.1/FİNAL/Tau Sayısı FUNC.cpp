#include <stdio.h>
#include <locale.h>
int Tau(int x)
{
	int sayac = 0;
	for(int i = 1;i<=x;i++)
	{
		if(x % i == 0) sayac++;
	}
	if(x % sayac == 0) return 1;
	else return 0;
}

int main()
{
	setlocale(LC_ALL,"Turkish");
	int a;
	printf("Say� giriniz : ");
	scanf("%d",&a);
	if(Tau(a)) printf("tau say�s�d�r");
	else printf("tau say�s� de�ildir.");
	return 0;
}
