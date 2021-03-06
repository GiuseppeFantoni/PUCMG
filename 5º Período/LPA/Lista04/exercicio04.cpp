#include <iostream>
#include <string>
#include <vector>

using namespace std;

// metodo para facilitar leitura de inteiro
int lerInteiro(){
    int x;
    cin >> x;  
    return x;
}

void impressao(bool test){
    //se possivel
    if(test){
        cout << "Ordering is possible." << endl;
    }

    //se nao possivel
    else{
        cout << "The door cannot be opened." << endl;
    }

}

//ver se as duas strings tem o mesmo char
bool iguais(string primeiroChar, string ultimoChar){
    bool res = true;
    int i = 0;

    while (i < primeiroChar.length() && res){

        if (primeiroChar[0] != ultimoChar[i]){
            res = false;
        }
        i++;
    }
    return res;
} 

// metodo boolean para verficar se o teste executado pode ser aceito
bool isPossivel(vector<char> primeiro, vector<char> ultimo)
{
    bool resp = false;
    string primeiroChar = "";
    string ultimoChar = "";
    string ult;
    string v;

    /* for que vai ater o tamanho do vector de char recebido para construir 2 string
    // a string primeiroChar recebe o primeiro char de todas palavras
    // a string ultimoChar recebe o ultimo char de todas palavras
    */
    for(int i = 0; i < primeiro.size(); i++) {
		primeiroChar = primeiroChar + primeiro[i]; 
		ultimoChar = ultimoChar + ultimo[i]; 
	}

    ult = ultimoChar;  // string clone

    for(int i = 0; i < primeiroChar.length(); i++){
        for(int j = 0; j < ult.length(); j++){
            if(primeiroChar[i] == ult[j]){
                ult.erase(j, 1); //deleta letra na pos j porque ele ja existe
                j = ultimoChar.length();
            } 
        } 
    }

    if(ult.length() == 1){ //se o tamanho do clone for 1 quer dizer que isPossible
        resp = true;
    }

    else if(ult.length() == 0) //quando for igual a zero temos que analisar as letras 
    {

        //caso os conjuntos n�o sejam identicos OU s�o identicos formados por apenas uma letra
        if(primeiroChar != ultimoChar || iguais(primeiroChar, ultimoChar)){
            resp = true;
        }

    } 

    /* for que recebe o vectorString e pega a primeira e ultima letra de cada palavra de todas position do vetor
    for(int i = 0; i < vectorString.size(); i++){

        vectorPrimeiroChar.push_back(vectorString[i].at(0));
        //vectorUltimoChar.push_back(vectorString[i[vectorString[i].at(size()-1)]]);

        cout << vectorPrimeiroChar[i] << endl;
        //cout << vectorUltimoChar[i] << endl;
    } */

    return resp;
}

int main(){

    string s;
    char c;
    int t;
    int n;

    // le t, que corresponde ao numero de teste
    t = lerInteiro();
    
    //while para rodar todos T testes do arquivo
    while(t > 0){

        vector<string> vectorString;
        vector<char> letraInicial; //vetor contendo as iniciais
        vector<char> letraFinal; //vetor contendo as letras finais

        // le n, que corresponde a quantidade de palavras no teste T
        n = lerInteiro();
        
        //for que percorre todas palavras do teste T e coloca na variavel vectorString
        for(int i = 0; i < n; i++){
            
            cin >> s;
            letraInicial.push_back(s[0]);
            letraFinal.push_back(s[s.length() - 1]);
        }

        impressao(isPossivel(letraInicial, letraFinal));

        t--;

    }

    
    return 0;
}
