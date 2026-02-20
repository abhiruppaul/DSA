#include<stdio.h>
#include<stdlib.h>
#define size 5
int arr[size];
int rear = -1, front = -1;
void enque(int n){
	if(rear == size-1 && front == 0 || rear +1 == front){
		printf("Queue Overflow");
		return;
	}
	if (rear == -1)
	rear = front = 0;
	else if(rear == size-1)
	rear = 0;
	else
	rear +=1;
	arr[rear] = n;
}

int deque(){
	if(front == -1){
		printf("Queue is empty");
		return 0;
	}
	
	int n = arr[front];
	if(rear == front)
	rear = front - 1;
	else if(front == size - 1)
	front = 0;
	else
	front++;
	return n;
}
	void show(){
		int i;
		printf("\n Queue Status");
		if(rear!=-1)
		{
			for(i=front;i<=rear;i++)
			printf("%4d",arr[i]);
		}
		else{
			for(i=rear;i<size;i++)
			printf("%4d",arr[i]);
			for(i=0;i<=front;i++)
			printf("%4d",arr[i]);
		}
	}
int main()
{
	int n,ch;
	while(1){
		printf("\n1....INSERT\n2....DELETE\n0....EXIT");
		scanf("%d",&ch);
		switch(ch){
			case 1:  printf("\n Enter a No:");
			scanf("%d",&n);
			show();
			break;
			case 2: n=deque();
				printf("\nDeleted item = %d",n);
				show();
				break;
			case 0: exit(0);
		}
	}
}


