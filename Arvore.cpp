#include <stdio.h>
#include <stdlib.h>
//		//PRIMEIRO ELEMENTO INSERIDO A ESQUERDA DO NÓ RAIZ
//		new_Element->number = number;
//		first->left = new_Element;
//		new_Element->up = first;
//		new_Element->right = NULL;
//		new_Element->left = NULL;
//		last_Left = new_Element;
//
//		//PRIMEIRO ELEMENTO INSERIDO A DIREITA DO NÓ RAIZ
//		new_Element->number = number;
//		first->right = new_Element;
//		new_Element->up = first;
//		new_Element->right = NULL;
//		new_Element->left = NULL;
//		last_Right = new_Element;
//		//
//		new_Element->number = first;
//		last_Right->left = new_Element;
//		new_Element->up = last_Right;
//		new_Element->left = NULL;
//		new_Element->right = NULL;
//		last_Right = new_Element;
//		//
//		new_Element->number = first;
//		last_Right->right = new_Element;
//		new_Element->up = last_Right;
//		new_Element->left = NULL;
//		new_Element->right = NULL;
//		last_Right = new_Element;
//
struct Number
{
	struct Number *up;
	struct Number *left;
	struct Number *right;
	int number;
};

struct Number *first = NULL;
struct Number *last;
struct Number *auxiliar;
struct Number *delete_Element;
int num_Numbers = 0;

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
			auxiliar->right = delete_Element->right;
			auxiliar->up = delete_Element->up;
			delete_Element->up->left = delete_Element->left;
			free(delete_Element);
		}
		else
		{
			auxiliar->left = delete_Element->left;
			auxiliar->up = delete_Element->up;
			delete_Element->up->right = delete_Element->right;
			free(delete_Element);
		}
	}
	else if (delete_Element->left == NULL)
	{
		auxiliar = auxiliar->right;
		if(delete_Element->number > auxiliar->number)
		{
			auxiliar->right = delete_Element->right;
			auxiliar->up = delete_Element->up;
			delete_Element->up->right = delete_Element->right;
			free(delete_Element);
		}
		else
		{
			auxiliar->left = delete_Element->left;
			auxiliar->up = delete_Element->up;
			delete_Element->up->left = delete_Element->left;
			free(delete_Element);
		}
	}

}
void deleteDoubleNode()
{
	delete_Element = auxiliar->left;

	while(7)
	{
		if(delete_Element->right!=NULL)
		{
			delete_Element = delete_Element->right;
		}
		else
		{
			break;
		}	
		
	}
	auxiliar->number = delete_Element->number;
	if(delete_Element->up==auxiliar && delete_Element->left!=NULL)
	{
		auxiliar->left = delete_Element->left;
		delete_Element->left->up = auxiliar;
	}
	else if (delete_Element->up==auxiliar)
	{
		auxiliar->left = NULL;
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
	insert(60);
	insert(70);
	insert(80);
	insert(85);
	insert(79);
	insert(3);
	int number;
	int option;
	while(7)
	{
		printf("1  - INSERIR VALOR \n");
		printf("2  - NAVEGAR NA ARVORE \n");
		printf("3+ - SAIR\n");
		printf("Escolha uma opçao: ");
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
			show();
			clear();
		}
		else
		{
			printf("O programa sera encerrado !");
			break;
		}
	}

}
