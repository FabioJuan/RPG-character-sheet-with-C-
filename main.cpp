#include <iostream>
#include <fstream>
#include <cstdlib>
#include "personagens.hpp"
#include "vetor.hpp"
#include "telas.hpp"

using namespace std;   

int main(){
    menu();
    int n_jogadores = 1;
    int position  = 0;
    int tela = 0;
    bool rodando = true;
    menu();
    personagem *jogadores = new personagem[n_jogadores];// vetor dimanico 
    Vetor personagens = Vetor(jogadores, n_jogadores, position);//o array jogadores recebe uma classe 
    personagens.inicializa();
    cin >> tela;
    while (rodando)
    {
        switch (tela)
        {
            case 1: 
                personagens.add_lista();
                break;
            case 2:
                //remove
                personagens.remove();
                break;
            case 3:
                //buscar ficha
                break;
            case 4 :
                personagens.lista_jogadores();
                break;
            case 5:
                system("clear");
                rodando = false;
                break;
            default:
                menu();
                cin >> tela;
                break;
            }
            menu();
            cin >> tela;
        }
        
    return 0;
}