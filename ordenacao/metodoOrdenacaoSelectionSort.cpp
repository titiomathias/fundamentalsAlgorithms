#include <iostream>

using namespace std;

/*

O Selection Sort é um algoritmo de ordenação que parte da ideia de sempre buscar um menor valor e colocá-lo no início do vetor.
Esse processo se repetirá n-1 vezes necessárias, até os últimos dois elementos de um vetor.

*/

int main(){
	int N; // Tamanho do vetor
	int menor, pos, temp; // Variáveis de: menor valor, posição, e armazenamento temporário para swap
	
	cin >> N; // Recebe o tamanho do vetor
	
	int vetor[N]; // Cria o vetor com o tamanho inserido
	
	for(int i = 0; i < N; i++){ // Passa por cada posição do vetor
		cin >> vetor[i]; // Lê e insere um valor na posição atual do vetor
	}
	
	for(int j = 0; j < N; j++){ // Passa por cada posição do vetor
		
		menor = vetor[j]; // Assume como menor valor o primeiro valor do vetor
		
		for(int i = j; i < N; i++){ // Para cada posição do vetor a partir do contador j, inicia a passagem pelo vetor
			if(vetor[i] <= menor){ // Se a posição atual do vetor for menor ou igual ao menor número declarado
				menor = vetor[i]; // O menor número passa a se tornar o número encontrado
				pos = i; // A posição do menor número em questão é armazenada
			}
		}

		// Processo de Swap
		temp = vetor[j]; // O valor inicialmente declarado como menor assume a variável temp
		vetor[j] = menor; // O valor inicial do vetor declarado como j assume o menor valor
		vetor[pos] = temp; // A posição anterior do menor valor do vetor recebe a variável temp
	}
	
	for(int i = 0; i < N; i++){ // Passa por cada posição do vetor
		cout << vetor[i] << " "; // Mostra o valor da respectiva posição na tela
	}
	
	return 0;
}
