//Create a single linked list and delete at the begining
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *next;
}*start=NULL;
void create(int n)
{
	struct node *tmp,*i;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=n;
	tmp->next=NULL;
	if(start==NULL)
	start=tmp;
	else{
		i=start;
		while(i->next!=NULL)
		{
			i=i->next;
		}
		i->next=tmp;
	}
}
void output()
{
	struct node *i=start;
	while(i!=NULL)
	{
		printf("%4d",i->info);
		i=i->next;
	}
}
//delete the first node of a ll'
void delbeg(){
	if(start==NULL)
	{
		printf("\n List is empty");
		return;
	}
	struct node *t=start;
	start=start->next;
	free(t);
	
}
int main()
{
	int i;
	for(i=10;i<=100;i+=10)
	{
		create(i);
	}
	printf("\n List is :");
	output();
	delbeg();
	printf("\n");
	output();
}
