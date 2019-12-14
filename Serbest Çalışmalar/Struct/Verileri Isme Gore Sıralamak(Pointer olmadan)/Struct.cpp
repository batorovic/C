#include <stdio.h>
#include <string.h>

struct Students
{
	int id;
	char name[30];
	int age;
	
}stds[5];

int main()
{

	
	
/*Id = 1, Name = bd, Age = 12 
Id = 2, Name = ba, Age = 10 
Id = 3, Name = bc, Age = 8 
Id = 4, Name = aaz, Age = 9 
Id = 5, Name = az, Age = 10 

Student Records sorted by Name:
Id = 4, Name = aaz, Age = 9 
Id = 5, Name = az, Age = 10 
Id = 2, Name = ba, Age = 10 
Id = 3, Name = bc, Age = 8 
Id = 1, Name = bd, Age = 12*/
	char temp[30];
	for(int i = 0;i<5;i++)
	{
		printf("id: ");
		scanf("%d",&stds[i].id);
		printf("Name: ");
		scanf("%s",&stds[i].name);
		printf("Age: ");
		scanf("%d",&stds[i].age);
	}
	
	
	int tid=0,tage=0;
	for(int i = 0;i<5;i++)
	{
		for(int j = 0;j<4;j++)
		{
			if(strcmp(stds[j].name,stds[j+1].name) > 0)
			{
				
				strcpy(temp,stds[j].name);
				strcpy(stds[j].name,stds[j+1].name);
				strcpy(stds[j+1].name,temp);
				
				tid = stds[j].id;
				stds[j].id = stds[j+1].id;
				stds[j+1].id = tid;
				
				tage = stds[j].age;
				stds[j].age = stds[j+1].age;
				stds[j+1].age = tage;
			}	
		}
	}


	printf("\n");
	for(int i = 0;i<5;i++)
	{
		printf("ID = %d Name =  %s Age = %d\n",stds[i].id,stds[i].name,stds[i].age);
	
	}
	
	

	

	/*
	char temp[30];
	char str1[30],str2[30];
	printf(": ");
	gets(str1);
	printf(": ");
	gets(str2);
	
	
	strcpy(temp,str1);
	strcpy(str1,str2);
	strcpy(str2,temp);

	printf("%s\n%s\n%s",str1,str2,temp);*/
	
	

	
	
	
	return 0;
}
