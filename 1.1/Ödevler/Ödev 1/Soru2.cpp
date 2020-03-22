#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL,"Turkish");

	
	short s1,s2;
	printf("1.Sayıyı giriniz ");
	scanf("%hd",&s1);
	printf("2.Sayıyı giriniz ");
	scanf("%hd",&s2);
	
	s1!=s2 ? s1>s2 ?printf("%hd > %hd",s1,s2):printf("%hd > %hd",s2,s1):printf("Sayılar eşit ");
	

	return 0;
}










