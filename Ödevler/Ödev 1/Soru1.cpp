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
	
	s2!=0 ?printf("Toplamları: %hd\nFarkları: %hd\nÇarpımları: %hd\nBölümleri: %.2f\n",(s1+s2),(s1-s2),(s1*s2),((float)(s1)/(float)(s2))):
	printf("Toplamları: %hd\nFarkları: %hd\nÇarpımları: %hd\nSıfıra Bölünemez",(s1+s2),(s1-s2),(s1*s2));
	
	return 0;
}
