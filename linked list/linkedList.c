#include <stdio.h>
#include <stdlib.h>

//CREATING A STRUCT
typedef struct student {
	int no;
	//char name[35];
	//int age;
	struct student *next;
} node;

node *head, *newNode;

// CREATING A LINEER ILST
node *createList() {
	int n,k;
	node *head, *p;

	printf("how many student in the list? ");
	scanf("%d",&n);
	head = NULL;
	for(k=0; k<n; k++)
	{
		if(head == NULL)
		{
			head = (node*)malloc(sizeof(node));
			p = head;
		}
		else
		{
			p->next = (node*)malloc(sizeof(node));
			p = p->next;
		}
		printf("enter %d. student number: ",k+1);
		scanf("%d",&(p->no));
		//printf("enter %d. student age: ",k+1);
		//scanf("%d",&(p->age));
		//printf("enter %d. student name: ",k+1);
		//scanf("%s",p->name);
		printf("\n");
	}
	p->next = NULL;
	return head;
}

// SORT OF THE LINEER LIST
void traverseList(node *head)
{
	int counter = 1;
	node *p;
	p = head;

	while(p != NULL)
	{
		printf("%d.ogrencinin numarasi %d\n\n",counter, p->no);
		//printf("%d--%d %s %d\n",counter, p->no, p->name, p->age);
		p = p->next;
		counter++;
	}
}
        // add node
node *addNode(node *head)
{
	int stdNo;
	node *p, *q;

	newNode = (node*)malloc(sizeof(node));
	printf("enter new student number: ");
	scanf("%d",&newNode->no);

	printf("enter std number that new record will be added before : \n");
	printf("pree 0 to add at the end of list\n ");
	scanf("%d",&stdNo);

	p = head;
	if(stdNo == p->no)      // add to the biginning
	{
		newNode->next = p;
		head = newNode;
	}
	else
	{
		while(p->no != stdNo && p->next != NULL)
		{
			q = p;
			p = p->next;
		}
		if(p->no == stdNo)
		{
			q->next = newNode;
			newNode->next = p;
		}
		else if(p->next == NULL)
		{
			p->next = newNode;
			newNode->next = NULL;
		}
	}
	return head;
}

        //delete node
node *deleteNode(node *head)
{
    int stdNo;
    node *p, *q;

    printf("enter the student number that will be deleted : ");
    scanf("%d",&stdNo);

    p = head;
    if(p->no == stdNo)
    {
        head = p->next;
        free(p);
    }
    else
    {
        while(p->next != NULL && p->no != stdNo)
        {
            q = p;
            p = p->next;
        }
        if(p->no == stdNo)
        {
            q->next = p->next;
            free(p);
        }
        else if(p->next == NULL)
        {
            printf("no node found to delete\n");
        }
    }
    return head;
}
int main()
{
	int selection = 0;
	node *head;

	printf(" 1- create list\n 2- traverse list\n 3- add node\n 4- delete node\n 5- exit\n");
	while(1) {
		printf("selection [ 1 - 5]? ");
		scanf("%d",&selection);
		printf("\n\n");
		switch(selection)
		{
		case 1:
			head = createList();
			printf("Adress : %p\n\n",head);
			printf("the creating of the list is successful\n");
			break;
		case 2:
			traverseList(head);
			break;
		case 3:
			head = addNode(head);
			printf("the addition operation is successful\n");
			break;
		case 4:
            head = deleteNode(head);
           printf("it is deleted\n");
			break;
		case 5:
			exit(0);
		}
	}
}
