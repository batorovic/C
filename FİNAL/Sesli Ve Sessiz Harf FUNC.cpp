#include <stdio.h>
#include <locale.h>
#include <string.h>

int Sesli(char str[])
{
	char sesliler[]={'a','e','i','o','u'};
	int s=0;
	while(str[s] != '\0')
	{
		s++;
	}
	int sesli=0;
	for(int i = 0;i<s;i++)
	{
		for(int j = 0;j<5;j++)
		{
			if(sesliler[j] == str[i] || sesliler[j] == str[i] + 32)
			{
				sesli++;
				break;
			}
		}
	}
	return sesli;
}

int Sessiz(char str[])
{
	int bosluk=0;
	for(int i = 0;str[i]!='\0';i++)
	{
		if(str[i] == ' ') bosluk++;
	}
	return strlen(str) - (bosluk+Sesli(str));
}

int main()
{
	setlocale(LC_ALL,"Turkish");
	//TR karakter hariç
	char str[100]; 
	printf("Metin giriniz : ");
	gets(str);
	printf("Sesli Sayısı : %d\nSessiz Sayısı : %d",Sesli(str),Sessiz(str));
	return 0;
}
