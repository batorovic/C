# Kuyruk Ödevi

A-) Yukarıda içeriği verilen bir metin dosyasındaki tüm isimleri ve bu isimlere ait öncelik bilgilerini (Tam
Sayı) oluşturacağınız kuyruk veri yapısına aktarınız. Kuyruk veri yapısını isteğiniz şekilde (bağlı liste, dizi, vb.)
tanımlayabilirsiniz. (Dosyada kayıtlar öncelik sırasına göre tutulmakta olup, 0 en öncelikli kayıttır. Diğer
numaralar (1, 2, 3, … öncelikler azalarak devam etmektedir. Dosyadan ekleme sırasında sıranın doğru
oluşturulduğu kabul edilerek, doğrudan text dosyasındaki sırayla eklemeler yapılabilir.

B-) Tüm kuyruktaki kişileri listeleyen kodu yazınız.

C-) İsmi verilen bir kullanıcının önünde kaç kişi olduğunu veren bir kod yazınız. Örnek: yukarıdaki dosya
içeriğine göre Mehmet’in önünde 5 kişi vardır.

D-) Kuyruğa kişi ekleme kodunu aşağıda verilen şartları kapsayacak şekilde yazınız.

- Kuyruğa eklenecek kişinin adını ve öncelik numarasını alınız.
- Kişiyi, kendiyle aynı öncelikli kişilerden sonra, kendinden daha az öncelikli kişilerden de önce eklemelisiniz.

Bu işlemi gerçekleştirirken, verileri tampon olarak aktarabileceğiniz veri yapıları, bağlı liste, yığın ya da
kuyruk veri yapılarıdır. Bunlar dışında yapı/değişken/nesne kullanmayınız.

Örnek:
- Yukarıda verilen text dosyasındaki verileri eklediğimiz bir kuyruğa aşağıdaki eklemeyi yaparsak;
- öncelik :1
- isim = Melek

**Ekleme Oncesi**        
| Öncelik	|	İsim 	| 												  
|	:---:      |     :---:|   
|	0  	| Veli    | 
|	0    | Ayşe  |     
|	1	 	| Kamile|
|	1		| Zeynep|	
|	1		| Ali|
|	2		| Mehmet|
|	2		| Mert |

**Ekleme Sonrası**
| Öncelik	|	İsim 	| 												  
|	:---:      |     :---:|   
|	0  	| Veli    | 
|	0    | Ayşe  |     
|	1	 	| Kamile|
|	1		| Zeynep|	
|	1		| Ali|
|1|Melek|
|	2		| Mehmet|
|	2		| Mert |
