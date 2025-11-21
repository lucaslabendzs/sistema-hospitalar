#include <stdio.h>
#include <string.h> 
#include "triagem.h"
#include "pacientes.h"
#include "fila.h"


int atribuirPrioridade(Fila *f, int id)
{
    // Primeiro, buscar na lista global de pacientes
    Paciente *p = buscarPacientePorID(id);
    if(p->prioridade != 1){
        printf("Paciente ja passou pela triagem");
        return -1;
    }
    if (p != NULL) {
        printf("\nSintoma do paciente %s: %s\n", p->nome, p->sintoma);
        printf("Doutor, atribua a prioridade (1 a 5):\n");
        int prioridade;
        while (1) {
            scanf("%d", &prioridade);
            if (prioridade < 1 || prioridade > 5) {
                printf("Numero invalido! Digite novamente (1 a 5): ");
            } else {
                p->prioridade = prioridade; // armazenar 1..5
                printf("Prioridade %d atribuida ao paciente %s\n", prioridade, p->nome);
                // Enfileira o paciente na fila correspondente
                enfileirar(f, p);
                return 1;
            }
        }
    }

    // Se não estava na lista global, procurar nas filas (caso ja tenha sido enfileirado)
    for (int pr = 0; pr < 5; pr++) {
        Paciente *atual = f->inicio[pr];
        while (atual != NULL) {
            if (atual->id == id) {
                printf("\nSintoma do paciente %s: %s\n", atual->nome, atual->sintoma);
                printf("Doutor, atribua a prioridade (1 a 5):\n");
                int prioridade;
                while (1) {
                    scanf("%d", &prioridade);
                    if (prioridade < 1 || prioridade > 5) {
                        printf("Numero invalido! Digite novamente (1 a 5): ");
                    } else {
                        atual->prioridade = prioridade; // armazenar 1..5
                        printf("Prioridade %d atribuida ao paciente %s\n", prioridade, atual->nome);
                        return 1;
                    }
                }
            }
            atual = atual->prox;
        }
    }

    printf("Paciente com ID %d nao encontrado!\n", id);
    return 0;
}

