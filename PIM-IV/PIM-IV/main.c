#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// Dados necessários para a criação da empresa
struct Empresa {
    char nome[100];
    char razaoSocial[100];
    char responsavel[100];
    char cnpj[20];
    char email[100];
    char telefone[15];
    char endereco[200];
};

// Limpar o console
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Função de criptografia básica
void criptografar(char *s) {
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = 'z' - (s[i] - 'a');
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = 'Z' - (s[i] - 'A');
        } else if (s[i] >= '0' && s[i] <= '9') {
            s[i] = '9' - (s[i] - '0');
        }
    }
}

// Função de descriptografia básica para a string fornecida (caso deseja implementar a descriptografia depois)
void descriptografar(char *s) {
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = 'z' - (s[i] - 'a');
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = 'Z' - (s[i] - 'A');
        } else if (s[i] >= '0' && s[i] <= '9') {
            s[i] = '9' - (s[i] - '0');
        }
    }
}

// Função para registrar uma nova empresa com criptografia
void registrarNovaEmpresa(FILE *file) {
    struct Empresa novaEmpresa;

    printf("Digite o nome da empresa: ");
    scanf("%s", novaEmpresa.nome);


    printf("Digite a razao social da empresa: ");
    scanf("%s", novaEmpresa.razaoSocial);
    criptografar(novaEmpresa.razaoSocial);

    printf("Digite o nome do responsavel: ");
    scanf("%s", novaEmpresa.responsavel);
    criptografar(novaEmpresa.responsavel);

    printf("Digite o CNPJ da empresa: ");
    scanf("%s", novaEmpresa.cnpj);
    criptografar(novaEmpresa.cnpj);

    printf("Digite o email da empresa: ");
    scanf("%s", novaEmpresa.email);
    criptografar(novaEmpresa.email);

    printf("Digite o telefone da empresa: ");
    scanf("%s", novaEmpresa.telefone);
    criptografar(novaEmpresa.telefone);

    printf("Digite o endereco da empresa: ");
    scanf("%s", novaEmpresa.endereco);
    criptografar(novaEmpresa.endereco);

    // Escrever os dados no arquivo
    fprintf(file, "%s %s %s %s %s %s %s\n", novaEmpresa.nome, novaEmpresa.razaoSocial, novaEmpresa.responsavel, novaEmpresa.cnpj, novaEmpresa.email, novaEmpresa.telefone, novaEmpresa.endereco);
    printf("\nEmpresa registrada com sucesso!\n");
    printf("\nPressione qualquer tecla para continuar...");
}

// Função para atualizar os dados de resíduos
void atualizarDadosDeResiduos(FILE *file) {
    char nomeEmpresa[100];
    float quantidadeResiduo;

    printf("Digite o nome da empresa: ");
    scanf("%s", nomeEmpresa);

    printf("Digite a quantidade de residuos descartados: ");
    scanf("%f", &quantidadeResiduo);

    // Escrever os dados no arquivo
    fprintf(file, "%s %.2f\n", nomeEmpresa, quantidadeResiduo);
    printf("Dados de residuos atualizados com sucesso!\n");
}

// Função para gerar relatórios
void gerarRelatorios(FILE *file) {
    char nomeEmpresa[100];
    float totalResiduos = 0;
    char empresa[100];
    float quantidade;
    int encontrouEmpresa = 0;

    printf("Digite o nome da empresa para o relatorio: ");
    scanf("%s", nomeEmpresa);

    // Lê cada linha do arquivo e verifica se o nome da empresa coincide
    rewind(file);
    while (fscanf(file, "%s %f", empresa, &quantidade) != EOF) {
        if (strcmp(empresa, nomeEmpresa) == 0) {
            totalResiduos += quantidade;
            encontrouEmpresa = 1;
        }
    }

    if (encontrouEmpresa) {
        printf("A empresa %s descartou um total de %.2f litros de residuos.\n", nomeEmpresa, totalResiduos);
    } else {
        printf("Empresa não cadastrada.\n");
    }
}


int main() {

	 FILE *file;
    file = fopen("EmpresasRegistros.txt", "a+");

    char username[20];
    char password[20];
    int choice;
    int loggedIn = 0;

    // Definir nome de usuário e senha
    char correct_username[] = "user";
    char correct_password[] = "user";

    while (!loggedIn) {
        clearScreen();
        printf("Seja Bem-Vindo a START-UP de Solucoes Ambientais\n");
        printf("Login\n");
        printf("Username: ");
        scanf("%s", username);

        printf("Password: ");
        scanf("%s", password);

        // Verificar se as credenciais são válidas
        if (strcmp(username, correct_username) == 0 && strcmp(password, correct_password) == 0) {
            printf("Login bem sucedido. Bem-vindo, %s!\n", username);
            loggedIn = 1;
        } else {
            printf("Credenciais invalidas. Tente novamente.\n");
        }
    }

    while (1) {
        clearScreen();
        printf("Menu de Opcoes:\n");
        printf("1. Registrar uma nova empresa\n");
        printf("2. Atualizar os dados Ambientais\n");
        printf("3. Gerar Relatorios\n");
        printf("4. Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                clearScreen();
                registrarNovaEmpresa(file);
                break;
            case 2:
                clearScreen();
                atualizarDadosDeResiduos(file);
                break;
            case 3:
            	clearScreen();
                gerarRelatorios(file);

                break;
            case 4:
                printf("Saindo do programa.\n");
                return 0;
            default:
                printf("Opcao invalida. Escolha novamente.\n");
        }

        printf("\nPressione qualquer tecla para continuar...");
        getchar(); // Para capturar a nova linha após a entrada numérica
        getchar(); // Aguarda a entrada de uma tecla para continuar
    }
    fclose(file);
    return 0;
}
