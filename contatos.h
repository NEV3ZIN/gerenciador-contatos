//Define impossibilidade de leitura dupla do arquivo
#ifndef CONTATOS_H
#define CONTATOS_H

//Limita a capacidade do sistema
#define MAX_CONTATOS 100
#define TAM_NOME     50
#define TAM_TELEFONE 20
#define TAM_EMAIL    50

//Informa que cada contato terá estes três campos
typedef struct {
    char nome[TAM_NOME];
    char telefone[TAM_TELEFONE];
    char email[TAM_EMAIL];
} Contato;

//Define os protótipos das funções
void cadastrarContato(Contato contatos[], int *total);
void listarContatos(Contato contatos[], int total);
void buscarContato(Contato contatos[], int total);
void editarContato(Contato contatos[], int total);
void removerContato(Contato contatos[], int *total);

//Função recursiva, retorna a quantidade de contatos com nome acima de N caracteres
int  estatisticas(Contato contatos[], int total, int indice);

//Fim da proteção de leitura dupla
#endif
