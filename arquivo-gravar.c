/*
    Programa que grava em um arquivo o que foi digitado pelo usuário
    via teclado(stdin);
    
    O nome desse arquivo é informado pelo usuário via teclado(stdin);
    
    Feito por Marcus em 02/10/2020;
    
*/

#include <stdio.h>

/* --- variáveis externas --- */

const int MAXA = 50;    /* Tamanho máximo para nome do arquivo */

int 
main()
{
    char arq[MAXA]; /* Nome do arquivo */
    FILE *f = NULL; /* Arquivo associado a arq[] */
    char c = 0;         /* Caractere para escrever as letras */
 
    printf ("Digite o nome do arquivo: ");
    scanf ("%s", arq);
 
    f = fopen (arq, "a");
 
    if(f == NULL)
    {
        printf ("%s nao foi aberto\n", arq);
        return 5;
    }

    printf ("Digite algo: ");

    scanf ("%c", &c); 
    
    do
    {
        scanf ("%c", &c);
        fputc (c, f);
    } while (c != '\n');
 
    fclose(f);
 
return 0;
}