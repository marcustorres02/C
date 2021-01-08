/*
    Programa que apresenta na tela uma sequência de caracteres
    concatenadas pelo caractere asterisco (*);
    
    Os dados de entrada estão em um arquivo, o qual seu nome será
    digitado pelo usuário via teclado(stdin);
    
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
    char car = 0;	        /* Apresentar os caracteres */
    
    printf ("Digite o nome do arquivo: ");
    scanf ("%s", arq);
    
    f = fopen (arq, "r");
    
    if (f == NULL)
    {
        printf ("Arquivo %s nao foi aberto", arq);    
        return 5;
    }
    
    printf ("\n");
    
    while ( (car = fgetc (f)) != EOF )
    {
        if (car == ' ')
        {
            printf ("*");
        }
        else
            fprintf (stdout, "%c", car);
    }
    printf ("\n");
    
    fclose(f);
    
    return 0;
}