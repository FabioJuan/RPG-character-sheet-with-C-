#include <iostream>
#include <fstream>
#include <vector>
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



int cadastro_ficha(){
    status n_status = padrao(n_status);
    personagem jogador;
    printf("digite o seu nome:");
    cin >> jogador.nome;

    printf("\n","digite o sua idade:");
    cin >> jogador.idade;

    printf("\n","digite o sua classe:");
    cin >> jogador.classe;

    printf("\n","digite o sua raça:");
    cin >> jogador.raca;

    printf("\n","digite sua historia:");
    getline(cin,jogador.descricao);

    printf("\n","digite o seu nome:");
    cin >> jogador.sexo;

    while (jogador.sexo != "f" and jogador.sexo != "F" and jogador.sexo != "m" and jogador.sexo != "M" and jogador.sexo != "n" and jogador.sexo != "N")
    {
        cin >> jogador.sexo;
    }
    jogador.persona_s = n_status;
    
}


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
    personagem jogador[n_jogadores];
    
    menu();
    return 0;
}