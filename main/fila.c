#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pacientes.h"
#include <stdbool.h>


//Renan - Inicializar a fila
void inicializar(Fila *f){
    for(int i=0; i<5; i++){
    f->inicio[i] = NULL;
    f->fim[i] = NULL;
    f->tamanho[i] = 0;
    }
}
// Inicializar estrutura de atendidos
void inicializarAtendido(FilaAtendido *fa){
    for(int i=0; i<5; i++){
        fa->inicio[i] = NULL;
        fa->fim[i] = NULL;
        fa->tamanho[i] = 0;
        fa->somaTempo[i] = 0;
        fa->totalAtendimentos[i] = 0;
    }
}
// Leticia - Verificação da fila vazia
bool vazia(Fila *f){
    int soma = 0;
    for (int i = 0; i < 5; i++) soma += f->tamanho[i];
    return (soma == 0); // retorna true se a fila estiver vazia
}

// Kauan - Enfileirar paciente na fila da sua prioridade
bool enfileirar(Fila *f, Paciente *p){
    if(f == NULL || p == NULL){ // verifica se a fila ou o paciente são nulos
        printf("nao existem pacientes na fila!\n");
        return false;
    }
    int prioridade = p->prioridade - 1;
    if (prioridade < 0) prioridade = 0;
    if (prioridade > 4) prioridade = 4;
    p->prox = NULL;
    if(f->fim[prioridade] == NULL){ //caso esteja vazia a fila
        f->fim[prioridade] = f->inicio[prioridade] = p; //inicio e fim apontam para o novo paciente
    }
    else{
        f->fim[prioridade]->prox = p; // o próximo do fim atual aponta para o novo paciente
        f->fim[prioridade] = p; // o fim da fila agora é o novo paciente
    }
    f->tamanho[prioridade]++; // incrementa o tamanho da fila
    return true;
}
//adiciona na fila de atendidos - Kauan
void adicionarAtendido(FilaAtendido *fa, Paciente *p){
    int pr = p->prioridade - 1;
    p->prox = NULL;

    if (pr < 0) pr = 0;
    if (pr > 4) pr = 4;

    if (fa->fim[pr] == NULL) {
        fa->inicio[pr] = fa->fim[pr] = p;
    } else {
        fa->fim[pr]->prox = p;
        fa->fim[pr] = p;
    }

    //atualizar as estatisticas ja
    fa->totalAtendimentos[pr]++;
    fa->somaTempo[pr] += p->tempoAtendimento;
    fa->tamanho[pr]++;
} 
// Lucas - Remover paciente da fila após atendimento
bool pacienteAtendido(Fila *f, FilaAtendido *fa) {
    int prioridade = -1;

    // Encontrar fila mais urgente (verifica do índice mais alto ao mais baixo)
    for (int i = 4; i >= 0; i--) {
        if (f->inicio[i] != NULL) {
            prioridade = i;
            break;
        }
    }

    if (prioridade == -1) {
        printf("\nNao existem pacientes na fila!!\n");
        return false;
    }

    Paciente *atual = f->inicio[prioridade];

    printf("\nPaciente %s atendido!!\nQuanto tempo ele levou para ser atendido? ", atual->nome);
    scanf("%d", &atual->tempoAtendimento);

    // Remove da fila de espera
    f->inicio[prioridade] = atual->prox;
    if (f->inicio[prioridade] == NULL)
        f->fim[prioridade] = NULL;

    f->tamanho[prioridade]--;

    // Adiciona na fila de atendidos por prioridade
    adicionarAtendido(fa, atual);
    return true;
}

// Renan - Consultar o elemento na frente da fila sem removê-lo
bool frente(Fila *f, int prioridade){
    if(vazia(f)){
        printf("Esta vazia, nao tem elementos para consultar.\n");
        return false;
    }
    
    if (prioridade < 0 || prioridade > 4){
        for (int i = 0; i < 5; i++){
            if (f->inicio[i] != NULL){
                prioridade = i;
                break;
            }
        }
    }
    
    if (f->inicio[prioridade] != NULL){
        printf("ID: %d  Nome: %s\n", f->inicio[prioridade]->id, f->inicio[prioridade]->nome); //exibe id e nome do paciente
    }
    
    return true;
}


//Leticia - Retornar o tamanho da fila
int tamanho_fila(Fila *f){
    int soma = 0;
    for (int i = 0; i < 5; i++) soma += f->tamanho[i];
    return soma; // retorna o tamanho total das filas
}

//Kauan - Exibir fila de espera
void exibir(Fila *f){
    if (vazia(f)){
        printf("Fila de espera vazia\n");
        return; // sai da função se as filas estiver vazias
    }

    for(int i = 0; i < 5; i++){
        Paciente* pos = f->inicio[i]; // posição inicial da fila
        printf("Prioridade %d\n", i+1);

        if (pos == NULL) continue; // se a fila estiver vazia pula pra proxima

        printf("==== Fila de espera ====\n");

        while (pos != NULL){
            printf("Nome: %s   Idade: %d  Sintomas: %s\n", pos->nome, pos->idade, pos->sintoma); // exibe os dados do paciente
            pos = pos->prox;
        }
    }
}

//Lucas - Limpar filas de espera
void limpar(Fila *f){
    inicializar(f);
    printf("fila limpa!");
}














