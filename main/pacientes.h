#ifndef PACIENTES_H
#define PACIENTES_H 

#define MAX_NOME 60 // máximo
#define MAX_SINTOMA 200 // máximo
// Kauan - estrutura para fila de pacientes
typedef struct Paciente
{ 
    int id; // identificador único
    int prioridade;
    char nome[MAX_NOME]; // nome do paciente
    int idade; // idade do paciente
    char sintoma[MAX_SINTOMA]; // sintoma apresentado
    struct Paciente *prox; // próximo paciente na lista
    int tempoAtendimento; // em minutos
}Paciente;

typedef struct Lista{
    Paciente *inicio;
}Lista;


void inicializarLista(void);
void adicionarPacienteLista(Paciente *p);
//Busca pacientes na lista global - Kauan
Paciente* buscarPacientePorID(int id);

// Lucas - função para criar paciente
Paciente* criarPaciente(int id, char*nome, int idade, char*sintoma);
#endif