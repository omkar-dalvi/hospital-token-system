#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
	int patno;
	char name[20];
	struct node *prev, *next;
};

typedef struct node NODE;
NODE *start = NULL;
int count = 0;

void insert()
{
	NODE *ptr, *t;
	count++;
	ptr = malloc(sizeof(NODE));
	printf("Enter name of the patient(use underscore instead of space):");
	scanf("%s", ptr->name);
	ptr->prev = NULL;
	ptr->next = NULL;
	ptr->patno = count;
	if (start == NULL)
	{
		start = ptr;
		start->prev = NULL;
		start->next = NULL;
	}

	else
	{
		t = start;
		while (t->next != NULL)
			t = t->next;
		ptr->prev = t;
		t->next = ptr;
	}
	printf("Your patient number is:%d\n", count);
}

void delete2()
{
	int no, flag = 0;
	NODE *ptr = start, *t;
	if (ptr == NULL)
	{
		printf("No records");
		return;
	}
	printf("Enter patient number you want to delete:");
	scanf("%d", &no);
	
	while (ptr->patno != no && ptr != NULL)
		ptr = ptr->next;

	if (ptr != NULL)
	{
		if (ptr == start)
		{
			flag = 1;
			printf("Deleted entry:");
			printf("\nPatient no:%d", ptr->patno);
			printf("\nPatient Name:");
			puts(ptr->name);
			start->prev = NULL;
			start->next = NULL;
			start = NULL;
			free(ptr);
		}
		else if (ptr->next == NULL)
		{
			flag = 1;
			ptr->prev->next = NULL;
			printf("Deleted entry:");
			printf("\nPatient no:%d", ptr->patno);
			printf("\nPatient Name:");
			printf(ptr->name);
			free(ptr);
		}
		else
		{
			flag = 1;
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
			printf("Deleted entry:");
			printf("\nPatient no:%d", ptr->patno);
			printf("\nPatient Name:");
			printf(ptr->name);
			free(ptr);
		}

		return;
	}
	else
	{
		printf("Entry not found");
		return;
	}
}
void show()
{
	NODE *ptr = start;
	printf("The appointments pending are:\n");
	if (ptr == NULL)
		printf("No appointments pending.");
	while (ptr != NULL)
	{
		printf("Patient number:%d", ptr->patno);
		printf("\nPatient Name:%s\n\n", ptr->name);
		ptr = ptr->next;
	}
}

int main()
{
	int c, ch;
	printf("\n\t\t\tHEALTHCARE HOSPITAL\n");
	//clrscr();
	do
	{
		printf("\n 1:Patient Record");
		printf("\n 2:Staff Record");
		printf("\n 3:Exit");
		printf("\n Enter choice:");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			do
			{
				printf("\n\nMenu:\n");
				printf("1:New Entry\t2:exit\n");
				printf("Enter your choice:");
				scanf("%d", &c);
				switch (c)
				{
				case 1:
					insert();
					break;
				case 2:
					break;
				}
			} while (c != 2);
			// getch();
			break;

		case 2:
			do
			{
				printf("\n\nMenu:\n");
				printf("1:Delete Existing\t2:Display pending appointments\t3:exit");
				printf("\nEnter your choice:");
				scanf("%d", &c);
				switch (c)
				{
				case 1:
					delete2();
					break;
				case 2:
					show();
					break;
				case 3:
					break;
				}
			} while (c != 3);
			// getch();
			break;

		case 3:
			break;
		}
	} while (ch != 3);
	// getch();
	return 0;
}
