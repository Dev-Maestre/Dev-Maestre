// fopen() cria ou abre um arquivo
// fclose() fecha um arquivo
// getc() le um caracter de um arquivo
// puts() escreve uma string em um arquivo
// fprintf() escreve um conjunto de dados em um arquivo
// fscanf() le um conjunto de dados de um arquivo

// 'r' abre um arquivo para leitura (se ele nao existir, recebera um erro)
// 'w' cria um arquivo de texto para escrita (se ja existir, é substituido)
// 'a' para adicionar conteudo no fim de um arquivo existente (se ele nao existe, é criado)

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int nd, carga;
    char disciplina[15];
    FILE *fp;
    fp = fopen("entrada.txt ", "a");
    if(fp==NULL) {
        printf('erro\n');
        exit(1); // aborta o programa
    }
    printf("\nQuantas disciplinas serão gravadas: ");
    scanf("%d", &nd);
    for(int i=0; i<nd; i++) {
        printf("\nInforme a disciplina: ");
        scanf("%s", &disciplina);
        printf("\nInforme a carga horaria: ");
        scanf("%d", &carga);
        fprintf(fp, "%s %d\n", disciplina, carga);
    }
    fclose(fp);
    fp = fopen("entrada.txt", "r");
    while(!feof(fp)) {
        fscanf(fp, "%s %d", &disciplina, &carga);
        if(!feof(fp)) {
            printf("\n%s %d", disciplina, carga);
        }
    }
    fclose(fp);
    return 0;
}

#include<stdio.h>
typedef struct aluno
{
    int ra;
    char nome[15];
    float rendafamiliar;
}TAluno;

int main()
{
FILE *arq;
TAluno aluno1;
int cont=0, na;
//arq = fopen("alunos.txt", "w");
arq = fopen("alunos.txt", "a");
if (arq==NULL) {
printf("Erro na abertura do arquivo.\n");
}
printf("Quantos alunos deseja cadastrar:");
scanf("%d",&na);
while(cont<na)
{
  printf("Informe Ra:");
  scanf("%d",&aluno1.ra);
  printf("Informe Nome:");
  scanf("%s",&aluno1.nome);
  printf("Informe Renda familiar:");
  scanf("%f",&aluno1.rendafamiliar);
  cont++;
  fprintf(arq,"%d %s %f\n",aluno1.ra,aluno1.nome,aluno1.rendafamiliar);
}
fclose(arq);
printf("Lendo dados do arquivo...\n");
arq=fopen("alunos.txt","r");
while(!feof(arq))
{

  fscanf(arq,"%d %s %f",&aluno1.ra,aluno1.nome,&aluno1.rendafamiliar);
  if(feof(arq)) break;//para n�o repeti o �ltimo registro
  printf("Ra:%d\n",aluno1.ra);
  printf("Nome:%s\n",aluno1.nome);
  printf("Renda familiar:%f\n",aluno1.rendafamiliar);
}
fclose(arq);
return 0;
}
