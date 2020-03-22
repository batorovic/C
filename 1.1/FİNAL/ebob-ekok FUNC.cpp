#include <stdio.h>

int Ebob(int s1,int s2)
{	
	int min=0,ebob=0;
	if(s1 > s2)
	{
		min = s2;
	}
	else
	{
		min = s1;
	}
	for(int i = 2;i<=min;i++)
	{
		if(s1 % i == 0 && s2 % i == 0)
		{
			ebob = i;
		}
	}
	return ebob;
	
}
int ekok(int s1,int s2)
{
	return s1*s2 / Ebob(s1,s2);
}

int main()
{
	
	//ebob ekok bul 
	int s1,s2,min=0,ebob=0;
	printf("s1 : ");
	scanf("%d",&s1);
	printf("s2 : ");
	scanf("%d",&s2);
	
	printf("Ebob : %d\nEkok : %d ",Ebob(s1,s2),ekok(s1,s2));
	
	return 0;
}
