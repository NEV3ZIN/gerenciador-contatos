# 📒 Gerenciador de Contatos em C

Projeto prático desenvolvido na disciplina **Laboratório de Programação — Ciclo 1**  
Universidade Evangélica de Goiás — UniEvangélica  
Curso de Engenharia de Software | Semestre 2026/1  
Orientação: Prof. Renato Luan de Sousa Araújo

---

## 👥 Integrantes

| Nome | Contribuição |

| Anne Franciele Ribeiro Silva | Estrutura geral, contatos.h e apresentação |
| Igor Enrique Neves Oliveira | Implementação das funções em contatos.c |
| Silas Silva de Morais | Função recursiva e busca case-insensitive |
| Wallison Souza de Amorim | main.c, menu e testes |

---

## 📋 Descrição

Sistema de gerenciamento de contatos executado em modo texto, desenvolvido em linguagem C.  
O sistema permite cadastrar, listar, buscar, editar e remover contatos, além de exibir estatísticas por meio de uma função recursiva.

Cada contato possui:
- Nome (até 50 caracteres)
- Telefone (até 20 caracteres)
- E-mail (até 50 caracteres)

Os dados são armazenados em um array de structs com capacidade para até 100 contatos.

---

## ⚙️ Funcionalidades

| Opção | Funcionalidade |
|---|---|
| 1 | Cadastrar novo contato |
| 2 | Listar todos os contatos |
| 3 | Buscar contato por nome (case-insensitive) |
| 4 | Editar contato existente |
| 5 | Remover contato |
| 6 | Estatísticas (função recursiva) |
| 7 | Sair do programa |

### Destaques técnicos
- **Busca case-insensitive** — buscar por "ana", "ANA" ou "Ana" retorna o mesmo resultado
- **Busca parcial** — buscar por "Ana" encontra "Ana Maria" e "Ana Paula"
- **Função recursiva** — conta contatos com nome acima de 5 caracteres sem usar loop
- **Ponteiros** — funções que modificam o total de contatos usam passagem por referência
- **Modularização** — código dividido em múltiplos arquivos com responsabilidades separadas

---

## 🗂️ Estrutura dos Arquivos

```
gerenciador-contatos/
├── README.md
├── contatos.c
├── contatos.h
└── main.c

```

### Papel de cada arquivo

**`contatos.h`** — Define o molde do contato (struct), as constantes de tamanho e os protótipos das funções. É o "contrato" do sistema.

**`contatos.c`** — Implementa todas as funções: cadastrar, listar, buscar, editar, remover e estatísticas. É onde o trabalho pesado acontece.

**`main.c`** — Configura o terminal, declara o array de contatos e exibe o menu em loop. Apenas chama as funções implementadas no contatos.c.

---

## 🛠️ Tecnologias Utilizadas

| Tecnologia | Descrição |
|---|---|
| Linguagem C | Linguagem principal do projeto |
| GCC | Compilador C (usado internamente pelo Dev-C++) |
| Dev-C++ 5.11 | IDE utilizada para desenvolvimento |
| Windows 10/11 | Sistema operacional de desenvolvimento |

### Bibliotecas utilizadas

| Biblioteca | Uso no projeto |
|---|---|
| `stdio.h` | `printf`, `scanf`, `fgets` — entrada e saída de dados |
| `string.h` | `strcpy`, `strstr`, `strcspn`, `strlen` — manipulação de strings |
| `ctype.h` | `tolower` — conversão para minúsculas na busca |
| `locale.h` | `setlocale` — configuração do idioma português |
| `windows.h` | `SetConsoleOutputCP` — acentuação no terminal Windows |

---

## 🚀 Como Compilar e Executar

### Pelo Dev-C++ (recomendado)

1. Abra o Dev-C++
2. Vá em **File → Open Project** e abra o arquivo `.dev` do projeto
3. Certifique-se que os três arquivos aparecem nas abas: `main.c`, `contatos.c` e `contatos.h`
4. Pressione **F11** ou vá em **Executar → Compilar & Executar**
5. O programa abrirá automaticamente no terminal

### Pelo terminal com GCC

Caso prefira compilar pelo terminal, navegue até a pasta do projeto e execute:

```bash
gcc src/main.c src/contatos.c -o contatos
```

Em seguida, execute o programa:

```bash
./contatos
```

> ⚠️ **Atenção:** o programa foi desenvolvido para Windows. Em Linux ou Mac, remova as linhas com `windows.h`, `SetConsoleOutputCP` e `SetConsoleCP` do `main.c` antes de compilar.

---

## 📌 Observações

- O código compila sem erros ou warnings no compilador GCC via Dev-C++ 5.11
- A busca por nome é **case-insensitive** e suporta **busca parcial**
- O sistema suporta até **100 contatos** simultâneos — esse limite pode ser alterado no `#define MAX_CONTATOS` dentro do `contatos.h`
- Os dados **não são persistidos** — ao fechar o programa, os contatos são perdidos

---

## 📚 Referências

- DEITEL, Paul; DEITEL, Harvey. *C: como programar*. 6. ed. São Paulo: Pearson, 2011.
- SCHILDT, Herbert. *C completo e total*. 3. ed. São Paulo: Makron Books, 2010.
- PINHEIRO, Francisco de Assis C. *Elementos de Programação em C*. Porto Alegre: Grupo A, 2012.
