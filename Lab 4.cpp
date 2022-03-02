#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>

struct data{
	char name[20];
	char type[7];
	char address[20];
	char phone[12];
	struct data* next;
};
struct data* top = NULL;

 push(char *name,char *type,	char *address,char *phone){
	struct data* temp = NULL;
	temp = (struct data*)malloc(sizeof(struct data));
	
	if(!temp){
		printf("\n Heap Overflow");
		exit (1);
	}
	
	strcpy(temp->name,name);
	strcpy(temp->type,type);
	strcpy(temp->address,address);
	strcpy(temp->phone,phone);
	
	if(top == NULL){
		temp->next = NULL;
	}
	else{
		temp->next = top;
	}
	top = temp;
	return 0;
}

void add(){
	fflush(stdin);
	system("cls");
	char name[25];
	char type[10];
	char address[25];
	char phone[15];
	int confirm;
	char choice;
	do{
		printf("\nInput Name of Person/Company/Society [3..20]: ");
		gets(name);
		if(strlen(name) > 20 || strlen(name) < 3){
		printf("\n-- Its length must be between 3 and 20 characters.--\n");
		getch();
		}
	}while(strlen(name) > 20 || strlen(name) < 3);
	do{
		printf("\nInput The Type of New Entry Name [person/company/society]: ");
		fflush(stdin);
		gets(type);
		if(strcmp(type,"person") != 0 && strcmp(type,"company") != 0 && strcmp(type,"society") != 0){
			printf("\nType of the item must be [person/company/society]!\n");
			getch();
		}
	}while(strcmp(type,"person") != 0 && strcmp(type,"company") != 0 && strcmp(type,"society") != 0);
	do{
		printf("\nInput Address of New Entry Name [6...20]: ");
		gets(address);
		if(strlen(address) > 20 || strlen(address) < 6){
			printf("\n-- Its length must be between 6 and 20 characters.--\n");
			getch();
		}
	}while(strlen(address) > 20 || strlen(address) < 6);
	do{
		printf("\nInput Phone of New Entry Name [9...12]: ");
		gets(phone);
		if(strlen(phone) > 12 || strlen(phone) < 9){
			printf("\n-- Its length must be between 9 and 12 characters.--\n");
			getch();
		}
	}while(strlen(phone) > 12 || strlen(phone) < 9);
	do{
		printf("\n\n Confirm ? (y/n):");
		scanf("\n%c",&choice);
		if(choice == 'y'|| choice == 'Y'){
			confirm = push(name,type,address,phone);
			printf("\n\n\n - Add New Information Success -");
			getch();
		}else if(choice == 'n'||choice == 'N'){
			printf("\n (back to menu)");
			getch();
			return;
		}else{
			printf("\n Choice Invalid!\n");
			getch();
		}
	}while(confirm != 0);
}
void del(){
	char name[50];
	char type[50];
	struct data* temp = NULL;
	
	temp = (struct data*)malloc(sizeof(struct data));

	if(top == NULL){
		printf("\n\n There are no information available!");
		getch();
	}
	else{
		
		temp = top;
		strcpy(name,temp->name);
		strcpy(type,temp->type);
		top = top->next;
		temp->next = NULL;
		free(temp);
		
		printf("\n\n The recently added item %s < %s > is being deleted",name,type);
		getch();
	}
}

void list(){
	system("cls");
	struct data* temp = NULL;
	temp = (struct data*)malloc(sizeof(struct data));
	temp = top;
	int no = 1;
	printf("\t\t\t--------INFORMATION LIST-------\n");
	printf("\n--------------------------------------------------------------------------------------------------");
	printf("\n| No  | Name                        | Type           | Address                | Phone            |");
	printf("\n--------------------------------------------------------------------------------------------------\n");
	while(temp != NULL){
		printf("| %-3d | %-27s | %-14s | %-22s |  %-14s  |\n",no,temp->name,temp->type,temp->address,temp->phone);
		temp = temp->next;
		no++;
	}
	printf("+-----+-----------------------------+----------------+------------------------+------------------+");
	getch();
}

int main(){
	int pilih;
	do{
		fflush(stdin);
		system("cls");
	printf("\tINFORMATION ADMINISTRATOR");
	printf("\n==============================================");
	printf("\n\n 1. Information List");
	printf("\n 2. Add New Information");
	printf("\n 3. Delete Lastest Information");
	printf("\n 4. Exit");
	printf("\n\n Input your choice : ");
	scanf("%d",&pilih);
	switch(pilih){
		case 1 : 
		list();
		system("cls");
		break;
		case 2 :
		add();
		system("cls");
		break;
		case 3 :	
		del();
		system("cls");
		break;
		}
	}while(pilih > 0 && pilih < 4 || pilih > 4);
	return 0;
}
