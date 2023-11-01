#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int compara_palavras(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main(void) {
    FILE *arquivo;
    char linha[100];
    char texto[100];
    char vetor_palavras[100][100];
    int i, j, num_palavras;

    arquivo = fopen("Arquivo TESTE.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    i = 0;
    while (fgets(linha, 100, arquivo) != NULL) {
        // Copia a linha para a string texto
        j = 0;
        while (linha[j] != '\0') {
            texto[i] = linha[j];
            i++;
            j++;
        }
    }

    fclose(arquivo);

    // Transforma todas as letras em minúsculas
    for (i = 0; texto[i] != '\0'; i++) {
        texto[i] = tolower(texto[i]);
    }

    // Extrai as palavras do texto e armazena no vetor_palavras
    i = 0;
    j = 0;
    num_palavras = 0;
    while (texto[i] != '\0') {
        if (isalpha(texto[i])) {
            vetor_palavras[num_palavras][j] = texto[i];
            j++;
        } else if (j > 0) {
            vetor_palavras[num_palavras][j] = '\0';
            num_palavras++;
            j = 0;
        }
        i++;
    }

    // Ordena as palavras armazenadas no vetor_palavras


    // Imprime as palavras armazenadas no vetor_palavras
    for (i = 0; i < num_palavras; i++) {
        printf("%s\n", vetor_palavras[i]);
    }

    return 0;
}
