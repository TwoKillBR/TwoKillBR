#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhação! *" << endl;
    cout << "**************************************" << endl;

    cout << "Escolha o seu nível de dificuldade: " << endl;
    cout << "Facil (F), Medoio (M) ou Dificil (D)" << endl;

    char dificuldade;
    cin >> dificuldade;

    int numeroDeTentativas;

    if (dificuldade == 'F') {
        numeroDeTentativas = 15;
    }
    else if (dificuldade == 'M') {
        numeroDeTentativas = 10;
    }
    else {
        numeroDeTentativas = 5;
    }

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for (tentativas = 1; tentativas <= numeroDeTentativas; tentativas++) {
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual seu chute? ";
        cin >> chute;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
        pontos -= pontos_perdidos;

        cout << "O valor do seu chute é: " << chute << endl;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou)
        {
            cout << "Parabéns! Você acertou o número secreto!" << endl;
            nao_acertou = false;
            break;
        }
        else if (maior)
        {
            cout << "Seu chute foi maior que o número secreto!" << endl;
        }
        else
        {
            cout << "Seu chute foi menor que o número secreto!" << endl;
        }
    }
    cout << "Fim de jogo!" << endl;
    if (nao_acertou) {
        cout << "Você perdeu, tente novamente!" << endl;
        cout << "Numero secreto era: " << NUMERO_SECRETO << endl;
    }
    else {
        cout << "Você acertou o número secreto em " << tentativas << " tentativas" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de " << pontos << " pontos." << endl;
    }
}
