#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Operation code definitions
// Input/output operations
#define READ 10
#define WRITE 11

// Load/store operations
#define LOAD 20
#define STORE 21

// Arithmetic operations
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33

// Transfer-of-control operations
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

void printWelcome() {
    printf(
        "*** Welcome to Simpletron! ***\n*** Please enter your program one "
        "instruction ***\n*** (or data word) at a time. I will type the "
        "***\n*** "
        "location number and a question mark (?). ***\n*** You then type the "
        "word for that location. ***\n*** Type the sentinel -99999 to stop "
        "entering ***\n*** your program. ***\n");
}

void printEnd() {
    printf(
        "\n*** Program loading completed ***\n\n*** Program execution begins "
        "***\n");
}

// void printOperationCodeInside(int **memoryArray, int **accumulator, int **operationCode, int **operand, int **instructionCounter, int **instructionRegister) {
//     printf("%.2d %.4d Operation Code: %.2d Operand: %.2d Operation: ", **instructionCounter, *memoryArray[**instructionCounter], **operationCode, **operand);
// }

void printOperationCode(int *memoryArray, int *accumulator, int *operationCode, int *operand, int *instructionCounter, int *instructionRegister) {
    *instructionCounter = 0;

    // Flags ou sinalizadores de controle de execucao do while que contem o switch, caso um deles retorne verdadeiro, na condicao do while sera false devido o operador logico "!"
    bool error = false;  // Caso de erro na leitura das instrucoes, comandos ou operacoes invalidas
    bool halt = false;   // Caso o programa tenha o codigo de termino de instrucoes

    printf("\n");

    while (memoryArray[*instructionCounter] != -99999 && *instructionCounter <= 99 && !error && !halt) {  // Caso a memoria seja diferente de "-99999" (que eh a condicao de saida das instrucoes do programa quando o usuario escreve) e o index da memoria seja menor ou igual a 99 e o "error" nao seja verdadeiro (o "!" inverte o valor de "error" que eh um booleano)

        *operationCode = memoryArray[*instructionCounter] / 100;  //  memoryArray[*instructionCounter] == *(memoryArray + *instructionCounter)
        *operand = memoryArray[*instructionCounter] % 100;
        *instructionRegister = memoryArray[*instructionCounter];

        if (*accumulator > 9999 || *accumulator < -9999) {  // Checa se o accumulator esta dentro do intervalo, caso esteja fora, ele sinaliza o error impedindo a execucao do programa
            printf("\n***Acumulador fora do intervalo permitido***\n");
            printf("*** Simpletron execution abnormally terminated ***\n\n");
            error = true;
        } else {
            switch (*operationCode) {
                case READ:  // == if (operationCode == READ)
                            // Le a entrada do usuario

                    // Impressao no terminal para testes
                    // printOperationCodeInside(&memoryArray, &accumulator, &operationCode, &operand, &instructionCounter, &instructionRegister);
                    // printf("READ\n");
                    printf(
                        "%.2d %.4d Operation Code: %.2d Operand: %.2d "
                        "Operation: "
                        "%s\n",
                        *instructionCounter, memoryArray[*instructionCounter], *operationCode,
                        *operand, "READ");

                    // Funcao
                    printf("Digite o numero dentro do intervalo: ");
                    scanf("%d", &memoryArray[*operand]);  // necessario escrever no endereco da memoria, por isso o "&"
                    fflush(stdin);

                    // Tratamento de excecoes
                    if (memoryArray[*operand] > 9999 || memoryArray[*operand] < -9999) {  // Checa se a entrada esta dentro do limite
                        printf("*** Acumulador fora do intervalo permitido ***\n");
                        printf("*** Simpletron execution abnormally terminated ***\n");
                        error = true;
                    }

                    printf("Accumulator: %.4d\n\n", *accumulator);

                    break;

                case WRITE:  // Escreve o conteudo da memoria no terminal

                    // Impressao no terminal para testes
                    printf(
                        "%.2d %.4d Operation Code: %.2d Operand: %.2d "
                        "Operation: "
                        "%s\n",
                        *instructionCounter, memoryArray[*instructionCounter], *operationCode,
                        *operand, "WRITE");

                    // Funcao
                    printf("%.4d\n", memoryArray[*operand]);

                    printf("Accumulator: %.4d\n\n", *accumulator);

                    break;

                case LOAD:  // Carrega o conteudo da memoria no accumulator

                    // Impressao no terminal para testes
                    printf(
                        "%.2d %.4d Operation Code: %.2d Operand: %.2d "
                        "Operation: "
                        "%s\n",
                        *instructionCounter, memoryArray[*instructionCounter], *operationCode,
                        *operand, "LOAD");

                    // Funcao
                    *accumulator = memoryArray[*operand];

                    printf("Accumulator: %.4d\n\n", *accumulator);

                    break;

                case STORE:  // Armazena o accumulator na memoria especificada

                    // Impressao no terminal para testes
                    printf(
                        "%.2d %.4d Operation Code: %.2d Operand: %.2d "
                        "Operation: "
                        "%s\n",
                        *instructionCounter, memoryArray[*instructionCounter], *operationCode,
                        *operand, "STORE");

                    // Funcao
                    memoryArray[*operand] = *accumulator;

                    printf("Accumulator: %.4d\n\n", *accumulator);

                    break;

                // Todas as operacoes aritmeticas sao armazenadas no accumulator
                case ADD:  // Adiciona o accumulator com o conteudo da memoria

                    // Impressao no terminal para testes
                    printf(
                        "%.2d %.4d Operation Code: %.2d Operand: %.2d "
                        "Operation: "
                        "%s\n",
                        *instructionCounter, memoryArray[*instructionCounter], *operationCode,
                        *operand, "ADD");

                    // Funcao
                    *accumulator += memoryArray[*operand];

                    printf("Accumulator: %.4d\n\n", *accumulator);

                    break;

                case SUBTRACT:  // Subtrai o accumulator com o conteudo da memoria

                    // Impressao no terminal para testes
                    printf(
                        "%.2d %.4d Operation Code: %.2d Operand: %.2d "
                        "Operation: "
                        "%s\n",
                        *instructionCounter, memoryArray[*instructionCounter], *operationCode,
                        *operand, "SUBTRACT");

                    // Funcao
                    *accumulator -= memoryArray[*operand];

                    printf("Accumulator: %.4d\n\n", *accumulator);

                    break;

                case DIVIDE:  // Divide o accumulator com o conteudo da memoria

                    // Impressao no terminal para testes
                    printf(
                        "%.2d %.4d Operation Code: %.2d Operand: %.2d "
                        "Operation: "
                        "%s\n",
                        *instructionCounter, memoryArray[*instructionCounter], *operationCode,
                        *operand, "DIVIDE");

                    // Funcao
                    *accumulator /= memoryArray[*operand];

                    printf("Accumulator: %.4d\n\n", *accumulator);

                    break;

                case MULTIPLY:  // Multiplica o accumulator com o conteudo da memoria

                    // Impressao no terminal para testes
                    printf(
                        "%.2d %.4d Operation Code: %.2d Operand: %.2d "
                        "Operation: "
                        "%s\n",
                        *instructionCounter, memoryArray[*instructionCounter], *operationCode,
                        *operand, "MULTIPLY");

                    // Funcao
                    *accumulator *= memoryArray[*operand];

                    printf("Accumulator: %.4d\n\n", *accumulator);

                    break;

                // Transfer-of-control operations:
                case BRANCH:  // Branch to a specific location in memory.

                    // Impressao no terminal para testes
                    printf(
                        "%.2d %.4d Operation Code: %.2d Operand: %.2d "
                        "Operation: "
                        "%s\n",
                        *instructionCounter, memoryArray[*instructionCounter], *operationCode,
                        *operand, "BRANCH");

                    // Funcao
                    *instructionCounter = *operand;

                    printf("Accumulator: %.4d\n\n", *accumulator);

                    break;

                case BRANCHNEG:  // Branch to a specific location in memory if the accumulator is negative.

                    // Impressao no terminal para testes
                    printf(
                        "%.2d %.4d Operation Code: %.2d Operand: %.2d "
                        "Operation: "
                        "%s\n",
                        *instructionCounter, memoryArray[*instructionCounter], *operationCode,
                        *operand, "BRANCHNEG");
                    break;

                case BRANCHZERO:  // Branch to a specific location in memory if the accumulator is zero.

                    // Impressao no terminal para testes
                    printf(
                        "%.2d %.4d Operation Code: %.2d Operand: %.2d "
                        "Operation: "
                        "%s\n",
                        *instructionCounter, memoryArray[*instructionCounter], *operationCode,
                        *operand, "BRANCHZERO");
                    break;

                case HALT:  // Encerra a execucao do programa (quando termina de inserir todas as instrucoes)

                    // Impressao no terminal para testes
                    printf(
                        "%.2d %.4d Operation Code: %.2d Operand: %.2d "
                        "Operation: "
                        "%s\n",
                        *instructionCounter, memoryArray[*instructionCounter], *operationCode,
                        *operand, "HALT");

                    // Funcao
                    printf("\n*** Simpletron execution terminated ***\n\n");
                    halt = true;  // Define halt como true, retornando no while como false devido ao operador logico "!" na condicao de execucao

                    break;

                default:                      // Ver como que o programa termina, se demonstrara um erro se nao colocar o comando de parada ou se nao mostrara o erro e executara normalmente
                    printf("FATAL ERROR\n");  // Todo codigo de operacao fora dos define sera considerado "fatal error", precisa ver se aparecera erros mais especificos como de escrita ou de operacao invalida
                    // O que acontece quando ele pega um valor?
                    printf("Error in line %02d with command %04d\n*** Simpletron execution abnormally terminated ***\n\n", *instructionCounter,
                           memoryArray[*instructionCounter]);
                    error = true;  // Define "error" como verdadeiro e para o while que esta em cima do switch case
                    break;
            }
        }
        *instructionCounter += 1;  // Quando chega ao final do switch, ele incrementa em um para executar a proxima instrucao
    }
}

