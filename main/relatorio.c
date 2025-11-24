#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pacientes.h"
#include "relatorio.h"

// Lucas - Exibir pacientes atendidos por prioridade
void atendimentoPrioridade(FilaAtendido *fa)
{   
    //Percorre todos as 5 prioridade
    for(int i = 0; i < 5; i++){

    //Ponteiro para o primeiro paciente da fila dessa prioridade
    Paciente* pos = fa->inicio[i];
    
    //verifica se não há pacientes armazenados nessa prioridade
    if(fa->tamanho[i] == 0){
    printf("Nenhum paciente foi atendido na prioridade %d!\n", i+1);
    continue;//passa para a proxima prioridade


    }
    // cabeçalho para exibição para a prioridade atual 
    printf("==== Pacientes Atendidos Prioridade %d ====\n", i+1);

    //Pecorre todos os pacientes que estão na lista dessa prioridade
     while (pos != NULL){
        //Exibe os dados completos do paciente 
        printf("ID: %d  Nome: %s   Idade: %d  Sintomas: %s  Tempo de espera: %d minutos\n", pos->id, pos->nome, pos->idade, pos->sintoma, pos->tempoAtendimento); // exibe os dados do paciente
        //Avança para o próximo paciente da fila
        pos = pos->prox;
    }
}
}

// Renan - Calculo do tempo medio de atendimento por prioridade
void tempoMedio(FilaAtendido *fa, int numero)
{
    int idx = numero - 1;//converte a prioridade para o indice do vetor

    if (idx < 0 || idx > 4) {
        printf("Numero de prioridade invalido. Use 1 a 5.\n");
        return;
    }

    if(fa->fim[idx] == NULL){ //Se ninguém foi atendido nessa prioridade
        printf("ninguem foi atendido nesta prioridade, entao o tempo medio eh 0\n");
        return;
    }

    int media = fa->somaTempo[idx] / fa->tamanho[idx]; //Tempo total dividido por paciente
    printf("Tempo medio de atendimento da prioridade %d = %d minutos\n", numero, media);
    
}

// Leticia - Exibe o total de pacientes atendidos em cada nivel
void pacientesPorNivel(FilaAtendido* fa){
    for(int i = 0; i < 5; i++){
    printf("Prioridade %d:  %d Pacientes atendidos.\n", i+1, fa->tamanho[i]);
    }
}