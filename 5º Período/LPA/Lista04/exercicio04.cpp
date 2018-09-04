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

// metodo boolean para verficar se o teste executado pode ser aceitdo
bool isPossivel(vector<string> vectorString)
{
    bool resp = false;
    vector<char> vectorPrimeiroChar;
    vector<char> vectorUltimoChar;
 
    // for que recebe o vectorString e pega a primeira e ultima letra de cada palavra de todas position do vetor
    for(int i = 0; i < vectorString.size(); i++){

        vectorPrimeiroChar.push_back(vectorString[i].at(0));
        //vectorUltimoChar.push_back(vectorString[i[vectorString[i].at(size()-1)]]);

        cout << vectorPrimeiroChar[i] << endl;
        //cout << vectorUltimoChar[i] << endl;
    }

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

        // le n, que corresponde a quantidade de palavras no teste T
        n = lerInteiro();
        
        //for que percorre todas palavras do teste T e coloca na variavel vectorString
        for(int i = 0; i < n; i++){
            
            cin >> s;
            
            vectorString.push_back(s);

            
            
        }
        t--;

        isPossivel(vectorString);
    }

    
    return 0;
}
