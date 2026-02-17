#ifndef editaelem_hpp
#define editaelem_hpp

#include <iostream>
#include <fstream>
#include<cstdlib>
#include"personagens.hpp"

using namespace std;

bool edit(personagem &edit_elem,int escolha){
    string alteracao;
    switch(escolha){
        case 1:
            cout << "digite o novo nome: ";
            cin.ignore();
            getline(cin,alteracao);
            edit_elem.nome = alteracao;
            break;
        case 2:
            cout << "digite a nova classe: ";
            cin.ignore();
            getline(cin,alteracao);
            edit_elem.classe = alteracao;
            break;
        case 3:
            cout << "digite a nova raça: ";
            cin.ignore();
            getline(cin,alteracao);
            edit_elem.raca = alteracao;
            break;
        case 4:
            while ((alteracao != "m" || alteracao != "M")
                && (alteracao != "f" || alteracao != "F")
                && (alteracao != "n" || alteracao != "N"))
            {
                cout << "digite o novo sexo: ";
                cin.ignore();
                getline(cin,alteracao);
                edit_elem.sexo = alteracao;
            }
            break;
        case 5:
            cout << "digite a nova idade: ";
            cin.ignore();
            getline(cin,alteracao);
            edit_elem.idade = stoi(alteracao);
            break;
        case 6:
            cout << "digite o novo level: ";
            cin.ignore();
            getline(cin,alteracao);
            edit_elem.persona_s.lv = stoi(alteracao);
            break;
        case 7:
            cout << "digite a nova descrição: ";
            cin.ignore();
            getline(cin,alteracao);
            edit_elem.descricao = alteracao;
            break;
        case 8:
            cout << "digite os novos pontos de hp: ";
            cin.ignore();
            getline(cin,alteracao);
            edit_elem.persona_s.hp = stoi(alteracao);
            break;
        case 9:
            cout << "digite os novos pontos de ataque: ";
            cin.ignore();
            getline(cin,alteracao);
            edit_elem.persona_s.atk = stoi(alteracao);
            break;
         case 10:
            cout << "digite os novos pontos de defesa: ";
            cin.ignore();
            getline(cin,alteracao);
            edit_elem.persona_s.def = stoi(alteracao);
            break;
        case 11:
            cout << "digite os novos pontos de inteligencia : ";
            cin.ignore();
            getline(cin,alteracao);
            edit_elem.persona_s.inteligencia = stoi(alteracao);
            break;
        case 12:
            cout << "digite os novos pontos de percepção: ";
            cin.ignore();
            getline(cin,alteracao);
            edit_elem.persona_s.percepcao = stoi(alteracao);
            break;
        case 13:
            cout << "digite os novos pontos de carisma: ";
            cin.ignore();
            getline(cin,alteracao);
            edit_elem.persona_s.carisma = stoi(alteracao);
            break;
        case 14:
            cout << "digite a arma atual: ";
            cin.ignore();
            getline(cin,alteracao);
            edit_elem.inventario.arma = alteracao;
            break;
        case 15:
            cout << "digite a armadura atual: ";
            cin.ignore();
            getline(cin,alteracao);
            edit_elem.inventario.armadura = alteracao;
            break;
        case 16:
            cout << "digite o acessorio atual: ";
            cin.ignore();
            getline(cin,alteracao);
            edit_elem.inventario.acessorio = alteracao;
            break;     
    }
    if(escolha >= 1 && escolha <= 16){
        return true;
        cout <<"alterado com sucesso";
    }
    return false;
}
#endif