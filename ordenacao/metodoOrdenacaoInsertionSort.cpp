#include <iostream>

using namespace std;

// 	Refer�ncia para desenvolvimento: https://pt.wikipedia.org/wiki/Insertion_sort

/*

O Insertion Sort � um algoritmo de ordena��o do qual constr�i um novo vetor inserindo um elemento de cada vez do vetor inicial.
Ele ir� inserir cada valor em seu devido lugar ordenado, at� que todos os elementos sejam inseridos em uma ordem previamente organizada.

*/

void insertionsort(int A[], int tamanho){ // Fun��o InsertionSort
	int i, j, eleito; // Contadores e valor eleito
	
	for(int i = 1; i < tamanho; i++){ // Come�a a passar por todos os itens do vetor a partir de seu segundo elemento.
		eleito = A[i]; // O valor eleito � o contador do elemento atual a partir da segunda posi��o
		j = i-1; // Contador do elemento anterior
		while((j>=0) && (eleito < A[j])){ // Se o contador do elemento anterior existir E a o vetor na posi��o for maior que eleito
			A[j+1] = A[j]; // Ent�o esse elemento passa a assumir o pr�ximo valor.
			j = j-1; // Subtrai um valor do elemento anterior
		}
		A[j+1] = eleito; // A nova chave passa a ser o valor anterior+1
	}
}

int main(){
	int tamanho;
	
	cin >> tamanho;
	
	int vetor[tamanho];
	
	for(int i = 0; i < tamanho; i++){
		cin >> vetor[i];
	}
	
	insertionsort(vetor, tamanho);
	
	for(int i = 0; i < tamanho; i++){
		cout << vetor[i] << " ";
	}
}