#include <iostream>
#include <cstring>

using namespace std;

/*

O código a seguir armazena os dados de alunos emu um vetor struct (nome e matricula), e para parar de inserir dados você deve digitar "fim".
Após isso, você pode procurar por qualquer nome de aluno, e se ele estiver no vetor, será retornado sua matricula e nome.

Para isso utilizaremos busca binária, o que significa que teremos que ordenar por nome!

Para que possamos comparar umas com as outras e ordena-las em ordem alfabética usaremos a tabela ascii e a função strcmp(), string compare.

Usando a função strcmp, nós podemos comparar duas strings para que se retorne um número inteiro.

Por exemplo, comparando as strings "Abc" e "Abd": Temos o retorno -1, pois a letra c, comparada a letra d, está uma posição atrás.
Se comparássemos o contrário, "Abd" e "Abc", teríamos o retorno 1, pois a letra d está uma posição a frente de c.
E se elas fossem idênticas, "Abc" e "Abc", teríamos o retorno 0.

Utilizando isso poderemos realizar qualquer método de ordenação e busca, mesmo que para ordenar vetores de caracter.

*/ 

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
	int inicio, meio, fim;
	inicio = 0;
	fim = tamanho - 1;
	achou = false;
	while ((inicio <= fim) && (achou == false))
	{
		meio = (inicio + fim) / 2;
		if (strcmp(nome, vetor[meio].nome) < 0)
			fim = meio - 1;
		else if (strcmp(nome, vetor[meio].nome) > 0)
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
