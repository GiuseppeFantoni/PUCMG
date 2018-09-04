#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lerInteiro(){
    int x;
    cin >> x;  
    return x;
}

bool isPossivel(vector<string> vectorString)
{
    bool resp = false;
    vector<char> vectorPrimeiroChar;
    vector<char> vectorUltimoChar;
 
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

    t = lerInteiro();
    
    while(t > 0){

        vector<string> vectorString;

        n = lerInteiro();
        cout << "N:" << n << endl;

        for(int i = 0; i < n; i++){
            
            cin >> s;
            cout << s.length();
            vectorString.push_back(s);

            cout << vectorString[i] << endl;
            
        }
        t--;

        isPossivel(vectorString);
    }

    
    return 0;
}
