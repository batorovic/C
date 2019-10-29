#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL,"Turkish");
	int s1,s2;
	char secim =' ';
	printf("1. Sayıyı giriniz. ");
	scanf("%d",&s1);
	printf("2. Sayıyı giriniz. ");
	scanf("%d",&s2);
	printf("Menü\nToplama +\nÇıkarma -\nÇarpma *\nBölme /\nOperatör seçininiz: ");
	scanf(" %c",&secim);
	switch(secim)
	{
		case '+':printf("Toplamları %d + %d = %d ",s1,s2,s1+s2);break;
		case '-':printf("Farkları %d - %d = %d ",s1,s2,s1-s2);break;
		case '*':printf("Çarpımları %d * %d = %d ",s1,s2,s1*s2);break;
		case '/':printf("Bölümleri %d / %d = %.2f ",s1,s2,(float)s1/s2);break;
		
		default: printf("Operatör harici tuşlamayın !");
	}
	
	return 0;
	
}
