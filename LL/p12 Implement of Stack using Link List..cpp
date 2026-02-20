//Implement of Stack using Link List.
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *next;
}*top=NULL;
void push(int n){
	struct node *tmp,*i;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=n;
	tmp->next=NULL;
	if(top==NULL)
	top=tmp;
	else{
		tmp->next=top;
		top=tmp;
	}
}
int pop(){
	if(top==NULL){
		printf("\n Stack is empty");
		return 0;
	}
	struct node *tmp=top;
	top =top->next;
	int n = tmp->info;
	free(tmp);
	return n;
	}
void show(){
	struct node *i=top;
	while(i!= NULL){
		printf("%4d",i->info);
		i=i->next;
	}
}
int main(){
	
}
