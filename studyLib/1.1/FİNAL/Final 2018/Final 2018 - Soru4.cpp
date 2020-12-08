#include <stdio.h>
#include <locale.h>
struct Ogrenci
{
	char ad[30];
	char soyad[30];
	struct  ders
	{
		int ders_kod;
		int vize;
		int final;	
		float ort;
	}ders[2];
}ogr[2];

int main()
{
	setlocale(LC_ALL,"Turkish");
	int i = 0;
	float derskort=0;
	for(int i = 0;i<2;i++)
	{
		printf("%d. Öðrencinin : \n",i+1);
		printf("Ad : ");
		scanf(" %[^\n]",&ogr[i].ad);
		printf("Soyad : ");
		scanf(" %[^\n]",&ogr[i].soyad);
		printf("\n");
		for(int j = 0;j<2;j++)
		{
			printf("%d. Ders kodu : ",j+1);
			scanf("%d",&ogr[i].ders[j].ders_kod);
			printf("Vize : ");
			scanf("%d",&ogr[i].ders[j].vize);
			printf("Final : ");
			scanf("%d",&ogr[i].ders[j].final);	
			ogr[i].ders[j].ort = (float) (ogr[i].ders[j].final*0.6)+(float)(ogr[i].ders[j].vize*0.4);
			derskort+=ogr[i].ders[j].ort;
		}	
	}
	
	for(int i = 0;i<2;i++)
	{
	
		printf("%d. öðrencinin : \n",i+1);
		for(int j = 0;j<2;j++)
		{
			printf("%d. ders kodunun ortalamasý : %.2f\n",j+1,ogr[i].ders[j].ort);
		}	
	}
	printf("\nSýnýfýn ortalamasý : %.2f",derskort/2);
	return 0;
}


