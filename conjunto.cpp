#include<bits/stdc++.h>
using namespace std;
struct Conjunto{
    int cjt[20];
    int n;
    void criarConj(){
        n = 0;
        cout << "Conjunto vazio criado!\n";
    }
    void ler(){
        cout << "Quantos elementos voce deseja adicionar?\n";
        int qtd;
        cin >> qtd;
        if(qtd > 20){
            cout << "Quantidade maxima = 20\n";
            qtd = 20;
        }
        for(int i=0; i<qtd; i++){
            cin >> cjt[i];
            n++;
        }
    }
    void imprimir(){
        if(n==0) {
            cout << "Conjunto vazio\n";
            return;
        }
        for(int i=0; i<n; i++){
            cout << cjt[i] << " ";
        }
        cout << endl;
    }
};

struct Operacoes{
    Conjunto cjts[2];
    void uniao(){
        cout << "Preencha os dados dos conjuntos:\n";
        cout << "Conjunto 1:\n";
        cjts[0].criarConj();
        cjts[0].ler();
        cout << "Conjunto 2:\n";
        cjts[1].criarConj();
        cjts[1].ler();

        cout << "Uniao dos dois conjuntos:\n";
        set<int>cjtUniao;
        for(int i=0; i<cjts[0].n; i++){
            cjtUniao.insert(cjts[0].cjt[i]);
        }
        for(int i=0; i<cjts[1].n; i++){
            cjtUniao.insert(cjts[1].cjt[i]);
        }
        cout << "{";
        for(auto i:cjtUniao){
            cout << i << " ";
        }
        cout << "}";
        cout << endl << endl;
    }
    void intersecao(){
        cout << "Preencha os dados dos conjuntos:\n";
        cout << "Conjunto 1:\n";
        cjts[0].criarConj();
        cjts[0].ler();
        cout << "Conjunto 2:\n";
        cjts[1].criarConj();
        cjts[1].ler();

        cout << "Intersecao dos dois conjuntos:\n";
        cout << "{";
        for(int i=0; i<cjts[0].n; i++){
            for(int j=0; j<cjts[1].n; j++){
                if(cjts[0].cjt[i] == cjts[1].cjt[j]){
                    cout << cjts[0].cjt[i] << " ";
                }
            }
        }
        cout << "}";
        cout << endl << endl;
    }
};
int main(){
    Conjunto c;
    Operacoes o;
    int opcao=0;
    while(opcao != 6){
        cout << "1 - Criar um conjunto vazio\n";
        cout << "2 - Ler os dados de um conjunto\n";
        cout << "3 - Fazer a uniao de 2 conjuntos\n";
        cout << "4 - Fazer a intersecao de 2 conjuntos\n";
        cout << "5 - Imprimir conjunto\n";
        cout << "6 - Sair do programa\n";
        cin >> opcao;
        switch (opcao){
        case 1:
            c.criarConj();
            break;
        
        case 2:
            c.ler();
            break;
        
        case 3:
            o.uniao();
            break;
            
        case 4:
            o.intersecao();
            break;

        case 5:
            c.imprimir();
            break;
        }
    }
    return 0;
}
