#include <iostream>

using namespace std;

struct alimento{
    string nome;
    int qtd;
};

int main(){
    int n;
    string search_alimento;

    cin >> n;

    alimento alim[n];

    for(int i = 0; i<n; i++){
        cin.ignore();
        getline(cin, alim[i].nome);
        cin >> alim[i].qtd;
    }

    cin.ignore();

    getline(cin, search_alimento);

    for(int i = 0; i < n; i++){
        if(alim[i].nome == search_alimento && alim[i].qtd > 0){
            cout << search_alimento << " em estoque!" << endl;
            return 0;
        }
    }

    cout << "Nao existe " << search_alimento << " no estoque!" << endl;

    return 0;
}