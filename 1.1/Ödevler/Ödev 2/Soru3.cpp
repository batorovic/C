#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>

int main()
{	
	setlocale(LC_ALL,"Turkish");
	int sayi,tekler,tTop=0,cCarp=1,ciftler=0;
	for(int i = 0; i < 4; i++)
	{
		printf("%d. sayıyı giriniz : ",i+1);
		scanf("%d",&sayi);
		if(sayi % 2 == 0)
		{
			ciftler++;
			cCarp*=sayi;
		}
		else
		{
			tekler++;
			tTop+=sayi;
		}
		
	}
	
	if(ciftler != 0){printf("Çiftlerin Geometrik Ortalaması : %lf\n",pow((double)cCarp,(double)1/ciftler));}
	
	if(tekler != 0){printf("Teklerin Aritmetik Ortalaması %.2f",(float)tTop/tekler);}

	getch();
	return 0;
}
