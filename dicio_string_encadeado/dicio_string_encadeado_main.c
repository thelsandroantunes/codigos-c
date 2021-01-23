/*  Autor: Thelsandro Costa Antunes
*   Data: 23/01/2021
*   EXERCÍCIO TAD HASH STRING - CODE::BLOCKS
*   Questao: Faça um programa dicionário de string para string usando encadeamento.
*
*/

#include <stdio.h>
#include <assert.h>
#include <locale.h>
#include "dicio_string_encadeado.h"

int main()
{
    setlocale (LC_ALL, "portuguese");
    Dicio d;
    char buf[512];
    int i;

    d = dicioCriar();

    dicioInserir(d, "foo", "hello world");
    dicioInserir(d, "xy", "brasilai");
    dicioInserir(d, "fo", "bras");
    //puts(dicioBuscar(d, "foo"));
    //dicioImprimir(d);
    dicioInserir(d, "foo", "hello world2");
    dicioImprimir(d);

    printf("\n");
    puts(dicioBuscar(d, "xy"));

    dicioDeletar(d, "xy");
    if(dicioBuscar(d, "xy") == 0)
        printf("EXCLUÍDO\n");

    printf("\n");
    dicioImprimir(d);
    //dicioDeletar(d, "foo");
    //assert(dicioBuscar(d, "foo") == 0);
    //dicioDeletar(d, "foo");

    for(i = 0; i < 20; i++) {
        sprintf(buf, "%d", i);
        dicioInserir(d, buf, buf);
    }



    dicioDestruir(d);

    return 0;
}


