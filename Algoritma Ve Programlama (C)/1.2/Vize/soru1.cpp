#include <stdlib.h>
#include <stdio.h>

//ana programdan gelen sayi, baslangica geliyor. Asal kontrol etmek icin sayac tanimlayip 2'ye esitliyorum.
//sayacin amaci sayiya kadar gidecek ve bu sayac, sayinin bolenleri varsa kontrol etmemizi saglayacak.
bool isPrime(int baslangic,int sayac = 2)  
{  										
	if(baslangic < 2)//baslangic 2'den kucukse false donduruyorum. Cunku 2'den kucukse asal olamaz.
		return false;
	if(baslangic == sayac) // sayi sayaca esitse asal demektir. true donduruyorum.
		return true;
	
	else //degilse
	{
		if(baslangic % sayac == 0) // sayi sayaca kalansiz bolunuyorsa asal degil demektir false donduruyorum.
			return false;
		else
			isPrime(baslangic,sayac+1); //Rekursif kullaným yeri. Sayi sayaca esit degil,tam da bolunmedi bu sebeple sayac+1.
	}

}


int main()
{
	
	FILE*fp; // file olusturmak icin file tipinden file pointer;
	
	//Kullanici Girdileri
	int x,y;
	printf("Baslangic : ");
	scanf("%d",&x);
	printf("Bitis : ");
	scanf("%d",&y);
	//Kullanici Girdileri
	
	//Dosya acarken hata alirsak kullaniciya bildiriyoruz ve return 1 ile hatali cikis yapýyorum.
	if((fp = fopen("primes.txt","w"))==NULL)
	{
		printf("dosya acilamadi ");
		return 1; // hatali cikis yapiyoruz.
	}
		
	
	for(x; x<=y;x++)//verilen aralik icin dongu
	{
		if(isPrime(x)==true)// x'i isPrime fonskiyonuna gonderiyoruz gelen sonuc true ise asaldýr ve if'e giriyoruz.
			fprintf(fp,"%d\n",x); // x asal olduðu icin dosyaya yaziyorum.
	}
	fclose(fp); // dosya kapatma
	
	return 0;
}
