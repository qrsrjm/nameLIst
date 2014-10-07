#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define false   0
#define true    1

typedef char elemType;
typedef struct Clinklist
{
	int select;
	elemType data[20];
	struct Clinklist *next;
}Clinklist;

Clinklist *head = NULL;

void create_list()
{
	head = (Clinklist*)malloc(sizeof(Clinklist));
	if(head != NULL)
	{
		head->next = head;
		head->select = 0;
	}
}

int insert_list(elemType *data)
{
	Clinklist *new = (Clinklist*)malloc(sizeof(Clinklist));
	if(new == NULL) return false;
	strcpy(new->data, data);
	new->next = new;

	Clinklist *p = head;
	while(p->next != head)
	{
		p = p->next;
	}

	new->next = p->next;
	p->next = new;
	return true;
}


int delete_list(elemType *data)
{
	Clinklist *p = head;
	while(0 != strcmp(p->data , data) && p->next != NULL)
	{
		p = p->next;
	}

	if(p->next == NULL && 0 != strcmp(p->data , data)) return -1;

	Clinklist *q = head;
	while(q->next != p)
	{
		q = q->next;
	}

	q->next = p->next;
	free(p);
	return 0;
}

int check_list(elemType *data)
{
	Clinklist *p = head;
	while(0 != strcmp(p->data , data) && p->next != NULL)
	{
		p = p->next;
	}

	if(p->next == NULL && 0 != strcmp(p->data , data)) return -1;

    p->select = 1;

	return 0;
}

void show_list()
{
	head = head->next;
	Clinklist *p = head;
	while(p->next != head)
	{
		printf("%s\t", p->data);
		p = p->next;
	}
//	printf("%d\t", p->data);
	printf("\n");

	p=p->next;
	while(p->next != head)
	{
		printf("%s\t", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
    create_list();

    char a[6] = "aaa";
    int i;
    for(i=0;i<10;i++) {
        a[3] = i+48; a[4] = '\0';
        printf("%s\n",a);
        insert_list(a);
    }

    show_list();

    char b[6]={"aaa9"};
    scanf("%s",b);
    delete_list(b);

    show_list();

    return 0;
}
