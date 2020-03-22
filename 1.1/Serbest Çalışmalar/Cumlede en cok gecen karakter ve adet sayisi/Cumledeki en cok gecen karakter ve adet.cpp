#include <stdio.h>
#include <string.h>
int main()
{
	
	//cümle içinde en çok geçen karakteri bul ve kaç kere geçtiðini söyle.
	char str[322],tut=' ';
	printf("Cumle : ");
	gets(str);
	int sayac = 0,sayac1=0;
	for(int i = 0;i<strlen(str);i++)
	{
		sayac = 0;
		for(int j = 0;j<strlen(str);j++)
		{
			if(str[j]  == str[i])
			{
				sayac++;
			}
		}
		if(sayac > sayac1)	
		{
			sayac1 = sayac;
			tut = str[i];
		}
	}
	printf("En fazla %c karakterinden vardir. %d adet.",tut,sayac1);
	
	
	
	
	return 0;
}
