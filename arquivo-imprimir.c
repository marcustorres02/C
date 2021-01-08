/*
    Programa que apresenta na tela do computador o conteúdo de um arquivo;
    
    O nome desse arquivo é informado pelo usuário via teclado(stdin);
    
    Feito por Marcus em 02/10/2020;
    
*/

#include <stdio.h>

/* --- variáveis externas --- */

const int MAXA = 50;    /* Tamanho máximo para nome do arquivo */

int
main()
{
    FILE *f = NULL;     /* Arquivo associado a arq[] */
    char arq[MAXA];     /* Nome do arquivo */
    char car = 0;	    /* Caractere que armazena o conteúdo do arquivo */
    
    printf ("Digite o nome do arquivo: ");
    scanf ("%s", arq);
    
    f = fopen (arq, "r");
    
    if (f == NULL)
    {
        printf ("Arquivo %s nao foi aberto", arq);    
        return 5;
    }
    
    while ( (car = fgetc (f)) != EOF )
    {
        fprintf (stdout, "%c", car);
    }
    printf ("\n");
    
    fclose(f);
    
    return 0;
}