#include <iostream>
#include <cstring>

using namespace std;

struct inseto{
	string nome;
	float tam;
};

void swap(string &nome_a, float &tamanho_a, string &nome_b, float &tamanho_b){ // Função de troca de variáveis
	float temp_tamanho;
    string temp_nome;

    temp_nome = nome_a;
    temp_tamanho = tamanho_a;

    nome_a = nome_b;
    tamanho_a = tamanho_b;

    nome_b = temp_nome;
    tamanho_b = temp_tamanho;
}

void bubblesort(inseto ins[], inseto ins_ordenado[], int n){
    bool trocado;
	
	do{
		trocado = false;
		for(int i = 0; i < n-1; i++){
			if(ins[i].tam > ins[i+1].tam){
				swap(ins[i].nome, ins[i].tam, ins[i+1].nome, ins[i+1].tam);
				trocado = true;
			}
		}
	}while(trocado);
	//organiza o vetor
	
	for(int i = 0; i < n; i++){
		ins_ordenado[i].nome = ins[i].nome;
		ins_ordenado[i].tam = ins[i].tam;
	}
}

int main(){
	int n; // Numero de insetos a serem cadastrados
	
	cin >> n;
	
	inseto ins[n];
    inseto ins_ord[n];
	
	for(int i = 0; i < n; i++){
        cin.ignore();
		getline(cin, ins[i].nome);
        cin >> ins[i].tam;
	}

    bubblesort(ins, ins_ord, n);

    for(int i = 0; i < n; i++){
        cout << ins_ord[i].nome << endl;
    }

}