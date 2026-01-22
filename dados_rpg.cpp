#include <iostream>
#include <fstream>
using namespace std;

int add_ficha(){

    int id = 0,level = 1;
    //dados do usuario
    string nome,classe,raca,descricao,sexo;
    //o usuario insere os dados 
    cout << "digite seu nome: ";
    cin >> nome;
    
    cout << "digite sua classe: ";
    cin >> classe;
    
    cout << "digite sua raça: ";
    cin >> raca;
    //string com palavras com espaço
    cout << "descreva a si mesmo: ";
    cin.ignore();
    getline(cin, descricao);
    //verifica se o valor inserido é valido
    while ((sexo != "F" and sexo != "f") and (sexo != "M" and sexo != "m") and (sexo != "N" and sexo != "n") )
    {
        cout << "digite seu sexo (F/M/N): ";
        cin >> sexo;
    }
    //abre o arquivo do novo jogador 
    ofstream novo_j("novo_jogador.txt");

    if(novo_j.is_open()){
        //incere os dados no arquivo
        novo_j <<id << ";" << level <<";"<< nome <<";"<< classe <<";"<< raca <<";"<< descricao;
        //fecha o arquivo 
        novo_j.close();
    }
    cout <<"dados gravados com sucesso";
    cin.ignore();
    cin.get();

    //atribui o valor da linha do novo jogador a uma string
    ifstream j_novo("novo_jogador.txt");
    string novojogador;
    getline(j_novo,novojogador);
    j_novo.close();
    cin.ignore();

    ifstream todos_jogadores("fichas.txt");
    string fichas;
    int n_jogadores = 0;
    string jogadores_anteriores[n_jogadores];
    if(todos_jogadores.is_open()){
        while (getline(todos_jogadores,fichas))
        {
            jogadores_anteriores[n_jogadores] = fichas;
            cout << jogadores_anteriores[n_jogadores];
            n_jogadores++;
        }
    }else{
        cout << "erro, não conseguimos encontrar os dados dos jogadores anteriores ";
    }
    cout << n_jogadores;

    for(int i = 0; i<n_jogadores;i++){
        cout<<jogadores_anteriores[i];
    }
    todos_jogadores.close();
    
    ofstream addjogador("fichas.txt");
    addjogador << "arq modificado";
    for(int i = 0;i < n_jogadores-4;i++){
        cout<<jogadores_anteriores[i]<<"\n";
    }
    addjogador.close();
    return 0;
}


int menu(){
    int tela = 0;
    cout <<"---------------------------------------------------------------"<<"\n" ;
    cout <<"-----------------criador de ficha de rpg-----------------------"<<"\n";
    cout <<"---------------------------------------------------------------"<<"\n";
    cout <<"(1)adicionar ficha"<<"\n";
    cout <<"(2)retirar ficha"<<"\n";
    cout <<"(3)buscar jogador"<<"\n";
    cout <<"(4)listar jogares"<<"\n";
    cin >> tela;
    switch (tela)
    {
    case 1:
        add_ficha();
        break;
    
    default:
        break;
    }
    return tela;
}
int main(){
    int n_jogadores = 1;
    //dados dos jogadores 
    //int id[n_jogadores];
    //int nivel[n_jogadores];
    string nome[n_jogadores];
    string classe[n_jogadores];
    string raca[n_jogadores];
    string descricao[n_jogadores];
    menu();
    return 0;
}