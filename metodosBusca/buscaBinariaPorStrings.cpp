#include <iostream>
#include <cstring>

using namespace std;

struct aluno{
	char nome[50];
	int matricula;
};

void bubble_sort(aluno vetor[], int tamanho){
	char nomeAuxiliar[50];
	int matAuxiliar;
	bool trocado;
	
	do{ 
		trocado = false;
		for(int i = 0; i < tamanho-1; i++){ 
			if(strcmp(vetor[i].nome, vetor[i+1].nome) > 0){ 
				strcpy(nomeAuxiliar, vetor[i].nome);
				strcpy(vetor[i].nome, vetor[i+1].nome);
				strcpy(vetor[i+1].nome, nomeAuxiliar);
				matAuxiliar = vetor[i].matricula;
				vetor[i].matricula = vetor[i+1].matricula;
				vetor[i+1].matricula = matAuxiliar;
				trocado = true;
			}
		}
	}while(trocado);
}

int binaria(aluno vetor[], int tamanho, char nome[])
{
	bool achou; 
	int baixo, meio, alto;
	baixo = 0;
	alto = tamanho - 1;
	achou = false;
	while ((baixo <= alto) && (achou == false))
	{
		meio = (baixo + alto) / 2;
		if (strcmp(nome, vetor[meio].nome) < 0)
			alto = meio - 1;
		else if (strcmp(nome, vetor[meio].nome) > 0)
			baixo = meio + 1;
		else
			achou = true;
	}
	if (achou)
		return meio;
	else
		return -1;
}

int main(){
	aluno Aluno[1000];
	char nAluno[50];
	int i = 1;
	
	cin.getline(Aluno[0].nome, 50);
	cin >> Aluno[0].matricula;
	cin.ignore();
	
	while(strcmp(nAluno, "fim") != 0){
		cin.getline(nAluno, 50);
		if(strcmp(nAluno, "fim") == 0){
			break;
		} else {
			strcpy(Aluno[i].nome, nAluno);
			cin >> Aluno[i].matricula;
			cin.ignore();
		}
		i++;
	}
	
	int tamanho = i;
	
	bubble_sort(Aluno, tamanho);
	
	cin.getline(nAluno, 50);
	
	int retorno = binaria(Aluno, tamanho, nAluno);
	
	if(retorno != -1){
		cout << "\nAluno encontrado!" << endl;
		cout << "Nome: " << Aluno[retorno].nome << endl;
		cout << "Matricula: " << Aluno[retorno].matricula << endl;
	} else {
		cout << "\nAluno nao encontrado!" << endl;
	}
	
	return 0;
}