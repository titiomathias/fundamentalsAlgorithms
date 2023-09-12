#include <iostream>

using namespace std;

// Um exemplo de busca sequencial. OBS: Os números devem ser inseridos em ordem crescente!

int main(){
	int n, numero;
	
	cout << "Digite o tamanho do vetor: ";
	cin >> n;
	
	int vetor[n];
	
	cout << "Insira os numeros no vetor: ";
	
	for(int i = 0; i < n; i++){
		cin >> vetor[i];
	}
	
	cout << "Digite o numero para busca: ";
	cin >> numero;
	
	int left = 0;
	int right = n-1;
	int mid;
	
	while(left<right){
		mid = (left+right)/2;
		
		if(vetor[mid] > numero){
			right = mid+1;
		} else if(vetor[mid] < numero){
			left = mid-1;
		} else {
			left = right = mid;
		}
	}
	
	if(vetor[left] == numero){
		cout << "\nNumero " << numero << " encontrado!" << endl;
	} else {
		cout << "Numero nao encontrado :(" << endl;
	}
	
	return 0;
}