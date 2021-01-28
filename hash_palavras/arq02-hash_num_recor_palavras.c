/*  Autor: Thelsandro Costa Antunes
*   Data: 27/01/2021
*   EXERC�CIO HASH RECORR�NCIA DE PALAVRAS
*   Questao: Fa�a um programa em tabela hash que conte o numero de palavras.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>


#define NPAL 64 /* dimens�o m�xima de cada palavra */
#define NTAB 127 /* dimens�o da tabela de dispers�o */
/* tipo que representa cada palavra */
struct palavra {
    char pal[NPAL];
    int n; /* contador de ocorr�ncias */
    struct palavra* prox; /* colis�o com listas */
};
typedef struct palavra Palavra;
/* tipo que representa a tabela de dispers�o */
typedef Palavra* Hash[NTAB];

static int le_palavra (FILE* fp, char* s)
{
    int i = 0;
    int c;
    /* pula caracteres que n�o s�o letras */
    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c))
        break;
    }
    if (c == EOF)
        return 0;
    else
        s[i++] = c; /* primeira letra j� foi capturada */
/* l� os pr�ximos caracteres que s�o letras */
    while ( i<NPAL-1 && (c = fgetc(fp)) != EOF && isalpha(c))
        s[i++] = c;
    s[i] = '\0';

    return 1;
}

static void inicializa (Hash tab)
{
    int i;
    for (i=0; i<NTAB; i++)
        tab[i] = NULL;
}

static int hash (char* s)
{
    int i;
    int total = 0;
    for (i=0; s[i]!='\0'; i++)
        total += s[i];
    return total % NTAB;
}

static Palavra *acessa (Hash tab, char* s)
{
    Palavra* p;
    int h = hash(s);
    for (p=tab[h]; p!=NULL; p=p->prox) {
        if (strcmp(p->pal,s) == 0)
            return p;
    }
    /* insere nova palavra no inicio da lista */
    p = (Palavra*) malloc(sizeof(Palavra));
    strcpy(p->pal,s);
    p->n = 0;
    p->prox = tab[h];
    tab[h] = p;
    return p;
}
/*
fun��o para percorrer a tabela e contar o
n�mero de palavras
entrada: tabela de dispers�o
*/
static int conta_elems (Hash tab)
{
    int i;
    Palavra* p;
    int total = 0;
    for (i=0; i<NTAB; i++) {
        for (p=tab[i]; p!=NULL; p=p->prox)
            total++;
    }
    return total;
}
/*
fun��o para criar dinamicamente o vetor de ponteiros
entrada: n�mero de elementos
tabela de dispers�o
*/
static Palavra** cria_vetor (int n, Hash tab)
{
    int i, j=0;
    Palavra* p;
    Palavra** vet = (Palavra**) malloc(n*sizeof(Palavra*));
    /* percorre tabela preenchendo vetor */
    for (i=0; i<NTAB; i++) {
        for (p=tab[i]; p!=NULL; p=p->prox)
            vet[j++] = p;
    }
    return vet;
}
static int compara (const void* v1, const void* v2)
{
    Palavra** p1 = (Palavra**)v1;
    Palavra** p2 = (Palavra**)v2;
    if ((*p1)->n > (*p2)->n) return -1;
    else if ((*p1)->n < (*p2)->n) return 1;
    else return strcmp((*p1)->pal,(*p2)->pal);
}
static void imprime (Hash tab)
{
    int i;
    int n;
    Palavra** vet;
    /* cria e ordena vetor */
    n = conta_elems(tab);
    vet = cria_vetor(n,tab);
    qsort(vet,n,sizeof(Palavra*),compara);
    /* imprime ocorr�ncias */
    for (i=0; i<n; i++)
        printf("%s = %d\n",vet[i]->pal,vet[i]->n);
    /* libera vetor */
    free(vet);
}

int main(){
    setlocale (LC_ALL, "portuguese");

    FILE* fp;
    Hash tab;
    char s[NPAL];

    /* abre arquivo para leitura */
    fp = fopen("arq02-palavras.txt","r+");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        return 0;
    }
    /* conta ocorr�ncia das palavras */
    inicializa(tab);
    while (le_palavra(fp,s)) {
        Palavra* p = acessa(tab,s);
        p->n++;
    }
    /* imprime ordenado */
    imprime (tab);

    system("pause");
    return 0;
}

