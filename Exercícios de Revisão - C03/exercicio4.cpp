#include <iostream>

using namespace std;

struct alimento{
    int codigo;
    string nome;
    int qtd;
};

int binaria(alimento vetor[], int tamanho, int codigo)
{
	bool achou; 
	int inicio, meio, fim;
	inicio = 0;
	fim = tamanho - 1;
	achou = false;
	while ((inicio <= fim) && (achou == false))
	{
		meio = (inicio + fim) / 2;
		if (vetor[meio].codigo > codigo)
			fim = meio - 1;
		else if (vetor[meio].codigo < codigo)
			inicio = meio + 1;
		else
			achou = true;
	}
	if (achou)
		return meio;
	else
		return -1;
}

int main(){
    int n;
    int search_codigo;

    cin >> n;

    alimento alim[n];

    for(int i = 0; i<n; i++){
        cin >> alim[i].codigo;
        cin.ignore();
        getline(cin, alim[i].nome);
        cin >> alim[i].qtd;
    }

    cin >> search_codigo;

    int retorno = binaria(alim, n, search_codigo);

    if(retorno == -1){
        cout << "Nao existem produtos com esse codigo em estoque!" << endl;
    } else {
        cout << alim[retorno].nome << " em estoque!" << endl;
    }

    return 0;
}