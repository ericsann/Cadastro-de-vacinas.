# Registro de Vacinação de Pacientes

Este é um programa simples em C para registrar informações sobre a vacinação de pacientes. Ele permite cadastrar novas aplicações de vacina, listar todas as aplicações registradas e consultar informações de um paciente específico através do seu CPF.

## Funcionalidades

O programa oferece as seguintes opções:

1.  **Cadastrar Vacina:** Permite inserir os dados de um novo paciente e a respectiva aplicação da vacina, incluindo nome, CPF, nome da vacina, data de aplicação e lote da vacina.
2.  **Listar Aplicações:** Exibe na tela todos os registros de vacinação cadastrados até o momento, mostrando todas as informações de cada paciente.
3.  **Consultar por CPF:** Solicita ao usuário que digite um CPF e, caso encontre um registro correspondente, exibe as informações da vacinação daquele paciente. Se o CPF não for encontrado, informa que o paciente não está cadastrado.
4.  **Sair:** Encerra a execução do programa.

## Como Usar

1.  **Compilação:** Para compilar o código, você precisará de um compilador C (como o GCC). Abra um terminal ou prompt de comando e navegue até o diretório onde o arquivo `.c` está salvo. Execute o seguinte comando:

    ```bash
    gcc nome_do_arquivo.c -o registro_vacina
    ```

    Substitua `nome_do_arquivo.c` pelo nome do seu arquivo C (por exemplo, `vacina.c`). Isso criará um executável chamado `registro_vacina` (ou `registro_vacina.exe` no Windows).

2.  **Execução:** Para executar o programa, digite o seguinte comando no terminal:

    ```bash
    ./registro_vacina
    ```

    No Windows, você pode simplesmente executar o arquivo `.exe`.

3.  **Menu:** O programa exibirá um menu com as opções disponíveis. Digite o número da opção desejada e pressione Enter. Siga as instruções na tela para inserir os dados ou visualizar as informações.

## Estrutura do Código

O código está estruturado da seguinte forma:

* **Inclusão de Bibliotecas:**
    * `stdio.h`: Para funções de entrada e saída padrão (como `printf` e `scanf`).
    * `stdlib.h`: Para funções de utilidades gerais (como `system`).
    * `string.h`: Para funções de manipulação de strings (como `strcmp`).
    * `locale.h`: Para configurações de localização (como o idioma Português).
* **Definição da Estrutura `cadastro`:**
    * Define um tipo de dado estruturado chamado `cadastro` para armazenar as informações de cada registro de vacinação. Essa estrutura contém os seguintes campos:
        * `nome`: Nome do paciente (string de até 30 caracteres).
        * `cpf`: CPF do paciente (string de até 15 caracteres).
        * `vacina`: Nome da vacina aplicada (string de até 15 caracteres).
        * `data`: Data da aplicação da vacina (string de até 15 caracteres).
        * `lote`: Número do lote da vacina (inteiro).
* **Função `main` (Algoritmo Principal):**
    * `setlocale(LC_ALL, "Portuguese");`: Define a localização para Português, o que pode influenciar a exibição de caracteres e formatação.
    * `struct cadastro ficha[999];`: Declara um array de estruturas `cadastro` capaz de armazenar até 999 registros de vacinação.
    * `int op, i, cont, acha;`: Declara variáveis inteiras para controlar as opções do menu (`op`), o índice do array (`i`), o contador de registros (`cont`) e uma flag para indicar se um CPF foi encontrado (`acha`).
    * `char cpfbusca[15];`: Declara um array de caracteres para armazenar o CPF digitado para busca.
    * **Loop `while (op!=4)`:** Mantém o programa em execução até que o usuário escolha a opção "Sair" (opção 4).
        * `system("cls");`: Limpa a tela do terminal (pode não funcionar em todos os sistemas).
        * Exibe o menu de opções para o usuário.
        * `scanf("%d", &op);`: Lê a opção digitada pelo usuário.
        * `fflush(stdin);`: Limpa o buffer de entrada.
        * **`switch(op)`:** Executa diferentes blocos de código com base na opção escolhida pelo usuário:
            * **`case 1` (Cadastrar Vacina):** Solicita ao usuário que digite as informações do paciente e da vacina, armazenando-as na próxima posição disponível do array `ficha`. Incrementa os contadores `i` e `cont`.
            * **`case 2` (Listar Aplicações):** Percorre o array `ficha` até o número de registros cadastrados (`cont`) e exibe as informações de cada paciente.
            * **`case 3` (Consultar por CPF):** Solicita o CPF para busca, percorre o array `ficha` comparando o CPF digitado com os CPFs armazenados. Se encontrar uma correspondência, exibe as informações do paciente. Se não encontrar, informa que o paciente não está cadastrado.
            * **`case 4` (Sair):** Exibe uma mensagem de saída.
            * **`default`:** Exibe uma mensagem de "Opção inválida" para opções não reconhecidas.
        * `system("pause");`: Pausa a execução do programa após cada operação (exceto ao sair), permitindo que o usuário veja a saída antes de retornar ao menu (pode não funcionar em todos os sistemas).
    * `return(0);`: Indica que o programa foi executado com sucesso.

## Observações e Melhorias Potenciais

* **Validação de Dados:** O programa não realiza nenhuma validação dos dados inseridos pelo usuário (por exemplo, verificar se o CPF tem o formato correto, se a data é válida, etc.). Adicionar validação tornaria o programa mais robusto.
* **Tratamento de Erros:** O programa não trata possíveis erros de entrada (por exemplo, se o usuário digitar letras onde se espera números).
* **Limite de Registros:** O programa tem um limite de 999 registros devido ao tamanho fixo do array `ficha`. Para um número maior de registros, seria mais adequado usar alocação dinâmica de memória ou armazenar os dados em um arquivo.
* **Persistência de Dados:** Os dados cadastrados são perdidos quando o programa é encerrado. Para armazenar os dados permanentemente, seria necessário implementar a leitura e escrita em arquivos (por exemplo, arquivos de texto ou binários).
* **Interface de Usuário:** A interface de linha de comando é básica. Uma interface gráfica (GUI) tornaria o programa mais amigável.
* **Busca Mais Eficiente:** Para um grande número de registros, a busca linear por CPF pode se tornar ineficiente. Utilizar estruturas de dados mais avançadas (como árvores de busca) ou indexação poderia melhorar o desempenho da busca.
