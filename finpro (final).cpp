/*********************************************************
Muhammad Irza A.D (2301946505)
Aria Rifqi (2301949091)
IT23
Binary Search Tree
Final Project Data Structure BC20
**********************************************************/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>

#define max 15

struct data
{
	char nama[30];
	char user[30];
	char pass[30];
	float ipa;
	float ips;
	float rata;
	struct data *left;
	struct data *right;
	int lev;
};
typedef struct data data;

struct data *root=NULL;

//fungsi fflush
void ff()
{
	fflush(stdin);
}

//fungsi clearscreen
void clrscr()
{
	system("cls");
}

//fungsi cek nama
int cek(data *ptr, char nama[])
{
	if(ptr==NULL)
		return 0;
	if(strcmp(ptr->nama, nama) == 0)
		return 1;
	if(cek(ptr->left, nama) == 1)
		return 1;
	else
		return cek(ptr->right, nama);
}

//fungsi search
data* search(data* ptr, char nama[]) {
    if(ptr == NULL || strcmp(ptr->nama, nama)==0)
        return ptr;
    if(strcmp(ptr->nama, nama) < 0)
        return search(ptr->right, nama);
    return search(ptr->left, nama);
}

//node dan pengecekan limit
data* node(data* n, int lvl) {
    n->lev = lvl;
    printf("\n\n--- Penambahan data sukses ---");
    return n;
}

//fungsi insert
data* insert(data* ptr, data* b, int level) {
    if(ptr == root && root == NULL) {
        root = node(b, level);
        return root;
    }
    if(max < level) {
        printf("\n\n--- Data sudah penuh ---");
    } 
	else 
	{
        if(ptr == NULL) 
		{
            return node(b, level);
        }
        if(strcmp(ptr->nama, b->nama) > 0)
            ptr->left = insert(ptr->left, b, ++level);
        else if(strcmp(ptr->nama, b->nama) < 0)
            ptr->right = insert(ptr->right, b, ++level);
    }
    return ptr;
}

//fungsi Inorder
void inorder(data *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		printf("%-5s	|%10.2f	|%10.2f	|%10.2f     |\n", ptr->nama, ptr->ipa, ptr->ips, ptr->rata);
		inorder(ptr->right);
	}
}

//fungsi add
void add()
{
	clrscr();
	ff();
	int level=1;
	data *b=(data*)malloc(sizeof(data));
	b->left = NULL;
	b->right = NULL;
	do
	{
		do
		{
			printf("Masukkan Nama: ");
			scanf("%s",b->nama);
		}while(strlen(b->nama)<0 ||strlen(b->nama)>20 );
		if(cek(root,b->nama)==1)
		{
			printf("\n\n--- Penambahan data gagal ---\n");
			printf("Nama sudah ada\n\n");	
		}	
	}while(cek(root,b->nama)!=0);
	do
	{
		printf("Masukkan Nilai IPA: ");
		scanf("%f",&b->ipa);
		ff();
	}while(b->ipa<0 || b->ipa>100);
	do
	{
		printf("Masukkan Nilai IPS : ");
		scanf("%f",&b->ips);
		ff();
	}while(b->ips<0 || b->ips>100);
	b->rata=(b->ipa + b->ips)/2;
	printf("Nilai Rata-Rata Siswa: %2.2f",b->rata);
	insert(root,b,1);
	getch();
}

//update
void update()
{
	struct node *ptr;
	char nama[30];
	
	clrscr();
	ff();
	if(root==NULL)
	{
		printf("--- Tidak ada data ---");
		getch();
	}
		
	else
	{
		data *ptr = (data*)malloc(sizeof(data));
		do
		{
			printf("Masukkan Nama: ");
			scanf("%s", nama);
		}
		while(strlen(nama)<0 ||strlen(nama)>20);
        if(cek(root,nama)==1)
        {
            ptr = search(root, nama);
            printf("\nNama  : %s\n", ptr->nama);
            printf("Nilai IPA :  %2.2f\n", ptr->ipa);
            printf("Nilai IPS :  %2.2f\n", ptr->ips);
            printf("Nilai Rata-Rata :  %2.2f\n", ptr->rata);
        	do
			{
		        printf("Masukkan Nilai IPA : \n");
		        scanf("%2.2f", &ptr->ipa);
		        ff();
        	}
			while(ptr->ipa<0||ptr->ipa>100);
			do
			{
		        printf("Masukkan Nilai IPS : \n");
		        scanf("%f", &ptr->ips);
		        ff();
        	}
			while(ptr->ips<0||ptr->ips>100);
		    ptr->rata=(ptr->ipa + ptr->ips)/2;
		    printf("Nilai Rata-Rata Baru: %2.2f",ptr->rata);
        	printf("\n\n\n--- Update Data Berhasil ---");
    	}
        else
            printf("\n\n--- Nama tidak ditemukan ---\n\n");
            getch();
    }
	return;
}


//fungsi print
void print(char *name)
{

	clrscr();
	ff();
	printf("==========================================\n");
	printf("||	Nama Guru: %s		||\n", name);
	printf("==========================================\n");

	if(root==NULL)
	{
		printf("There Are no Data to Be Displayed");
		getch();
	}
	else
	{
	printf("---------------------------------------------------------\n");
	printf("Nama	|Nilai IPA	|Nilai IPS	|Nilai Rata-rata|\n");
	printf("---------------------------------------------------------\n");
	inorder(root);
	printf("---------------------------------------------------------\n");
	getch();
	}

}


//fungsi main menu
void menu(char *name)
{
	clrscr();
	int ans;
	do
	{
		printf("Main Menu\n");
		printf("++++++++++++++++\n\n");
		printf("1.Masukkan Data\n");
		printf("2.Update Data\n");
		printf("3.Print Data\n");
		printf("4.Exit\n\n");
		printf("Masukkan Pilihan: ");
		scanf ("%d",&ans);
		ff();
		switch(ans)
		{
			case 1:
			add();
			clrscr();
			break;
			
			case 2:
			update();
			clrscr();
			break;
			
			case 3:
			print(name);
			clrscr();
			break;
			
			case 4:
			exit(0);
			break;
		}	
	}while(ans>0 && ans<4||ans>4);
	
}

//login
void login()
{
	char name[30];

	clrscr();
	ff();
	char pass[15];
	char rep;
	printf("LOGIN PAGE\n");
	printf("++++++++++++++++++++\n\n");
	do
	{
		printf("Masukkan Nama: ");
		gets(name);
		
		ff();
	}while(strlen(name)<0 || strlen(name)>30);
	
	do
	{
		printf("Masukkan Password: ");
		gets(pass);
		ff();	
	}while(strlen(pass)<0 || strlen(pass)>12);
	
	if(strcmp(name,"Budianto")==0 || strcmp(name,"budianto")==0 && strcmp(pass,"budi")==0 || strcmp(name,"Bambang")==0 || strcmp(name,"bambang")==0 && strcmp(pass,"bambang")==0 )
	{
		menu(name);
	}
	else
	{
		printf("\n\nWrong Username or Password\n");
        printf("Masukkan Ulang? [y/n] ");
        rep = getch();
        ff();
        while(rep == 'y')
        {
            clrscr();
            ff();
            login();
        }
        if(rep == 'n')
        {
            getch();
            exit(0);
        }
	}
	getch();
}


int main()
{
	login();
}
