# Projeto de Linguagem de Programação

O objetivo é o desenvolvimento de um simulador (do livro "C: Como programar - Paul Deitel e Harvey Deitel" na seção especial: construindo o seu próprio computador)

O projeto consiste em montar um computador (por meio do técnica de simulação baseada no software) por meio do qual é possível executar programas em linguagem de máquina.

---

PROGRAMAÇÃO EM LINGUAGEM DE MÁQUINA

---

O computador criado chama-se **Simpletron**, e sua linguagem, **Simpletron Machine Learning** (SML).  
O Simpletron contém um acumulador em que as informações são registradas antes que o computador as utilize em operações. Toda informação é tratada sob forma de palavra: número decimal de quatro dígitos com sinal. O Simpletron conta com uma memória de **100 palavras**, referenciadas por seus números de local (de 00 a 99). Cada local pode conter uma instrução, um dado ou uma área de memória não utilizada.  
Antes de executar um programa, é necessário carregá-lo na memória, sendo a primeira instrução colocada no local 00.
Cada instrução ocupa uma palavra da memória. As instruções têm sempre sinal positivo, mas os dados podem possuir sinal negativo ou positivo.
Os dois primeiros dígitos de uma instrução consistem no código de operação - a operação a ser realizada -, e os outros dois consistem no operando - o endereço do local de memória que contém a palavra sobre a qual se aplica a operação.

`+1007`: lê o primeiro número do teclado (A) e o coloca no local 07 (que foi inicializado em 0)
`+1008`: ê o próximo número e coloca em 08.
`+2007`: coloca o primeiro número no acumulador
`+3008`: soma o segundo número ao número no acumulador. os resultados de todas as operações aritméticas são colocadas no acumulador. 
`+2109`: coloca o resultado no local 09
`+1109`: imprime o valor do local 09
as próximas linhas são passadas como `+0000`, de forma que recebam os valores ao longo da execução do programa.

```c
scanf("%d"){
    //cria um array instructionRegister
    //while diferente de 4300
    //incrementa 1 contador
}


operationCode = instructionRegister / 100;
operand = instructionRegister % 100;

scanf("%d", &memory [operand]);
    //depois instrução do que fazer com esse operando
```