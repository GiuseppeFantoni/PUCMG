#include <iostream>

using namespace std;

// Procura o representante de um amigo ( pra quem ele aponta)
int findDad(int i, int grupo[]) {
    if( grupo[i] != i ) {
        grupo[i] = findDad(grupo[i],grupo);
    }
    return grupo[i];
}

// Verifica se dois elementos estão no mesmo grupo
bool sameGroup(int x, int y, int grupo[]) {
    return (findDad(x,grupo) == findDad(y,grupo));
}

// Faz a conexão entre dois amigos
void conectar(int x, int y, int grupo[], int pessoas[], int rank[]) {

    // Verifica se os dois membros não pertencem ao mesmo grupo
    if(!sameGroup(x,y,grupo)) {

        // Verifica se o rank de um é maior do que o outro e junta-se ao menor deles.
        if(rank[x] > rank[y] ) { 
            grupo[y] = x;
            pessoas[x] += pessoas[y];
        } else {
            grupo[x] = y;
            pessoas[y] += pessoas[x];
            
            // se estão no mesmo nível, escolhe um elemento ( no caso o y) para ser o representante do outro.
            if( rank[x] == rank[y]) {
                rank[x] = rank[x] + 1;
            }
        }
    }
}

int maiorGrupo(int pessoas[], int populacao) {
    int resp = 0;
    for( int i = 0 ; i < populacao; i++ )
        resp = ( pessoas[i] > resp ) ? pessoas[i] : resp;
    return resp;

}

void maiorGrupo() {

    int populacao;
    int dupla;
    int x;
    int y;

    cin >> populacao;
    cin >> dupla;

    int pessoas[populacao];
    int grupos[populacao];
    int rank[populacao];

    for(int i = 0;  i < populacao; i++ ){
        pessoas[i] = 1;
        grupos[i]  = i;
        rank[i] = 0;
    }

    for ( int i = 0; i < dupla; i++ ) {
        cin >> x;
        cin >> y;
        conectar(findDad(x-1,grupos),findDad(y-1,grupos),grupos,pessoas,rank);
    }

    cout << maiorGrupo(pessoas,populacao) << endl; 

}

int main(){
    int numeroTestes;

    cin >> Testes;

    while (numeroTestes > 0 ){
        maiorGrupo();
        numeroTestes --;
    }

    return 0;
}