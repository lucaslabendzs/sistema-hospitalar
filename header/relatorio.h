#ifndef RELATORIO_H
#define RELATORIO_H

#include "pacientes.h"
#include "fila.h"

//Prototipo das funções
void atendimentoPrioridade(Fila *f);
void tempoMedio(Fila *f, Paciente *p);
void pacientesPorNivel(FilaAtendido* fa);

#endif