/**************************************************************
Muhammad Irza A.D
2301946505
IT 23
Lab 2
****************************************************************/

#include <stdio.h>
#include <conio.h> 
#include <string.h>
#include <stdlib.h>

struct rice{
	char type[15];
	int weight;
	struct rice *next;
};

struct rice *top;

int linked(char *type,int weight)
{
	struct rice *temp = NULL;
	temp = (struct rice*)malloc(sizeof(struct rice));
	
	if(!temp){
		printf("\n\n Overflow");
		return 0;
	}
	
	strcpy(temp->type,type);
	temp->weight = weight;
	
	if(top == NULL){
		temp->next = NULL;
	}
	else{
		temp->next = top;
	}
	top = temp;
	return 0;	
}

int max(){
	int data=1;
	struct rice *temp = NULL;
	temp = (struct rice*)malloc(sizeof(struct rice));
	
	temp = top;
	while(temp != NULL){
		data++;
		temp = temp->next;
	}
	
	if(data <= 10){
		return 1;
	}else{
		return 0;
	}
	getch();
}

void stock(){
	struct rice *temp = NULL;
	temp = (struct rice*)malloc(sizeof(struct rice));
	temp = top;
	
	printf("  Rice Stock (STACK)\n\n");
	
	while(temp != NULL){
		if(temp == top){
			printf("| %6s grain : %4d kg(s) | -> [top]\n",temp->type,temp->weight);
		}
		else{
			printf("| %6s grain : %4d kg(s) |\n",temp->type,temp->weight);
	    }
		temp = temp->next;
	}
	printf("\n");
}
void add(){
	char type[100];
	int weight;
	if(max() == 1){
		
		do{
		
			printf("\n\nInput Rice Type [long/medium/short] grain: ");
			fflush(stdin);
		    gets(type);
			if(strcmp(type, "long") !=0 && strcmp(type, "medium") !=0 && strcmp(type, "short") !=0){
				printf("\n      		Please choose appropriate type !\n ");
				getch();
			}
			
		}while(strcmp(type, "long") !=0 && strcmp(type, "medium") !=0 && strcmp(type, "short") !=0);
		
		do{
			
			printf("\nInput Weight of The Rice Sack [10..100 kg(s)]: ");
			scanf("%d",&weight);
		
			if(weight < 10 || weight > 100){
				printf("\n  Weight must be between 10 and 100 \n\n");
				getch();
			}
			
		}while(weight < 10 || weight > 100);
		
		linked(type,weight);
		printf("\n	--- Add Rice Sack Success ---");
		getch();
	}
	else{
		printf("\n	--- The Rice Storage is Full ---");
		getch();
	}
}
		

void sell(){
	struct rice *temp = NULL;
	
	temp = (struct rice*)malloc(sizeof(struct rice));

	if(top == NULL){
		printf("\n\n --- The Rice Storage is Empty ---");
		getch();
	}
	else{
		temp = top;
		top = top->next;
		temp->next = NULL;
		free(temp);
		printf("--- Sell Rice Sack Success ---");
		getch();
	}
}

int main()
{
	int choice;
	do
	{
		printf("BLUE RICE STOCK\n");
		printf("^^^^^^^^^^^^^^^^^^^^\n\n");
		stock();
		printf("Menu : \n");
		printf("1.Stock Rice Sack\n");
		printf("2.Sell Rice Sack\n");
		printf("3.Exit\n\n");
		printf(">> Input Choice : ");
		scanf("%d",&choice);
		fflush(stdin);
		switch(choice)
		{
			case 1:
				add();
				system("cls");
				break;
			case 2:
				sell();
				system("cls");
				break;
			case 3:
				exit(0);
				break;
		}
	}while(choice>0 && choice<3 || choice>3);
	
}
