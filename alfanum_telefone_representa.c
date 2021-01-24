/*  Autor: Thelsandro Costa Antunes
*   Data: 24/01/2021
*   EXERCÍCIO REPRESENTAÇÃO ALFANUMÉRICA DE TELEFONE
*   Questao: Considere que uma representação alfanumérica de um número de telefone é uma sequência de
*            caracteres tal que cada caractere pode ser: uma letra maiúscula (de A a Z), um hifen (-) ou um
*            dígito 1 ou tt 0, sendo que letras maiúsculas representam dígitos de 2 a 9, de acordo com a tabela
*            abaixo:
*
*            _____________________________
*               Letras    -     Números
*            _____________________________
*               ABC       -     2
*               DEF       -     3
*               GHI       -     4
*               JKL       -     5
*               MNO       -     6
*               PQRS      -     7
*               TUV       -     8
*               WXYZ      -     9
*            _____________________________
*
*            Escreva um programa que leia várias linhas, cada linha contendo
*            uma tal representacão alfanumérica de número de telefone, e imprima
*            uma sequência de representações para os números de telefone, novamente
*            uma em cada linha, que substitua letras maiúsculas por dígitos de acordo com
*            a tabela mostrada. Considere que cada representacão alfanumérica possui entre
*            1 e 30 caracteres. A entrada é terminada por fim de arquivo (EOF).
*
*            Por exemplo, para a entrada:
*
*               1-HOME-SWEET-HOME
*               MY-MISERABLE-JOB
*
*            A saída deve ser:
*
*               1-4663-79338-4663
*               69-647372253-562
*
*/


#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

const int n = 26; // Número de letras maiúsculas

char* mkCodLetras() {
    char i='A', codigo ='2', *cod=malloc(n*sizeof(char));
    int j, k;
    while (i<='W') {
        k = (i == 'P' || i == 'W')? 4 : 3;
        for (j=0; j<k; j++)
            cod[i-'A'+j] = codigo;
        codigo++;
        i+=k;
    }
    return cod;
}

int main()
{
    setlocale (LC_ALL, "portuguese");

    const int max = 31; // 31 devido a terminação com '\0'
    char *codLetras = mkCodLetras(), *exp = malloc(max*sizeof(char));
    int numValLidos;

    while(1)
    {
        numValLidos = scanf ("%s", exp);
        if(numValLidos != 1)
            break;
        int i = 0,
        c_A;
        char c;

        while(exp[i] != '\0')
        {
            c = exp[i];
            c_A = c-'A';
            printf("%c", c_A>=0 && c_A<n? codLetras[c_A] : c);
            i++;
        }

        printf ("\n");
    }


    system("pause");
    return 0;
}
