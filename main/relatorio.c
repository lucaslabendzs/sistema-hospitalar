#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "paciente.h"
#include "relatorio.h"

// Exibir pacientes atendidos por prioridade
void atendimentoPrioridade(FilaAtendido *fa)
{   
    for(int i = 0; i < 5; i++){
    Paciente* pos = fa->inicio[i];

    if(fa->tamanho[i] == 0){
    printf("Nenhum paciente foi atendido nesta prioridade!\n");
    continue;
    } 
    printf("==== Pacientes Atendidos Prioridade %d ====\n", i);

     while (pos != NULL){
        printf("ID: %d  Nome: %s   Idade: %d  Sintomas: %s  Tempo de espera: %d\n", pos->id, pos->nome, pos->idade, pos->sintoma, pos->tempoAtendimento); // exibe os dados do paciente
        pos = pos->prox;
    }
}
}

void tempoMedio(FilaAtendido *fa, int numero)
{
    if(fa->fim[numero] == NULL){
        printf("ninguem foi atendido nesta prioridade, entao o tempo medio eh 0");
        return;
    }
    int media = fa->somaTempos[numero] / fa->totalAtendidos[numero];
    printf("Tempo médio de atendimento da prioridade %d = %d minutos\n", numero, media);
    
}
void pacientesPorNivel(FilaAtendido* fa){
    return fa->tamanho;
}