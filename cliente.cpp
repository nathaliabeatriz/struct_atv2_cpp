#include<bits/stdc++.h>
#include<ctime>
using namespace std;
time_t now = time(0);
tm *ltm = localtime(&now);

struct Data{
    int dia, mes, ano;
    int diaAtual = ltm->tm_mday;
    int mesAtual = ltm->tm_mon + 1;
    int anoAtual = ltm->tm_year + 1900;
    int calcularIdade(){
        int idade = anoAtual - ano;
        if(mesAtual - mes < 0){
            idade--;
        } else if(mesAtual - mes == 0){
            if(diaAtual - dia < 0) idade--;
        }
        return idade;
    }
};

struct Cliente{
    string nome;
    Data dataNasc;
    char sexo;
    int idade;

    void ler(){
        cout << "Digite o nome:\n";
        cin >> nome;
        cout << "Digite a data de nascimento:\n";
        scanf("%d/%d/%d", &dataNasc.dia, &dataNasc.mes, &dataNasc.ano);
        cout << "Digite o sexo:\n";
        cin >> sexo;
    }

    void imprimir(){
        cout << "Dados do cliente: \n";
        cout << "Nome: " << nome << endl;
        cout << "Data de nascimento: ";
        printf("%d/%d/%d\n", dataNasc.dia, dataNasc.mes, dataNasc.ano);
        cout << "Sexo: " << sexo << endl;
        cout << "Idade: " << dataNasc.calcularIdade() << endl << endl;
    }
};
int qtdClientes = 0;
struct Clientes{
    Cliente clientes[50];
    void cadastrar(){
        if(qtdClientes > 50){
            cout << "Limite de clientes atingido\n";
            return;
        }
        clientes[qtdClientes].ler();
        qtdClientes++;
    }
    void imprimir(){
        if(qtdClientes == 0){
            cout << "Nenhum cliente cadastrado\n";
            return;
        }
        for(int i=0; i<qtdClientes; i++){
            clientes[i].imprimir();
        }
    }
};

int main(){
    Clientes c;
    int opcao = 1;
    while(opcao!=3){
        cout << "1 - Cadastrar cliente\n";
        cout << "2 - Listar clientes\n";
        cout << "3 - Sair do programa\n";
        cin >> opcao;
        switch (opcao){
        case 1:
            c.cadastrar();
            break;
        
        case 2:
            c.imprimir();
            break;
        }
    }
    return 0;
}
