/**************************************************************
Muhammad Irza A.D
2301946505
IT 23
Lab 6
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct data{
	char name[50];
	char address[50];
	char city[50];
	char phone[50];
	struct data *next;
	struct data *prev;
};

struct data *head = NULL;
struct data *tail = NULL;


int insert(char *name, char *address, char *city, char *phone,int select){
	int i,index;
	struct data *temp = (struct data*)malloc(sizeof(struct data));
	
	strcpy(temp->name,name);
	strcpy(temp->address,address);
	strcpy(temp->city,city);
	strcpy(temp->phone,phone);
	
	if(head==NULL)
	{
		temp->next=NULL;
		temp->prev=NULL;
		head=temp;
		tail=temp;
	}
	else
	{
		tail->next=temp;
		temp->prev=tail;
		tail=temp;	
	}
}

void add(){
	system("cls");
	fflush(stdin);
	char name[100],address[100],city[100],phone[100];
	int choice;
	

	do{
		printf("\n Input company's name [5...30] : ");
		gets(name);
		if(strlen(name) < 5 || strlen(name) > 30){
			printf("\n Name Character's length must be between 5...30! \n");getch();
		}
	}while(strlen(name) < 5 || strlen(name) > 30);
	

	do{
		printf("\n Input company's address [5...50] : ");
		gets(address);
		if(strlen(address) < 5 || strlen(address) > 50){
			printf("\n Address Character's length' must be between 5...50! \n");getch();
		}
	}while(strlen(address) < 5 || strlen(address) > 50);
	

	do{
		printf("\n Input company's city [5...30] : ");
		gets(city);
		if(strlen(city) < 5 || strlen(city) > 30){
			printf("\n City Character's length' must be between 5...30! \n");getch();
		}
	}while(strlen(city) < 5 || strlen(city) > 30);
	
	
	do{
		printf("\n Input company's phone [6..12] : ");
		gets(phone);
		if(strlen(phone) < 6 || strlen(phone) > 12 ){
			printf("\n Phone Number Character's length' must be between 6...11! \n");getch();
		}
	}while(strlen(phone) < 6 || strlen(phone) > 12);
	printf("\nEntered Data:");
	printf("\n%s | %s | %s | %s ",name,address,city,phone);
	insert(name,address,city,phone,choice);
	getch();
	
}

void list(){
	system("cls");
	struct data *temp = (struct data*) malloc(sizeof(struct data));
	int i = 1;
	printf("\n\t\t\t\t\t--- DATABASE CUSTOMER ---\n");
	printf("\n+----+--------------------------------+--------------------------------+------------------+------------------+");
	printf("\n| No.| Company Name                   | Address                        | City             | Phone Number     |");
	printf("\n+----+--------------------------------+--------------------------------+------------------+------------------+\n");
	if(tail == NULL){
		printf("+----+--------------------------------+--------------------------------+------------------+------------------+\n");
	}else{
		temp = head;
		do{
			printf("| %-2d | %-30s | %-30s | %-16s | %-16s |\n",i,temp->name,temp->address,temp->city,temp->phone);
			temp = temp->next;
			i++;
		}while(temp != tail->next);
		printf("+----+--------------------------------+--------------------------------+------------------+------------------+\n");
	}
	getch();
}

int main_menu(){
	int choice;
	printf(" DATABASE CUSTOMER");
	printf("\n .......................");
	printf("\n\n 1. View Customer Database");
	printf("\n 2. Add New Customer");
	printf("\n 3. Exit");
	printf("\n\n >> Input Choice : ");
	scanf("\n%d",&choice);
	return choice;
}

int main(){
	int choice;
	do{
		system("cls");
		choice = main_menu();
		switch(choice){
			case 1 : 
			list();
			break;
			case 2 : 
			add();
			break;
			case 3 : 
			exit(0);
			system("cls");
			printf("\n Thank You For Using This Program ");
			getch();
			break;
		}
	}while(choice != 3);
	return 0;	
}
