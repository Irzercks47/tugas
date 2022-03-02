/*********************************************
Muhammad Irza A.D
IT23
2301946505
Lab 5
*********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


struct drink{
	char name[30];
	int  qty;
	char denom[30];
	struct drink *next;
};
struct drink *front;
struct drink *rear;
int choice;

void view();
void add();
void take();



int main(){
	
	int choice;
	do{
		printf("BLUE DRINKS SHOP\n");
		printf(".........................\n\n");
		printf("1. View Order List\n");
		printf("2. Add New Order\n");
		printf("3. Take Order\n");
		printf("4. Exit\n\n");
		printf(">> Input your choice : ");
		scanf("%d",&choice);
		fflush(stdin);
		switch(choice)
		{
			case 1:
				view();
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
				printf("Thank You for Using This Program ");
				getch();
				exit(0);
				break; 
		}
	}while(choice > 0 && choice < 4 || choice > 4);	
}


int main_menu(){
	
}


void view(){
	struct drink *temp = (struct drink*) malloc(sizeof(struct drink));
	int i =1;
	
	system("cls");
	
	printf("\t\t\t --- ORDER LIST ---\n");
    printf("\n+----+---------------------+-----------------+----------------------+");
	printf("\n| No.| Name of Drink       | Quantity        | Denomination         |");
	printf("\n+----+---------------------+-----------------+----------------------+\n");
	if(rear == NULL){
		printf("+----+---------------------+-----------------+----------------------+");
	}else{
		temp = front;
		do{
		printf("| %-2d | %-19s | %-15d | %-20s |\n",i,temp->name,temp->qty,temp->denom);
		temp = temp->next;
		i++;
		}while(temp != front);
		printf("+----+---------------------+-----------------+----------------------+");
	}
	
	getch();
}



int data = 0;

int push(char *name, int qty, char *denom){
	struct drink *temp = (struct drink*) malloc(sizeof(struct drink));
	strcpy(temp->name,name);
	temp->qty = qty;
	strcpy(temp->denom,denom);
	
	if(rear == NULL){
		temp->next = temp;
		rear = temp;
		front = temp;
	}else{
		temp->next = rear->next;
		rear->next = temp;
		rear = temp;
	}
	++data;
	return 0;
}

void add(){
	char name[30];
	int qty;
	char denom[30];
	char choice;
	
	system("cls");
	fflush(stdin);
    do{
		system("cls");
		printf("Input Name of Drink [3..30]: ");
		fflush(stdin);
		gets(name);
		if(strlen(name) < 3 || strlen(name) > 30){
			printf("The length of Name must be between 3 and 30 characters");
			getch();
		}
    }while(strlen(name) < 3 || strlen(name) > 30);
    
	do{
		system("cls");
		printf("Input Name of Drink [3..30]: %s ",name); 
		
		printf("\n\nInput Quatity of Drink [1..100] : ");
		fflush(stdin);
	    scanf("%d",&qty);
		
		if(qty < 1 || qty > 100){
			printf("\nThe quantity must be between 1 and 100");
			getch();
		}
		
	}while(qty < 1 || qty > 100);
	
	do{
		
		system("cls");
		printf("Input Name of Drink [3..30]: %s ",name); 
		printf("\n\nInput Quatity of Drink [1..100] : %d",qty);
		
		printf("\n\nInput Denomination [pieces/dozen/box]: ");
		fflush(stdin);
		gets(denom);
		
		if(strcmp(denom,"pieces") !=0 && strcmp(denom,"dozen") !=0 && strcmp(denom,"box") !=0){
			printf("\n      		Please choose appropriate type !\n ");
			getch();
		}
			
	}while(strcmp(denom,"pieces") !=0 && strcmp(denom,"dozen") !=0 && strcmp(denom,"box") !=0);
		
	push(name,qty,denom);
	
	printf("\n--- Add New Order Success ---");
	getch();

}
		

void Delete(int index){
	int i = 1;
	struct drink *temp = (struct drink*)malloc(sizeof(struct drink));
	struct drink *pretemp = (struct drink*) malloc(sizeof(struct drink));
	temp = rear->next;
	while(index != i){
		pretemp = temp;
		temp = temp->next;
		i++;
	}
	if(temp->next == temp){
		front = NULL;
		rear = NULL;
		free(temp);
	}
	else if(temp == front){
		pretemp = rear;
		front = temp->next;
		pretemp->next = front;
		free(temp);
	}else if(temp == rear){
		pretemp->next = front;
		rear = pretemp;
		free(temp);
	}else{
		pretemp->next = temp->next;
		temp = NULL;
		free(temp);
	}
	--data;
}

void take(){
	struct drink *temp = NULL;
	temp = (struct drink *)malloc(sizeof(struct drink));
	temp = front;
	int i = 0;
	i = data;
	int number;
	
	if(front == NULL){
		printf("\n --- There is No Order in The List ---\n");
		getch();
		return;
	}else{
		system("cls");
		view();
		
		do{
			printf("\n\n Input Number of The Order [1...%d] : ",i);
			scanf("%d",&number);
			if(number > i || number < 1){
				printf("\n Number of order must be between 1...%d! \n",i);
				getch();
			}
		}while(number > i || number < 1);
		Delete(number);
		printf("\n\n\n --- Take Order Success ---");
		getch();
	}

}



