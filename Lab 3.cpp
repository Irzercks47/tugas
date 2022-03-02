#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct printer{
	char name[35];
	char brand[6];
	char type[20];
	char damage[100];	
	struct printer *next;
}*front,*rear;

int push(char*name,char*brand,char*type,char*damage)
{
	if(rear == NULL){
		rear = (struct printer *)malloc(sizeof(struct printer));
		rear->next = NULL;
		strcpy(rear->name,name);
		strcpy(rear->brand,brand);
		strcpy(rear->type,type);
		strcpy(rear->damage,damage);
		front = rear;
	}
	else{
		struct printer *temp = NULL;
		temp = (struct printer *)malloc(sizeof(struct printer));
		rear->next = temp;
		strcpy(temp->name,name);
		strcpy(temp->brand,brand);
		strcpy(temp->type,type);
		strcpy(temp->damage,damage);
		rear = temp; 
		rear->next = NULL;
	}
}

void add()
{
	char name[100];
	char brand[100];
	char type[100];
	char damage[100];
	int i;
	do{
		printf("Input Customer Name: ");
		gets(name);
		fflush(stdin);
		i=strlen(name);
	}while(i<1 || i>35);
	do{
		printf("Input Printer Brand [canon/epson/hp]: ");
		gets(brand);
		fflush(stdin);
	}while (strcmp(brand,"canon") != 0 && strcmp(brand,"epson") != 0 && strcmp(brand,"hp") != 0);
	do{
		printf("Input Printer Type [4...20]: ");
		gets(type);
		fflush(stdin);
		i=strlen(type);
	}while(i<4 || i>20);
	do{
		printf("Input Damaged [5..100]: ");
		gets(damage);
		fflush(stdin);
		i=strlen(damage);	
	}while(i<5 || i>100);
	printf("\n\nData yang dimasukkan\n");
	printf("%s %s %s %s",name,brand,type,damage);
	push(name,brand,type,damage);
	getch();
}

void take()
{
	
	char name[50];
	char type[50];
	struct printer* temp = NULL;
	
	temp = (struct printer*)malloc(sizeof(struct printer));

	if(front == NULL){
		printf("\n\n --Thereis no printer to repair--");
		getch();
	}
	else{
		
		temp = front;
		strcpy(name,temp->name);
		strcpy(type,temp->type);
		front = front->next;
		temp->next = NULL;
		free(temp);
		
		printf("\n\n item %s < %s > is being deleted",name,type);
		getch();
	}
}


void list()
{
	int index=1;
	struct printer* temp = NULL;
	temp=(struct printer*)malloc(sizeof(struct printer));
	temp=front;
	printf("\t\t\t---Printer Services---\n\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("No|Customer Name		|Printer's Brand  |Type			|Damaged				|\n");	
	printf("-----------------------------------------------------------------------------------------------------------------");	
	while(temp!=NULL)
	{
		printf ("\n%-2d|",index);
		printf ("%-29s|",temp->name);
		printf ("%-17s|",temp->brand);
		printf ("%-21s|",temp->type);
		printf ("%-39s|",temp->damage);
		temp=temp->next;
		index++;
	}
	printf("\n");
	printf("-----------------------------------------------------------------------------------------------------------------");
	getch();
}

int main()
{
	int choice;
	do{
		printf("PRINTER SERVICES\n");
		printf("+++++++++++++++++++++++++++++++\n\n");
		printf("1. Service List\n");
		printf("2. Add Service\n");
		printf("3. Take Service\n");
		printf("4. Exit\n\n");
		printf(">> Input your choice: ");
		scanf("%d",&choice);
		fflush(stdin);
		system("cls");
		switch(choice)
		{
			case 1:
			list();
			system("cls");
			break;
			case 2:
			add();
			system("cls");
			break;
			case 3:
			take();
			system("cls");
			break;
			case 4:
			exit(0);
		}
	}while(choice<0 && choice>5 || choice<5);
	
}
