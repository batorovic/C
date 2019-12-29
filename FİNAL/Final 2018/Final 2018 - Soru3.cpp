#include <stdio.h>
#include <string.h>
void AyarCek(char str[])
{
	for(int i = 0;i<strlen(str);i++)
	{
		if(i % 2 == 0)
		{
			if(str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i]+=32;
			}	
		}
		else
		{
			if(str[i] >= 'a' && str[i] <= 'z')
			{
				str[i]-=32;
			}
		}
	}	
	printf("%s",str);
}

int main()
{
	char metin[200];
	printf("Metin : ");
	gets(metin);
	AyarCek(metin);
	return 0;
}
