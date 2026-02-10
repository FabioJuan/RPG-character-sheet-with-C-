#include <iostream>
#include <fstream>
#include "personagens.hpp"
#include "vetor.hpp"

using namespace std;


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
        
        break;
        
        default:
        break;
    }
    return tela;
}
int main(){
    int n_jogadores = 1;
    personagem *jogadores = new personagem[n_jogadores];// vetor dimanico 
    Vetor personagens = Vetor(jogadores, n_jogadores);//o array jogadores recebe uma classe 
    
    personagens.imprime_jogadores();

    menu();

    return 0;
}