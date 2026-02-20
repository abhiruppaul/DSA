#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define size 100
char stk[size];
int top = -1;
void push(char c){
	stk[++top] = c;
}
char pop(){
	return stk[top--];
}
char peep(){
	return stk[top];
}
int prec(char c){
	int p = 0;
	switch(c){
		case '+':
		case '-': p = 1;
		                 break;  
		case '%': p = 2; break;
		case '*':
		case '/': p = 3; break;
		case '^': p = 4; break;
	}
	return p;
}
int main(){
	char s[size]="A+(B*C-(D/E^F)*G)*H";
	char y[size],ch;
	int i,j=0;
	push('(');
	strcat(s,")");
	for ( i = 0; s[i]; i++){
		if(isalpha(s[i]))
		y[j++] = s[i];
		else{
			if(s[i] == '(')
			push(s[i]);
			else if(s[i] == ')'){
				do{
					ch = pop();
					if(ch == '(')
					break;
					y[j++] = ch;
				}while(1);
			}
			else{
				ch = peep();
				if(prec(ch)>prec(s[i]))
				y[j++] = pop();
				else
				push(s[i]);
			}
		}
	}
	y[j] = '\0';
	puts(y);
}
