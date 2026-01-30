#ifndef CADASTRO_HPP
#define CADASTRO_HPP
#include <iostream>
#include "pstatus.hpp"


using namespace std;

status padrao(status Spadrao){
    Spadrao.hp = 20;
    Spadrao.hp_atual = 20;
    Spadrao.lv = 20;
    Spadrao.xp = 0;
    Spadrao.xp_next_lv = 100;
    Spadrao.def = 10;
    Spadrao.atk = 10;
    Spadrao.carisma = 15;
    Spadrao.inteligencia = 15;
    Spadrao.percepcao = 15;
    return Spadrao;
}

personagem cadastro_ficha(){
    status n_status = padrao(n_status);
    personagem c_jogador;
    printf("digite o seu nome:");
    cin >> c_jogador.nome;

    printf("\n","digite o sua idade:");
    cin >> c_jogador.idade;

    printf("\n","digite o sua classe:");
    cin >> c_jogador.classe;

    printf("\n","digite o sua raça:");
    cin >> c_jogador.raca;

    printf("\n","digite sua historia:");
    getline(cin,c_jogador.descricao);

    printf("\n","digite o seu nome:");
    cin >> c_jogador.sexo;

    while (c_jogador.sexo != "f" and c_jogador.sexo != "F" and c_jogador.sexo != "m" and c_jogador.sexo != "M" and c_jogador.sexo != "n" and c_jogador.sexo != "N")
    {
        cin >> c_jogador.sexo;
    }
    c_jogador.persona_s = n_status;

    return c_jogador;
}



#endif 