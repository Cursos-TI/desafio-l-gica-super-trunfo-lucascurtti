#include <stdio.h>
#include <string.h>

// Estrutura para armazenar as informações de uma cidade
struct Cidade {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
};

// Função para cadastrar uma cidade
void cadastrarCidade(struct Cidade *cidade) {
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]%*c", cidade->nome);

    printf("Digite a população: ");
    scanf("%d", &cidade->populacao);

    printf("Digite a área em km²: ");
    scanf("%f", &cidade->area);

    printf("Digite o PIB em bilhões de reais: ");
    scanf("%f", &cidade->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade->pontos_turisticos);

    printf("\nCidade cadastrada com sucesso!\n\n");
}

// Função para exibir as informações de uma cidade
void exibirCidade(struct Cidade cidade) {
    printf("Nome da Cidade: %s\n", cidade.nome);
    printf("População: %d\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: %.2f bilhões de reais\n", cidade.pib);
    printf("Número de Pontos Turísticos: %d\n", cidade.pontos_turisticos);
    printf("---------------------------------------\n");
}

// Função para comparar múltiplos atributos e determinar a cidade vencedora
void compararCidades(struct Cidade cidade1, struct Cidade cidade2, int atributo) {
    printf("\nComparando %s com %s:\n", cidade1.nome, cidade2.nome);

    switch (atributo) {
        case 1:  // Comparação por População
            printf("Comparando População...\n");
            if (cidade1.populacao > cidade2.populacao) {
                printf("Vencedor: %s\n", cidade1.nome);
            } else if (cidade1.populacao < cidade2.populacao) {
                printf("Vencedor: %s\n", cidade2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2:  // Comparação por Área
            printf("Comparando Área...\n");
            if (cidade1.area > cidade2.area) {
                printf("Vencedor: %s\n", cidade1.nome);
            } else if (cidade1.area < cidade2.area) {
                printf("Vencedor: %s\n", cidade2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3:  // Comparação por PIB
            printf("Comparando PIB...\n");
            if (cidade1.pib > cidade2.pib) {
                printf("Vencedor: %s\n", cidade1.nome);
            } else if (cidade1.pib < cidade2.pib) {
                printf("Vencedor: %s\n", cidade2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4:  // Comparação por Número de Pontos Turísticos
            printf("Comparando Número de Pontos Turísticos...\n");
            if (cidade1.pontos_turisticos > cidade2.pontos_turisticos) {
                printf("Vencedor: %s\n", cidade1.nome);
            } else if (cidade1.pontos_turisticos < cidade2.pontos_turisticos) {
                printf("Vencedor: %s\n", cidade2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5:  // Comparação aninhada: População > Área > PIB > Pontos Turísticos
            printf("Comparando atributos de forma aninhada (População > Área > PIB > Pontos Turísticos)...\n");
            if (cidade1.populacao != cidade2.populacao) {
                printf("Vencedor pela População: %s\n", cidade1.populacao > cidade2.populacao ? cidade1.nome : cidade2.nome);
            } else if (cidade1.area != cidade2.area) {
                printf("Vencedor pela Área: %s\n", cidade1.area > cidade2.area ? cidade1.nome : cidade2.nome);
            } else if (cidade1.pib != cidade2.pib) {
                printf("Vencedor pelo PIB: %s\n", cidade1.pib > cidade2.pib ? cidade1.nome : cidade2.nome);
            } else if (cidade1.pontos_turisticos != cidade2.pontos_turisticos) {
                printf("Vencedor pelos Pontos Turísticos: %s\n", cidade1.pontos_turisticos > cidade2.pontos_turisticos ? cidade1.nome : cidade2.nome);
            } else {
                printf("Empate total!\n");
            }
            break;

        default:
            printf("Atributo inválido!\n");
            break;
    }
}

int main() {
    struct Cidade cidade1, cidade2;
    int opcao, atributo;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Cadastrar Cidade 1\n");
        printf("2. Cadastrar Cidade 2\n");
        printf("3. Comparar Atributos\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nCadastro da Cidade 1\n");
                printf("---------------------------------------\n");
                cadastrarCidade(&cidade1);
                break;

            case 2:
                printf("\nCadastro da Cidade 2\n");
                printf("---------------------------------------\n");
                cadastrarCidade(&cidade2);
                break;

            case 3:
                printf("\nEscolha o atributo para comparar:\n");
                printf("1. População\n");
                printf("2. Área\n");
                printf("3. PIB\n");
                printf("4. Número de Pontos Turísticos\n");
                printf("5. Comparação Aninhada (População > Área > PIB > Pontos Turísticos)\n");
                printf("Escolha o atributo: ");
                scanf("%d", &atributo);
                compararCidades(cidade1, cidade2, atributo);
                break;

            case 4:
                printf("Saindo...\n");
                return 0;

            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}
