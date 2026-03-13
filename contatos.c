#include <stdio.h>
#include <string.h>
#include "contatos.h"
#include <ctype.h> // necessário para o tolower (converter letra maiúscula para minúscula)

void cadastrarContato(Contato contatos[], int *total) {
    
    // Verificar se o limite não foi atingido
    if (*total >= MAX_CONTATOS) {
        printf("Limite de contatos atingido!\n");
        return;
    }

    // Limpar buffer do teclado depois do scanf do menu no main.c
    setbuf(stdin, NULL);

    // Pedir e armanezar os dados do usuário
    printf("Nome: ");
    fgets(contatos[*total].nome, TAM_NOME, stdin);

    printf("Telefone: ");
    fgets(contatos[*total].telefone, TAM_TELEFONE, stdin);

    printf("Email: ");
    fgets(contatos[*total].email, TAM_EMAIL, stdin);

    // Ponteiro para aumentar a quantidade total de contatos
    *total = *total + 1;

    printf("Contato cadastrado com sucesso!\n");
}

void listarContatos(Contato contatos[], int total) {

    // Verificar se há contatos cadastrados
    if (total == 0) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    printf("\nLISTA DE CONTATOS\n");

    // Lista todos os contatos cadastrados
    int i;
    for (i = 0; i < total; i++) {
        printf("\n[%d]\n", i + 1); // Número
        printf("Nome:     %s", contatos[i].nome);
        printf("Telefone: %s", contatos[i].telefone);
        printf("Email:    %s", contatos[i].email);
    }

    printf("\n\n");
}

// Converter os caracteres para minúsculas, para fazer busca sem diferenciar maiúscula e minúscula
void converterMinusculas(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

void buscarContato(Contato contatos[], int total) {

    char nomeBuscado[TAM_NOME];
    setbuf(stdin, NULL);
    printf("Digite o nome para buscar: ");
    fgets(nomeBuscado, TAM_NOME, stdin);
    nomeBuscado[strcspn(nomeBuscado, "\n")] = '\0'; // Remove o enter do final do nome que o fgets captura
    
    // Cria uma cópia minúscula do que foi digitado pelo usuário
    char buscaMinuscula[TAM_NOME];
    strcpy(buscaMinuscula, nomeBuscado);
    converterMinusculas(buscaMinuscula);

    int i;
    int encontrou = 0;
    for (i = 0; i < total; i++) {

        // Cria uma cópia do nome do contato cadastrado pelo usuário e converte em minúscula
        char nomeMinusculo[TAM_NOME];
        strcpy(nomeMinusculo, contatos[i].nome);
        nomeMinusculo[strcspn(nomeMinusculo, "\n")] = '\0';
        converterMinusculas(nomeMinusculo);

        // strstr encontra o texto buscado se este estiver contido na string e exibe os resultados
        if (strstr(nomeMinusculo, buscaMinuscula) != NULL) {
            printf("\nContato encontrado:\n");
            printf("Nome:     %s\n", contatos[i].nome); // exibe o original, não a cópia
            printf("Telefone: %s", contatos[i].telefone);
            printf("Email:    %s", contatos[i].email);
            encontrou = 1;
        }
    }

    if (encontrou == 0) {
        printf("Nenhum contato encontrado com esse nome.\n");
    }
}

void editarContato(Contato contatos[], int total) {

    if (total == 0) { // Verifica se existe contato cadastrado
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    // Mostra a lista para o usuário escolher qual editar
    listarContatos(contatos, total);

    int indice;
    printf("Digite o número do contato que deseja editar: ");
    scanf("%d", &indice);
    indice = indice - 1; // Ajusta para índice real (usuário vê 1, 2, 3... mas o array começa em 0)

    // Verifica se o número digitado é válido
    if (indice < 0 || indice >= total) {
        printf("Número inválido.\n");
        return;
    }

    setbuf(stdin, NULL);

    // Sobrescreve os dados do contato escolhido
    printf("Novo nome: ");
    fgets(contatos[indice].nome, TAM_NOME, stdin);

    printf("Novo telefone: ");
    fgets(contatos[indice].telefone, TAM_TELEFONE, stdin);

    printf("Novo email: ");
    fgets(contatos[indice].email, TAM_EMAIL, stdin);

    printf("Contato editado com sucesso!\n");
}

void removerContato(Contato contatos[], int *total) {

    if (*total == 0) { // Com ponteiro, pois remover diminui o total de contatos
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    // Exibe a lista os contatos para o usuário escolher qual remover
    listarContatos(contatos, *total);
    
    // Captura o número escolhido pelo usuário e ajusta para o índice real do array
    int indice;
    printf("Digite o número do contato que deseja remover: ");
    scanf("%d", &indice);

    indice = indice - 1;

    // Verifica se o número digitado pelo usuário existe na lista
    if (indice < 0 || indice >= *total) {
        printf("Número inválido.\n");
        return;
    }

    // Empurra todos os contatos uma posição pra trás
    int i;
    for (i = indice; i < *total - 1; i++) {
        contatos[i] = contatos[i + 1];
    }

    // Diminui o total pelo ponteiro
    *total = *total - 1;
    printf("Contato removido com sucesso!\n");
}

int estatisticas(Contato contatos[], int total, int indice) {

    // Verifica se chegou ao fim da lista
    if (indice == total) return 0;

    int temNomeLongo = 0;

    // Conta o número de caracteres do nome
    if (strlen(contatos[indice].nome) > 5) {
        temNomeLongo = 1;
    }

    // Soma o resultado do contato atual com o resultado recursivo dos próximos contatos
    return temNomeLongo + estatisticas(contatos, total, indice + 1);
}
