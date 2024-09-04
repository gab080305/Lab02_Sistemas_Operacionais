#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. Abra o arquivo em modo leitura
    FILE *file = fopen("lab2_ex2.txt", "r");

    // Verifique se o arquivo foi aberto com sucesso
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // 2. Inicialize o contador de linhas
    int lineCount = 1;
    char buffer[128];

    // 3. Leia o arquivo em partes até o final
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Percorra o buffer para contar as quebras de linha
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] == '\n') {
                lineCount++;
            }
        }
    }

    // 4. Exiba o número total de linhas na tela
    printf("Numero total de linhas: %d\n", lineCount);

    // 5. Feche o arquivo após a leitura
    fclose(file);

    return 0;
}
