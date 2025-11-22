#ifndef RELATORIO_H
#define RELATORIO_H

#include "pacientes.h"
#include "fila.h"

//Prototipo das funções
void atendimentoPrioridade(FilaAtendido *fa);
void tempoMedio(FilaAtendido *fa, int numero);
void pacientesPorNivel(FilaAtendido* fa);

#endif