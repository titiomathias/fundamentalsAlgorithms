#include <iostream>
#include <vector>

using namespace std;

int hash1(int k, int m) {
    int p = k % m;
    return p;
}

int hash2(int k, int m) {
    return 1 + (k % (m - 1));
}

int hash_insert(int vetor[], int m, int k){
	int i = hash1(k, m);
	int j = hash2(k, m);
	
	while(vetor[i]!=-1){
		i = (i+j) % m;
	}
	
	return i;
}

int main() {
    int m, n;
    int numero;

    cin >> m;

    int vetor[m];

    for (int i = 0; i < m; i++) {
        vetor[i] = -1;
    }

    cin >> n;

    vector<int> pilha;

    for (int i = 0; i < n; i++) {
        cin >> numero;
        pilha.push_back(numero);
    }

    for (int i = 0; i < n; i++) {
        int elemento = pilha.back();
        pilha.pop_back();

        vetor[hash_insert(vetor, m, elemento)] = elemento;
    }

    for (int i = 0; i < m; i++) {
        cout << vetor[i] << " ";
    }

    cout << endl;

    return 0;
}
