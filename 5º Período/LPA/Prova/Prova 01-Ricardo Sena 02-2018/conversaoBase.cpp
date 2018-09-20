#include <iostream>

using namespace std;

int n;
string s;

 void conversao(int numero,string base){
    short aux1, aux2;
    string aux3;

    if(base == "bin"){
        aux1 = numero; 
        aux1 = (aux1/2,5); //binario para decimal
        aux2 = (aux1/16,5); //binario para hexa
        cout << endl;
        cout << aux1 << " " << "dec" << endl;
        cout << aux2 << " " << "hex" << endl;
        cout << endl;
    }
    else if(base == "dec"){
        aux1 = numero; 
        aux1 = ((aux1/16)*10) + (aux1%16); //decimal para hexa
        aux2 = (aux1/2); //decimal para binario 
        cout << endl;
        cout << aux1 << " " << "hex" << endl;
        cout << aux2 << " " << "bin" << endl;
        cout << endl;
        
 
    }
    else{
        aux1 = numero;
        aux3 = numero;
        aux1 = (aux1/16); //hexa para decimal
        aux2 = aux2/16; //hexa para binario
        cout << endl;
        cout << aux1 << " " << "dec" << endl;
        cout << aux2 << " " << "bin" << endl;
        cout << endl;
 

    }
    
}

int main(){
    int nTeste;

    cin >> nTeste;

    for(int i = 0; i < nTeste; i++){
        cin >> n;
        cin >> s;
        cout << "Case" << " " << (i+1) << ":";
        conversao(n,s);
        
   }

    return 0;
}