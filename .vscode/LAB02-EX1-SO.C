#include <stdio.h>
#include <stdlib.h>

int main() {
    // Nome do arquivo
    const char *arquivo = "lab2_ex1.txt";
    
    // Buffer para armazenar o conteúdo lido (128 bytes)
    char buffer[128];
    
    // Ponteiro para o arquivo
    FILE *file;
    
    // Abrindo o arquivo no modo de leitura
    file = fopen(arquivo, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }
    
    // Lendo o conteúdo do arquivo para o buffer
    size_t bytes_lidos = fread(buffer, sizeof(char), 127, file);
    
    // Certificando-se de adicionar o caractere nulo (\0) ao final do buffer
    buffer[bytes_lidos] = '\0';
    
    // Exibindo o conteúdo lido na tela
    printf("Conteúdo do arquivo:\n%s\n", buffer);
    
    // Fechando o arquivo
    fclose(file);
    
    return EXIT_SUCCESS;
}
