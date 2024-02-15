#include <iostream>
#include <cstring>

using namespace std;

struct gladiador
{
	string nome;
	int forca;
	int habilidade;
	int idade;
	int vida;
};

// COMENTÁRIO SOBRE O CÓDIGO: Decidi incrementar um sistema de ataques por turno para deixar mais divertido.
// Entretanto, o objetivo do código foi cumprido ao mostrar o vencedor do combate após um dos gladiadores
// chegar a 0 pontos de vida. Espero que considerem. Obrigado!

void combate(string nome1, int vida1, int dano1, string nome2, int vida2, int dano2){
	while(vida1 > 0 || vida2 > 0){
		cout << endl;
		cout << "Turno de ataque de " << nome1 << endl;
		cout << "Dano: " << dano1 << endl;
		vida2 -= dano1;
		
		if(vida2 <= 0){
			cout << nome2 << " chegou a 0 pontos de vida!" << endl;
			cout << "Vitoria para " << nome1 << "!" << endl;
			break;
		}
		
		cout << nome2 << " esta com " << vida2 << " pontos de vida!" << endl;
		cout << "\n" << endl;
		cout << "Turno de ataque do " << nome2 << "!" << endl;
		cout << "Dano: " << dano2 << endl;
		vida1 -= dano2;
		
		if(vida1 <= 0){
			cout << nome1 << " chegou a 0 pontos de vida!" << endl;
			cout << "Vitoria para " << nome2 << "!" << endl;
			break;
		}
		
		cout << nome1 << " esta com " << vida1 << " pontos de vida!" << endl;
		
		cout << endl;
		
		if(vida1 > vida2){
			cout << "Vantagem para " << nome1 << endl;
		} else if(vida1 == vida2){
			cout << "Disputa muito acirrada!" << endl;
		} else {
			cout << "Vantagem para " << nome2 << endl;
		}
		
		cout << endl;
		
		cout << "Vamos para a proxima rodada!" << endl;
	}
}

int main(){
	gladiador g[5];
	int g1 = 0; // Gladiador 1
	int g2 = 0; // Gladiador 2
	int option = 0;
	
	for(int i = 0; i < 5; i++){
		cin.ignore();
		getline(cin, g[i].nome);
		cin >> g[i].forca >> g[i].habilidade >> g[i].idade;
		g[i].vida = 100;
	}
	do{
		cout << "[!] ESCOLHA OS GLADIADORES DA RODADA [!]" << endl;
		for(int i = 0; i < 5; i++){
			cout << "Numero: " << i << endl;
			cout << "Nome: " << g[i].nome << endl;
			cout << "Forca: " << g[i].forca << endl;
			cout << "Habilidade: " << g[i].habilidade << endl;
			cout << "Idade: " << g[i].idade << endl;
			cout << endl;
		}
		
		do {
			cout << "Gladiador 1: ";
			cin >> g1;
		}while(g1<0 || g1>5);
		
		cout << endl; // Quebra de Linha
		
		do {
			cout << "Gladiador 2: ";
			cin >> g2;	
		}while(g2<0 || g2>5 || g2 == g1);
		
		int danoGladiador1 = g[g1].forca + (g[g1].habilidade * g[g1].habilidade);
		int danoGladiador2 = g[g2].forca + (g[g2].habilidade * g[g2].habilidade);
	
		combate(g[g1].nome, g[g1].vida, danoGladiador1, g[g2].nome, g[g2].vida, danoGladiador2);
		cout << "Digite -1 para sair ou qualquer outra tecla para iniciar um novo combate: ";
		cin >> option;
	}while(option!=-1);
	
	return 0;
}