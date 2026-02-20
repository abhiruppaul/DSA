//Delete the desired node.
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
void del_desire(int n){
	struct node *tmp;
	if(start->info==n)
	{
		tmp=start;
		start=start->next;
		free(tmp);
	}
	else{
		struct node *i=start->next;
		struct node *j=start;
		while(i->next!=NULL)
		{
			if(i->info==n)
			{
				tmp=i;
				j->next=i->next;
				free(tmp);
				break;
			}
			j=i;
			i=i->next;
		}
		if(i->info==n)
		{
			j->next=NULL;
			free(i);
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
	printf("\n After deleting the desired node: ");
	del_desire(100);
	output();
}
