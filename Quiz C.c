#include <stdio.h>   // Biblioteca padrão para entrada/saída
#include <stdlib.h>  // Biblioteca para uso do system()

int main() 
{
    char opcao; // Armazena a escolha do jogador para jogar novamente ('S' ou 'N')

    // Vetor com as perguntas
    char perguntas[5][100] = 
    {
        "Qual teoria cientifica explica a origem do universo?",
        "Qual e o maior oceano do planeta?",
        "Qual o elemento quimico da agua?",
        "Quantos segundos tem um minuto?",
        "Qual e a funcao principal do DNA nas celulas?"
    };

    // Vetor com as opções de resposta para cada pergunta
    char opcoes[5][4][50] = 
    {
        {"Big Bang", "Evolucao", "Criacionismo", "Relatividade"},
        {"Atlantico", "Indico", "Pacifico", "Artico"},
        {"O2", "H2O", "CO2", "CH4"},
        {"30", "100", "120", "60"},
        {"Proteger os orgaos", "Armazenar energia", "Transmitir informacoes geneticas", "Criar celulas-tronco"}
    };

    // Vetor com os índices das respostas corretas (de 1 a 4)
    int corretas[5] = {1, 3, 2, 4, 3};

    // Vetor com as dicas que podem ser usadas pelo jogador
    char dicas[5][150] = 
    {
        "E a teoria mais aceita pela comunidade cientifica e envolve uma grande explosao.",
        "E o oceano que banha a costa oeste da America do Sul.",
        "Dois atomos de hidrogenio e um de oxigenio.",
        "E uma das unidades basicas do tempo.",
        "Contem as instrucoes geneticas para o desenvolvimento e funcionamento do organismo."
    };

    int total = 5; // Quantidade total de perguntas do jogo

    // Laço principal do jogo com opção de jogar novamente
    do
    {
        int acertos = 0; // Reinicia o número de acertos a cada nova jogada
        system("cls");   // Limpa a tela

        printf("=== QUIZ C ===\n");

        // Laço principal de perguntas
        for (int i = 0; i < total; i++) 
        {
            int usou_dica = 0; // Variável de controle para limitar o uso de dica por pergunta

            // Exibe a pergunta atual
            printf("\nPergunta %d: %s\n\n", i + 1, perguntas[i]);

            // Mostra as opções de resposta
            for (int j = 0; j < 4; j++) 
            {
                printf("%d - %s\n", j + 1, opcoes[i][j]);
            }

            printf("\n5 - Usar dica\n"); // Opção especial para o jogador ver uma dica

            int escolha;
            int respondeu = 0;

            // Loop interno para garantir resposta válida do jogador
            while (!respondeu) 
            {
                printf("\nEscolha: ");
                scanf("%d", &escolha);

                if (escolha >= 1 && escolha <= 4) 
                {
                    // Verifica se a escolha está correta
                    if (escolha == corretas[i]) 
                    {
                        printf("\nCorreto!\n");
                        acertos++; // Incrementa acertos se o jogador acertar
                    } 
                    else 
                    {
                        // Informa a resposta correta se errar
                        printf("\nErrado. A resposta certa era: %s\n", opcoes[i][corretas[i] - 1]);
                    }
                    respondeu = 1; // Sai do loop após resposta válida
                } 
                else if (escolha == 5 && !usou_dica) 
                {
                    // Exibe dica se o jogador ainda não tiver usado
                    printf("\nDica: %s\n", dicas[i]);
                    usou_dica = 1; // Caso a dica já tenha sido usada
                } 
                else if (escolha == 5 && usou_dica) 
                {
                    // Impede uso da dica mais de uma vez por pergunta
                    printf("\nDica ja usada para esta pergunta.\n");
                } 
                else 
                {
                    // Captura entradas inválidas
                    printf("\nOpcao invalida.\n");
                }
            }
        }

        // Exibe o resultado final após todas as perguntas
        printf("\n=== RESULTADO FINAL ===\n");
        printf("Voce acertou %d de %d perguntas.\n", acertos, total);

        // Feedback baseado no desempenho
        if (acertos == total)
            printf("Incrivel! Voce gabaritou!\n");
        else if (acertos >= 4)
            printf("Muito bem! Voce mandou bem!\n");
        else if (acertos >= 2)
            printf("Nada mal, mas pode melhorar!\n");
        else
            printf("Melhor estudar um pouco mais!\n");

        // Pergunta se deseja jogar novamente
        printf("\nDeseja jogar novamente? (S/N): ");
        scanf(" %c", &opcao);

    } while (opcao == 'S' || opcao == 's'); // Repete se jogador quiser

    printf("\nObrigado por jogar!\n"); // Mensagem final

    return 0; // Finaliza o programa
}
