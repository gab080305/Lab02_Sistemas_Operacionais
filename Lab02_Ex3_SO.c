#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>   // Para O_RDONLY, O_WRONLY, O_CREAT, O_TRUNC
#include <unistd.h>  // Para read(), write(), close()

int main() {
    // 1. Abra o arquivo de origem em modo leitura
    int origem = open("lab2_ex3_origem.txt", O_RDONLY);
    
    // Verifique se o arquivo de origem foi aberto com sucesso
    if (origem == -1) {
        perror("Erro ao abrir o arquivo de origem");
        return 1;
    }

    // 2. Abra ou crie o arquivo de destino em modo escrita
    int destino = open("lab2_ex3_destino.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    // Verifique se o arquivo de destino foi aberto/criado com sucesso
    if (destino == -1) {
        perror("Erro ao abrir/criar o arquivo de destino");
        close(origem); // Feche o arquivo de origem antes de sair
        return 1;
    }

    // 3. Crie um buffer de 128 bytes para copiar o conteúdo
    char buffer[128];
    ssize_t bytesRead, bytesWritten;

    // 4. Use um loop para ler do arquivo de origem e escrever no arquivo de destino
    while ((bytesRead = read(origem, buffer, sizeof(buffer))) > 0) {
        bytesWritten = write(destino, buffer, bytesRead);

        // Verifique se a escrita foi bem-sucedida
        if (bytesWritten != bytesRead) {
            perror("Erro ao escrever no arquivo de destino");
            close(origem);
            close(destino);
            return 1;
        }
    }

    // Verifique se houve erro na leitura
    if (bytesRead == -1) {
        perror("Erro ao ler o arquivo de origem");
    }

    // 5. Feche ambos os arquivos
    close(origem);
    close(destino);

    return 0;
}
