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

int main(void) {
    int accumulator;
    // Representa o registro do acumulador
    int instructionCounter;
    // Representa o registro
    int programIteration[99], index = 0;
    int teste;
    int content[99];
    // Memory allocation on array
    // Simulate the memory of the Simpletron with a one-dimensional array memory
    // that has 100 elements (livro)
    for (int i = 0; i <= 99; i++) {
        programIteration[i] = i;
        // printf("%.2d\n", programIteration[i]);
    }

    // Uma das formas de implementacao possivel eh uma construcao de array de
    // enderecos que armazena as instrucoes que serao inseridos na entrada do
    // programa

    // Colocar todas as operacoes que o programa precisa realizar antes do
    // printWelcome(), assim sera possivel saber se o programa terminou a
    // execucao das instrucoes iniciais

    // When Simpletron begins execution, the special registers are initialized
    // as follows:
    // accumulator +0000
    // instructionCounter 00
    // instructionRegister +0000
    // operationCode 00
    // operand 00

    printWelcome();
    while (programIteration[index] <= 99 && teste != -99999) {
        printf("%.2d ? ", programIteration[index]);
        scanf("%d", &teste);
        content[index] = teste;
        index++;
    };

    printEnd();

    for (int i = 0; i <= 99 && content[i] != -99999; i++) {
        printf("%.2d %.4d\n", programIteration[i], content[i]);
    }
}