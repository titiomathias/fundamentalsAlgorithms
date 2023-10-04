#include <iostream>

using namespace std;

/*
Refer�ncias para desenvolvimento e estudo: http://www.decom.ufop.br/romildo/2012-1/bcc222/slides/06-recursividade.pdf

A recursividade � o mecanismo de programa��o do qual um objeto definido refere-se a ele mesmo para otimiza��o de linguagens.

Uma fun��o recursiva � aquela que � definida em si mesma, otimizando um processo em sua fun��o atrav�s da mesma.

Esse algoritmo n�o se trata necessariamente de uma otimiza��o, mas sim de uma DEMONSTRA��O DE RECURSIVIDADE.
*/

int potencia(int a, int n){ // Fun��o recursiva "potencia".
    if(n == 0){ // Caso o valor do qual a � elevado � 0, a fun��o se finaliza.
        return 1; // Retorna 1, que � o resultado de qualquer n�mero elevado a 0.
    }
    
    return a*potencia(a, n-1); // Caso n seja maior que zero, ent�o podemos dizer que a*a^(n-1) OU a*potencia(a, n-1).
}

/* A fun��o acima ir� se executar n vezes, at� que em algum momento n-1 seja igual a 0.
Quando ela finalmente parar de se executar, o valor de retorno ser� fornecido e c�lculado para todas as execu��es.
Retornando por fim o valor inicial que gostar�amos de c�lcular.
*/

int main(){
    int a, n; // V�riaveis a = Base e n = expoente.
    
    cin >> a; // Leitura da base
    cin >> n; // Leitura do expoente
    
    cout << potencia(a, n) << endl; // Chamada da fun��o recursiva
    
    return 0;
}