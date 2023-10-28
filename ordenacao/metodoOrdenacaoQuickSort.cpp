#include <iostream>
using namespace std;

// Esta ainda é uma versão beta do quicksort utilizando recursividade, tive alguns problemas no desenvolvimento.
// Além do que, também não testei em muitos casos de ordenação diferentes, mas aparentemente seu funcionamento está razoável.

int divide(int vetor[], int inicio, int fim){
	int pivo = vetor[inicio + (fim - inicio) / 2];
	
	int i = inicio;
	int j = fim;
	
	while(i < j){
	
		while(vetor[i] < pivo && (i < j))
		   	i++;
		
		while(vetor[j] > pivo && (i < j))
			j--;
	
		if(i < j){
			int temp = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = temp;
			i++;
			j--;
		}
	}
	
	return j;
}

void quicksort(int vetor[], int inicio, int fim){
	if(inicio < fim){
		int pivo = divide(vetor, inicio, fim);
		quicksort(vetor, inicio, pivo-1);
		quicksort(vetor, pivo+1, fim);
	}
}

int main(){
	int n;
	
	cin >> n;
	
	int vetor[n];
	
	for(int i = 0; i < n; i++){
		cin >> vetor[i];
	}
	 	 
	quicksort(vetor, 0, n-1
	);
	
	cout << "Vetor organizado!" << endl;
	
	for(int i = 0; i < n; i++){
		cout << vetor[i] << " ";
	}
	
	return 0;
}
