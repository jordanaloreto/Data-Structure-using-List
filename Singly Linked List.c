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
	novo->proximo = lst;
	
	return novo; 
}

void lst_imprimir(Lista *lst)
{
	Lista *aux_lst;
	
	for(aux_lst = lst; aux_lst != NULL; aux_lst = aux_lst = aux_lst->proximo)
	{
		if(aux_lst == NULL)
			printf("Nulo");
		printf("%d\n", aux_lst->valor);
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

Lista *lst_remover(Lista *lst, int v)
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

void lst_liberar(Lista *lst)
{
	Lista *p = lst;
	Lista *ant;
		
	while(p != NULL)
	{
		ant = p;
		p = p->proximo;
		free(ant);
	}

}

int lst_vazia(Lista *lst)
{
	if(lst == NULL)
	{
		return 1;
	}
	
	return 0;
}

Lista *lst_inserir_ordenado(Lista *l, int v)
{
	Lista *p = l;
	Lista *ant = NULL;
	while(p->valor<v&&p!=NULL)
	{
		ant = p;
		p = p->proximo;
	}
	Lista *novo = (Lista *) malloc(sizeof(Lista));
	novo->valor=v;
	if(ant==NULL)
	{
		novo->proximo=l;
		l=novo;
	}
	else
	{
		novo->proximo=ant->proximo;
		ant->proximo=novo;
	}
	return l;
	
}

int main()
{
	Lista *lst1 = lst_criar();
	
	if(lst_vazia(lst1))
	{
		printf("Lista vazia\n");
	}
		
	lst1 = lst_inserir_ordenado(lst1, 15);
	lst1 = lst_inserir_ordenado(lst1, 27);
	lst1 = lst_inserir_ordenado(lst1, 25);
	lst1 = lst_inserir_ordenado(lst1, 13);
	
	lst1 = lst_remover(lst1, 13);
	
	lst_imprimir(lst1);
	
    lst_liberar(lst1);
	

	
	return 0;
}
