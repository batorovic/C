#include <stdio.h>
#include <locale.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL,"Turkish");
	//ebob ve ekok bulma
	int s1,s2,max=0,ebob=0;
	printf("1. sayıyı giriniz : ");
	scanf("%d",&s1);
	printf("2. sayıyı giriniz : ");
	scanf("%d",&s2);
	if(s1 > s2){max = s1;}
	else{max = s2;}
	for(int i = 1;i<=max;i++)
	{
		if(s1 % i == 0 && s2 % i == 0)
		{
			ebob = i;
		}	
	}
	

	printf("Ebobları : %d\n",ebob);
	printf("Ekokları : %d\n",s1*s2/ebob);
		
	
	
	return 0;
}
