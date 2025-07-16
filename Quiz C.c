#include <stdio.h>   // Biblioteca padrão para entrada/saída
#include <stdlib.h>  // Biblioteca para uso do system()

int main() 
{
    char opcao; // Armazena a escolha do jogador para jogar novamente (S/N)

    // Vetor com as perguntas
    char perguntas[10][100] = 
    {
        "Qual a capital do Brasil?",
        "Quanto e 7 x 8?",
        "Quem escreveu Dom Casmurro?",
        "Qual e o menor planeta do Sistema Solar?",
        "Qual linguagem estamos usando agora?",
        "Qual e o maior oceano do planeta?",
        "Quem pintou a Mona Lisa?",
        "Qual o elemento quimico da agua?",
        "Quantos segundos tem um minuto?",
        "Em que continente esta o Egito?"
    };

    // Opções de resposta para cada pergunta
    char opcoes[10][4][50] = 
    {
        {"Sao Paulo", "Brasilia", "Rio de Janeiro", "Curitiba"},
        {"54", "56", "48", "49"},
        {"Jose de Alencar", "Machado de Assis", "Clarice Lispector", "Monteiro Lobato"},
        {"Marte", "Terra", "Plutao", "Mercurio"},
        {"Python", "Java", "C", "Pascal"},
        {"Atlantico", "Indico", "Pacifico", "Artico"},
        {"Van Gogh", "Leonardo da Vinci", "Pablo Picasso", "Michelangelo"},
        {"H2O", "O2", "CO2", "CH4"},
        {"60", "100", "120", "30"},
        {"Asia", "Africa", "Europa", "America"}
    };

    // Índices das respostas corretas (1 a 4)
    int corretas[10] = {2, 1, 2, 4, 3, 3, 2, 1, 1, 2};

    // Dicas para cada pergunta (usadas se o jogador solicitar)
    char dicas[10][150] = 
    {
        "E uma cidade planejada localizada no Centro-Oeste.",
        "E o resultado da tabuada do 7.",
        "Autor brasileiro associado ao realismo.",
        "E o planeta mais proximo do Sol.",
        "E uma linguagem compilada, estruturada e de baixo nivel.",
        "E o oceano que banha a costa oeste da America do Sul.",
        "O pintor era tambem inventor e cientista renascentista.",
        "Dois atomos de hidrogenio e um de oxigenio.",
        "E uma das unidades basicas do tempo.",
        "Fica ao norte da Africa e abriga as piramides."
    };

    int total = 10; // Número total de perguntas

    // Laço principal do jogo com opção de jogar novamente
    do
    {
        int acertos = 0; // Zera acertos no início de cada nova partida
        system("cls");   // Limpa a tela

        printf("=== JOGO DE PERGUNTAS ===\n");

        // Loop para apresentar todas as perguntas
        for (int i = 0; i < total; i++) 
        {
            int usou_dica = 0; // Controle de uso da dica por pergunta
            printf("\nPergunta %d: %s\n\n", i + 1, perguntas[i]);

            // Exibe as opções de resposta
            for (int j = 0; j < 4; j++) 
            {
                printf("%d - %s\n", j + 1, opcoes[i][j]);
            }

            printf("\n5 - Usar dica\n");

            int escolha;
            int respondeu = 0;

            // Loop de validação da resposta
            while (!respondeu) 
            {
                printf("\nEscolha: ");
                scanf("%d", &escolha);

                // Verifica se a resposta está entre 1 e 4
                if (escolha >= 1 && escolha <= 4) 
                {
                    if (escolha == corretas[i]) 
                    {
                        printf("\nCorreto!\n");
                        acertos++;
                    } 
                    else 
                    {
                        printf("\nErrado. A resposta certa era: %s\n", opcoes[i][corretas[i] - 1]);
                    }
                    respondeu = 1; // Sai do loop após resposta válida
                } 
                // Exibe dica se ainda não usada
                else if (escolha == 5 && !usou_dica) 
                {
                    printf("\nDica: %s\n", dicas[i]);
                    usou_dica = 1;
                } 
                // Caso a dica já tenha sido usada
                else if (escolha == 5 && usou_dica) 
                {
                    printf("\nDica ja usada para esta pergunta.\n");
                } 
                else 
                {
                    printf("\nOpcao invalida.\n");
                }
            }
        }

        // Exibe o resultado final após todas as perguntas
        printf("\n=== RESULTADO FINAL ===\n");
        printf("Voce acertou %d de %d perguntas.\n", acertos, total);

        if (acertos == total)
            printf("Incrivel! Voce gabaritou!\n");
        else if (acertos >= 7)
            printf("Muito bem! Voce mandou bem!\n");
        else if (acertos >= 4)
            printf("Nada mal, mas pode melhorar!\n");
        else
            printf("Melhor estudar um pouco mais!\n");

        // Pergunta se o jogador quer jogar novamente
        printf("\nDeseja jogar novamente? (S/N): ");
        scanf(" %c", &opcao);

    } while (opcao == 'S' || opcao == 's'); // Repete se jogador quiser

    printf("\nObrigado por jogar!\n");

    return 0;
}
