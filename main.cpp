#include <iostream>
#include <fstream>
#include <cstdlib>
#include "./hpp/personagens.hpp"
#include "./hpp/vetor.hpp"
#include "./hpp/telas.hpp"

using namespace std;   

int main(){
    menu();
    int n_jogadores = 1;
    int position  = 0;
    int tela = 0;
    bool rodando = true;
    personagem *jogadores = new personagem[n_jogadores];// vetor dimanico 
    Vetor personagens = Vetor(jogadores, n_jogadores, position);//o array jogadores recebe uma classe 
    personagens.receba_();
    personagens.atualiza();
    cin >> tela;
    while (rodando)
    {
        switch (tela)
        {

            case 1:
                //adiciona personagens na lista
                personagens.add_lista();
                tela = 0;
                break;
            case 2:
                //remove
                personagens.remove();
                tela = 0;
                break;
            case 3:
                //busca
                personagens.busca();
                tela = 0;
                break;
            case 4 :
                //lista os personagens
                personagens.lista_jogadores();
                tela = 0;
                break;
            case 5:
                limpa_tela();
                rodando = false;
                break;
            default:
                menu();
                cin >> tela;
                break;
            }
        }
        
    return 0;
}