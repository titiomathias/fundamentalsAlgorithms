#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct produto {
    int codigo;
    string nome;
    int preco;
};

int hash1(int k, int m) {
    return k % m;
}

int hashLinear(int k, int i, int m){
	int r = hash1(k, m)+i;
    return r%m;
}

int hash_insert(produto vetor[], int m, int k, int preco, string nome){
	int i = 0;
	int j = 0;
	
	do{
		j = hashLinear(k, i, m);
		if(vetor[j].codigo == -1){
            vetor[j].codigo = k;
			vetor[j].nome = nome;
			vetor[j].preco = preco;
			return j;
		} else {
			i++;
		}
	}while(i!=m);
	
	return -1;
}

int hash_search(produto t[], int m, int k){
    int i = 0;
	int j = 0;
	
	do{
		j = hashLinear(k, i, m);
		if(t[j].codigo == k){
			return j;
		} else {
			i++;
		}
	}while(i!=m && t[j].codigo != -1);
	
	return -1;
}


int main(){
    int n; // quantidade de itens
    int m = 43; // tamanho da tabela hash
    int V, C, L = 0; // Itens vendidos e comprados a serem processados e lucro
    
    int codigo, preco; // codigo e preco dos produtos
    string nome; // nome do produto
    
    produto tabela[43]; // Tabela hash

    vector<int> vi; // itens a serem vendidos (FILA)
    vector<int> ci; // itens a serem comprados (PILHA)

    for(int i = 0; i < 43; i++){ // Tabela hash 'vazia'
        tabela[i].codigo = -1;
    }

    cin >> n;

    // Adicionando itens na minha tabela hash
    for(int i = 0; i < n; i++){
        cin >> codigo >> nome >> preco;
        hash_insert(tabela, m, codigo, preco, nome);
    }

    // Adicionando itens em formato de fila no vector vi
    cin >> codigo;
    do{
        vi.push_back(codigo);
        cin >> codigo;
    }while (codigo != -1);


    // Adicionando itens em formato de pilha no vector ci
    cin >> codigo;
    do{
        ci.push_back(codigo);
        cin >> codigo;
    }while (codigo != -1);


    // Itens vendidos a serem processados
    cin >> V;
    for(int i = 0; i < V; i++){
        int h = hash_search(tabela, m, vi.front());
        L += tabela[h].preco;
        vi.erase(vi.begin());
    }

    // Itens comprados a serem processados
    cin >> C;
    for(int i = 0; i < C; i++){
        int h = hash_search(tabela, m, ci.back());
        L -= tabela[h].preco;
        ci.pop_back();
    }

    cout << L << " moeda(s)." << endl; // Lucro final

    return 0;
}