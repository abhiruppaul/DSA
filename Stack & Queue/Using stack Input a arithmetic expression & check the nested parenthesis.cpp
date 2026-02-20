//Input a arithmetic expression & check the nested parenthesis.
#include<stdio.h>
#include<stdlib.h>
#define size 100
int stk[size];
int top = -1;
void push(char c){
	stk[++top] = c;
}
char pop(){
	return stk[top--];
}
int main(){
	char s[size],x;
	int i;
	printf("Enter an arithmetic expression ");
	gets(s);
	for (i = 0; s[i];i++){
		if(s[i] == '(')
		push(s[i]);
		else if(s[i] == ')')
		x = pop();
	}
	if(top == -1)
    printf("Valid");
    else
    printf("Invalid");
}
