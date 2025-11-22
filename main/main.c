#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "fila.h"
#include "pacientes.h"
#include "relatorio.h"
#include "triagem.h"

int main()
{
    Fila pacientes;
    FilaAtendido pacientes2;
    inicializar(&pacientes);
    inicializarAtendido(&pacientes2);
    inicializarLista();
    int opcao;
    char nome[100];
    int idade, id;
    char sintoma[100];
    int nivel;

    do
    { // menu

        printf("\n===SISTEMA HOSPITALAR===\n");
        printf("1. Adicionar paciente\n");
        printf("2. Classificar paciente na triagem com prioridade (1 a 5) e inserir na fila\n");
        printf("3. Atender proximo paciente com maior prioridade\n");
        printf("4. Visualizar fila de espera atual por ordem de prioridade\n");
        printf("5. Pacientes atendidos por prioridade\n");
        printf("6. Tempo medio atendimento\n");
        printf("7. Total de pacientes por nivel de risco (1 a 5)\n");
        printf("0. Sair\n");
        scanf("%d", &opcao); // le a opcao do usuario
        getchar();

        switch (opcao) // executa a opcao escolhida
        {
        case 1: // Adicionar paciente

            printf("Digite o nome do paciente\n"); // le o nome do paciente
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = 0;

            printf("Digite o id do paciente\n"); // le o id do paciente
            scanf("%d", &id);
            getchar();

            printf("Digite a idade do paciente\n"); // le a idade do paciente
            scanf("%d", &idade);
            getchar();

            printf("Digite o sintoma do paciente\n"); //le o sintoma do paciente
            fgets(sintoma, sizeof(sintoma), stdin);
            sintoma[strcspn(sintoma, "\n")] = 0;

            {
                Paciente *p = criarPaciente(id, nome, idade, sintoma); // cria o paciente
                if (p == NULL) {
                    printf("Falha ao inserir paciente. Verifique se o ID ja existe.\n");
                } else {
                    printf("Paciente inserido:\n");
                }
            }
            break;
        case 2:
            printf("Digite o ID do paciente que vai passar pela triagem agora\n");
            scanf("%d", &id);
            getchar();
            atribuirPrioridade(&pacientes, id);
            break;
        case 3: //Atender próximo paciente com maior prioridade
            pacienteAtendido(&pacientes, &pacientes2);
            break;
        case 4: // Visualizar fila de espera, ainda verificar
            exibir(&pacientes);
            break;
        case 5: // Pacientes atendidos por prioridade
            atendimentoPrioridade(&pacientes2);
            break;
        case 6: // Tempo medio atendimento
            printf("Digite o nivel de prioridade (1-5) para calcular o tempo medio: \n");
            scanf("%d", &nivel);
            getchar();
            tempoMedio(&pacientes2, nivel);
            break;
        case 7: //Total de pacientes por nível de risco (1 a 5)\n"
            pacientesPorNivel(&pacientes2);  
            break;     
        case 0: // Sair
            printf("Voce escolheu sair!\n");
            printf("Saindo...\n");
            break;
        default: // Opcao invalida
            printf("Opcao invalida!\n");
            break;
        }
    } while (opcao != 0); // enquanto a opcao for diferente de 5 (sair)

    return 0;
}

   