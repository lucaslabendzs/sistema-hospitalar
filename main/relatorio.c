#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pacientes.h"
#include "relatorio.h"

// Exibir pacientes atendidos por prioridade
void atendimentoPrioridade(FilaAtendido *fa)
{   
    for(int i = 0; i < 5; i++){
    Paciente* pos = fa->inicio[i];

    if(fa->tamanho[i] == 0){
    printf("Nenhum paciente foi atendido na prioridade %d!\n", i+1);
    continue;
    } 
    printf("==== Pacientes Atendidos Prioridade %d ====\n", i+1);

     while (pos != NULL){
        printf("ID: %d  Nome: %s   Idade: %d  Sintomas: %s  Tempo de espera: %d minutos\n", pos->id, pos->nome, pos->idade, pos->sintoma, pos->tempoAtendimento); // exibe os dados do paciente
        pos = pos->prox;
    }
}
}

// Calculo do tempo medio de atendimento por prioridade
void tempoMedio(FilaAtendido *fa, int numero)
{
    int idx = numero - 1;
    if (idx < 0 || idx > 4) {
        printf("Numero de prioridade invalido. Use 1 a 5.\n");
        return;
    }
    if(fa->fim[idx] == NULL){
        printf("ninguem foi atendido nesta prioridade, entao o tempo medio eh 0\n");
        return;
    }
    int media = fa->somaTempo[idx] / fa->tamanho[idx];
    printf("Tempo medio de atendimento da prioridade %d = %d minutos\n", numero, media);
    
}

// Exibe o total de pacientes atendidos em cada nivel
void pacientesPorNivel(FilaAtendido* fa){
    for(int i = 0; i < 5; i++){
    printf("Prioridade %d:  %d Pacientes atendidos.\n", i+1, fa->tamanho[i]);
    }
}