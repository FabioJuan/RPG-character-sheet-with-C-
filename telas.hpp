#ifndef tela_hpp
#define tela_hpp

#include <iostream>
#include <fstream>
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

void detalhe_personagem(personagem p_detalhado){
    system("clear");
    ifstream arq;
    string linha;
    int editar;
    if(p_detalhado.sexo == "f" ||p_detalhado.sexo == "F" ){
        //escolhe o arquivo muie
        arq.open("./pixelart/muie.txt");
    }
    if(p_detalhado.sexo == "h" ||p_detalhado.sexo == "M" ){
        //escolhe o arquivo muie
        arq.open("./pixelart/homi.txt");
    }
    if(p_detalhado.sexo == "n"||p_detalhado.sexo == "N" ){
        //escolhe o arquivo muie
    }
    getline(arq,linha);//linha0
    cout<<linha<<endl;
    getline(arq,linha);//linha1
    cout<<linha<<"geral"<<endl;
    getline(arq,linha);//linha2
    cout<<linha<<"(1)id: "<<p_detalhado.id<<endl;
    getline(arq,linha);//linha3
    cout<<linha<<"(2)nome: "<<p_detalhado.nome<<endl;
    getline(arq,linha);//linha4
    cout<<linha<<"(3)classe: "<<p_detalhado.classe<<endl;
    getline(arq,linha);//linha5
    cout<<linha<<"(4)raça: "<<p_detalhado.raca<<endl;
    getline(arq,linha);//linha6
    cout<<linha<<"(5)sexo: "<<p_detalhado.sexo<<endl;
    getline(arq,linha);//linha7
    cout<<linha<<"(6)idade: "<<p_detalhado.idade<<endl;
    getline(arq,linha);//linha8
    cout<<linha<<"(7)level: "<<p_detalhado.persona_s.lv<<endl;
    getline(arq,linha);//linha9
    cout<<linha<<"(8)descrição: "<<p_detalhado.descricao<<endl;
    getline(arq,linha);//linha10
    cout<<linha<<endl;
    arq.close();
    cout<<"você deseja editar algum atributo se não digite -1: ";
    cin >> editar;

    
}
#endif