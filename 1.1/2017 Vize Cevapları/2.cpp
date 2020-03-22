#include <stdio.h>
#include <locale.h>
#include <string.h>
int main()
{
	char str[123];
	printf("Metin : ");
	gets(str);
	for(int i = 0;i<strlen(str);i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] = '*';
		else if(str[i] >= 'a' && str[i] <= 'z') 
			str[i] -=32 ;
	}
	printf("%s",str);
	return 0;
}
