#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node 
{
    char name[20];
    int age;
    int password;
    struct node *next;
} node;

void add_end(node **list, char *name, int age, int password); // Function to Add node at the end of queue (the last in)
node *free_preferential(node **list);
void free_beginning(node **list); // Function to remove the first node of queue (the first in need to be the first out)
void print_queue(node *list);

int main(void)
{
    int op = 0, password = 1, age = 0;
    char name[20];

    node *preferential = NULL, *list = NULL;
    do{
        printf("1- Gerar fila\n2- Adicionar Paciente\n3- Atender Paciente\n4- Atender Preferencial\n5- Imprimir fila \n6- Sair\n");
        scanf("%d", &op);

        switch (op){
            case 1:
                if (list != NULL)
                {
                    printf("\nFila ja cadastrada!\n");
                    break;
                } 
                printf("Nome do primeiro paciente: ");
                scanf("%s", name);
                printf("Idade do paciente: ");
                scanf("%d", &age);
                add_end(&list, name, age, password);
                password++;
            break;

            case 2:
                if (list == NULL)
                {
                    printf("\nFila ainda nao gerada!\n");
                    break;
                }
                printf("Nome do paciente: ");
                scanf("%s", name);
                printf("Idade do paciente: ");
                scanf("%d", &age);
                add_end(&list, name, age, password);
                password++;
            break;

            case 3:
                if (list == NULL)
                {
                    printf("\nFila vazia !\n");
                    break;
                }
                free_beginning(&list);
                printf("\nPaciente atendido\n");
            break;

            case 4:
                if (list == NULL)
                {
                    printf("\nFila vazia!");
                    break;
                }
                preferential = free_preferential(&list);
                free(preferential);
            break;

            case 5:
                if (list == NULL) printf("\nFila vazia !\n");
                print_queue(list);
            break;


        }
        

    }while (op >= 1 && op <= 5);
}

void add_end(node **list, char *name, int age, int password)
{
    node *tmp = *list;
    node *new_node = (node *) malloc(sizeof(node));
    if (new_node == NULL) return;
    strcpy(new_node->name,name);
    new_node->password = password;
    new_node->age = age;
    new_node->next = NULL;

    if (tmp == NULL)
    {
        *list = new_node;
        printf("\nFila gerada!\n\n");
        return;
    }

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    } 
    tmp->next = new_node;
    printf("Paciente adicionado!\n");
    return;

}

void free_beginning(node **list)
{
    node *tmp = *list;
    if (tmp == NULL) return;
    *list = tmp->next;
    free(tmp);
    tmp = NULL;
}


node *free_preferential(node **list)
{
    node *tmp = *list;
    node *remove = NULL;

    if (tmp->age >= 60)
    {
        remove = tmp;
        *list = remove->next;
        return remove;
    }
    while(tmp->next != NULL && tmp->next->age <= 65)
        tmp = tmp->next;
    if (tmp->next != NULL)
    {
        remove = tmp->next;
        tmp->next = remove->next;
        return remove;
    }
    // perguntar pra prof.
}

void print_queue(node *list)
{
    while (list != NULL)
    {
        printf("\nNome: %s\nSenha: %d\n", list->name, list->password);
        list = list->next;
    }
}
