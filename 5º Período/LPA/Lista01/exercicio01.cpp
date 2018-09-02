#include <stdlib.h>
#include <iostream>
using namespace std;


int** preencherMatriz (int n);
void print (int** matriz, int n);
int soma(int** matriz, int n);

int main() {

  int n;
  cin >> n;
  int** matriz = preencherMatriz(n);
  //print (matriz, n);
  cout << soma(matriz,n);
  
  return 0;
}

int** preencherMatriz (int n) {
  int** matriz = new int*[n];
  // Alocacação da Matriz
  for( int i = 0; i < n; i++)
    matriz[i] = new int[n];

  // for para preencher a matriz
  for( int i = 0; i < n; i++ ){
    for( int j = 0; j < n; j++){
      cin >> matriz[i][j];        
    }
  }  
  return matriz;
}

void print (int** matriz, int n) {
  for( int i = 0; i < n; i++ ){
    for( int j = 0; j < n; j++){         
      cout << "["<< matriz[i][j] << "] ";           
    }
    cout << endl;
  }
}

int soma(int** matriz, int n) {
  
  
  int somaMaxima = matriz[0][0];
  int somaHorizontal = matriz[0][0];
  int somaVertical = matriz[0][0];  
 
  // for para andar nas linhas
  for( int k = 0; k < n; k++) {
    somaVertical = somaHorizontal = matriz[0][0];
    for( int j = 0; j < n; j++) {
      for( int i = k ; i < n ; i++ ) {        
        somaVertical += matriz[i][j];
        somaHorizontal += matriz[j][i];
        
      } 
      if (somaVertical > somaMaxima ) somaMaxima = somaVertical;
      if (somaHorizontal > somaMaxima ) somaMaxima = somaHorizontal;  
     
    }
  } 
  return somaMaxima;
}