#ifndef PERSONAGENS_HPP
#define PERSONAGENS_HPP

#include <iostream>
#include <vector>
#include <string>


using namespace std;


struct itens
{
    string arma;
    string armadura;
    string acessorio;
};

struct status{
    float hp;
    int lv;
    int atk;
    int def;
    int inteligencia;
    int percepcao;
    int carisma;

};

struct personagem{
    int id;
    int idade;
    string sexo;
    string nome;
    string classe;
    string raca;
    string descricao;
    //a struct status quando personagem criado deve criar um status padrão lv 1
    status persona_s;
    itens inventario;
};
#endif 