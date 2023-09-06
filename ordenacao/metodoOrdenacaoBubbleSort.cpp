#include <iostream>

using namespace std;

// Referência para desenvolvimento: https://pt.wikipedia.org/wiki/Bubble_sort

/*

O Bubble Sort é um algoritmo de ordenação do qual percorre o mesmo vetor várias vezes trocando seus elementos por seus
respectivos sucessores caso eles apresentem a característica de menoridade, ou seja, há uma troca de todo elemento i
pelo elemento i+1 caso o elemento i+1 seja maior que o elemento i.

*/

void swap(int &a, int &b){ // Função de troca de variáveis
	int temp = a;
	a = b;
	b = temp;
}

int main(){
	int N; // Tamanho do Vetor
	bool trocado; // Verificação de troca
	
	cin >> N; // Lê o tamanho do vetor
	
	int vetor[N]; // Cria o vetor de tamanho N
	
	for(int i = 0; i < N; i++){ // Insere todos os itens inteiros no vetor
		cin >> vetor[i]; // Lê cada inteiro dentro da sua posição respectiva
	}
	
	do{ // Inicia o algoritmo Bubble Sort
		trocado = false; // A verificação começa falsa para verificar se o vetor já não está ordenado
		for(int i = 0; i < N-1; i++){ // Percorre o vetor até seu penúltimo item
			if(vetor[i] > vetor[i+1]){ // Verifica se o item em questão é maior que seu próximo item
				swap(vetor[i], vetor[i+1]); // Se a condição acima for verdadeira, ambos trocam de posição
				trocado = true; // A verificação se torna verdadeira
			}
		}
	}while(trocado); // O loop se repete devido a condição de verificação (trocado) ser verdadeira
	
	for(int i = 0; i < N; i++){ // Percorre o vetor agora ordenado em ordem decrescente
		cout << vetor[i] << " "; // Mostra cada elemento na tela
	}
	
	return 0;
}