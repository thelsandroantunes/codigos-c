/*  Autor: Thelsandro Costa Antunes
*   Data: 25/01/2021
*   EXERCÍCIO TABELA HASH ENCADEADA
*   Questao: Faça um programa com lista encadeada na tabela hash de alunos com matrículas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define M 19

typedef struct {
    int matricula;
    char nome[50];
} Pessoa;

typedef struct no {
    Pessoa pessoa;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
    int tam;
} Lista;

Lista *tabela[M];
void imprimirTabela();
Pessoa* buscarPessoaTabela(int);
void inserTabela();
int funcaoEspalhamento(int);
void inicializar();
void imprimirLista(No*);
No* buscarNo(int, No*);
Lista* criarLista();
void imprimirPessoa(Pessoa);
Pessoa criarPessoa();



int main() {

    setlocale (LC_ALL, "portuguese");

    int op, mat;
    Pessoa *p;
    inicializar();
    do {
        printf("\n0 - Sair\n1 - Inserir\n2 - Buscar\n3 - Imprimir tabela\n");
        scanf("%d", &op);
        switch(op) {
        case 0:
            printf("saindo...\n");
            break;
        case 1:
            inserTabela();
            break;
        case 2:
            printf("Qual a matricula a ser buscada? ");
            scanf("%d", &mat);
            p = buscarPessoaTabela(mat);
            if(p) {
                printf("Pessoa encontrada: Matricula: %d\tNome: %s", p->matricula, p->nome);
            } else
                printf("Pessoa nao contrada!\n");
            break;
        case 3:
            imprimirTabela();
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while(op != 0);
    return 0;
}

Pessoa criarPessoa() {
    Pessoa p;
    printf("Digite o nome da pessoa: ");
    scanf("%*c");
    fgets(p.nome, 50, stdin);
    printf("Digite a matricula: ");
    scanf("%d", &p.matricula);
    return p;
}

void imprimirPessoa(Pessoa p) {
    //printf("[%d, %s] -> ", p.matricula, p.nome);
    printf(" {MAT:[%d] NOME:[%s]} -->", p.matricula, p.nome);
}
Lista* criarLista() {
    Lista *l = malloc(sizeof(Lista));
    l->inicio = NULL;
    l->tam = 0;
    return l;
}
void inserirInicio(Pessoa p, Lista *lista) {
    No *no = malloc(sizeof(No));
    no->pessoa = p;
    no->proximo = lista->inicio;
    lista->inicio = no;
    lista->tam++;
}
No* buscarNo(int mat, No *inicio) {
    while(inicio != NULL) {
        if(inicio->pessoa.matricula == mat)
            return inicio;
        else
            inicio = inicio->proximo;
    }
    return NULL;// matricula não encontrada
}
void imprimirLista(No *inicio) {
    while(inicio != NULL) {
        imprimirPessoa(inicio->pessoa);
        inicio = inicio->proximo;
    }
    printf("NULL\n");
}
void inicializar(){
    int i;
    for(i = 0; i < M; i++)
        tabela[i] = criarLista();
}
int funcaoEspalhamento(int mat){
    return mat % M;
}
void inserTabela(){
    Pessoa pes = criarPessoa();
    int indice = funcaoEspalhamento(pes.matricula);
    inserirInicio(pes, tabela[indice]);
}
Pessoa* buscarPessoaTabela(int mat){
    int indice = funcaoEspalhamento(mat);
    No *no = buscarNo(mat, tabela[indice]->inicio);
    if(no)
        return &no->pessoa;
    else
        return NULL;
}
void imprimirTabela(){
    int i;
    printf("\n---------------------TABELA-------------------------\n");
    for(i = 0; i < M; i++){
        printf("[%d] :  colisões %d \n", i, tabela[i]->tam);
        imprimirLista(tabela[i]->inicio);
    }
    printf("---------------------FIM TABELA-----------------------\n");
}
