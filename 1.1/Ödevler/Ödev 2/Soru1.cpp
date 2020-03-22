#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Turkish");
   
	int vize=0,final=0,ort=0,but=0;
	basa:
	printf("Vize notunuzu giriniz : ");
	scanf("%d",&vize);
	printf("Final notunuzu giriniz : ");
	scanf("%d",&final);
	
	if(vize>=0 && vize <=100 && final>=0 && final<=100)
	{
		ort = (vize*0.4)+(final*0.6);
		if(ort >= 60){printf("GEÇTİNİZ.");}
		else
		{
			bute:
			printf("Büt notunuzu giriniz : ");
			scanf("%d",&but);
			if(but>=0 && but <=100)
			{
				ort = (vize*0.4)+(but*0.6);
				if(ort >= 60){printf("GEÇTİNİZ.");}
				else{printf("KALDINIZ.");}	
			}
			else {printf("Geçerli büt notu giriniz.\n");goto bute;}	
		}		
	}
	else {printf("Geçerli not giriniz\n");goto basa;}
			
	return 0;
}
