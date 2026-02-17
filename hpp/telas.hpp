#ifndef tela_hpp
#define tela_hpp

#include <iostream>
#include <fstream>
#include<cstdlib>
#include"personagens.hpp"
#include"edita_elem.hpp"

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

void detalhe_personagem(personagem &p_detalhado,bool foi_alterado){
    system("clear");
    ifstream arq;
    string linha;
    int editar;
    if(p_detalhado.sexo == "f" ||p_detalhado.sexo == "F" ){
        //escolhe o arquivo muie
        arq.open("./pixelart/muie.txt");
    }
    if(p_detalhado.sexo == "m" ||p_detalhado.sexo == "M" ){
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
    cout<<linha<<"id: "<<p_detalhado.id<<endl;
    getline(arq,linha);//linha3
    cout<<linha<<"(1)nome: "<<p_detalhado.nome<<endl;
    getline(arq,linha);//linha4
    cout<<linha<<"(2)classe: "<<p_detalhado.classe<<endl;
    getline(arq,linha);//linha5
    cout<<linha<<"(3)raça: "<<p_detalhado.raca<<endl;
    getline(arq,linha);//linha6
    cout<<linha<<"(4)sexo: "<<p_detalhado.sexo<<endl;
    getline(arq,linha);//linha7
    cout<<linha<<"(5)idade: "<<p_detalhado.idade<<endl;
    getline(arq,linha);//linha8
    cout<<linha<<"(6)level: "<<p_detalhado.persona_s.lv<<endl;
    getline(arq,linha);//linha9
    cout<<linha<<"(7)descrição: "<<p_detalhado.descricao<<endl;
    getline(arq,linha);//linha10
    cout<<linha<<endl;

    arq.close();

    //status
    cout<<"     status"<<endl;
    cout <<"(8)hp: "<<p_detalhado.persona_s.hp<<endl;
    cout <<"(9)ataque: "<<p_detalhado.persona_s.atk<<endl;
    cout <<"(10)defesa: "<<p_detalhado.persona_s.def<<endl;
    cout <<"(11)inteligencia: "<<p_detalhado.persona_s.inteligencia<<endl;
    cout <<"(12)percepção: "<<p_detalhado.persona_s.percepcao<<endl;
    cout <<"(13)carisma: "<<p_detalhado.persona_s.carisma<<endl;
    cout <<"    inventário"<<endl;
    cout <<"(14)arma: "<<p_detalhado.inventario.arma<<endl;
    cout <<"(15)armadura: "<<p_detalhado.inventario.armadura<<endl;
    cout <<"(16)acessorio: "<<p_detalhado.inventario.acessorio<<endl;
    while (editar != -1)
    {
        cout<<"você deseja editar algum atributo se não digite -1: ";
        cin >> editar;
        if(edit(p_detalhado,editar)){
            foi_alterado = true;
        }
    }
    
      

}


#endif