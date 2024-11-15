#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct list
{
	int info;
	struct list *next;
};
typedef struct list node;
node *create();
int sum(node *);
int max(node *);
void display(node *);
int search(node *,int);
void sort(node *);
int count(node *);

main()
{
	node *s;
	int n,r;
	s = create();
	display(s);
	printf("\n");
	r = sum(s);
	printf("Sum = %d\n",r);
	r = count(s);
	printf("Total Nodes = %d\n",r);
	r = max(s);
	printf("Max = %d\n",r);

	sort(s);
	printf("After Sorting:");
	display(s);
    printf("Enter the no to search:");
	scanf("%d\n",&n);
	r = search(s,n);
	if(r==1)
	{
		printf("Found\n");
	}
	else
	{
		printf("Not Found.\n");
	}

}

node *create()
{
	node *s=NULL,*p,*nn;
	int n;
	char ano = 'y';
	while(ano == 'y')
	{
		printf("Enter the number:");
		scanf("%d",&n);
		nn = (node * )malloc(sizeof(node));
		nn -> info = n;
		nn -> next = NULL;
		if(s == NULL)
		{
			s = nn;
		}
		else
		{
			p->next = nn;
		}
		p = nn;
		printf("Continue?[y/n]");
		fflush(stdin);
		scanf("%c",&ano);
	}
	return (s);
}
void sort(node *s)
{
	node *tempi,*tempj;
	int t;
	for(tempi=s;tempi->next!=NULL;tempi=tempi->next)
	{
		for(tempj=tempi->next;tempj!=NULL;tempj=tempj->next)
		{
			if(tempi->info>tempj->info)
			{
				t = tempi->info;
				tempi->info = tempj->info;
				tempj->info = t;
			}
		}
	}
}
int search(node *s,int n)
{
	node *temp = s;
	int flag = 0;
	while(temp!=NULL)
	{
		if(temp->info==n)
		{
			flag = 1;
			break;

		}

		temp = temp->next;
	}
	return (flag);
}
int max(node *s) {
    int maximum;
    node *t = s;

    maximum = t->info;
    while (t != NULL) {
        if (t->info > maximum) {
            maximum = t->info;
        }
        t = t->next;
    }
    return maximum;
}
int sum(node *s)
{
	int summ =  0;
	node *temp;
	temp = s;
	while(temp!=NULL)
	{
		summ = summ + temp->info;
		temp = temp->next;
	}
	return(summ);
}
int count(node *s)
{
	int c = 0;
	node *temp;
	temp = s;
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	return(c);
}
void display(node *s)
{
	node *temp;
	temp = s;
	while(temp!=NULL)
	{
		printf("%d\n",temp->info);
		temp = temp->next;
	}
}

