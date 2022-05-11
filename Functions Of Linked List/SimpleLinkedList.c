#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
  int number;
  struct node *next;
} node;

void add_beginning(int n, node **list);
void add_end(int n, node **list);
void print_list(node *list);
void free_list(node *list);
void free_end(node *list);
bool exist_node(int n, node *list);
int search_list(int n,node *list);

int main (void)
{
  node *list = (node *) malloc(sizeof(node));
  if (!list) return -1;
  list = NULL;

}

bool exist_node(int n, node *list)
{
  if (list == NULL) return false;
  if (list->number == n) return true;
  exist_node(n, list->next);
}

void add_beginning(int n, node **list)
{
  node *tmp = (node *) malloc(sizeof(node));
  if (!tmp) return;

  tmp->number = n;
  tmp->next = *list;
  *list = tmp;
}

void add_end(int n, node **list)
{
  node *new_node = (node *) malloc(sizeof(node));
  if (!new_node) return;

  new_node->number = n;
  new_node->next = NULL;
  if (*list == NULL) list = new_node;
  else
  {
    node *tmp = *list;
    while (tmp->next != NULL)
      {
        tmp = tmp->next;
      }
    tmp->next = new_node;
  }
}

void print_list(node *list)
{
  while (list != NULL)
    {
      printf("%d\n", list->number);
      list = list->next;
    }
}

void free_list(node *list)
{
  node *tmp = list;
  while (list != NULL)
    {
      tmp = list->next;
      free(list);
      list = tmp;
    }
}

void free_beginning(node *list)
{
  node *tmp = list;
  tmp = list->next;
  free(list);
  list = tmp;
}

void free_end(node *list)
{
  while (list->next->next != NULL)
    {
      list = list->next;
    }
  free(list->next);
  list->next = NULL;
}

int search_list(int n,node *list)
{
  node *tmp = list;
  int index = 1;
  if (!exist_node(n, list)) return -1;
  while (tmp->number != n)
    {
      tmp = tmp->next;
      index++;
    }
  return index;
}
