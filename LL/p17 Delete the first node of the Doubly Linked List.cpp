//Delete the first node of the Doubly Linked List
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
	if(start==NULL){
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
void delbeg(){
	if(start==NULL){
		printf("\n List ie empty");
		return;
	}
	struct node *tmp;
	tmp=start;
	start=start->next;
	start->prev=NULL;
}		
void show(){
	struct node *i=start;
	while(i!=NULL){
		printf("%4d",i->info);
		i=i->next;
	}
}
int main(){
	int i;
	for(i=10;i<=100;i+=10)
	{
		create(i);
	}
	printf("\n List is :\n");
	show();
	delbeg();
	printf("\n List after deleting the first node:");
	show();
	return 0;
}
