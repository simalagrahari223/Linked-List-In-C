
// MADE BY ~SAG
// Doubly Linked-List
// OPERATIONS DONE~Insertion, DELETION, TRAVERSE, REVERSE.

#include <stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
	struct node *prev;  
};

typedef struct node NODE; 

NODE *temp, *head; 
NODE *start = NULL;    

//Insertion at Beg
void insertAtBeg()
{
	head = (NODE*)malloc(sizeof(NODE));
	printf("Enter Data in a NOde in Beg: ");
	scanf("%d",&head->data);
	if(start == NULL)
	{
		start = head;
		head->prev = NULL;
		head->next = NULL;
	}	
	else
	{
		
		start->prev = head;
		head->next = start;
		head->prev = NULL;
		start = head;
	}
}

//insertion at last
void insertAtLast()
{
	head = (NODE*) malloc(sizeof(NODE)); 
	printf("Enter data in node to insert at last: ");
	scanf("%d",&head->data);
	if(start == NULL)
	{
		start = head;
		head->prev = NULL;
		head->next = NULL;
	}
	else if(start->next == NULL) // 1 node present
	{
		start->next = head;
		head->prev = start;
		head->next = NULL;
	}
	else // more than 1 nodes are present
	{
		temp = start;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = head;
		head->prev = temp;
		head->next = NULL;
	}
	
}

//Insertion at POsition
void insertAtPos()
{
	int pos;
	printf("Enter postion: ");
	scanf("%d",&pos);
	
	head = (NODE*) malloc(sizeof(NODE)); 
	printf("Enter Data in node to insert at last: ");
	scanf("%d",&head->data);

	int count = 1;
	
	if(pos == 1)
	{
		start->prev = head;
		head->next = start;
		head->prev = NULL;
		start = head;
	}
	else
	{
		temp = start;
		while(temp != NULL && count != pos)
		{
			temp = temp->next;
			count++;
		}	
		if (temp != NULL)
		{
			temp->prev->next = head;
			head->prev = temp->prev;
			head->next = temp;
			temp->prev = head;
		}
		else
		{
			printf("Invaild Position\n");
		}
	}

}

// To display SLL
void traverse() 
{
	printf("DISPLAYING...\n");
	temp = start;
	printf("NULL-->");
	while(temp != NULL)
	{
		printf("%d-->",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

//Deletion at beg
void deleteAtBeg()
{
	if(start == NULL)
	{
		printf("LIST IS EMPTY DELETION IS NOT POSSIBLE!\n");
	}
	else if(start->next == NULL)
	{
		temp = start;
		printf("Deleted Element is: %d\n",temp->data);
		free(temp);
		start = NULL;
	}
	else
	{
		temp = start;
		printf("Deleted Element is: %d\n",temp->data);
		start = temp->next;
		temp->next->prev = NULL;
		free(temp);
	}
}


// deletion at last
void deleteAtLast()
{
	if(start == NULL)
	{
		printf("LIST IS EMPTY DELETION IS NOT POSSIBLE!\n");
	}
	else if(start->next == NULL)
	{
		temp = start;
		printf("Deleted Element is: %d\n",temp->data);
		free(temp);
		start = NULL;	
	}
	else
	{
		temp = start;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->prev->next = NULL;
		temp->prev = NULL;
		printf("Deleted Element is: %d\n",temp->data);
		free(temp);
	}
	
}

//delete at Position
void deleteAtPos()
{
	int pos;
	printf("Enter position of node you want to delete: ");
	scanf("%d",&pos);
	
	if(start == NULL)	
	{
		printf("Deletion Not possible DLL is empty.\n");
	}
	else if(pos == 1)
	{
		temp = start;
		temp->next->prev = NULL;
		start = start->next;
		printf("Deleted Element is: %d\n",temp->data);
		temp->next = NULL;
		free(temp);
		
	}	
	else
	{
		int count = 1;
		temp = start;
		while(temp != NULL && count != pos)
		{
			temp = temp->next;
			count++;
		}
		if(temp != NULL) //yani ki count != pos se break hua h position exist
		{	
			if(temp->next != NULL)
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
			else
			{
				temp->prev->next = NULL;	
			}
			
			printf("Deleted Element is: %d\n",temp->data);
			free(temp);
		}
		
		else
			{
				printf("Invaild Position\n");
			}
			
	}
}

// Reverse a DLL
void reverseDll()
{
	if(start == NULL)	
	{
		printf("DLL is empty.\n");
	}
	else if(start->next == NULL) // 1 node present
	{
		printf("Only 1 node present i.e. : %d\n",start->data);
	}	
	else
	{
		temp = start;
		while(temp->next != NULL)
		{
			temp = temp->next;	
		}	
		printf("IN REVERSE ORDER:\n");
		printf("NULL");
		while(temp != NULL)
		{
			printf("<--%d-",temp->data);
			temp = temp->prev;
		}
		printf("NULL\n");
	}		
}


// In MAin
void main()
{
	printf(">>STARTING DLL...\n\n");
	insertAtBeg();
	insertAtBeg();
	//insertAtBeg();
	//insertAtLast();
	traverse();
	//insertAtPos();
	//deleteAtBeg();
	//deleteAtLast();
	//deleteAtPos();
	reverseDll();
	//traverse();

}























