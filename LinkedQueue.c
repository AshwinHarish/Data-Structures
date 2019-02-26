#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int key;
}element;

struct queue
{
	element data;
	struct queue* link;
};
typedef struct queue* queueptr;
queueptr front[10],rear[10];
void insert(element item,int i)
{
	queueptr temp;
	temp=(queueptr)malloc(sizeof(struct queue));
	temp->data=item;
	if(front[i])
	{
		rear[i]->link=temp;
	}
	else
		front[i]=temp;
	rear[i]=temp;
	rear[i]->link=NULL;
}

element delete(int i)
{
	queueptr temp;
	temp=front[i];
	element item;
	if(front[i])
	{
		item=front[i]->data;
		front[i]=front[i]->link;
	}
	else
	{
		item.key=-1;
	}
	free(temp);
	return item;
}

void display(int i)
{
	queueptr temp;
	temp=front[i];
	for(;temp;temp=temp->link)
		printf("%d\t",temp->data.key);
	printf("\n");
}

int main(void)
{
    int choice, i;
	element item;
	while(1)
	{
		printf("Enter\n 1. Insert\n 2. Delete\n 3.Display\n");
		scanf("%d",&choice);
		printf("Enter queue to perform operation : ");
		scanf("%d",&i);
		switch(choice)
		{
		case 1:
			printf("Enter data to be inserted: ");
			scanf("%d",&item.key);
			insert(item,i);
			break;
		case 2:
			item=delete(i);
			if(item.key==-1)
				printf("Queue empty");
			else
				printf("Element deleted: %d",item.key);
			break;
		case 3:
			display(i);
			break;
        case 4:
            printf("\nInvalid Choice\n");
            break;
		}
	}
}
