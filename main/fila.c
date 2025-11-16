#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "paciente.h"
#include <stdbool.h>


//Renan - Inicializar a fila
void inicializar(Fila *f){
    for(int i=0; i<5; i++){
    f->inicio[i] = NULL;
    f->fim[i] = NULL;
    f->tamanho[i] = 0;
    }
}
// Leticia - Verificação da fila vazia
bool vazia(Fila *f){
    return(f->tamanho == 0); // retorna true se a fila estiver vazia
}

// Kauan - Enfileirar paciente na fila da sua prioridade
bool enfileirar(Fila *f){
    if(f == NULL){ // verifica se a fila ou o paciente são nulos
        printf("nao existem pacientes na fila!")
        return false;
    }
    int prioridade = p->prioridade -1;
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
void adicionarAtendido(FilaAtendido *fa, Paciente *p){
    int pr = p->prioridade;
     p->prox = NULL;

    if (fa->fim[pr] == NULL) {
        fa->inicio[pr] = fa->fim[pr] = p;
    } else {
        fa->fim[pr]->prox = p;
        fa->fim[pr] = p;
    }

    //atualizar as estatisticas ja
    fa->totalAtendimentos[pr]++;
    fa->somaTempo[pr] += p->tempoAtendimento;
} 
// Lucas - Remover paciente da fila após atendimento
bool pacienteAtendido(Fila *f, FilaAtendido *fa) {
    int prioridade = 0;

    // Encontrar fila mais urgente
    for (int i = 0; i < 5; i++) {
        if (f->inicio[i] != NULL) {
            prioridade = i;
            break;
        }
    }

    if (prioridade == 0) {
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
    free(atual);
    return true;
}

// Renan - Consultar o elemento na frente da fila sem removê-lo
bool frente(Fila *f, int id){
    if(vazia(f)){
        printf("Esta vazia, nao tem elementos para consultar.\n");
        return false;
    }
    
    if (f->inicio[i] != NULL){
        f->inicio[i]->id, f->inicio[i]->nome; //exibe id e nome do paciente
    }
    
    return true;
}


//Leticia - Retornar o tamanho da fila
int tamanho_fila(Fila *f){
    return f->tamanho; // retorna o tamanho da fila
}

//Kauan - Exibir fila de espera
void exibir(Fila *f){
    
    for(int i = 0; i < 5; i++;){
    Paciente* pos = f->inicio[i]; // posição inicial da fila
    printf("Prioridade %d", i);
    if (vazia(f)){
        printf("Fila de espera vazia\n");
        return; // sai da função se as filas estiverem vazias
    }

    printf("==== Fila de espera ====\n");

    if (pos == NULL) continue; // se a fila estiver vazia pula pra proxima
        
        while (pos != NULL){
        printf("%d  Nome: %c   Idade: %d  Sintomas: %c  Tempo de espera: %d\n", pos->id, pos->nome, pos->idade, pos->sintoma, pos->tempoAtendimento); // exibe os dados do paciente
        pos = pos->prox;
        }
    }
}

//Lucas - Limpar filas de espera
void limpar(Fila *f){
    inicializar(f);
    printf("fila limpa!");
}