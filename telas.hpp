#ifndef tela_hpp
#define tela_hpp

#include <iostream>
#include<cstdlib>
#include"personagens.hpp"

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

        cout <<"                            (1)adicionar ficha"<<"\n";
        cout <<"                                (2)remover ficha"<<"\n";
        cout <<"                                (3)buscar ficha"<<"\n";
        cout <<"                                (4)listar ficha"<<"\n";
        cout <<"                                (5)fechar progama"<<"\n";
}

void detalhe_personagem(){
    
}
#endif