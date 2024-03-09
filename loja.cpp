#include<bits/stdc++.h>
using namespace std;

struct Funcionario{
    string nome, cargo;
    double salarioBase, beneficios, descontos, salarioLiquido;

    void ler(){
        cout << "Digite o nome do funcionario: \n";
        cin >> nome;
        cout << "Digite o cargo do funcionario: \n";
        cin >> cargo;
        cout << "Digite o valor do salario base: \n";
        cin >> salarioBase;
        cout << "Digite o valor de beneficios: \n";
        cin >> beneficios;
        cout << "Digite o valor dos descontos: \n";
        cin >> descontos;
        salarioLiquido = salarioBase+beneficios-descontos;
    }

    void imprimir(){
        cout << "Dados do funcionario:\n";
        cout << "Nome: " << nome << endl;
        cout << "Cargo: " << cargo << endl;
        cout << "Salario Base      " << salarioBase << endl;
        cout << "Beneficios        " << beneficios << endl;
        cout << "Descontos         " << descontos << endl;
        cout << "Salario Liquido   " << salarioLiquido << endl << endl;
    }
};
int qtdFunc = 0;
struct Loja{
    Funcionario funcionarios[10];
    void cadastrar(){
        if(qtdFunc > 10){
            cout << "Limite de funcionarios atingido\n";
            return;
        }
        funcionarios[qtdFunc].ler();
        qtdFunc++;
    }
    void imprimir(){
        if(qtdFunc == 0){
            cout << "Nenhum funcionario foi cadastrado.\n";
            return;
        }
        for(int i=0; i<qtdFunc; i++){
            funcionarios[i].imprimir();
        }
    }
    void mediaSalarial(){
        if(qtdFunc == 0){
            cout << "Nenhum funcionario foi cadastrado.\n";
            return;
        }
        double media=0;
        for(int i=0; i<qtdFunc; i++){
            media += funcionarios[i].salarioLiquido;
        }
        media = media/qtdFunc;
        printf("Media salarial: %.2lf\n\n", media);
    }
    void maiorSalario(){
        if(qtdFunc == 0){
            cout << "Nenhum funcionario foi cadastrado.\n";
            return;
        }
        double maior = 0;
        int pos;
        for(int i=0; i<qtdFunc; i++){
            if(funcionarios[i].salarioLiquido > maior){
                maior = funcionarios[i].salarioLiquido;
                pos = i;
            }
        }
        cout << "Funcionario com maior salario:\n";
        funcionarios[pos].imprimir();
    }
};
int main(){
    Loja l;
    int opcao;
    while(opcao!=5){
        cout << "1 - Cadastrar funcionarios\n";
        cout << "2 - Listar funcionarios\n";
        cout << "3 - Calcular media salarial\n";
        cout << "4 - Maior salario\n";
        cout << "5 - Sair do programa\n";
        cin >> opcao;
        switch (opcao){
        case 1:
            l.cadastrar();
            break;
        
        case 2:
            l.imprimir();
            break;

        case 3:
            l.mediaSalarial();
            break;

        case 4:
            l.maiorSalario();
            break;
        }
    }
    return 0;
}
