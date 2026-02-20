//Reverse a ll
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
void reverse(){
	struct node *ptr,*next,*prev=NULL;
	ptr=start;
	while(ptr!=NULL){
		next=ptr->next;
		ptr->next=prev;
		prev=ptr;
		ptr=next;
	}
	start=prev;		
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
	printf("\n After reversing : ");
	reverse();
	output();
}
