

// MADE BY ~SAG
// SINGLY LINKED-LIST 
// OPERATIONS DONE~INSERTION, DELETION, TRAVERSE, REVERSE.

#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;  
};

typedef struct node NODE; 

NODE *temp, *head; 
NODE *start = NULL;    

// Insertion at beg
void insertAtBeg()  
{
	head = (NODE*) malloc(sizeof(NODE)); 
	printf("Enter data in node to insert at beg: ");
	scanf("%d",&head->data);
	if(start == NULL) 
	{
		start = head;
		head->next = NULL;
	}
	else
	{
		head->next = start;
		start = head;
	}
}

// Insertion at last
void insertAtLast()
{
	head = (NODE*) malloc(sizeof(NODE)); 
	printf("Enter data in node to insert at last: ");
	scanf("%d",&head->data);
	if(start == NULL) //nodes not present
	{
		start = head;
		head->next = NULL;
	}
	else if(start->next == NULL) //1 node present only
	{
		start->next = head;
		head->next = NULL;
	}
	else
	{
		temp = start;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = head;
		head->next = NULL;
	}
}

// Insertion at given POSITION
void insertAtPos()
{
	int pos;
	printf("ENTER POSITION: ");
	scanf("%d",&pos);
	
	head = (NODE*) malloc(sizeof(NODE)); 
	printf("Enter data in node to insert at given position: ");
	scanf("%d",&head->data);
	
	int count = 1;
	NODE* prev;
	if(pos == 1) // in a 1st node
	{
		head->next = start;
		start = head;
	}
	else 
	{
		temp = start;
		while(temp != NULL && count != pos)
		{
			prev = temp;
			temp = temp->next;
			count++;
		}
		if(temp != NULL)
		{
			prev->next = head;
			head->next = temp;
		}
		else
		{
			printf("Invaild POsition.\n");
		}
	}	
}

// To display SLL
void traverse() 
{
	printf("DISPLAYING...\n");
	temp = start;
	while(temp->next != NULL)
	{
		printf("%d-->",temp->data);
		temp = temp->next;
	}
	printf("%d-->NULL\n",temp->data); 
}

// Deletion at beg
void deleteAtBeg()
{
	if(start == NULL)
	{
		printf("Deletion Not possible.\n");
	}
	else if(start->next == NULL)
	{
		temp = start;
		start = NULL;
		printf("Deleted Elements is : %d\n",temp->data);
		free(temp);
	}
	else
	{
		temp = start;
		start = temp->next;
		printf("Deleted Elements is : %d\n",temp->data);
		free(temp);
	}
}

// Deletion at Last
void deleteAtLast()
{
	if(start == NULL)
	{
		printf("Deletion Not possible.\n");
	}
	else if(start->next == NULL)
	{
		temp = start;
		start = NULL;
		printf("Deleted Elements is : %d\n",temp->data);
		free(temp);	
	}
	else
	{
		NODE* prev;
		temp = start;
		while(temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		printf("Deleted Elements is : %d\n",temp->data);
		free(temp);	
	}
}

// Deletion at Position
void deleteAtPos()
{
	int pos;
	printf("Enter position of node you want to delete: ");
	scanf("%d",&pos);
	
	if(start == NULL)	
	{
		printf("Deletion Not possible.\n");
	}
	else if(pos == 1)
	{
		temp = start;
		start = start->next;
		printf("Deleted Elements is : %d\n",temp->data);
		free(temp);	
	}
	else
	{
		int count = 1;
		NODE* prev;
		temp = start;
		while(temp != NULL && count != pos)
		{
			prev = temp;
			temp = temp->next;
			count++;
		}
		if(temp != NULL)
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

// Reverse SLL
void reverseSll()
{
    NODE *t1, *t2, *t3;
    t1 = start;       // Initialize t1 to the head of the list
    t2 = t1->next;    // Initialize t2 to the second node
    t1->next = NULL;  // The first node becomes the last node, so its next should be NULL

    while (t2 != NULL)
    {
        t3 = t2->next; // t3 holds the next node in the original list
        t2->next = t1; // Reverse the link
        t1 = t2;       // Move t1 forward
        t2 = t3;       // Move t2 forward
    }

    start = t1; // Update the start pointer to the new head of the list
}



// In Main()
void main()
{
	printf(">>STARTING SLL...\n\n");
	insertAtBeg();	
	traverse();
	printf("\n");
	insertAtBeg();	
	traverse();
	printf("\n");
	insertAtLast();
	traverse();
	printf("\n");
//	insertAtPos();
//	traverse();
//	printf("\n");
//	deleteAtBeg();
//	traverse();
//	printf("\n");
//	deleteAtLast();
//	traverse();
//	printf("\n");
//	deleteAtPos();
//	traverse();
//	printf("\n");
	reverseSll();
	traverse();
}



