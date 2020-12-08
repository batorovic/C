#include <stdio.h>
#include <locale.h>

int main()
{
	char str[200],ara[39];
	printf("Metin : ");
	scanf(" %[^\n]",&str);
	printf("Aranan kelime : ");
	scanf(" %[^\n]",&ara);

	int uzunluk = 0,uzunluk2=0;
	for(int i =0;str[i] != '\0';i++)
	{
		uzunluk++;
	}
	
	for(int i =0;ara[i] != '\0';i++)
	{
		uzunluk2++;
	}
	int sayac = 0,bas=0,son=0,i;
	for(i = 0;i<uzunluk;i++)
	{
		if(str[i] == ' ' || str[i] != ara[sayac]) sayac = 0;
	
		else if(str[i] == ara[sayac])
		{
			sayac++;
			if(sayac == uzunluk2) 
			{
				printf("aradiginiz kelime cumlede vardir.\n%d.indexten %d.indexe kadar.\n",i-uzunluk2+1,i);
				sayac=0;
			}
		}
	}
	
	
	return 0;
}
