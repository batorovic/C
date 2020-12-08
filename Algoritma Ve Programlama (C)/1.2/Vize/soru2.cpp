#include <stdlib.h>
#include <stdio.h>

int main()
{
// kullanicidan gelen girdiyi tutmak icin sayi tanimladim. A ve B dizileri dinamik olacagi icin basta null olarak tanimladim.
	int sayi,*A=NULL,*B=NULL;
	
// Dizinin dinamikligini saglamak icin boyut degiskenleri olusturdum.
	int boyutA = 1,boyutB = 1;
	
	while(1)//sonsuz dongu
	{
		//kullanýcý girdileri
		printf("Sayi : ");
		scanf("%d",&sayi);
		//kullanýcý girdileri
			
		if(sayi == 0) // kullanici sifir girerse if'e gir ve donguden cik.
			break;
		else
		{
			if(sayi % 2 == 0)// sayi 2'ye kalansiz bolunuyorsa cift demektir.
			{
				B = (int*)realloc(B,sizeof(int)*boyutB); // B icin ram'den boyutB adet integerlik yer ayirtiyorum.
				
				*(B+boyutB-1) = sayi; // -1 yapmamin sebebi 0.indisten baslatmak. Ornegin 2. CÝFT sayi girilince boyut 2 olacagindan yeni deger 1. indiste olacak
				
				boyutB++;//kullanicinin tekrar CÝFT sayi girme ihtimaline karsin boyutu 1 arttiriyorum.
			}
			else // sayi tek demektir.
			{
				A = (int*)realloc(A,sizeof(int)*boyutA);// A icin ram'den boyutA adet integerlik yer ayirtiyorum.
				
				*(A+boyutA-1) = sayi; // -1 yapmamin sebebi 0.indisten baslatmak. Ornegin 2. TEK sayi girilince boyut 2 olacagindan yeni deger 1. indiste olacak
				
				boyutA++; //kullanicinin tekrar TEK sayi girme ihtimaline karsin boyutu 1 arttiriyorum.
			}
		}
			
	}
	
	//Dizileri ekrana basma
	printf("\nCift sayilar : \n");
	for(int i = 0;i<boyutB-1;i++)
		printf("%4d",*(B+i));
	
	
	printf("\nTek sayilar : \n");
	for(int i = 0;i<boyutA-1;i++)
		printf("%4d",*(A+i));
	
	//ram'de yer ayirdigim yerlerle isim bittigi icin ayrilan yerleri temizliyorum
	free(A);
	free(B);
	
	return 0;
}
