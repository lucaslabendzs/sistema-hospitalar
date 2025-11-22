#ifndef FILA_H
#define FILA_H
#include <stdbool.h>
#include "pacientes.h"

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
    int totalAtendimentos[5];
}FilaAtendido;


//protótipo das funções

//Renan - Inicializar a fila
void inicializar(Fila *paciente);
// Lucas - Inicializar estrutura de atendidos
void inicializarAtendido(FilaAtendido *fa);
// Leticia - Verificação da fila vazia
bool vazia(Fila *f);
// Kauan - Enfileirar paciente na fila da sua prioridade
bool enfileirar(Fila *f, Paciente *p);
// Kauan - adiciona na fila de atendidos
void adicionarAtendido(FilaAtendido *fa, Paciente *p);
// Lucas - Remover paciente da fila após atendimento
bool pacienteAtendido(Fila *f, FilaAtendido *fa);
//Leticia - Retornar o tamanho da fila
int tamanho_fila(Fila *f);
//Renan - Exibir fila de espera
void exibir(Fila *f);
//Lucas - Limpar filas de espera
void limpar(Fila *f);

#endif