void printDump(int *memoryArray, int *accumulator, int *instructionCounter,
               int *instructionRegister, int *operationCode,
               int *operand) {  // Talvez seja melhor modularizar mais ainda essa funcao porque ha muitos parametros
    printf("REGISTERS:\n");
    printf("accumulator: %+.4d\n", *accumulator);
    printf("instructionCounter: %02d\n", *instructionCounter);
    printf("instructionRegister: %+.4d\n", *instructionRegister);
    printf("operationCode: %02d\n", *operationCode);
    printf("operand: %02d\n\n", *operand);
    printf("MEMORY:\n");
    for (int x = 0; x <= 9; x++) {  // Geracao dos numeros do "eixo x" do dump da memoria
        printf("%6d", x);
    }
    printf("\n");
    int dumpIteration = 0;
    for (int y = 0; y <= 9; y++) {  // Geracao dos numeros do "eixo y" do dump da memoria
        printf("%d ", y);
        for (int z = 0; z <= 9; z++) {
            printf("%+05d ", *(memoryArray + dumpIteration));
            dumpIteration++;
        }
        printf("\n");
    }
}

// When Simpletron begins execution, the special registers are initialized
// as follows:
int main(void) {                  // Todos os registradores devem ser inicializados com zero
    int accumulator = 0;          // Representa o registro do acumulador
    int instructionCounter = 0;   // Representa o registro
    int instructionRegister = 0;  // Representa o registro da instrução
    int operationCode = 0;        // Codigo de operacao
    int operand = 0;              // Codigo do operando
    int memory[99];               // Memory allocation on array
    // Simulate the memory of the Simpletron with a one-dimensional array memory

    // Uma das formas de implementacao possivel eh uma construcao de array de
    // enderecos que armazena as instrucoes que serao inseridos na entrada do
    // programa

    // Colocar todas as operacoes que o programa precisa realizar antes do
    // printWelcome(), assim sera possivel saber se o programa terminou a
    // execucao das instrucoes iniciais

    for (int i = 0; i <= 99; i++) {  // Inicializacao da memoria com zeros
        memory[i] = 0;
    }

    printWelcome();  // Escrita da boas vindas
    int teste = 0;   // variavel de teste

    FILE *code = fopen("teste.txt", "r");
    char c, string[7];  // string[6]={'1','0','1','1','\n','\0'}
    int index = 0;

    for (int i = 0; i < 100; i++) {
        memory[i] = 0;
    }
    if (code != NULL) {
        while (fgets(string, sizeof(string), code) != NULL) {
            printf("%.2d ? %s", instructionCounter, string);
            memory[index] = atoi(string);
            ++index;
        }
    }
    // printf("\n");
    // index = 0;
    // while (index < 20) {
    //     printf("Memoria %.2d :%d\n", index, memory[index]);
    //     ++index;
    // }
    printEnd();  // Escreve o final da escrita das instrucoes pelo usuario

    printOperationCode(memory, &accumulator, &operationCode, &operand, &instructionCounter, &instructionRegister);  // Mostra cada operacao realizada pelas instrucoes que o usuario colocou

    printDump(memory, &accumulator, &instructionCounter, &instructionRegister,
              &operationCode,
              &operand);  // Mostra os registradores e o dump de memoria
}