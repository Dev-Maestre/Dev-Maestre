#include <stdio.h>
#include <stdlib.h>

typedef struct Func
{
	char name[20];
	int age;
	int sex;
	struct Func *next;
}Func;

Func *add_func();
void create_teams(Func *func);
void free_vet(Func *func);

int main()
{
	Func *func = (Func *) malloc(sizeof(Func));
	if (!func) return -1;

	int op = 0;

	while (op > 0 || op < 4)
	{
		printf("1- Carregar arquivos de dados - Funcionário\n");
		printf("2- Distribuir funcionários nas equipes\n");
		printf("3- Sair\n");
		scanf("%d", &op);

		if (op == 1) 
		{
			func = add_func();
		}

		if (op == 2)
		{
			create_teams(func);
		}

		if (op == 3)
		{
			free_vet(func);
		}

		if (op<1) break;
		if (op>3) break;
	} 


}

Func *add_func()
{
	FILE *file;
	Func *new_func = (Func *) malloc(sizeof(Func));
	if (!new_func) exit(1);
	new_func == NULL;
	int i = 0;


	file = fopen("funcionario.txt", "r");
	if (file == NULL)
	{
		printf("Error\n");
		exit(2);
	}
	else
	{
		while (!feof(file))
		{
			fscanf(file, "%s %d %d", (new_func + i)->name, &(new_func + i)->age, &(new_func + i)->sex);
			i++;
			if (feof(file))break;
		}
	}
	printf("Dados carregados !\n");
	fclose(file);
	return new_func;
}

void create_teams(Func *func)
{
	int i = 0;
	Func *teamA = (Func *) malloc(sizeof(Func));
	if (!teamA) exit(1);

	Func *TeamB = (Func *) malloc(sizeof(Func));
	if (!TeamB) exit(1);

	Func *TeamC = (Func *) malloc(sizeof(Func));
	if (!TeamC) exit(1);


	FILE *file;
	file = fopen("funcionario.txt", "r");
	if (file == NULL)
	{
		printf("Error\n");
		exit(1);
	}
	else
	{
		while (!feof(file))
		{
			i++;
			if(feof(file)) break;
		}
	}
	if (i % 2 != 0)
	{

	}
}

void free_vet(Func *func)
{
	int  index = 0;
	FILE *file;
	file = fopen("funcionario.txt", "r");
	if (file == NULL)
	{
		printf("Error\n");
		exit(1);
	}
	else
	{
		while (!feof(file))
		{
		index++;
		if (feof(file)) break;
		}	
	}

	for (int j = 0; j < index; j++)
	{
		free (func + j);
	}

	printf("Vetores desalocados !");
}



