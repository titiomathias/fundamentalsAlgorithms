#include <iostream>

using namespace std;

// Refer�ncia para desenvolvimento: https://pt.wikipedia.org/wiki/Bubble_sort

/*

O Bubble Sort � um algoritmo de ordena��o do qual percorre o mesmo vetor v�rias vezes trocando seus elementos por seus
respectivos sucessores caso eles apresentem a caracter�stica de menoridade, ou seja, h� uma troca de todo elemento i
pelo elemento i+1 caso o elemento i+1 seja maior que o elemento i.

*/

void swap(int &a, int &b){ // Fun��o de troca de vari�veis
	int temp = a;
	a = b;
	b = temp;
}

int main(){
	int N; // Tamanho do Vetor
	bool trocado; // Verifica��o de troca
	
	cin >> N; // L� o tamanho do vetor
	
	int vetor[N]; // Cria o vetor de tamanho N
	
	for(int i = 0; i < N; i++){ // Insere todos os itens inteiros no vetor
		cin >> vetor[i]; // L� cada inteiro dentro da sua posi��o respectiva
	}
	
	do{ // Inicia o algoritmo Bubble Sort
		trocado = false; // A verifica��o come�a falsa para verificar se o vetor j� n�o est� ordenado
		for(int i = 0; i < N-1; i++){ // Percorre o vetor at� seu pen�ltimo item
			if(vetor[i] > vetor[i+1]){ // Verifica se o item em quest�o � maior que seu pr�ximo item
				swap(vetor[i], vetor[i+1]); // Se a condi��o acima for verdadeira, ambos trocam de posi��o
				trocado = true; // A verifica��o se torna verdadeira
			}
		}
	}while(trocado); // O loop se repete devido a condi��o de verifica��o (trocado) ser verdadeira
	
	for(int i = 0; i < N; i++){ // Percorre o vetor agora ordenado em ordem decrescente
		cout << vetor[i] << " "; // Mostra cada elemento na tela
	}
	
	return 0;
}