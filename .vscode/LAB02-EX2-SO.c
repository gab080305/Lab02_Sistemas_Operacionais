#include <stdio.h>
#include <stdlib.h>

int main() {
    // Nome do arquivo
    const char *arquivo = "lab2_ex2.txt";
    
    // Buffer de 128 bytes
    char buffer[128];
    
    // Ponteiro para o arquivo
    FILE *file;
    
    // Variável para contar o número de linhas
    int num_linhas = 0;
    
    // Abrindo o arquivo no modo de leitura
    file = fopen(arquivo, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }
    
    // Lendo o arquivo em blocos de 128 bytes
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Contando o número de quebras de linha no buffer
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] == '\n') {
                num_linhas++;
            }
        }
    }
    
    // Fechando o arquivo
    fclose(file);
    
    // Exibindo o número total de linhas
    printf("O arquivo '%s' possui %d linhas.\n", arquivo, num_linhas);
    
    return EXIT_SUCCESS;
}
