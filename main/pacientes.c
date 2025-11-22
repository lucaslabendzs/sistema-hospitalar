#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacientes.h"

// Lucas - função de criação de criar paciente
Paciente* criarPaciente(int id, char*nome, int idade, char*sintoma){ 
    // verifica se já existe paciente com esse ID
    if (buscarPacientePorID(id) != NULL) {
        printf("Erro: ja existe um paciente com ID %d\n", id);
        return NULL;  // impede criação duplicada
    }

    Paciente* p = (Paciente*) malloc(sizeof(Paciente));    // faz alocação de memória necessária para um novo Paciente

    // verifica se a alocação de memória realmente foi realizada corretamente
    if(p == NULL){
        printf("Erro ao alocar memoria\n");
        return NULL;  // retorna erro caso a alocação falhe
    }

    p->id = id; // atribui valor do ID
    strcpy(p->nome, nome); // copia o nome passado para o campo nome do struct
    p->idade = idade; // atribui idade do paciente
    strcpy(p->sintoma, sintoma); // copia o sintoma para o campo sintoma do struct
    p->prioridade = -1; // inicializa prioridade como -1 (ainda não classificado)
    p->tempoAtendimento = 0; // inicializa o tempo de atendimento
    p->prox = NULL; // inicializa o ponteiro para o próximo paciente como NULL

    // adiciona o paciente à lista global de pacientes
    adicionarPacienteLista(p);

    return p;  // retorna o novo paciente criado
}
//Kauan
// Lista global de pacientes (armazenamento simples em memória)
// Ponteiro que sempre aponta para o início da lista ligada de pacientes
static Paciente *listaPacientes = NULL;
//Kauan
void inicializarLista(void){
    listaPacientes = NULL;  // reinicia a lista (útil no início do programa)
}
//Kauan
void adicionarPacienteLista(Paciente *p){
    if (p == NULL) return;  // segurança: evita inserir ponteiros inválidos
    p->prox = listaPacientes;  // novo paciente aponta para o antigo primeiro
    listaPacientes = p;        // novo paciente vira o primeiro da lista
}
//Renan - Busca pacientes na lista global
Paciente* buscarPacientePorID(int id){
    Paciente *atual = listaPacientes;  // começa no início da lista
    while (atual != NULL) {            // percorre toda a lista
        if (atual->id == id) {         // se o ID bater
            return atual;              // retorna o paciente encontrado
        }
        atual = atual->prox;           // avança para o próximo nó da lista
    }
    return NULL; // não encontrou nenhum paciente com o ID informado
}
