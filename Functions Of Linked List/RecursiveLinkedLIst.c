#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
	int number;
	struct node *next;
} node;

void add_end(node **list, int n);
void print_list(node *list);
void free_list(node **list);
node *search_node(node *list, int n);

int main(int argc, char *argv[])
{
}

void add_end(node **list, int n)
{
	node *new_node = NULL;

	if (*list == NULL) 
	{
		node *new_node = (node *) malloc(sizeof(node));
		if (!new_node) return;
		new_node->number = n;
		new_node->next = NULL;
	
		*list = new_node;	
	}
	else
	{
		add_end(&(*list)->next, n);
	}
}

void print_list(node *list)
{
	if (list == NULL) printf("Lista vazia!");
	else
	{
		printf("%d\n", list->number);
		print_list(list->next);
	}
}

void free_list(node **list)
{
	if (list == NULL) return;
	else
	{
		free(&(*list)->next);
		(*list)->next = NULL;
		free(list);
		*list =
	}
}

node *search_node(node *list, int n)
{
	if (list == NULL) 
	{
		printf("Não encontrado!\n");	
	}
	else
	{
		if (list->number == n) return list;
		search_node(list->next, n);
	}
}


