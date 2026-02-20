//Input a string & reverse it using stack.
#include<stdio.h>
#include<stdlib.h>
#define size 100
char stk[size];
int top = -1;
void push(char c){
	stk[++top] = c;
}
char pop(){
	return stk[top--];
}
int main(){
	char s[size];
	int i;
	printf("\n Enter a string :");
	gets(s);
    for(i = 0; s[i] != NULL; i++){
    	push(s[i]);
	}
	while(top != -1){
		printf("%c",pop());
	}
}
