/**************************************************
Muhammad Irza A.D
2301946505
Lab 8
IT23
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct bio
{
	char name [25];
	int score;
	int lev;
	struct bio *right;
	struct bio *left;	
};
struct bio *root;
int max=4;
int data=0;

int cek(bio *temp, int score)
{
	if(temp==NULL)
		return 0;
	if(temp->score == score)
		return 1;
	if(cek(temp->left, score) == 1)
		return 1;
	else 
		return cek(temp->right, score);
}

int insert(char *name, int score)
{
	char ans[20];
	int level=1;
	struct bio *temp=(struct bio*)malloc(sizeof(struct bio));
	temp->left=NULL;
	temp->right=NULL;
	
	if(!temp)
	{
		printf("Error");
	}
	strcpy(temp->name,name);
	temp->score=score;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		bio *ptr=root;
		bio *preptr=root;
		do
		{
			do
			{
				printf("\nWill He Be in 'left' or 'right' %s [type le for left and ri for right]? ", ptr->name);
				gets(ans);
			}
			while(strcmp(ans, "le")!=0 && strcmp(ans, "ri")!=0);
			preptr = ptr;
			if(strcmp(ans, "le")==0)
			{
				ptr = ptr->left;
			}		
			else if(strcmp(ans, "ri")==0)
			{
				ptr = ptr->right;
			}
			level++;
		}
		while(ptr!=NULL && ptr->lev <= max);
		if(preptr->lev == max)
		{
			printf("\n\n--- Maximum Tree Level is 4 ---");
			return 0;
		}
		if(strcmp(ans, "le")==0)
		{
			preptr->left = temp;
		}
		else if (strcmp(ans, "ri")==0)
		{
			preptr->right = temp;
		}
	}
	temp->lev = level;
	data++;
	printf("\n\n--- Add Student Success ---");
	return 0;
}


void add()
{
	system("cls");
	fflush(stdin);
	char name[30];
	int score;
	do
	{
		printf("Input Student's Name [3..20]: ");
		gets(name);
		fflush(stdin);
		if(strlen(name)<3 || strlen(name)>20)
		{
			printf("Name Character's length must be between 3...20!\n");
		}
	}while(strlen(name)<3 || strlen(name)>20);
	do
	{
		do
		{
			printf("Input Student's Score [0..100]: ");
			scanf("%d",&score);
			fflush(stdin);
			if(score<0 || score>100)
			{
				fflush(stdin);
				printf("Score must be between 0...100\n!");
			}
		}while(score<0 || score>100);		
	}while(cek(root,score)!=0);
	insert(name,score);
}

void dat(bio *temp)
{
	if(temp!=NULL)
	{
		printf("- %-18s %d \n", temp->name, temp->score);
		dat(temp->left);
		dat(temp->right);
	}
}
void list()
{
	system("cls");
	if(root==NULL)
	{
		printf("--There is no data--");
	}
	else
	{
		printf("Student List\n");
		dat(root);
	}
	getch();
}

void del(bio *preptr, bio *ptr, int score)
{
	if(ptr!=NULL)
	{
		if(ptr->score == score)
		{
			if(ptr == root)
				root = NULL;
			else
			{
				if(preptr->left == ptr)
					preptr->left = NULL;
				else if(preptr->right == ptr)
					preptr->right =  NULL;
				free(ptr);
			}
			data--;
			return;	
		}
		del(ptr, ptr->left, score);
		del(ptr, ptr->right, score);
	}
}

void hapus()
{
	system("cls");
	if(root==NULL)
		printf("--- There is No Student in the Tree ---");
	else
	{
		int score;
		do
		{
			printf("Input Student's Score That You Want to Be Removed [0...100]: ");
			scanf("%d", &score);
		}
		while(score < 0 || score > 100);
		if(cek(root,score)==1)
		{
			del(root, root, score);
			printf("\n\n--- The Student Has Been Removed ---");
		}
		else
		printf("\n\n--- The Student Doesn't Exit ---");
	}
	return;
}

void preorder(bio *temp)
{
	if(temp!=NULL)
	{
		printf("%d ", temp->score);
		preorder(temp->left);
		preorder(temp->right);
	}
	
}

void inorder(bio *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d ", temp->score);
		inorder(temp->right);
	}
	
}

void postorder(bio *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d ", temp->score);
	}
	
}

void ord()
{
	system("cls");
	if(root==NULL)
		printf("--- There is No Student in the Tree ---");
	else
	{
		printf("Preorder    : ");
		preorder(root);
		printf("\nInorder     : ");
		inorder(root);
		printf("\nPostorder   : ");
		postorder(root);
		getch();
	}
}

int main()
{
	int ans;
	do
	{
		printf("BIOLOGY SCORE\n");
		printf("*************************\n\n");
		printf("1.View All Student\n");
		printf("2.Add Student\n");
		printf("3.Remove Student\n");
		printf("4.Inorder, Predorder, Postorder\n");
		printf("5.Exit and Delete\n\n");
		printf(">> Input Choice : ");
		scanf("%d",&ans);
		switch(ans)
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
			hapus();
			system("cls");
			break;
			
			case 4:
			ord();
			system("cls");
			break;
			
			case 5:
			exit(0);	
			break;	
		}
	}while(ans>0 && ans<5||ans>5);
	
	
}
