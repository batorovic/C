# Stack Ödevi

Bu ödevde tamsayı türünde verilerin tutulduğu ve üzerinde işlem yapıldığı bir yığın (stack) sistemi tasarlanacaktır. Sistem üzerinde stack yapısı kullanarak geri alma işleminin gerçekleştirilmesi amaçlanmaktadır. Bu işlemler için kullanılan komutlar aşağıda açıklanmıştır.
EKLE X: X tamsayısı işlem stack’ine eklenecek
SİL: Stack’deki son eleman silinecek
YAZDIR: Stack içindeki elemanlar ekrana stack mantığında listelenecek ( son giren ilk çıkar)
GERİ AL: Yapılan işlem geri alınacak

Ödevde Geri stack ve İşlem stack olmak üzere 2 tane stack veri yapısının kullanılması beklenmektedir.
Örnek Uygulama:


| INPUT 		| 		OUTPUT | 
|	:---        |     :---:      |   
|	EKLE 30   	| DEĞER EKLENDİ     | 
|	EKLE 10     | DEĞER EKLENDİ       | 
|	YAZDIR	 	| EKRANA YAZDIRILDI= “ 10 -30 “	|
|	SİL			| 10 SİLİNDİ	|
|	YAZDIR		| EKRANA YAZDIRILDI= “30 “|
|	GERİ AL		| 10 SİLİNME İŞLEMİ GERİ ALINDI|
|	YAZDIR 		| EKRANA YAZDIRILDI= “ 10-30 “|
|	EKLE 11		|DEĞER EKLENDİ|
|	EKLE 27		|DEĞER EKLENDİ|
|	SİL			|27 SİLİNDİ|
|	YAZDIR		|EKRANA YAZDIRILDI= “ 11-10-30 “|
|	EKLE 99		|DEĞER EKLENDİ|
|	GERİ AL		|99 EKLEME İŞLEMİ GERİ ALINDI|
|	YAZDIR		|EKRANA YAZDIRILDI= “ 11-10-30 “|
|	GERİ AL		|27 SİLİNME İŞLEMİ GERİ ALINDI|
|	YAZDIR		|EKRANA YAZDIRILDI= “ 27-11-10-30 “|
|	SİL			|27 SİLİNDİ|
|	YAZDIR		|EKRANA YAZDIRILDI= “ 11-10-30“|
