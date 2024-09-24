#include <iostream>
#include <vector>

using namespace std;

void exibirMenu() {
    cout << "-----------------------------------------------" << endl;
    cout << "Menu" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Aperte 1 para a primeira questao" << endl;
    cout << "Aperte 2 para a segunda questao" << endl;
    cout << "Aperte 3 para a terceira questao" << endl;
	cout << "Aperte 4 para sair..." << endl;
    cout << "-----------------------------------------------" << endl;
}

void questao1() {
	int matriz[3][3];
	int maior = 0;
	cout << "Digite os valores da matriz 3x3: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> matriz[i][j];
			if (matriz[i][j] > maior) {
				maior = matriz[i][j];
			}
		}
	}
	cout << "Matriz original: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Matriz resultante: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matriz[i][j] * maior << " ";
		}
		cout << endl;
	}
}

int fatorial(int n) {
	int fat = 1;
	for (int i = 1; i <= n; i++) {
		fat *= i;
	}
	return fat;
}

void arranjo(int n, int k) {
	int arranjo = fatorial(n) / fatorial(n - k);
	cout << "Arranjo de " << n << " e " << k << " = " << arranjo << endl;
}

void combinacao(int n, int k) {
	int combinacao = fatorial(n) / (fatorial(k) * fatorial(n - k));
	cout << "Combinacao de " << n << " e " << k << " = " << combinacao << endl;
}

void questao2() {
	int n, k;
	cout << "Digite o valor de n: ";
	cin >> n;
	cout << "Digite o valor de k: ";
	cin >> k;
	arranjo(n, k);
	combinacao(n, k);
}

void questao3() {
	vector<int> N, P, K;
	int maiorPrimo = 0;
	cout << "Digite 10 numeros inteiros: " << endl;
	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;
		N.push_back(num);
	}
	for (int i = 0; i < N.size(); i++) {
		int num = N[i];
		bool primo = true;
		for (int j = 2; j < num; j++) {
			if (num % j == 0) {
				primo = false;
				break;
			}
		}
		if (primo) {
			P.push_back(num);
			if (num > maiorPrimo) {
				maiorPrimo = num;
			}
		}
	}
	for (int i = 0; i < P.size(); i++) {
		K.push_back(P[i] * maiorPrimo);
	}
	cout << "Vetor N (Primeiro Vetor): ";
	for (int i = 0; i < N.size(); i++) {
		cout << N[i] << " ";
	}
	cout << endl;
	cout << "Vetor P (Vetor com numeros primos): ";
	for (int i = 0; i < P.size(); i++) {
		cout << P[i] << " ";
	}
	cout << endl;
	cout << "Vetor K (Vetor resultante da multiplicacao de " << maiorPrimo << " pelo vetor P): ";
	for (int i = 0; i < K.size(); i++) {
		cout << K[i] << " ";
	}
	cout << endl;
	cout << "Maior primo: " << maiorPrimo << endl;
}

int main() {
	int opcao;
	do {
		exibirMenu();
		cout << "Digite a opcao desejada: ";
		cin >> opcao;
		switch (opcao) {
		case 1:
			questao1();
			break;
		case 2:
			questao2();
			break;
		case 3:
			questao3();
			break;
		case 4:
			cout << "Saindo..." << endl;
			break;
		default:
			cout << "Informe um numero valido!" << endl;
			break;
		}
	} while (opcao != 4);
	return 0;
}