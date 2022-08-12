#include <iostream>
#include <vector>
using namespace std;

//Pseudonimos: Marcos Vinicius Boava, Felipe Rangel Michalszeszen, Joao Vitor

// typedef struct{
    vector<int> arestas[2000];
    char torre[2000];
    bool cinza[2000] = { false };//todos iniciam como não visitados
    int cont;
//}Grafo;
void addAresta(int a, int b) {//bidirecional
    arestas[a].push_back(b);
    arestas[b].push_back(a);
}

void dfs(int i) {//visit

    cinza[i] = true;//verice visitado
    if(torre[i]=='B'){//se B então cont ++
        cont++;
    }
    for (auto j: arestas[i]) {
        if (cinza[j] == false){
            dfs(j);//chamada recursiva com o elemento do for each
        }

    }
}

void Componente(int n){//componente recebe pariedade de cont//dfs//alem de par o cont de B é conexo
    for(int i=1;i<=n;i++){
        cont=0;
        if(!cinza[i]){
            dfs(i);
        }
        if(cont%2==1){
            cout<<"N"<<endl;
            return;
        }
    }
    cout<<"Y"<<endl;
}

int main() {
    int n,m,a,b;
    bool possivel;
    while (cin >> n >> m){
        for(int i=1;i<=n;i++){
            cinza[i]=false;//reseta valores 
        }
        for(int i=1;i<=n;i++){
            cin>>torre[i];
        }
        for(int j=1;j<=m;j++){
            cin>>a>>b;
            addAresta(a,b);
        }
        Componente(n);
        for(int j=0;j<=2000;j++){
            arestas[j].clear();//limpa para a próxima execção
        }
    }
}
/*
https://gist.github.com/sr6033/3d4a018fc0ae598616ca11f134e060c5
https://github.com/manosriram-youtube/algorithms/blob/master/dfs.cpp
*/
/*
#include <iostream>
#include <vector>
using namespace std;
// typedef struct{
    vector<int> arestas[2000];
    char torre[2000];
    bool cinza[2000] = { false };
    int cont;
//}Grafo;
void addAresta(int a, int b) {
    arestas[a].push_back(b);
    arestas[b].push_back(a);
}

void contador(int n){
    if(cont%2==0){
        cout<<"Y"<<endl;
    }else{
        cout<<"N"<<endl;
    }
}

void dfs(int i) {
    if (cinza[i] == true) return;

    //cout << i << " ";
    cinza[i] = true;
    
    for (auto j: arestas[i]) {
        //AQUI
        cont=0;
        dfs(j);
        if(torre[j]=='B'){
            //torre[j]='A';
            cont++;
        }

    }
    //return cont;
}

int main() {
    int n,m,a,b;
    bool possivel;
    while (cin >> n >> m){
        for(int i=1;i<=n;i++){
            cinza[i]=false;
            //torre[i]='';
        }
        for(int i=1;i<=n;i++){
            cin>>torre[i];
        }
        for(int j=1;j<=m;j++){
            cin>>a>>b;
            addAresta(a,b);
        }
        for(int i=1;i<=n;i++){
            cont=0;
            if(!cinza[i]){
                dfs(i);
            }
            if(cont%2==0){
                cout<<"Y"<<endl;
            }else{
                cout<<"N"<<endl;
            }
        }
    }
}

https://gist.github.com/sr6033/3d4a018fc0ae598616ca11f134e060c5
https://github.com/manosriram-youtube/algorithms/blob/master/dfs.cpp

*/