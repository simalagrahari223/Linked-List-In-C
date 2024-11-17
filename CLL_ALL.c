
// MADE BY ~SAG
// Circular LINKED-LIST
// OPERATIONS DONE~INSERTION, 

#include <stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;  
};

typedef struct node NODE; 

NODE *temp, *head, *prev; 
NODE *start = NULL;    

// insert at beg
void insertAtBeg()
{
	head = (NODE*)malloc(sizeof(NODE));
	printf("Enter Data in a Node in Beg: ");
	scanf("%d",&head->data);
	if(start == NULL)
	{
		start = head;
		head->next = start;
	}
	else
	{
		temp = start;
		while(temp->next != start)
		{
			temp = temp->next;	
		}	
		temp->next = head;
		head->next = start;
		start = head;
	}	
}

// insert at last
void insertAtLast()
{
	head = (NODE*)malloc(sizeof(NODE));
	printf("Enter Data in a Node in last: ");
	scanf("%d",&head->data);
	if(start == NULL)
	{
		start = head;
		head->next = start;
	}
	else if(start->next == start)
	{
		start->next = head;
		head->next = start;
	}
	else
	{
		temp = start;
		while(temp->next != start)
		{	
			temp = temp->next;	
		}
		temp->next = head;
		head->next = start;	
	}		
}

//insert at given position
void insertAtPos()
{
	int pos;
	printf("Enter postion: ");
	scanf("%d",&pos);
	
	head = (NODE*) malloc(sizeof(NODE)); 
	printf("Enter Data in node to insert at pos: ");
	scanf("%d",&head->data);

	int count = 1;
	
	if(pos == 1)
	{
		temp = start;
		while(temp->next != start)
		{
			temp = temp->next;	
		}	
		temp->next = head;
		head->next = start;
		start = head;	
	}
	else
	{
		temp = start;
		while(temp->next != start && count < pos)
		{
			prev = temp;
			temp = temp->next;
			count++;
		}	
		if (count == pos)
		{
			prev->next = head;
			head->next = temp;
		}
		else
		{
			printf("Invaild Position\n");
		}
	}
}

// Deletion at beg
void deleteAtBeg()
{
	if(start == NULL)
	{
		printf("Deletion not posible since list is empty!\n");
	}
	else
	{
		temp = start;
		prev = temp;
		while(temp->next != start)
		{
			temp = temp->next;
		}
		temp->next = start->next;
		start = start->next;
		printf("Deleted Element is: %d\n",prev->data);
		free(prev);
	}
}

//Deletion at last
void deleteAtLast()
{
	if(start == NULL)
	{
		printf("Deletion not posible since list is empty!\n");
	}
	else
	{
		temp = start;
		prev = temp;
		while(temp->next != start)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		printf("Deleted Element is: %d\n",temp->data);
		free(temp);	
	}
}

//Delete at Position
void deleteAtPos()
{
	int pos;
	printf("Enter position of node you want to delete: ");
	scanf("%d",&pos);
	
	if(start == NULL)	
	{
		printf("Deletion Not possible. Since List is EMPTY. \n");
	}
	else if(pos == 1)
	{
		if (start->next == start) // only 1 node is present for pos = 1
		{
			temp = start;
			printf("Deleted Elements is : %d\n",temp->data);
			start = start->next;
			free(temp);
		}
		else // more than 1 nodes are present for pos =1 
		{
			temp = start;
			prev = temp; // to store 1st position node
			while(temp->next != start)
			{
				temp = temp->next;
			}
			temp->next = start->next;
			start = start->next;
			printf("Deleted Elements is : %d\n",prev->data); // pos =1 store in prev
			free(prev);	
		}
	}
	else
	{
		int count = 1;
		temp = start;
		while(temp != start && count != pos)
		{
			prev = temp;
			temp = temp->next;
			count++;
		}
		if(temp != start)
		{
			prev->next = temp->next;
			printf("Deleted Elements is : %d\n",temp->data);
			free(temp);
		}
		else
		{
			printf("Invaild position\n");
		}
		
	}
}

// display a CLL
void traverse()
{
	temp = start;
	while(temp->next != start)
	{
		printf("%d-->",temp->data);
		temp = temp->next;
	}
	printf("%d\n",temp->data);
}

void main()
{
	printf("Starting CLL...\n\n");
	insertAtBeg();
	insertAtBeg();
	//insertAtBeg();
	//insertAtLast();
	traverse();
	//insertAtPos();
	//deleteAtBeg();
	//deleteAtLast();
	deleteAtPos();
	traverse();
	
}
