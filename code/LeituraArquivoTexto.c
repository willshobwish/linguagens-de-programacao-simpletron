#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *code = fopen("teste.txt", "r");
    char c, string[7];  // string[6]={'1','0','1','1','\n','\0'}
    int index = 0, memory[99];

    for (int i = 0; i < 100; i++) {
        memory[i] = 0;
    }
    if (code != NULL) {
        while (fgets(string, sizeof(string), code) != NULL) {
            printf("%s", string);
            memory[index] = atoi(string);
            ++index;
        }
    }
    printf("\n");
    index = 0;
    while (index < 20) {
        printf("Memoria %.2d :%d\n", index, memory[index]);
        ++index;
    }

    // FILE *code = fopen("teste.txt", "r");
    // int memory[99];
    // int index = 0, memoryIndex = 0;
    // char caractere, temp[4];
    // bool erro = false;

    // while (index <= 99) {
    //     memory[index] = 0;
    //     ++index;
    // }

    // if (code != NULL) {
    //     while ((caractere = fgetc(code)) != EOF) {
    //         if (caractere == "\n") {
    //             temp[4] = "\0";
    //             memory[memoryIndex] = atoi(temp);
    //             ++memoryIndex;
    //             index = 0;
    //         } else if (index > 3) {
    //             erro = true;
    //         } else {
    //             caractere = temp[index];
    //             index++;
    //             printf("%c", caractere);
    //         }
    //     }
    // }
    // memoryIndex = 0;
    // while (memory[memoryIndex] != 0) {
    //     printf("%d", memory[memoryIndex]);
    //     ++memoryIndex;
    // }
}