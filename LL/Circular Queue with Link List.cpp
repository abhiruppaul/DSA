//Circular Queue with Link List
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *next;
}*start=NULL;
void create(int n){
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=n;
	if(start==NULL){
		start=tmp;
		tmp->next=start;
	}
	else{
		tmp->next=start->next;
		start->next=tmp;
		start=tmp;
	}
}
void show(){
	struct node *i=start->next;
	while(i!=start){
		printf("%4d",i->info);
		i=i->next;
	}
	printf("%4d",i->info);
}
int main(){
	int i;
	for(i=10;i<=100;i+=10){
		create(i);
	}
	printf("\n List is :");
	show();
}
