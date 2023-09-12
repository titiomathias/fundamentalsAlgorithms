#include <iostream>

using namespace std;

// Um exemplo de Busca Sequencial.

int main(){
	int n, numero;
	bool found;
	
	cout << "Digite o tamanho do vetor: ";
	cin >> n;
	
	int vetor[n];
	
	cout << "Insira os numeros no vetor: ";
	
	for(int i = 0; i < n; i++){
		cin >> vetor[i];
	}
	
	cout << "Digite o numero para busca: ";
	cin >> numero;
	
	for(int i = 0; i < n; i++){
		if(numero == vetor[i]){
			cout << "\nNumero " << numero << " encontrado na posicao " << i << "." << endl;
			found = true;
			break;
		}
	}
	
	if(!found){
		cout << "Numero nao encontrado :(" << endl;
	}
	
	return 0;
}