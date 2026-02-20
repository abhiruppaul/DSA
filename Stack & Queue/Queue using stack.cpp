#include<stdio.h>
#include<stdlib.h>
#define size 5
int arr[size];
int rear = -1,front=0;
void enque(int n){
	if(rear==size-1)
	{
		printf("\n Queue Overflow");
		return;
	}
	rear++;
	arr[rear]=n;
	
}
int deque(){
	if(rear<front)
	{
		printf("\n Queue Underflow");
		return 0;
	}
	int n=arr[front];
	front++;
	return n;
}
void show()
{
	int i;
	printf("\n queue status : ");
	for(i=front;i<=rear;i++)
	{
		printf("%4d",arr[i]);
	}
}
int main(){
	int n,ch;
	while(1){
		printf("\n1....INSERT\n2....DELETE\n0....EXIT");
		scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1: printf("\n Enter a No:");
	    			scanf("%d",&n);
	    			enque(n);
	    			show();
	    			break;
	    	case 2: n=deque();
	    			printf("\n Deleted item =%d",n);
	    			show();
	    			break;
	    	case 0: exit(0);
	    	
		}
    } 
}
