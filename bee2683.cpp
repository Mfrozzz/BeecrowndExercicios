#include<iostream>
#include<queue>
#include<utility>

using namespace std;
/*Pseudonimos: Marcos Vinicius Boava, Felipe Rangel Michalszeszen, Joao Vitor*/
/*
first: peso
second first: origem
second second: destino
*/
int contador;

void Kruskal(priority_queue<pair<int,pair<int,int>>> arestas){
    int aux[1001], x;
    for(int i=1;i<1001;i++){
        aux[i]=i;//inicia vvetor de auxilio ou A
    }
    while(!arestas.empty()){//enquanto fila não estiver vazia //.top() == primeiro da fila
        if(aux[arestas.top().second.first] != aux[arestas.top().second.second]){
            //se origem diferente de destino
            contador+= arestas.top().first;//soma dos pesos
            x=aux[arestas.top().second.first];//x recebe aux de valor de origem
            aux[arestas.top().second.first]=aux[arestas.top().second.second];//pos de origem recebe destino -> <-
            for(int i=1; i <= 1001;i++){
                if(aux[i] == x){//se na posição do aux == valor da origem
                    aux[i] = aux[arestas.top().second.second];// aux[i] vira destino
                }
            }
        }
        arestas.pop();//retirando da fila - 
    }
}

int main(){
    priority_queue<pair<int,pair<int,int>>> arestas;
    priority_queue<pair<int,pair<int,int>>> arestas2;
    int n,a,b,p,max,min = 0;
    cin>> n;

    for(int i=1;i <= n;i++){
        cin>> a >> b >>p;
        arestas.push(make_pair(p, make_pair(a, b)));//insere nas arestas o peso - e o par de origem,destino +
        arestas2.push(make_pair(-p, make_pair(a, b)));//insere nas arestas o peso - e o par de origem,destino -
    }
    Kruskal(arestas);
    cout << contador << endl;

    contador=0;//reseta valor

    Kruskal(arestas2);
    cout << (contador*-1) << endl;

    return 0;
}