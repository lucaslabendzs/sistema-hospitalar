#include <stdio.h>
#include <string.h> 
#include "triagem.h"
#include "pacientes.h"
#include "fila.h"


int atribuirPrioridade(Fila *f, int id)
{
    // Percorrer todas as prioridades
    for(int pr = 0; pr < 5; pr++)
    {
        Paciente *atual = f->inicio[pr];

        // Percorrer a lista da prioridade atual
        while(atual != NULL)
        {
            if(atual->id == id)   // Paciente encontrado
            {
                printf("\nSintoma do paciente %s: %s\n", atual->nome, atual->sintoma);
                printf("Doutor, atribua a prioridade (1 a 5):\n");

                int prioridade;

                while(1)
                {
                    scanf("%d", &prioridade);

                    if(prioridade < 1 || prioridade > 5)
                    {
                        printf("Número inválido! Digite novamente (1 a 5): ");
                    }
                    else
                    {
                        atual->prioridade = prioridade;
                        printf("Prioridade %d atribuída ao paciente %s\n",
                               prioridade, atual->nome);
                        return 1;   // sucesso
                    }
                }
            }

            atual = atual->prox; // avança para próximo da fila
        }
    }

    // Se chegou aqui, paciente não existe
    printf("Paciente com ID %d não encontrado!\n", id);
    return 0;
}

