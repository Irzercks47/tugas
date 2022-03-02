#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/*********************************************************************
Muhammad Irza Athanafi Diarifin
2301946505
**********************************************************************/
struct stationary//struct
{
	char statcode[7];
	char statname[10];
	int stok;
	int price;
};

struct stationary stat[4]={//data
	
	{"SA001","Pencil",140,7500},
	{"SA004","Eraser",90,5000},
	{"SA009","Pen",120,8000},
	{"SA004","Notes",80,9500}	
};
int indeks=0;
int main();
void tabel()
{
	int i;
	printf("BAGOES Stationary Store\n");
	printf("***********************\n\n");
	printf("No| Stationary Code	| Stationary Name	| Available	| Price\n");
	printf("------------------------------------------------------------------------------\n");
	for(i=0;i<4;i++)
	{
		printf("%-2d|%-21s|%-23s|%-15d|Rp. %-5d,-\n",i+1, stat[i].statcode, stat[i].statname, stat[i].stok, stat[i].price);
	}
}


int search(struct stationary ptr[],char *statcode){//untuk search code stationary
	
	int i;
	for(i = 0 ; i < 4 ; i++){
			if(strcmp(ptr[i].statcode,statcode) == 0){
				return i;
			}
		}
	return -1;
}

void sell(struct stationary ptr[])
{
	char code[7];
	int indeks,stok,total,limit;
	tabel();
	printf("\n\n");
	
	do{
		printf("Input Stationary Code [5 chars]:");
		gets(code);
		fflush(stdin);
		limit=strlen(code);//batas loop do...while
		if(search(stat,code) == -1)
		{
			printf("--- The Stationery Code does not exist ---" );
			getch();
		}
		else
		{
			indeks=search(stat,code);
			printf("Nama: %s\n",ptr[indeks].statname);
			printf("Input Quantity [0...%d]:",ptr[indeks].stok);
			scanf("%d",&stok);
			fflush(stdin);
			if(stok<ptr[indeks].stok)
			{
				total=ptr[indeks].price*stok;
				printf("\n\nTotal Price is : %d x %d = %d\n",ptr[indeks].price,stok,total);
				ptr[indeks].stok = ptr[indeks].stok - stok;
				printf("---------------Thank You--------------------");
				getch();
			}
			else
			{
				printf("...The quantity of stationery is not enough...");
				getch();
			}		
		}
	}while(limit<1 || limit>5);
	system("cls");
	main();
}
void addstock(struct stationary ptr[])
{
	int indeks,stok,total,limit;
	char code[7];
	tabel();
	printf("\n\n");
	do{
		printf("Input Stationary Code [5 chars]:");
		gets(code);
		limit=strlen(code);
		if(search(stat,code) == -1)
		{
			printf("--- The Stationery Code does not exist ---" );
			getch();
		}
		else
		{
			do
			{
				indeks=search(stat,code);
				printf("Nama: %s\n",ptr[indeks].statname);
				printf("Input Quantity [0...10]:");
				scanf("%d",&stok);
				fflush(stdin);
			}while(stok>10 || stok<1);
			total=ptr[indeks].price+stok;
			ptr[indeks].stok = ptr[indeks].stok + stok;
			printf("---------------Thank You--------------------");
			getch();
		}
	}while(limit<1 || limit>5);
	system("cls");
	main();
}

int main()
{
	int menu;
	do
	{
		tabel();
		printf("\n\n");
		printf("Menu:\n");
		printf("1. Sell\n");
		printf("2. Add Stock\n");
		printf("3. Exit\n");
		printf("Input Choice:");
		scanf("%d",&menu);
		fflush(stdin);
		system("cls");	
		switch(menu)
		{
			case 1:
			sell(stat);
			system("cls");
			break;
		
			case 2:
			addstock(stat);
			system("cls");
			break;
		
			case 3:
			printf("Thank You For Using This program");
			getch();
			return 0;
			break;
		}
	}while(menu<1 || menu>3);

}
