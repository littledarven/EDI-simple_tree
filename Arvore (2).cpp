#include <stdio.h>
#include <stdlib.h>

struct Number
{
	struct Number *up;
	struct Number *left;
	struct Number *right;
	int number;	
};
	struct Number *first;
	struct Number *last_Right;
	struct Number *last_Left;
	int num_Numbers = 0;
void Insert()
{
	struct Number *new_Element = struct Number* malloc(sizeof(struct Number));
	struct Number *auxiliar;
	if(num_Numbers==0)
	{
		new_Element->number = number;
		new_Element->up = NULL;
		new_Element->left = NULL;
		new_Element->right = NULL;
		first = new_Element;	
	}
	else
	{
		//PRIMEIRO ELEMENTO INSERIDO A ESQUERDA DO NÓ RAIZ
		new_Element->number = number;
		first->left = new_Element;
		new_Element->up = first;
		new_Element->right = NULL;
		new_Element->left = NULL;
		last_Left = new_Element;
	
		//PRIMEIRO ELEMENTO INSERIDO A DIREITA DO NÓ RAIZ
		new_Element->number = number;
		first->right = new_Element;
		new_Element->up = first;
		new_Element->right = NULL;
		new_Element->left = NULL;
		last_Right = new_Element;		
		//
		new_Element->number = first;
		last_Right->left = new_Element;
		new_Element->up = last_Right;
		new_Element->left = NULL;
		new_Element->right = NULL;
		last_Right = new_Element;
		//
		new_Element->number = first;
		last_Right->right = new_Element;
		new_Element->up = last_Right;
		new_Element->left = NULL;
		new_Element->right = NULL;
		last_Right = new_Element;
		//
		new_Element->number = number;
		auxiliar = first;
		while(7)
		{
			if(new_Element->number>auxiliar->number)
			{
				if(auxiliar->right==NULL)
				{
					new_Element->up = auxiliar;
					new_Element->right = NULL;
					new_Element->left = NULL;
					auxiliar->right = new_Element;
					last_Right = new_Element;
					break;
				}
				else
				{
					auxiliar = auxiliar->right;
				}
			}
			else if(new_Element->number<auxiliar->number)
			{
				if(auxiliar->left==NULL)
				{
					new_Element->up = auxiliar;
					new_Element->right = NULL;
					new_Element->left = NULL;
					auxiliar->left = new_Element;
					last_Left = new_Element;
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
	int option;
	printf("Escolha uma opçao: ");
	scanf("%d",&option);
	if(option==1)
	{
		printf("Digite o valor que deseja inserir: ");
		scanf("%d",&number);
		Insert();
	}
}
