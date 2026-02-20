//Add 2 polynomial
#include<stdio.h>
#include<stdlib.h>
struct node{
	int coef,exp;
	struct node *link;
};
struct node * create(int c,int e)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->coef=c;
	tmp->exp=e;
	tmp->link=NULL;
	return tmp;
}
struct node * create_poly(struct node *p,int c,int e)
{
	struct node *tmp,*i;
	tmp=create(c,e);
	if(p==NULL)
	p=tmp;
	else{
		i=p;
		while(i->link!=NULL)
		{
			i=i->link;
		}
		i->link=tmp;
	}
	return p;
}
void show(struct node *p)
{
	while(p!=NULL)
	{
		printf("%dx^%d =>",p->coef,p->exp);
		p=p->link;
	}
}
struct node * add_poly(struct node *p1,struct node *p2,struct node *p3)
{
	int c,e;
	struct node *tmp,*rear;
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->exp > p2->exp)
		{
			c=p1->coef;
			e=p1->exp;
			p1=p1->link;
		}
		else if(p2->exp > p1->exp)
		{
			c=p2->coef;
			e=p2->exp;
			p2=p2->link;
		}
		else{
			c=p1->coef+p2->coef;
			e=p1->exp;
			p1=p1->link;
			p2=p2->link;
		}
		tmp=create(c,e);
		if(p3==NULL)
		p3=rear=tmp;
		else{
			rear->link=tmp;
			rear=tmp;
		}
	}
	if(p1!=NULL)
	{
		while(p1!=NULL)
		{
			tmp=create(p1->coef,p1->exp);
			rear->link=tmp;
			rear=tmp;
			p1=p1->link;
		}
	}
	else if(p2!=NULL)
	{
		while(p2!=NULL)
		{
			tmp=create(p2->coef,p2->exp);
			rear->link=tmp;
			rear=tmp;
			p2=p2->link;
		}
	}
	return p3;
}
int main()
{
	int c[]={1,5,-7,6};
	int c1[]={2,7,-3,2};
	int e[]={8,4,2,1};
	int e1[]={9,5,4,3};
	struct node *p1=NULL,*p2=NULL,*p3=NULL;
	int i;
	for(i=0;i<4;i++)
	{
		p1=create_poly(p1,c[i],e[i]);
		p2=create_poly(p2,c1[i],e1[i]);
	}
	printf("\n Poly 1 :\n");
	show(p1);
	printf("\n Poly 2 :\n");
	show(p2);
	p3=add_poly(p1,p2,p3);
	printf("\n Poly 3 :\n");
	show(p3);
	
}
