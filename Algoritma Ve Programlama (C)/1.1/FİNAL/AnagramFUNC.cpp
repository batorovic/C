#include <stdio.h>
#include <string.h>


int Anagram(char str[],char str1[])
{
	int k1[26]={},k2[26]={},i=0;
	while(str[i] != '\0')
	{
		k1[str[i]-'a']++;
		i++;
	}
	
	i = 0;
	while(str[i] != '\0')
	{
		k2[str1[i]-'a']++;
		i++;
	}
	i=0;
	while(i<26)
	{
		if(k1[i] != k2[i])
		{
			return 0;
		}
		i++;
	}
	return 1;
}
int main()
{
	char str[30],str1[30];
	scanf(" %[^\n]",&str);
	scanf(" %[^\n]",&str1);
	if(strlen(str) != (strlen(str1))) return 0;

	if(str,str1) printf("anagramdir");
	return 0;
}
