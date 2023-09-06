#include <iostream>

using namespace std;

int main(){
	int N;
	int menor, pos, temp;
	
	cin >> N;
	
	int vetor[N];
	
	for(int i = 0; i < N; i++){
		cin >> vetor[i];
	}
	
	for(int j = 0; j < N; j++){
		
		menor = vetor[j];
		
		for(int i = j; i < N; i++){
			if(vetor[i] <= menor){
				menor = vetor[i];
				pos = i;
			}
		}
		
		temp = vetor[j];
		vetor[j] = menor;
		vetor[pos] = temp;
	}
	
	for(int i = 0; i < N; i++){
		cout << vetor[i] << " ";
	}
	
	return 0;
}