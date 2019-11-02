#include <stdio.h>
#include <locale.h>
int main()
{
	//Faktöriyel
	setlocale(LC_ALL,"Turkish");
	int sayi = 0;
	printf("Faktöriyelini bulmak istediğiniz sayıyı giriniz : ");
	scanf("%d",&sayi);
	int faktor = 1;
	for(int i = 1;i<=sayi;i++)
	{
		faktor*=i;
	}
	printf("%d",faktor);
	return 0;
}
