//Insert a node to the dsired place.
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
void adddesire(int n,int p){
	struct node *tmp,*i;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=n;
	tmp->next=NULL;
	if(p==1){
		tmp->next = start;
		start = tmp;
	}
	else{
		i=start;
		for(int k=1;k<p-1 && i->next!=NULL;k++){
			i=i->next;
		}
		if(i->next==NULL)
		i->next=tmp;
		else{
			tmp->next=i->next;
			i->next=tmp;
		}
	}
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
	printf("\n After Adding a nose to the desired place: ");
	adddesire(25,5);
	output();
}
