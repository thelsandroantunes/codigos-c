#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "dicio_string_encadeado.h"

struct elt {
    struct elt *prox;
    char *chave;
    char *val;
};

struct dicio {
    int tam;
    int n;
    struct elt **tabela;
};

#define INITIAL_SIZE (20)
#define GROWTH_FACTOR (2)
#define MAX_LOAD_FACTOR (1)

Dicio intoDicioCriar(int tam)
{
    Dicio d;
    int i;

    d = malloc(sizeof(*d));

    assert(d != 0);

    d->tam = tam;
    d->n = 0;
    d->tabela = malloc(sizeof(struct elt *) * d->tam);

    assert(d->tabela != 0);

    for(i = 0; i < d->tam; i++) d->tabela[i] = 0;

    return d;
}

Dicio dicioCriar(void)
{
    return intoDicioCriar(INITIAL_SIZE);
}

void dicioDestruir(Dicio d)
{
    int i;
    struct elt *e;
    struct elt *prox;

    for(i = 0; i < d->tam; i++) {
        for(e = d->tabela[i]; e != 0; e = prox) {
            prox = e->prox;

            free(e->chave);
            free(e->val);
            free(e);
        }
    }

    free(d->tabela);
    free(d);
}

#define MULTIPLIER (97)

static unsigned long
hash_function(const char *s)
{
    unsigned const char *us;
    unsigned long h;

    h = 0;

    for(us = (unsigned const char *) s; *us; us++) {
        h = h * MULTIPLIER + *us;
    }

    return h;
}

static void grow(Dicio d)
{
    Dicio d2;
    struct dicio swap;
    int i;
    struct elt *e;

    d2 = intoDicioCriar(d->tam * GROWTH_FACTOR);

    for(i = 0; i < d->tam; i++) {
        for(e = d->tabela[i]; e != 0; e = e->prox) {
            dicioInserir(d2, e->chave, e->val);
        }
    }

    swap = *d;
    *d = *d2;
    *d2 = swap;

    dicioDestruir(d2);
}

void dicioInserir(Dicio d, const char *chave, const char *val)
{
    struct elt *e;
    unsigned long h;

    assert(chave);
    assert(val);

    e = malloc(sizeof(*e));

    assert(e);

    e->chave = strdup(chave);
    e->val = strdup(val);

    h = hash_function(chave) % d->tam;

    e->prox = d->tabela[h];
    d->tabela[h] = e;

    d->n++;

    if(d->n >= d->tam * MAX_LOAD_FACTOR) {
        grow(d);
    }
}

const char *dicioBuscar(Dicio d, const char *chave)
{
    struct elt *e;

    for(e = d->tabela[hash_function(chave) % d->tam]; e != 0; e = e->prox) {
        if(!strcmp(e->chave, chave)) {

            return e->val;
        }
    }

    return 0;
}

void dicioDeletar(Dicio d, const char *chave)
{
    struct elt **ant;
    struct elt *e;

    for(ant = &(d->tabela[hash_function(chave) % d->tam]);
        *ant != 0;
        ant = &((*ant)->prox)) {
        if(!strcmp((*ant)->chave, chave)) {

            e = *ant;
            *ant = e->prox;

            free(e->chave);
            free(e->val);
            free(e);

            return;
        }
    }
}

void dicioImprimir(Dicio d) {

    int i;
    struct elt *e;
    struct elt *prox;

    for(i = 0; i < d->tam; i++) {
        printf(" [%d] : ", i);
        for(e = d->tabela[i]; e != 0; e = prox)
        {
            prox = e->prox;
            printf(" %s -> ", e->val);
        }
        printf("\n");
    }
}
