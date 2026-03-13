#include <stdio.h>
#include "contatos.h"
#include <locale.h>  // necessário para configurar o idioma
#include <windows.h> // necessário para configurar o terminal do Windows

int main() {
    setlocale(LC_ALL, "Portuguese"); 
    SetConsoleOutputCP(1252); // Configura o terminal para aceitar acentos
    SetConsoleCP(1252); // Configura a entrada também

    // Array dos contatos, armazena os contatos cadastrados
    Contato contatos[MAX_CONTATOS];

    // Contador de quantos contatos foram cadastrados.
    int total = 0;

    // Variável que guarda a opção digitada pelo usuário.
    int opcao = 0;

    // Loop principal do programa, fica rodando até o usuário escolher a opção 7
    while (opcao != 7) {

        printf("\n GERENCIADOR DE CONTATOS \n\n");
        printf("1. Cadastrar contato\n");
        printf("2. Listar contatos\n");
        printf("3. Buscar por nome\n");
        printf("4. Editar contato\n");
        printf("5. Remover contato\n");
        printf("6. Estatísticas\n");
        printf("7. Sair\n");
        printf("\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Verifica qual opção foi digitada e chama a função correspondente
        switch (opcao) {

            case 1:
                cadastrarContato(contatos, &total); // Com & pois cadastrar modifica o total
                break;

            case 2:
                listarContatos(contatos, total);
                break;

            case 3:
                buscarContato(contatos, total);
                break;

            case 4:
                editarContato(contatos, total);
                break;

            case 5:
                removerContato(contatos, &total); // Também modifica o total
                break;

            case 6: {
            	// Chama a função recursiva e exibe quantos contatos tem nome acima de 5 caracteres
                int resultado = estatisticas(contatos, total, 0);
                printf("Contatos com nome acima de 5 caracteres: %d\n", resultado);
                break;
			}

            case 7:
                printf("Encerrando o programa. Até logo!\n");
                break;

            default:
                // Cai aqui se o usuário digitar qualquer número fora de 1 a 7
                printf("Opção inválida! Digite um número entre 1 e 7.\n");
                break;
        }
    }

    return 0;
}
