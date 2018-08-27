#include <stdio.h>
#include <stdlib.h>
struct Number
{
	int number;
	struct Number *up;
	struct Number *left;
	struct Number *right;
	bool isLeftVerified;
	bool isRightVerified;   	
};
struct Number *first = NULL;
struct Number *auxiliar;
struct Number *delete_Element;
int num_Numbers = 0;
int preVector[50];
int i = 0;
int depth;
int depthCounter;
int unbalanceCounter;
int totalUnbalance;
void runStraightLeft()
{
	while(auxiliar->left != NULL)
	{
		auxiliar = auxiliar->left;
		if(i==1)
		{
			printf("%d  ",auxiliar->number);
		}
		auxiliar->isLeftVerified = true;
		depthCounter++;
		unbalanceCounter++;
	}
	if(i==0 && auxiliar->right==NULL)
	{
		printf("%d  ",auxiliar->number);
	}
}
void runStraightRight()
{
	while(auxiliar->right != NULL)
	{
		auxiliar = auxiliar->right;
		if(i==1)
		{
			printf("%d",auxiliar->number);
		}
		if(auxiliar->left!=NULL)
		{
			if(auxiliar->right==NULL)
			{
				auxiliar->isRightVerified = true;
			}
			unbalanceCounter--;
			runStraightLeft();
		}
		else
		{
			unbalanceCounter++;
			auxiliar->isRightVerified = true;
		}
		depthCounter++;
	}
}
void posOrder()
{
	i = 0;
	auxiliar = first;
	runStraightLeft();
	while(7)
	{
		if(auxiliar->right!=NULL && auxiliar->isRightVerified==false)
		{
			auxiliar->isRightVerified = true;
			auxiliar = auxiliar->right;
			if(auxiliar->left!=NULL)
			{
				auxiliar->isLeftVerified=true;
				runStraightLeft();
			}
			else if(auxiliar->right!=NULL)
			{
				auxiliar->isRightVerified=true;
				runStraightRight();
			}
			else
			{
				printf("%d  ",auxiliar->number);
			}
		}

		auxiliar = auxiliar->up;
		if(auxiliar->isRightVerified==true)
		{
			printf("%d  ",auxiliar->number);
		}
		if(auxiliar->up==NULL && auxiliar->isRightVerified==true)
		{
			break;
		}
	}
}
void preOrder()
{
	i = 1;
	auxiliar = first;
	printf("%d  ",auxiliar->number);
	runStraightLeft();
	while(auxiliar->up!=NULL)
	{
		if(auxiliar->right!=NULL && auxiliar->isRightVerified==false)
		{
			depthCounter++;
			auxiliar->isRightVerified = true;
			runStraightRight();
		}
		auxiliar = auxiliar->up;
		depthCounter--;
		if(auxiliar->up==NULL && auxiliar->isRightVerified==false)
		{
			totalUnbalance = unbalanceCounter;
			auxiliar->isRightVerified = true;
			depthCounter = 0;
			runStraightRight();
		}
		if(depthCounter>depth)
		{
			depth = depthCounter;
		}
	}
	depth--;
}
void inOrder()
{
	i = 0;
	auxiliar = first;
	runStraightLeft();
	while(7)
	{
		if(auxiliar->right!=NULL && auxiliar->isRightVerified==false)
		{
			auxiliar->isRightVerified = true;
			auxiliar = auxiliar->right;
			if(auxiliar->left!=NULL)
			{
				auxiliar->isLeftVerified=true;
				runStraightLeft();
			}
			else if(auxiliar->right!=NULL)
			{
				auxiliar->isRightVerified=true;
				printf("%d  ",auxiliar->number);
				runStraightRight();
			}
			else
			{
				printf("%d  ",auxiliar->number);
			}
		}
		
		auxiliar = auxiliar->up;
		if(auxiliar->isRightVerified==false)
		{
			
			printf("%d  ",auxiliar->number);
		}
		if(auxiliar->up==NULL && auxiliar->isRightVerified==true)
		{
			break;
		}
		
	}
}
void clear()
{
	system("pause");
	fflush(stdin);
	system("cls");
}
void deleteNoNode()
{
	auxiliar = auxiliar->up;
	if(delete_Element->number > auxiliar->number)
	{
		auxiliar->right = NULL;
		free(delete_Element);
	}
	else
	{
		auxiliar->left = NULL;
		free(delete_Element);
	}
}
void deleteOneNode()
{
	if(delete_Element->right == NULL)
	{
		auxiliar = auxiliar->left;
		if(delete_Element->number > auxiliar->number)
		{
			auxiliar->up = delete_Element->up;
			delete_Element->up->left = delete_Element->left;
			free(delete_Element);
		}
		else
		{
			auxiliar->up = delete_Element->up;
			delete_Element->up->right = delete_Element->left;
			free(delete_Element);
		}
	}
	else if (delete_Element->left == NULL)
	{
		auxiliar = auxiliar->right;
		if(delete_Element->number > auxiliar->number)
		{
			auxiliar->up = delete_Element->up;
			delete_Element->up->left = delete_Element->right;
			free(delete_Element);
		}
		else
		{
			auxiliar->up = delete_Element->up;
			delete_Element->up->right = delete_Element->right;
			free(delete_Element);
		}
	}
}
void deleteDoubleNode()
{	
	delete_Element = auxiliar->left;
	while(delete_Element->right!=NULL)
	{
		delete_Element = delete_Element->right;
		   
	}
	auxiliar->number = delete_Element->number;
	if(delete_Element->up==auxiliar && delete_Element->left!=NULL)
	{
		auxiliar->left = delete_Element->left;
		delete_Element->left->up = auxiliar;
	}
	else if(delete_Element->up==auxiliar)
	{
		auxiliar->left = NULL;
	}
	else if(delete_Element->up != auxiliar && delete_Element->left == NULL)
	{
		delete_Element->up->right = NULL;
	}
	else
	{
		delete_Element->up->left = delete_Element->left;
	}
	free(delete_Element);
}
void show()
{
	int option;
	auxiliar = first;
	while(7)
	{
		printf("Elemento atual: %d | 1 - ESQUERDA | 2 - CIMA | 3 - DIREITA | 4 - DELETAR | 5+ - SAIR |", auxiliar->number);
		scanf("%d", &option);
		if(option == 1)
		{
			if(auxiliar->left == NULL)
			{
				printf("Nao ha elementos a esquerda !\n");
				clear();
			}
			else
			{
				auxiliar = auxiliar->left;
				system("cls");
			}
		}
		else if(option == 2)
		{
			if(auxiliar->up == NULL)
			{
				printf("Voce ja esta no elemento no da arvore !\n");
				clear();
			}
			else
			{
				auxiliar = auxiliar->up;
				system("cls");
			}

		}
		else if(option == 3)
		{
			if(auxiliar->right == NULL)
			{
				printf("Nao ha elementos a direita !\n");
				clear();
			}
			else
			{
				auxiliar = auxiliar->right;
				system("cls");
			}

		}
		else if(option == 4)
		{
			delete_Element = auxiliar;
			if(delete_Element->right == NULL && delete_Element->left == NULL)
			{
				deleteNoNode();
			}
			else if((delete_Element->right == NULL && delete_Element->left != NULL) || (delete_Element->right != NULL && delete_Element->left == NULL))
			{
				deleteOneNode();
			}
			else if(delete_Element->right != NULL && delete_Element->left != NULL)
			{
				deleteDoubleNode();
			}
			system("cls");
		}
		else
		{
			break;
		}
	}
}
void insert(int number)
{
				
	struct Number *new_Element;
	new_Element = (struct Number*) malloc(sizeof(struct Number));

	if(first == NULL)
	{
		new_Element->number = number;
		new_Element->up = NULL;
		new_Element->left = NULL;
		new_Element->right = NULL;
		new_Element->isLeftVerified = false;
		new_Element->isRightVerified = false;
		first = new_Element;
	}
	else
	{
		new_Element->number = number;
		auxiliar = first;

		while(7)
		{
			if(new_Element->number > auxiliar->number)
			{
				if(auxiliar->right == NULL)
				{
					new_Element->up = auxiliar;
					new_Element->right = NULL;
					new_Element->left = NULL;
					new_Element->isLeftVerified = false;
			  		new_Element->isRightVerified = false;
					auxiliar->right = new_Element;

					break;
				}
				else
				{
					auxiliar = auxiliar->right;
				}
			}
			else if(new_Element->number < auxiliar->number)
			{
				if(auxiliar->left == NULL)
				{
					new_Element->up = auxiliar;
					new_Element->right = NULL;
					new_Element->left = NULL;
					new_Element->isLeftVerified = false;
					new_Element->isRightVerified = false;
					auxiliar->left = new_Element;

					break;
				}
				else
				{
					auxiliar = auxiliar->left;
				}
			}
		}
	}
}
int main()
{
	insert(50);
	insert(40);
	insert(30);
	insert(35);
	insert(20);
	insert(27);
	insert(37);
	insert(34);	
	insert(60);
	insert(100);
	insert(80);
	insert(45);
	insert(43);
	insert(42);
	insert(41);
	insert(47);
	int number;
	int option;
	while(7)
	{
		printf("1 - INSERIR VALOR \n");
		printf("2 - NAVEGAR NA ARVORE \n");
		printf("3 - PRE-ORDER\n");
		printf("4 - SAIR\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &option);
		if(option == 1)
		{
			printf("Digite o valor que deseja inserir: ");
			scanf("%d", &number);
			insert(number);
			clear();
		}
		else if(option == 2)
		{
			if(first == NULL)
			{
				printf("Arvore vazia!");
				system("pause");
				system("cls");
			}
			else
			{
				show();
				clear();					
			}

		}
		else if(option==3)
		{
			preOrder();
			printf("Arvore em pre ordem: \n\n");
			for(i=0;i<50;i++)
			{
				if(preVector[i]!=0)
				{
					printf("%d\t",preVector[i]);	
				}
				
			}
			printf("\n-----------------------------------------------------------------------------------------\n\n\nProfunidade da arvore: %d \nQuanto a arvore esta desbalanceada: %d\n\n",depth, unbalanceCounter);
			
		}
		else if(option==4)
		{
			inOrder();
		}
		else if(option==5)
		{
			posOrder();
		}
		else
		{
			printf("O programa sera encerrado !");
			break;
		}
	}

}