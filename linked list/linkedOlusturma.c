#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    int no;
    char name[50];
    int age;
    struct student *next;
} node;
node *head, *newNode;
int n;

node *createList() {
	int k;
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
		printf("enter %d. student name: ",k+1);
		scanf("%s",&(p->name));
		printf("enter %d. student age: ",k+1);
		scanf("%d",&(p->age));
		printf("\n");
	}
	p->next = NULL;
	return head;
}

int main()
{

    head = createList();
    node *p = head;
    for(int i=0; i<n; i++){
        printf("%d %s %d\n",p->no,p->name,p->age);
        p = p->next;
    }

    exit(0);
}

