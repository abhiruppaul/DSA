//Doubly Linked List
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *next;
	struct node *prev;
}*start=NULL;       
void create(int n){
	struct node *tmp,*i;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=n;
	tmp->next=NULL;
	if(start==NULL)
	{
		start=tmp;
		tmp->prev=NULL;
	}
	else{
		i=start;
		while(i->next!=NULL)
		{
			i=i->next;
		}
		i->next=tmp;
		tmp->prev=i;
	}
}		
void show(){
	struct node *i=start;
	printf("\n IN FORWARD DIRECTION : ");
	while(i->next!=NULL)
	{
		printf("%4d",i->info);
		i=i->next;
	}
	printf("%4d",i->info);
	printf("\n IN BACKWARD DIRECTION : ");
	while(i!=NULL)
	{
		printf("%4d",i->info);
		i=i->prev;
	}
}
int main(){
	int i;
	for(i=10;i<=100;i+=10)
	{
		create(i);
	}
	printf("\n List is :");
	show();
}
