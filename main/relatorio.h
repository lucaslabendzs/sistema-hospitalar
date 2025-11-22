#ifndef RELATORIO_H
#define RELATORIO_H

#include "pacientes.h"
#include "fila.h"

//Prototipo das funções
// Lucas - Exibir pacientes atendidos por prioridade
void atendimentoPrioridade(FilaAtendido *fa);
// Renan - Calculo do tempo medio de atendimento por prioridade
void tempoMedio(FilaAtendido *fa, int numero);
// Leticia - Exibe o total de pacientes atendidos em cada nivel
void pacientesPorNivel(FilaAtendido* fa);

#endif