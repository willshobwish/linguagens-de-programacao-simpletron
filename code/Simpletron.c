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
        "*** Program loading completed ***\n*** Program execution begins "
        "***\n");
}

void printOperationCode(int *memoryArray, int *operationCode, int *operand) {
    int index = 0;
    bool error = false;
    printf("\n");
    while (*(memoryArray + index) != -99999 && index <= 99 &&
           !error) {  // Caso a memoria seja diferente de "-99999" (que eh a condicao de saida das instrucoes do programa quando o usuario escreve) e o index da memoria seja menor ou igual a 99 e o "error" nao seja verdadeiro (o "!" inverte o valor de "error" que eh um booleano)
        *operationCode = memoryArray[index] / 100;
        *operand = memoryArray[index] % 100;
        switch (*operationCode) {
            case READ:  // == if (operationCode == READ)
                printf(
                    "%.2d %.4d operationCode: %.2d Operand: %.2d "
                    "Operation: "
                    "%s\n",
                    index, memoryArray[index], *operationCode,
                    *operand, "READ");
                break;

            case WRITE:
                printf(
                    "%.2d %.4d operationCode: %.2d Operand: %.2d "
                    "Operation: "
                    "%s\n",
                    index, memoryArray[index], *operationCode,
                    *operand, "WRITE");
                break;

            case LOAD:
                printf(
                    "%.2d %.4d operationCode: %.2d Operand: %.2d "
                    "Operation: "
                    "%s\n",
                    index, memoryArray[index], *operationCode,
                    *operand, "LOAD");
                break;

            case STORE:
                printf(
                    "%.2d %.4d operationCode: %.2d Operand: %.2d "
                    "Operation: "
                    "%s\n",
                    index, memoryArray[index], *operationCode,
                    *operand, "STORE");
                break;

            case ADD:
                printf(
                    "%.2d %.4d operationCode: %.2d Operand: %.2d "
                    "Operation: "
                    "%s\n",
                    index, memoryArray[index], *operationCode,
                    *operand, "ADD");
                break;

            case SUBTRACT:
                printf(
                    "%.2d %.4d operationCode: %.2d Operand: %.2d "
                    "Operation: "
                    "%s\n",
                    index, memoryArray[index], *operationCode,
                    *operand, "SUBTRACT");
                break;

            case DIVIDE:
                printf(
                    "%.2d %.4d operationCode: %.2d Operand: %.2d "
                    "Operation: "
                    "%s\n",
                    index, memoryArray[index], *operationCode,
                    *operand, "DIVIDE");
                break;

            case MULTIPLY:
                printf(
                    "%.2d %.4d operationCode: %.2d Operand: %.2d "
                    "Operation: "
                    "%s\n",
                    index, memoryArray[index], *operationCode,
                    *operand, "MULTIPLY");
                break;

            case BRANCH:
                printf(
                    "%.2d %.4d operationCode: %.2d Operand: %.2d "
                    "Operation: "
                    "%s\n",
                    index, memoryArray[index], *operationCode,
                    *operand, "BRANCH");
                break;

            case BRANCHNEG:
                printf(
                    "%.2d %.4d operationCode: %.2d Operand: %.2d "
                    "Operation: "
                    "%s\n",
                    index, memoryArray[index], *operationCode,
                    *operand, "BRANCHNEG");
                break;

            case BRANCHZERO:
                printf(
                    "%.2d %.4d operationCode: %.2d Operand: %.2d "
                    "Operation: "
                    "%s\n",
                    index, memoryArray[index], *operationCode,
                    *operand, "BRANCHZERO");
                break;

            case HALT:
                printf(
                    "%.2d %.4d operationCode: %.2d Operand: %.2d "
                    "Operation: "
                    "%s\n",
                    index, memoryArray[index], *operationCode,
                    *operand, "HALT");
                break;

            default:                      // Ver como que o programa termina, se demonstrara um erro se nao colocar o comando de parada ou se nao mostrara o erro e executara normalmente
                printf("FATAL ERROR\n");  // Todo codigo de operacao fora dos define sera considerado "fatal error", precisa ver se aparecera erros mais especificos como de escrita ou de operacao invalida
                printf("Error in line %02d with command %04d\n", index,
                       *(memoryArray + index));
                error = true;  // Define "error" como verdadeiro e para o while que esta em cima do switch case
                break;
        }
        index++;
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
    for (int index = 0; index <= 99 && teste != -99999;
         index++) {  // Repeticao enquanto nao atingir a condicao de -99999 ou 99 instrucoes
        printf("%.2d ? ", index);
        scanf("%d", &teste);
        if (teste != -99999) {
            memory[index] = teste;
        }
    };

    printEnd();  // Escreve o final da escrita das instrucoes pelo usuario

    printOperationCode(memory, &operationCode, &operand);  // Mostra cada operacao realizada pelas instrucoes que o usuario colocou

    printDump(memory, &accumulator, &instructionCounter, &instructionRegister,
              &operationCode,
              &operand);  // Mostra os registradores e o dump de memoria
}
