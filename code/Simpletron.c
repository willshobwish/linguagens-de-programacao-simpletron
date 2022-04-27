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
        "*** Program loading completed ***\n*** Program execution begins ***");
}

int main(void) {
    int accumulator;
    // Representa o registro do acumulador
    int instructionCounter;
    // Representa o registro
    int programIteration = 0;
    int teste;
    printWelcome();
    while (programIteration <= 99) {
        printf("%.2d ? ", programIteration);
        programIteration++;
        scanf("%d", &teste);
    };
    printEnd();
}