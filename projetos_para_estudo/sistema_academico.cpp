#include <iostream>
#include <string>
#include <locale>

using namespace std;

struct aluno {
	int matricula;
	string nome;
	int idade;
};

aluno cria_aluno(int){
	aluno a;
	
	cout << endl;
	
	cout << "Matrícula: ";
	cin>>a.matricula;
	
	cout << "Nome: ";
	cin>>a.nome;
	
	cout << "Idade: ";
	cin>>a.idade;
	
	return a;	
}

int busca_seq_aluno_mat(aluno alunos[], int n, int mat){
	   for(int i=0; i<n; i++){
		   if(mat == alunos[i].matricula){
			   return i;
		   }
	   }
	   return -1;	
}

void swap(int &matA, string &nomeA, int &idadeA, int &matB, string &nomeB, int &idadeB){
	int temp_matA;
	string temp_nomeA;
	int temp_idadeA;
	
	temp_matA = matA;
	matA = matB;
	matB = temp_matA;
	
	temp_nomeA = nomeA;
	nomeA = nomeB;
	nomeB = temp_nomeA;
	
	temp_idadeA = idadeA;
	idadeA = idadeB;
	idadeB = temp_idadeA;
}

void bubblesort(aluno alunos[], aluno vetor_ordenado[], int n){
	bool trocado;
	
	do{
		trocado = false;
		for(int i = 0; i < n-1; i++){
			if(alunos[i].matricula > alunos[i+1].matricula){
				swap(alunos[i].matricula, alunos[i].nome, alunos[i].idade, alunos[i+1].matricula, alunos[i+1].nome, alunos[i+1].idade);
				trocado = true;
			}
		}
	}while(trocado);
	//organiza o vetor
	
	for(int i = 0; i < n; i++){
		vetor_ordenado[i].matricula = alunos[i].matricula;
		vetor_ordenado[i].nome = alunos[i].nome;
		vetor_ordenado[i].idade = alunos[i].idade;
	}
}

int busca_bin_aluno_mat(aluno alunos[], int n, int mat){
	int inicio = 0;
	int fim = n - 1;
	int meio = 0;
	aluno alunos_ordenado[n];
	
	bubblesort(alunos, alunos_ordenado, n);
	
	//começa a repetição
	while(inicio <= fim)
	{
		meio = (inicio+fim)/2;
		if(mat == alunos_ordenado[meio].matricula){
			return meio;		
		} else {
			if(mat > alunos_ordenado[meio].matricula){
				inicio = meio + 1;
			} else {
				fim = meio - 1;
			}
		}
	}
	
	return -1;
}

int busca_seq_aluno_nome(aluno alunos[], int n, string nome){
	   for(int i=0; i<n; i++){
		   if(nome == alunos[i].nome){
			   return i;
		   }
	   }
	   return -1;	
}

int busca_seq_aluno_idade(aluno alunos[], int n, int idade){
	   int contador = 0;
	   for(int i=0; i<n; i++){
		   if( alunos[i].idade <= idade){
			   contador++;
		   }
	   }
	   return contador;	
}

int menu(){
	int option;
	
	
	cout << endl;
	cout << "[-] MENU DE OPÇÕES [-]" << endl;
	cout << "[1] Busca sequencial por matrícula" << endl;
	cout << "[2] Busca sequencial por nome" << endl;
	cout << "[3] Busca sequencial por idade" << endl;
	cout << "[4] Busca binária por matrícula" << endl;
	cout << "[5] Sair" << endl;
	cout << endl;
	
	cout << "Digite a opção desejada: ";
	cin >> option;
	
	while(option >5 || option < 1){
		cout << "Opção inválida! Digite novamente!" << endl;
		cout << endl;
		
		cout << "Digite a opção desejada: ";
		cin >> option;
	}
	
	return option;
}


int main(){
	setlocale(LC_ALL,"");
	
	int n, option, mat, resultado, idade_buscada;
	string nome;
	
	cout << "[!] INICIANDO SISTEMA ACADÊMICO [!]" << endl;
	cout << endl;
	
	cout << "Digite quantos alunos serão cadastrados no seu sistema: ";
	cin>>n;
	
	cout << endl;
	
	aluno alunos[n];

	for(int i=0;i<n;i++){
		alunos[i] = cria_aluno(i);
	}
	
	cout << endl;
	
	cout << "[+] SISTEMA ACADÊMICO - ADMIN [+]" << endl;
	
	cout << endl;
	
	cout << "[Made by] TioMathias / github.com/titiomathias [Made by]" << endl;
	
	cout << endl;
	
	cout << "O SISTEMA ACADÊMICO foi criado como um projeto modelo do curso de Algoritmos - Estrutura e Análise de dados." << endl;
	cout << "Esse código engloba pesquisa sequencial e binária com a ordenação BubbleSort para fins didáticos. Bons estudos!" << endl;
	
	option = menu();
	
	while(option != 5){
		switch(option)
		{
		case 1:
			int mat;
			cout << "Digite a matrícula: ";
			cin >> mat;
			cout << endl;
			
			resultado = busca_seq_aluno_mat(alunos, n, mat);
	
			if(resultado != -1){
				cout << "[!] MATRÍCULA ENCONTRADA [!]" << endl;
				cout << "Nome: ";
				cout<< alunos[resultado].nome <<endl;
				cout << "Matrícula: ";
				cout<< alunos[resultado].matricula <<endl;
				cout << "Idade: ";
				cout<< alunos[resultado].idade <<endl;
			} else {
				cout << "Aluno nao encontrado!" << endl;
			}
			break;
		case 2:
			cin.ignore();
			cout << "Digite o nome para busca: ";
			getline(cin, nome);
			cout << endl;
			
			resultado = busca_seq_aluno_nome(alunos, n, nome);
			
			if(resultado != -1){
				cout << "[!] NOME ENCONTRADO [!]" << endl;
				cout << "Nome: ";
				cout<< alunos[resultado].nome <<endl;
				cout << "Matrícula: ";
				cout<< alunos[resultado].matricula <<endl;
				cout << "Idade: ";
				cout<< alunos[resultado].idade <<endl;
			} else {
				cout << "Aluno nao encontrado!" << endl;
			}
			break;
		case 3:
			cout << "Digite a idade: ";
			cin >> idade_buscada;
			cout << endl;
	
			resultado = busca_seq_aluno_idade(alunos,n,idade_buscada);
			
			cout << "[!] RESULTADO [!]" << endl;
			cout << "Existe(m) " << resultado; 
			cout << " aluno(a)(s) com essa idade ou menor" << endl;
			break;
		case 4:
			cout << "Digite a matrícula: ";
			cin >> mat;
			cout << endl;
			
			resultado = busca_bin_aluno_mat(alunos, n, mat);
			
			if(resultado != -1){
				cout << "[!] MATRÍCULA ENCONTRADA [!]" << endl;
				cout << "Nome: ";
				cout<< alunos[resultado].nome <<endl;
				cout << "Matrícula: ";
				cout<< alunos[resultado].matricula <<endl;
				cout << "Idade: ";
				cout<< alunos[resultado].idade <<endl;
			} else {
				cout << "Aluno nao encontrado!" << endl;
			}
			break;
		default:
			break;
		}
		
		option = menu();
	}
	
	cout << "Programa finalizado!" << endl;
	
	return 0;	
}