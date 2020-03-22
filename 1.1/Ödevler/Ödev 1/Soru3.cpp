#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL,"Turkish");
	
	float s1,s2,s3;
	printf("1. Sayıyı Giriniz : ");
	scanf("%f",&s1);
	printf("2. Sayıyı Giriniz : ");
	scanf("%f",&s2);
	printf("3. Sayıyı Giriniz : ");
	scanf("%f",&s3);
	printf("Girilen sayıların Toplamı: %.2f\nOrtalaması = %.2f",(s1+s2+s3),(s1+s2+s3)/3);

	return 0;
}


