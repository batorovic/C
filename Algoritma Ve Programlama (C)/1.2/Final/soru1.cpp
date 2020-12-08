#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cift Yonlu Bagli Liste icin gerekli yapi.
struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;	
};

typedef struct Node Node;

Node *head = NULL;




void DoubleLinkedListAdd(Node* input);

void DoubleLinkedListAdd(Node* input)//sirali ekleme fonksiyonu.
{
	Node *temp = NULL;
	
	if (head == NULL) // Liste bos ise.
    {
        head = input;
        head->prev = NULL;
        head->next = NULL;
    }

    else if (head->data > input->data) // Listenin Basina ekleme islemi.
    {

        input->next = head;
        input->next->prev = input;

        head = input;
    }
    
    else // kaydedilecek yeri belirliyorum.
    {
        Node *temp = head;

        while (temp->next != NULL && temp->next->data < input->data)
            temp = temp->next;


        input->next = temp->next;

        if (temp->next != NULL)
            input->next->prev = input;

        temp->next = input;
        input->prev = temp;
    }
    free(temp);
    
    
}

void PrintList() // Listeyi ekrana basan fonksiyon.
{
    Node *_temp = head;

    while (_temp != NULL)
    {
        printf("%4d", _temp->data);
        _temp = _temp->next;
    }

    printf("\n\n");
}

void ReverseList(FILE *fp1) // Listeyi tersten dosyaya yazan fonksiyon.
{
    Node *_temp = head;
	while(_temp->next != NULL) // listenin sonuna gidip son elemaný buluyorum.
		_temp = _temp->next;
	
	while (_temp != NULL) // listeyi tersten dosyaya yazýyorum.
    {
    	fprintf(fp1,"%d\n",_temp->data);
        _temp = _temp->prev;
    }
}

//RAM'de ayrýlan her bir Node'u temizleyen fonksiyon
void FreeList(Node* headref)
{
    Node *_temp;

    while (headref != NULL)
    {
        _temp = headref;
        headref = headref->next;

        free(_temp);
    }
}



int main()
{
	srand(time(NULL));
	
	FILE *fp=NULL,*fp1=NULL;
	
	int i = 0;
	
	if((fp = fopen("sayilar.txt","w+")) == NULL) // sayilar.txt dosyasini acma islemi. Daha sonra bu dosyayi okuyacaðim icin w+ modunda aciyorum.
	{
		printf("Dosya acilamadý");
		return 1; // dosya acilamaz ise hatali cikis.
	}
	
	while(i<10) // sayilar.txt'ye 10 adet random sayi atiyorum.
	{
		fprintf(fp,"%d\n",rand() % 100);
		i++;
	}


	
	//DoubleLinkedListAdd fonksiyonuna veri gondermem icin Node tipinden bir degisken olusturuyorum.
	Node *info = (Node *)malloc(sizeof(Node)); 
	
	
	fseek(fp, 0, 0);//sayilar.txt'de dosyayi bastan sona dogru okumak icin cursor'u en uste aliyorum.
	
	while(fscanf(fp,"%d",&info->data) == 1) // sayilar.txt'den veri okundugu sürece ekleme yapýyorum.
	{
		DoubleLinkedListAdd(info); // her yeni degeri cift yonlu bagli listeye sirali olarak eklemek icin fonksiyona degeri gonderiyorum.
		info = (Node *)malloc(sizeof(Node)); // her yeni deger icin Node tipinden info olusturuyorum.
	}
	

	
	printf("sayilar.txt 'den okunan verilerin sirali hali : ");
	printf("\n\n");
	
	PrintList(); //sirali cift yonlu bagli listeyi ekrana basan fonksiyonu cagiriyorum.
	
	if((fp1 = fopen("sayilarters.txt","w")) == NULL) // sayilarters.txt olusturma islemi.
	{
		printf("Dosya acilamadi");
		return 1; // dosya acilamaz ise hatali cikis..
	}
	
	
	printf("Sayilar buyukten kucuge sayilarters.txt dosyasina kaydedildi.\n");
	
	
	
	ReverseList(fp1); // listeyi buyukten kucuge dosyaya yazmak icin fonksyionu cagiriyorum ve fp1 dosyasýný gönderiyorum .
	
	
	
	//islem bittigi icin gerekli temizlikleri yapýyorum.
	FreeList(head);
	free(info);

	fclose(fp1);
	fclose(fp);

	
	
	return 0;
}




