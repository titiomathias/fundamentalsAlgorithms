#include <iostream>

using namespace std;

// A new function to found the key position (hash_search())
// Really like the insert function

struct dado{
	int valor;
	int status;
};

int hash1(int k, int m){
	return k%m;
}

int hashLinear(int k, int i, int m){
	return (hash1(k, m)+i)%m;
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

int hash_search(dado t[], int m, int k){
    int i = 0;
	int j = 0;
	
	do{
		j = hashLinear(k, i, m);
		if(t[j].valor == k){
			return j;
		} else {
			i++;
		}
	}while(i!=m && t[j].status!=0);
	
	return -1;
}

int main(){
	int m, k, search;
	
	cin >> m;
	
	dado vetor[m];
	
	for(int i = 0; i < m; i++){
		vetor[i].status = -1;
	}
	
	int a = 0; 
	
	cin >> k;
	
	do{
		hash_insert(vetor, m, k);
		a++;
		cin >> k;
	}while(k!=0 && a!=m);
	
	cin >> search;
	
	int found = hash_search(vetor, m, search);
	
	if(found != -1){
	    cout << "Chave " << search << " encontrada na posicao " << found << endl;
	} else {
	    cout << "Chave " << search << " nao encontrada";
	}
	
	return 0;
}