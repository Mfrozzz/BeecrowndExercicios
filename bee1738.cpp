#include <iostream>

using namespace std;

#define infinito 1738

/*Pseudonimos: Marcos Vinicius Boava, Felipe Rangel Michalszeszen, Joao Vitor*/

int main(){

    int n,a,b;
	bool tem_empresa;
	string empresas;
	
	while ((cin>>n)&&(n!=0)){
		int matriz[n][n][26];
        
        //todos os pontos da matriz recebem infinito
        //para que depois aqueles que possuem ligação
        //recebam 1, representando a aresta direcionada
		for (int i = 0 ; i < n ; i++){
			for (int j = 0 ; j < n; j++){
				for (int k = 0 ; k < 26; k++){
					matriz[i][j][k] = infinito;
				}
			}
		}
		
		while((cin>>a>>b)&&((a!=0)&&(b!=0))){
            a-=1;
            b-=1;
			cin >> empresas;
			for (int i = 0 ; i < empresas.length(); i++){
				matriz[a][b][empresas[i] - 'a'] = 1;
			}
		}
		
		//for externo que percorre pelas letras do alfabeto
        //das quais as empresas são representadas
		for (int letras = 0 ; letras < 26; letras++){
    		//floyd-Warshall
		    for (int i = 0 ; i < n ; i++){
		        for (int j = 0 ; j < n ; j++){
			        for (int k = 0; k < n; k++){
					matriz[j][k][letras] = min(matriz[j][k][letras], 
                                           matriz[j][i][letras] + 
                                           matriz[i][k][letras]);
				    }
			    }
		    }
	    }
		
		while((cin>>a>>b)&&((a!=0)&&(b!=0))){
			tem_empresa = false;
            a-=1;
            b-=1;
			for (int i = 0 ; i < 26 ; i++){
				if (matriz[a][b][i] != infinito) {
					cout << (char)(i+'a');
					tem_empresa = true;
				}
			}
			if (!tem_empresa){ 
			    cout << '-';
			}
			cout << endl;
		}
		cout << endl;
	}
}