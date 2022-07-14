#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *root = NULL;
int len;

void append ()
{
	printf("%s: Begin\n",__func__);
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	scanf("%d",&temp->data);
	temp->next = NULL;

	if (root == NULL)
	{
		root = temp;
		printf("root is no more NULL\n");
	}
	else
	{
		struct node *p;
		p = root; 
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = temp; 
	}
	printf("%s: End\n",__func__);
}

void delete(int n)
{
	printf("%s: Begin\n",__func__);
	struct node *temp;
	struct node *temp2;
	temp = root;
	if (n == 1)
	{
		root = temp->next;
		free(temp);
		return;
	}
	int i=0;
	while(i<n-2)
	{
		temp = temp->next;
		i++;
	}
	temp2 = temp->next;
	temp->next = temp2->next;
	free(temp2);
	printf("%s: End\n",__func__);
}

void appendatBegin()
{
	printf("%s: Begin\n",__func__);
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the number\n");
	scanf("%d", &temp->data);
	temp->next=NULL;
	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		struct node *temp2;
		temp2 = root;
		root = temp;
		root->next = temp2;
	}
	printf("%s: End\n",__func__);
}

void reverse()
{
	printf("%s: Begin\n",__func__);

	struct node *current = root;
	struct node *pre = NULL;
	struct node *next;
	
	while(current != NULL)
	{
		next = current->next;
		current->next = pre;
	       	pre = current;
		current = next;
	}
	root = pre;
	printf("%s: End\n",__func__);
}

int length()
{
	printf("%s: Begin\n",__func__);
	int count=0;
	struct node *temp;
	temp = root;
	while(temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	printf("length = %d \n", count);
	printf("%s: End\n",__func__);
	return count;
}

void display()
{
	printf("%s: Begin\n",__func__);
        struct node *temp;
        temp = root;
	if (temp == NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		while(temp != NULL)
        	{
                	printf("--->%d\n",temp->data);
                	temp = temp->next;
        	}
	}
	printf("%s: End\n",__func__);
}



int main()
{

	int ch;
	printf ("Single Linked List Operation :\n");
	printf ("1. Append \n");
	printf ("2. Append at begin\n");
	printf ("3. Reverse a Linked List \n");
	printf ("4. Length\n");
	printf ("5. Display\n");
	printf ("6. Delete\n");
	printf ("7. Quit\n");

	while(1)
	{
		printf("Enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 	
				append();
				break;
			case 2: 
				appendatBegin();
				break;
			case 3: 
				reverse();
				break;
			case 4: 
				len = length();
				break;
			case 5: 
				display();
				break;
			case 6: 
				printf("Enter deleting node\n");
				int n;
				scanf("%d", &n);
				delete(n);
				break;
			case 7:
				exit(1);
			default:
				printf("Invalid Input\n");
				exit(1);			
		}
	}
	return 0;
}
