#include <stdio.h>
#include <stdlib.h>

struct lista
{
	int valor;
	struct lista *proximo;
};

typedef struct lista Lista;

Lista *lst_criar()
{
	return NULL;
}

Lista *lst_inserir(Lista *lst, int valor)
{
	Lista *novo = (Lista *) malloc(sizeof(Lista));
	novo->valor = valor;
	
	if(lst==NULL)
	{
		novo->proximo=novo;
	}
	else
	{
		novo->proximo=lst;
		Lista *lst_aux=lst;
		
		while(lst_aux->proximo!=lst)
		{
			lst_aux=lst_aux->proximo;
		}
		
		lst_aux->proximo=novo;
	}

	
	return novo; 
}


void lst_imprimir(Lista *lst)
{
	Lista *lst_aux=lst;
	do
	{
		printf("%d\n",lst_aux->valor);
		lst_aux=lst_aux->proximo;
		
	}while(lst_aux!=lst);
}


int lst_vazia(Lista *lst)
{
	if(lst == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

Lista *lst_buscar(Lista *lst, int valor)
{
	Lista *p;
	
	for(p = lst; p != NULL; p = p->proximo)
	{
		if (p->valor == valor)
		{
			return p;
		}
	}
	
	return NULL;
	
}

Lista *lst_retirar(Lista *lst, int v)
{
	Lista *p = lst;
	Lista *ant = NULL;
	
	while(p != NULL && p->valor != v)
	{
		ant = p;
		p = p->proximo;
	}
	
	if(p == NULL)
	{
		return lst;
	}
	
	if(ant == NULL)
	{
		lst = p->proximo;
		
	}
	else
	{
		ant->proximo = p->proximo;
	}
	
	free(p);
	return lst;
	
}

Lista *lst_liberar(Lista *lst)
{
	Lista *p = lst;
	
	while(p != NULL)
	{
		Lista *aux = p->proximo;
		free(p);
		p = aux;
	}
	
	return p;
}

Lista *lst_inserir_ordenado(Lista *lst, int v)
{
	Lista *p = lst;
	Lista *ant = NULL;
	
	while(p != NULL && p->valor < v)
	{
		ant = p;
		p = p->proximo;
	}
	
	Lista *novo = (Lista *) malloc(sizeof(Lista));
	novo->valor = v;
	
	if(ant == NULL)
	{
		novo->proximo = lst;
		lst = novo;
	}
	else
	{
		novo->proximo = ant->proximo;
		ant->proximo = novo;
	}
	
	return lst;
	
}

int main()
{
	Lista *lst1 = lst_criar();
	
	if (lst1 == NULL)
		{
			printf("Nulo\n");
		}
		
	lst1 = lst_inserir(lst1, 15);

	lst1 = lst_inserir(lst1, 25);
	lst1 = lst_inserir(lst1, 13);
	
	lst_imprimir(lst1);
	
	/*Lista *busca =  lst_buscar(lst1, 25);
	
	if(!lst_vazia(busca))
	{
		printf("Valor encontrado: %d\n", busca->valor);
	}
	
	lst1 = lst_retirar(lst1, 27);*/
	
	lst_imprimir(lst1);
	
	/*lst1 = lst_liberar(lst1);
	
	if(lst_vazia(lst1))
	{
		printf("Lista vazia!");
	}*/
	
	return 0;
}
