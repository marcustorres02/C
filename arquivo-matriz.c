/*
    Programa que apresenta os valores de uma matriz N X N e dados sobre 
    a matriz;
    
    Os dados de entrada são passados por meio de uma arquivo, o qual seu nome
    é informado pelo usuário via teclado (stdin);
    
    Feito por Marcus em 03/10/2020.
    
*/

#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

/* --- variáveis externas --- */

const int MAX = 10;  /* Tamanho máximo para matriz */ 
const int MAXA = 50;    /* Tamanho máximo para nome do arquivo */

/* --- protótipos --- */

void dp(int o, int array[][MAX]);
void ds(int o, int array[][MAX]);
int tl(int o, int array[][MAX]);

int
main()
{
    FILE *f = NULL;     /* Arquivo associado a arq[] */
    char arq[MAXA];     /* Nome do arquivo */
    int mA[MAX][MAX];   /* Array que representa a matriz */
    int N = 0;          /* Ordem da matriz */
    char op[MAXA];      /* Opção para interação */
    int i, j;           /* Indexadores */
   
    printf ("Digite o nome do arquivo: ");
    scanf ("%s", arq);
    printf ("\n");
    
    f = fopen (arq, "r");
    
    if (f == NULL)
    {
        printf ("arquivo %s nao foi aberto", arq);
        return 5;
    }
    
    fscanf(f, "%d", &N);
    
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            fscanf (f, "%d", &mA[i][j]);
            printf ("%d\t", mA[i][j]);
        }
        printf ("\n");
    }
    
    do 
    {
        printf ("\nDP - matriz, DS - diagonal secundaria, TotalLinha - Soma e Sair\n\n");
        printf ("Digite a sua opcao: ");
        scanf ("%s", op);
        printf ("\n");
        
        if (strcmp (op, "DP") == 0)
        {
            dp (N, mA);
            printf ("\n");
        }
        else if (strcmp (op, "DS") == 0)
        {
            ds (N, mA);
            printf ("\n");
        }
        else if (strcmp (op, "TotalLinha") == 0)
        {
            tl (N, mA);
            printf ("\n");
        }
        
        __fpurge(stdin);
        
    } while (strcmp (op, "Sair") != 0 );
    
    fclose (f);
      
    return 0;
}

/*
    dp
    -----
    Função que mostra a Diagonal Principal(DP) da matriz
*/

void
dp(int o, int array[][MAX])
{
    int i;      /* Linha da matriz */
    int j = 0;  /* Coluna da matriz */
    
    for(i = 0; i < o; i++, j++)
    {
        printf("%d ",array[i][j]);
    }
    
}

/*
    ds
    -----
    Função que mostra a Diagonal Secundária(DS) da matriz
*/

void
ds(int o, int array[][MAX])
{
    int i;      /* Linha da matriz */
    int j = 0;  /* Coluna da matriz */
    
    for(i = o - 1; j < o; --i,j++)
    {
        printf ("%d  ", array[i][j]);
    }
}

/*
    tl
    -----
    Função que faz a soma dos valores da linha digitada pelo usuário
    e retorna essa soma
*/

int
tl(int o, int array[][MAX])
{
    int X = 0;      /* Linha que o usuário quer */
    int i;          /* Linha da matriz */
    int j = 0;      /* Coluna da matriz */
    int soma = 0;   /* Soma dos valores da linha */
    
    printf ("Digite a linha desejada: ");
    scanf ("%d", &X);
    
    for(i = X - 1; j < o; j++)
    {
        soma = soma + array[i][j];
    }
    printf ("\n%d", soma);
    
    return soma;
}