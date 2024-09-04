#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. Abra o arquivo em modo leitura
    FILE *file = fopen("lab2_ex1.txt", "r");

    // 2. Verifique se o arquivo foi aberto com sucesso
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // 3. Crie um buffer de 128 bytes
    char buffer[128];

    // 4. Leia o conteúdo do arquivo para o buffer
    // fread() retorna o número de elementos lidos
    size_t bytesRead = fread(buffer, sizeof(char), sizeof(buffer) - 1, file);

    // Adicione o caractere nulo (\0) ao final do buffer
    buffer[bytesRead] = '\0';

    // 5. Exiba o conteúdo lido na tela
    printf("Conteudo do arquivo:\n%s", buffer);

    // 6. Feche o arquivo após a leitura
    fclose(file);

    return 0;
}
