#include <iostream>

using namespace std;

/*
Referências para desenvolvimento e estudo: http://www.decom.ufop.br/romildo/2012-1/bcc222/slides/06-recursividade.pdf

A recursividade é o mecanismo de programação do qual um objeto definido refere-se a ele mesmo para otimização de linguagens.

Uma função recursiva é aquela que é definida em si mesma, otimizando um processo em sua função através da mesma.

Esse algoritmo não se trata necessariamente de uma otimização, mas sim de uma DEMONSTRAÇÃO DE RECURSIVIDADE.
*/

int potencia(int a, int n){ // Função recursiva "potencia".
    if(n == 0){ // Caso o valor do qual a é elevado é 0, a função se finaliza.
        return 1; // Retorna 1, que é o resultado de qualquer número elevado a 0.
    }
    
    return a*potencia(a, n-1); // Caso n seja maior que zero, então podemos dizer que a*a^(n-1) OU a*potencia(a, n-1).
}

/* A função acima irá se executar n vezes, até que em algum momento n-1 seja igual a 0.
Quando ela finalmente parar de se executar, o valor de retorno será fornecido e cálculado para todas as execuções.
Retornando por fim o valor inicial que gostaríamos de cálcular.
*/

int main(){
    int a, n; // Váriaveis a = Base e n = expoente.
    
    cin >> a; // Leitura da base
    cin >> n; // Leitura do expoente
    
    cout << potencia(a, n) << endl; // Chamada da função recursiva
    
    return 0;
}