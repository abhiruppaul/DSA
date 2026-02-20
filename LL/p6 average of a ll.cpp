#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *next;
}*start=NULL;
void create(int n){
	struct node *tmp,*i;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=n;
	tmp->next=NULL;
	if(start==NULL)
	start=tmp;
	else{
		i=start;
		while(i->next!=NULL){
			i=i->next;
		}
		i->next=tmp;
	}
}
void output(){
	struct node *i=start;
	while(i!=NULL){
		printf("%4d",i->info);
		i=i->next;
	}
}
//Average of a ll
void swap(){
	struct node *i=start;
	int sum=0, count=0;
	while(i!= NULL){
		sum+=i->info;
		count+=1;
		i=i->next;
	}
	float avg = sum/count;
	printf("\n Average=%f",avg);
}
int main(){
	int i;
	for(i=10;i<=100;i+=10){
		create(i);
	}
	printf("\n List is :");
	output();
	swap();
	printf("\n");
}
