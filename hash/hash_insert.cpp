#include <iostream>

using namespace std;

// This code will make a insertion using linear hashing.
// Will be show in the screen the inserted values in the respective positions at the vector, and if the position is null, she will keep with your original value (-1).

struct dado{
	int valor;
	int status;
};

int hash(int k, int m){
	return k%m;
}

int hashLinear(int k, int i, int m){
	return (hash(k, m)+i)%m;
}

int hash_insert(dado vetor[], int m, int k){
	int i = 0;
	int j = 0;
	
	do{
		j = hashLinear(k, i, m);
		if(vetor[j].status != 1){
			vetor[j].valor = k;
			vetor[j].status = 1;
			return j;
		} else {
			i++;
		}
	}while(i!=m);
	
	return -1;
}

int main(){
	int m, k;
	
	cin >> m;
	
	dado vetor[m];
	
	for(int i = 0; i < m; i++){
		vetor[i].status = -1;
		vetor[i].valor = -1;
	}
	
	int a = 0; 
	
	cin >> k;
	
	do{
		hash_insert(vetor, m, k);
		a++;
		cin >> k;
	}while(k!=0 && a!=m);
	
	for(int i = 0; i < m; i++){
		cout << vetor[i].valor << " ";	
	}
	
	return 0;
}
