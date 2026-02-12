#include <iostream>
#include <fstream>
#include <cstdlib>
#include "personagens.hpp"
#include "vetor.hpp"

using namespace std;   

void menu(){
    system("clear");
    int tela = 0;
    const std::string titulo = "\
         _         _                                                           \n\
  __ _ _(_)__ _ __| |___ _ _    _ __  ___ _ _ ___ ___ _ _  __ _ __ _ ___ _ __  \n\
 / _| '_| / _` / _` / _ \\ '_|  | '_ \\/ -_) '_(_-</ _ \\ ' \\/ _` / _` / -_) '  \\ \n\
 \\__|_| |_\\__,_\\__,_\\___/_|    | .__/\\___|_| /__/\\___/_||_\\__,_\\__, \\___|_|_|_|\n\
                               |_|                 _ _ _ __  __|___/           \n\
                                                  | '_| '_ \\/ _` |             \n\
                                                  |_| | .__/\\__, |             \n\
                                                      |_|   |___/              \n\
";
    cout << titulo;

    cout <<"                                (1)adicionar ficha"<<"\n";
    cout <<"                                (2)remover ficha"<<"\n";
    cout <<"                                (3)buscar ficha"<<"\n";
    cout <<"                                (4)listar ficha"<<"\n";
    cout <<"                                (5)fechar progama"<<"\n";
}
int main(){
    int n_jogadores = 1;
    int position  = 0;
    int tela = 0;
    bool rodando = true;
    menu();
    personagem *jogadores = new personagem[n_jogadores];// vetor dimanico 
    Vetor personagens = Vetor(jogadores, n_jogadores, position);//o array jogadores recebe uma classe 
    cin >> tela;
    while (rodando)
    {
        switch (tela)
        {
            case 1: 
                personagens.add_lista();
                break;
            case 2:
                personagens.remove();
                break;
            case 3:
                //buscar ficha
                personagens.ln();
                break;
            case 4 :
                personagens.imprime_jogadores();
                break;
            case 5:
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