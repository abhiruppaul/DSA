//Check the given number is pallindrom or not.
#include<stdio.h>
#include<stdlib.h>
#define size 100
int stk[size];
int top = -1;
void push(int n){
	stk[++top] = n;
}
int pop(){
	return stk[top--];
}
int main(){
	int n;
	printf("Enter a number:");
    scanf("%d",&n);
	if{
		n %= 100;
	    n /= 10;
        n %= 10;
	    printf("The number is pallindrome.");
	}
	else{
		printf("The number is not pallindorme.")
	}
}
