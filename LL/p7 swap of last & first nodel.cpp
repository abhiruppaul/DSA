//Create a single linked list and display it
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
//Swappimg of 1st node & last node of a ll
void swap(){
	struct node *i=start,*j;
    while(i->next!=NULL){
    	j=i;
    	i=i->next;
	}
	i->next=start->next;
	j->next=start;
	start->next=NULL;
	start=i;
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
	printf("\n After Swap : ");
	swap();
	output();
}
