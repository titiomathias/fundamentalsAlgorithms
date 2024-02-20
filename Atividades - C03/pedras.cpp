#include <iostream>
#include <string>

using namespace std;

struct pedras {
	string nome;
	float peso;
	float volume;
	float preco;
};

void gulosa(pedras vetor[], int n, float volume_carrinho, float carga_carrinho) { // Algoritmo de Estratégia Gulosa com complexidade n
    string resultado[n];
	float peso_total, volume_total, valor_total;
	int i = 0;
	
	do{
		volume_total+=vetor[i].volume;
		peso_total+=vetor[i].peso;
		
		if(peso_total > carga_carrinho || volume_total > volume_carrinho){
			break;
		} else {
			valor_total += vetor[i].preco;
            resultado[i] = vetor[i].nome;
		}
		
		i++;
	}while(peso_total<=400 && volume_total<=1000);
	
	cout << "Melhor combinação de pedras: ";
    for (int a = 0; a < i; a++) {
        cout << resultado[a] << " ";
    }
    cout << "resultando R$" << valor_total << endl;
}

void bruteforce(pedras vetor[], int n, float volume_carrinho, float carga_carrinho) { // Algoritmo de Força Bruta com complexidade 2^n
    float melhor_lucro = 0;
    int melhor_combinacao[n];
    int melhor_tamanho_combinacao = 0;

    for (int i = 1; i < (1 << n); ++i) { // Obs.: Descobri essa 'sintaxe' com uma ajuda do chat-gpt para testar 2^n combinações, deslocando o bit 1 n vezes para a esquerda
        float peso_total = 0;
        float volume_total = 0;
        float valor_total = 0;
        int combinacao[n];
        int tamanho_combinacao = 0;

        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                peso_total += vetor[j].peso;
                volume_total += vetor[j].volume;
                valor_total += vetor[j].preco;
                combinacao[tamanho_combinacao++] = j;
            }
        }

        if (peso_total <= carga_carrinho && volume_total <= volume_carrinho && valor_total > melhor_lucro) {
            melhor_lucro = valor_total;
            melhor_tamanho_combinacao = tamanho_combinacao;
            for (int k = 0; k < tamanho_combinacao; ++k) {
                melhor_combinacao[k] = combinacao[k];
            }
        }
    }

    cout << "Melhor combinação de pedras: ";
    for (int i = 0; i < melhor_tamanho_combinacao; ++i) {
        cout << vetor[melhor_combinacao[i]].nome << " ";
    }
    cout << "resultando R$" << melhor_lucro << endl;
}

int main(){
	int n; // Número de pedras preciosas a serem inseridas no vetor
	
	cin >> n;
	
	pedras pedra[n]; // Vetor do tipo 'pedras' para armazenar todas as pedras preciosas
	
	for(int i = 0; i < n; i++){
		cin >> pedra[i].nome >> pedra[i].volume >> pedra[i].peso >> pedra[i].preco; // Recebe todas as características de cada pedra (DEVE SER INSERIDO EM ORDEM DECRESCENTE POR PRECO)
	}
	
	float volume_carrinho = 1000; // Volume total do carrinho (metros cúbicos)
	float carga_carrinho = 400; // Carga total do carrinho (kg)

    int option; // Opção a ser escolhida: [1] Estratégia Gulosa ou [2] Bruteforce

    cout << "Digite [1] para a Estrategia Gulosa e [2] para fazer um Bruteforce: ";
    cin >> option;

    if(option == 1){ // Utiliza a função gulosa
        gulosa(pedra, n, volume_carrinho, carga_carrinho);
    } else if(option == 2) { // Utiliza a função de força bruta
        bruteforce(pedra, n, volume_carrinho, carga_carrinho);
    } else {
        cout << "Opção Inválida!" << endl;
    }

    return 0;
}