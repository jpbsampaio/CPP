#include <random>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int aleatorio(int min, int max) {
    // Criar um gerador de números aleatórios
    random_device rd;
    mt19937 gen(rd());
    // Utiliza distribuição uniforme para obter o número
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

void lancarDado() {
    vector<int>resultados(6, 0);
    int pares = 0, impares = 0;
    for(int i = 0; i < 40; i++) {
        int lancamento = aleatorio(1, 6);
        resultados[lancamento - 1]++;
        if (lancamento % 2 == 0) {
            pares++;
        }
        else {
            impares++;
        }
    }
    cout << "Frequencia: " << endl;
    for (int i = 0; i < 6; ++i) {
        cout << "numero" << (i + 1) << ":" << resultados[i] << " vezes" << endl;
    }
    int numeroFrequente = 1;
    int maxFrequencia = resultados[0];
    for (int i = 1; i < 6; ++i) {
        if (resultados[i] > maxFrequencia) {
            maxFrequencia = resultados[i];
            numeroFrequente = i + 1;
        }

    }
    cout << "O numero que apareceu mais vezes foi: " << numeroFrequente << "(" << maxFrequencia << " vezes)" << endl;
    cout << "total de numeros pares: " << pares << endl;
    cout << "total de numeros impares: " << impares << endl;
    if (pares > impares) {
        cout << "Houveram mais pares!";
    }
    else if (impares > pares) {
        cout << "Houveram mais pares!";
    }
    else {
        cout << "Foram iguais!";
    }
}

void exibirMenu() {
    cout << "-----------------------------------------------" << endl;
        cout << "Menu" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "1 - Simular lancamento de dados 40x" << endl;
        cout << "2 - Gerar vetor" << endl;
        cout << "3 - Gerar matriz" << endl;
        cout << "4 - Criar matriz" << endl;
        cout << "5 - sair" << endl;
        cout << "-----------------------------------------------" << endl;

}

int geraVetor() {
    const int tamanho = 15;
    vector<int> A(tamanho);
    vector<int> B;
    cout << "Vetor A(original)";
    for(int i = 0; i < tamanho; i++) {
        A[i] = aleatorio(-10, 10);
        cout << A[i] << " ";
    }
    for (int i = 0; i < tamanho; i++) {
        if (A[i] > 0) {
            B.push_back(A[i]);
        }
    }
    cout << "vetor B: ";
    for (int i = 0; i < B.size(); i++) {
        cout << B[i] << " ";
    }
    cout << endl;
    return 0;
}

int geraMatriz() { const int TAM_VETOR = 18;
    const int LINHAS = 3;
    const int COLUNAS = 6
;   int vet[TAM_VETOR];
    int matriz[LINHAS][COLUNAS];
    cout << "Vetor gerado: ";
    for (int i = 0; i < TAM_VETOR; ++i) {
        vet[i] = aleatorio(1, 100);
        cout << vet[i] << " ";
  
    } 
    int index = 0;
    for (int i = 0; i < LINHAS; ++i) {
        for (int j = 0; j < COLUNAS; ++j) {
            matriz[i][j] = vet[index];
                index++;
        }
    }
    cout << "\n\nMatriz gerada (3x6):\n";
    for (int i = 0; i < LINHAS; ++i) {
        for (int j = 0; j < COLUNAS; ++j) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    return 0; 
}

int criaMatriz() { 
    const int TAM = 5;
    int matriz[TAM][TAM] = {0};
    int num, count_5 = 0, count_11 = 0, count_13 = 0;
    while (count_5 < TAM || count_11 < (TAM * (TAM - 1)) / 2 || count_13 < (TAM * (TAM - 1)) / 2) {
        cout << "Digite um numero (multiplo de 5, 11 ou 13, maior que zero): ";
        cin >> num; if (num <= 0) {
            cout << "Numero invalido. Deve ser maior que zero!" << endl;
            continue;
        } 
        if (num % 5 == 0 && count_5 < TAM) { 
            matriz[count_5][count_5] = num;
            count_5++;
        } else if (num % 11 == 0 && count_11 < (TAM * (TAM - 1)) / 2) {
            bool inserido = false;
            for (int i = 0; i < TAM && !inserido; i++) { 
                for (int j = i + 1; j < TAM; j++) { 
                    if (matriz[i][j] == 0) { 
                        matriz[i][j] = num;
                        inserido = true;
                        count_11++;
                        break;
                    } 
                } 
            } 
        } else if (num % 13 == 0 && count_13 < (TAM * (TAM - 1)) / 2) { bool inserido = false;
        for (int i = 1; i < TAM && !inserido; i++) { 
            for (int j = 0; j < i; j++) { 
                if (matriz[i][j] == 0) { 
                    matriz[i][j] = num;
                    inserido = true;
                    count_13++;
                    break;
                } 
            } 
        } 
        } else { 
            cout << "Numero invalido. Deve ser multiplo de 5, 11 ou 13!" << endl;
        } 
    }
    cout << "\nMatriz 5x5 gerada:\n";
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            cout << matriz[i][j] << "\t";
        } cout << endl;
    } return 0;
}

int main() {
    int opcao;
    do {
        exibirMenu();
        cout << "Escolha uma opcao" << endl;
        cin >> opcao;
        switch (opcao) {
            case 1: 
                lancarDado();
                break;
            case 2:
                geraVetor();
                break;
            case 3:
                geraMatriz();
                break;
            case 4:
                criaMatriz();
                break;
            case 5:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida tente novamente";
        }
        cout << endl;

    } while (opcao != 5);
            return 0;
}

