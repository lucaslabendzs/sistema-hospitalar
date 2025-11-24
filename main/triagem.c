#include <stdio.h>
#include <string.h> 
#include "triagem.h"
#include "pacientes.h"
#include "fila.h"



// Kauan - função para atribuir prioridade ao paciente baseado no sintoma
int atribuirPrioridade(Fila *f, int id)
{
    // Primeiro, buscar na lista global de pacientes
    Paciente *p = buscarPacientePorID(id);

    //Verifica se pestá diferente de Null
    if (p != NULL) {
        if (p->prioridade != -1) {
            printf("Paciente ja passou pela triagem\n");
            return -1;
        }
        printf("\nSintoma do paciente %s: %s\n", p->nome, p->sintoma);
        printf("Doutor, atribua a prioridade (1 a 5):\n");
        int prioridade;

        //loop para garantir que o valor digitado esteja correto
        while (1) {
            scanf("%d", &prioridade);

            //Verifica o intervalo de 1 - 5, se estiver fora digite novamente
            if (prioridade < 1 || prioridade > 5) {
                printf("Numero invalido! Digite novamente (1 a 5): ");
            } else {

                //se for válida, grava a prioridade
                p->prioridade = prioridade; // armazenar 1..5
                printf("Prioridade %d atribuida ao paciente %s\n", prioridade, p->nome);
                // Enfileira o paciente na fila correspondente
                enfileirar(f, p);
                return 1;
            }
        }
    }

    // Se não estava na lista global, procurar nas filas (caso ja tenha sido enfileirado)
    for (int pr = 0; pr < 5; pr++) { // Percorre as 5 filas de prioridade
        Paciente *atual = f->inicio[pr]; // Ponteriro para primeiro paciente da fila

        //Percorre todos os pacientes da fila
        while (atual != NULL) {

            //verifica se é o paciente procurado pelo ID
            if (atual->id == id) {

                //Printa as informações principais
                printf("\nSintoma do paciente %s: %s\n", atual->nome, atual->sintoma);
                printf("Doutor, atribua a prioridade (1 a 5):\n");

                int prioridade;

                //Loop para garantir que o médico informe uma prioridade válida
                while (1) {
                    scanf("%d", &prioridade);

                    //caso o valor digitado seja invalido, pede novamente
                    if (prioridade < 1 || prioridade > 5) {
                        printf("Numero invalido! Digite novamente (1 a 5): ");
                    } else {

                        //se for valido armazenas as informações
                        atual->prioridade = prioridade; // armazenar 1..5

                        //printa a confirmações
                        printf("Prioridade %d atribuida ao paciente %s\n", prioridade, atual->nome);
                        return 1;
                    }
                }
            }
            //avança para o próximo paciente da fila
            atual = atual->prox;
        }
    }

    printf("Paciente com ID %d nao encontrado!\n", id);
    return 0;
}

