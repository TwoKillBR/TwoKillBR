#include <iostream>
#include <string>
using namespace std;

int main() {
    int height, width;
    cin >> height >> width;

    // Leitura do cenário inicial
    string cenarioAtual[height] = {};
    for (int i = 0; i < height; i++) cin >> cenarioAtual[i];

    int segundos;
    cin >> segundos;
    while (segundos--) {
        bool jaAndeiComEsseMonstro[height][width] = {};
        for (int linha = 0; linha < height; linha++) {
            for (int coluna = 0; coluna < width; coluna++) {
                int x, y;
                char reverse;
                if (
                    cenarioAtual[linha][coluna] != 'x' && 
                    cenarioAtual[linha][coluna] != 'o' &&
                    jaAndeiComEsseMonstro[linha][coluna] != true
                ) {
                  switch (cenarioAtual[linha][coluna]) {
                    case 'b':
                      x = linha+1, y = coluna;

                      reverse = 'c';
                      break;
                    case 'c':
                      x = linha-1, y = coluna;
                      reverse = 'b';
                      break;
                     case 'd':
                      x = linha, y = coluna+1;
                      reverse = 'e';
                      break;
                     case 'e':
                      x = linha, y = coluna-1;
                      reverse = 'd';
                      break;
                  };
                  bool estaDentroDosLimites = (x >= 0 && x < height) && (y >= 0 && y < width);
                  if (!estaDentroDosLimites || cenarioAtual[x][y] != 'o') cenarioAtual[linha][coluna] = reverse;
                  else {
                    cenarioAtual[x][y] = cenarioAtual[linha][coluna];
                    cenarioAtual[linha][coluna] = 'o';
                    jaAndeiComEsseMonstro[x][y] = true;
                    // coluna += 1;
                  };
                };
            };
        };

    };

    // Imprima a cena final
    for (int i = 0; i < height; i++) {
        cout << cenarioAtual[i] << endl;
    };
    return 0;
};
