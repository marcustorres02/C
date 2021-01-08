/*
    Esse programa apresenta as iniciais das palavras digitadas por um usuário,
    essas palavras tem o limite de 99 caracteres + \0;
    O dado de entrada é ou são as palavras que o usuário digitar;
    Esse dado é capturado por meio de um scanf() com o formato %c;
    Esses caracteres serão armazenadas em um array unidimensional de 100 posições;
    Feito por Marcus Vinícius Torres Silva em 04/09/2020.
*/
#include <stdio.h>

const int MAX = 100;    /* Limite de posições. */

int 
main()
{
    unsigned char palavra[MAX]; // Array para armazenar os caracteres.
    int c = 0;                  // Indexador.
   
    // Lendo os caracteres que o usuário digitar através de um laço de repetição.
   
    printf ("Digite uma palavra ou mais palavras: ");
    
    do
    {
        scanf ("%c",&palavra[c]);
        if (palavra[c] == '\n')     
        {
            palavra[c] = '\0';
            break;              
        }
        c++;
    } while (palavra[c] != '\n');
    
    // Mostrando na tela as iniciais das palavras
    c = 0;
    
    printf ("%c",palavra[c]);
    
    while (palavra[c] != '\0')
    {
        if (palavra[c] == ' ')
        {
           printf ("%c",palavra[c+1]);
        }
        c++;
    }
    
    return 0;
}
