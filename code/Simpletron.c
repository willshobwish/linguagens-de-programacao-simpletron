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

void printDump(int *memoryArray, int *accumulator, int *instructionCounter,
               int *instructionRegister, int *operationCode, int *operand) {
    printf("REGISTERS:\n");
    printf("accumulator: %+.4d\n", *accumulator);
    printf("instructionCounter: %02d\n", *instructionCounter);
    printf("instructionRegister: %+.4d\n", *instructionRegister);
    printf("operationCode: %02d\n", *operationCode);
    printf("operand: %02d\n\n", *operand);
    printf("MEMORY:\n");
    for (int x = 0; x <= 9; x++) {
        printf("%6d", x);
    }
    printf("\n");
    int dumpIteration = 0;
    for (int y = 0; y <= 9; y++) {
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
int main(void) {  // Todos os registradores devem ser inicializados com zero
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
         index++) {  // Repeticao enquanto nao atingir a condicao de -99999 ou
                     // 99 instrucoes
        printf("%.2d ? ", index);
        scanf("%d", &teste);
        memory[index] = teste;
    };

    printEnd();

    for (int i = 0; i <= 99 && memory[i] != -99999; i++) {
        printf("%.2d %.4d operationCode: %.2d Operand: %.2d\n", i, memory[i],
               memory[i] / 100, memory[i] % 100);
    }

    printDump(memory, &accumulator, &instructionCounter, &instructionRegister,
              &operationCode, &operand);
}