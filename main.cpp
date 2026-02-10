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
    cout <<"(2)remover ficha"<<"\n";
    cout <<"(3)buscar jogador"<<"\n";
    cout <<"(4)listar jogares"<<"\n";
}
int main(){
    int n_jogadores = 1;
    int position  = 0;
    int tela = 0;
    personagem *jogadores = new personagem[n_jogadores];// vetor dimanico 
    Vetor personagens = Vetor(jogadores, n_jogadores, position);//o array jogadores recebe uma classe 
    personagens.imprime_jogadores();
    menu();

    cin >> tela;
    switch (tela)
    {
    case 1: 
        personagens.add_lista();
        break;
    case 2:
        personagens.remove();
        break;
    case 3:
        break;
    case 4 :
        personagens.imprime_jogadores();
        break;
    default:

        break;
    }



    return 0;
}