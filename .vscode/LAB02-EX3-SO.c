#include <fcntl.h>   // Para open()
#include <unistd.h>  // Para read(), write() e close()
#include <stdio.h>   // Para perror()
#include <stdlib.h>  // Para EXIT_FAILURE, EXIT_SUCCESS

int main() {
    // Nomes dos arquivos
    const char *arquivo_origem = "lab2_ex3_origem.txt";
    const char *arquivo_destino = "lab2_ex3_destino.txt";

    // Buffer de 128 bytes
    char buffer[128];
    
    // Variáveis para armazenar os descritores de arquivo
    int fd_origem, fd_destino;
    
    // Abrindo o arquivo de origem no modo leitura (O_RDONLY)
    fd_origem = open(arquivo_origem, O_RDONLY);
    if (fd_origem == -1) {
        perror("Erro ao abrir o arquivo de origem");
        return EXIT_FAILURE;
    }
    
    // Abrindo ou criando o arquivo de destino no modo escrita (O_WRONLY | O_CREAT | O_TRUNC)
    fd_destino = open(arquivo_destino, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_destino == -1) {
        perror("Erro ao abrir/criar o arquivo de destino");
        close(fd_origem);
        return EXIT_FAILURE;
    }
    
    // Variável para armazenar o número de bytes lidos/escritos
    ssize_t bytes_lidos, bytes_escritos;
    
    // Loop para ler o arquivo de origem e escrever no arquivo de destino
    while ((bytes_lidos = read(fd_origem, buffer, sizeof(buffer))) > 0) {
        bytes_escritos = write(fd_destino, buffer, bytes_lidos);
        if (bytes_escritos != bytes_lidos) {
            perror("Erro ao escrever no arquivo de destino");
            close(fd_origem);
            close(fd_destino);
            return EXIT_FAILURE;
        }
    }
    
    // Verificando se houve erro na leitura do arquivo de origem
    if (bytes_lidos == -1) {
        perror("Erro ao ler o arquivo de origem");
    }
    
    // Fechando os arquivos
    close(fd_origem);
    close(fd_destino);
    
    printf("Conteúdo copiado com sucesso de '%s' para '%s'.\n", arquivo_origem, arquivo_destino);

    return EXIT_SUCCESS;
}