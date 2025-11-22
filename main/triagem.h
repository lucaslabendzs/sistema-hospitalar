#ifndef TRIAGEM_H   
#define TRIAGEM_H
#include "pacientes.h"
#include "fila.h"


// Kauan - função para atribuir prioridade ao paciente baseado no sintoma
int atribuirPrioridade(Fila *f, int id);

#endif