#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int key;
}element;
struct stack
{
	element data;
	struct stack* link;
};
typedef struct stack* stackptr;
stackptr top[10];
void push(element item, int i)
{
	stackptr temp;
	temp=(stackptr)malloc(sizeof(struct stack));
	temp->data=item;
	temp->link=top[i];
	top[i]=temp;
}
element pop(int i)
{
	stackptr temp;
	temp=top[i];
	element item;
	if(!top[i])
	{
		item.key=-1;
		return item;
	}
	item=top[i]->data;
	top[i]=top[i]->link;
	free(temp);
	return item;
}
void display(int i)
{
	stackptr temp;
	for(temp=top[i];temp;temp=temp->link)
		printf("%d\t",temp->data.key);
	printf("\n");
}
int main(void) {
	int choice, i;
	element item;
	while(1)
	{
		printf("\nEnter\n 1. Push\n 2. Pop\n 3.Display\n");
		scanf("%d",&choice);
        printf("Enter stack to perform operation: ");
		scanf("%d",&i);
		switch(choice)
		{
            case 1:
			printf("Enter data to be inserted: ");
			scanf("%d",&item.key);
			push(item,i);
			break;
            case 2:
			item=pop(i);
			if(item.key==-1)
				printf("Stack empty");
			else
				printf("Element deleted: %d",item.key);
			break;
            case 3:
			display(i);
		}
	}
}
