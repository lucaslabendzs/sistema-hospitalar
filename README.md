# Simulador de Atendimento Hospitalar (Protocolo de Manchester)
Este projeto é o Trabalho Prático II da disciplina de Estrutura de Dados, focado na implementação de filas com prioridade.A aplicação simula um sistema de triagem e atendimento hospitalar baseado no Protocolo de Manchester, escrito em Linguagem C.

O objetivo é gerenciar o fluxo de pacientes, garantindo que o atendimento seja realizado conforme a prioridade clínica (nível de risco), e não por ordem de chegada.

## Funcionalidades Principais

O sistema implementa as seguintes funcionalidades obrigatórias:

  ***Cadastrar Paciente:** Registro de nome, idade e sintomas.
  ***Triagem (Classificação):** Classifica o paciente com uma prioridade (1 a 5) e o insere na fila de atendimento.
  ***Atender Paciente:** Remove da fila o próximo paciente com a maior prioridade .
  ***Visualizar Fila:** Exibe a fila de espera atual, ordenada por prioridade.
  ***Gerar Relatórios:** Consolida estatísticas dos atendimentos, incluindo:
      *Total de pacientes atendidos por nível de prioridade.
      *Tempo médio de espera por categoria.
      *Total de pacientes classificados por cor/risco.

## Classificação de Risco
O sistema utiliza o Protocolo de Manchester para definir prioridades  7, conforme a tabela:

| Cor | Prioridade | Tempo Máximo Recomendado |
| :--- | :--- | :--- |
| Vermelho | 1 (Imediato) | - |
| Laranja | 2 | Até 10 minutos |
| Amarelo | 3 | Até 60 minutos |
| Verde | 4 | Até 120 minutos |
| Azul | 5 | Até 240 minutos |

## Como Executar

1. Clone este repositório.
2.  Compile os arquivos-fonte. (Ex: usando GCC)
    ```bash
    gcc main.c pacientes.c triagem.c fila.c relatorio.c -o simulador_hospital
    ```
3.  Execute o programa compilado:
    ```bash
    ./simulador_hospital
    ```

## Estrutura do Projeto
O código-fonte está organizado nos seguintes módulos:

  * `main.c`: Menu principal e inicialização do programa.
  * `pacientes.c` / `pacientes.h`: Funções de cadastro e estrutura de dados do paciente.
  * `triagem.c` / `triagem.h`: Lógica de classificação de risco (Manchester).
  * `fila.c` / `fila.h`: Implementação da estrutura de fila com prioridade.
  * `relatorio.c` / `relatorio.h`: Funções para geração de relatórios e estatísticas.

## Vídeo de Demonstração
Conforme solicitado, um vídeo demonstrando a execução completa do sistema está disponível no link abaixo:

https://youtu.be/TVza5ZV8K1Q

## Autores
    * Kauan Calegari 
    * Leticia Eugenio Santos 
    * Lucas Labendzs 
    * Renan teles de Oliveira 