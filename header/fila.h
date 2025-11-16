#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

//estrutura da fila
typedef struct {
    Paciente* inicio[5];
    Paciente* fim[5];
    int tamanho[5];
}Fila;

typedef struct {
    Paciente* inicio[5];
    Paciente* fim[5];
    int tamanho[5];
    int somaTempo[5];
}FilaAtendido;


//protótipo das funções
void inicializar(Fila *paciente);
bool vazia(Fila *f);
bool enfileirar(Fila *f);
void adicionarAtendido(FilaAtendido *fa, Paciente *p);
bool pacienteAtendido(Fila *f);
bool frente(Fila *f, int id);
int tamanho_fila(Fila *f);
void exibir(Fila *f);
void limpar(Fila *f);

#endif