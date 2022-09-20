#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int chave;
    string palavra;
    char continuar = 'S';

    while(continuar=='S'){
        cout<<"Insira a palavra a ser criptografada."<<endl;
        cin >> palavra;
        cout<<"Insira a chave para criptografar"<<endl;
        cin >> chave;
        
        for(int j = 0;j < palavra.size(); j++){

            if((palavra[j] + chave) > 122){
                palavra[j] = palavra[j]-26;
            }
            palavra[j] = palavra[j] + chave;
        }
        cout<<palavra<< endl;
        cout<<"\nDeseja continuar?(S/N)"<<endl;
        cin>>continuar;
        continuar=toupper(continuar);
        palavra = "";
    }
    cout<<"finalizado"<<endl;
    return 0;
}