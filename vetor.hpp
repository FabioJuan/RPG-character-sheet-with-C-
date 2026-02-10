#ifndef vetor_hpp
#define vetor_hpp

#include <iostream>
#include "personagens.hpp"

using namespace std;

class Vetor {
    private:
    personagem* m_personagens;//parametros do array 
    int m_tamanho;//parametro do tamanho

    public:
    Vetor::Vetor(personagem* personagens, int tamanho): m_personagens(personagens), m_tamanho(tamanho) {}
    

    personagem cadasdastro(){
        personagem novo_jogador;
        printf("digite o seu nome:");
        cin >> novo_jogador.nome;

        printf("\n","digite o sua idade:");
        cin >> novo_jogador.idade;

        printf("\n","digite o sua classe:");
        cin >> novo_jogador.classe;

        printf("\n","digite o sua raça:");
        cin >> novo_jogador.raca;

        printf("\n","digite sua historia:");
        getline(cin,novo_jogador.descricao);

        printf("\n","digite o seu nome:");
        cin >> novo_jogador.sexo;

        while (novo_jogador.sexo != "f" and novo_jogador.sexo != "F" and 
                novo_jogador.sexo != "m" and novo_jogador.sexo != "M" and 
                novo_jogador.sexo != "n" and novo_jogador.sexo != "N")
        {
            cin >> novo_jogador.sexo;
        }

        return novo_jogador;

    }
    void add_lista(){
        cadasdastro();
    }
    void imprime_jogadores() {
        cout << "#id|#" << " #nome#"<<" #clase#"<<" #raça#"<<" #sexo#"<<" #idade#"<<" #descrição#";
        
        for(int i = 0;i <= m_tamanho;i++){
            cout << m_personagens[i].id << m_personagens[i].nome << m_personagens[i].classe << m_personagens[i].raca<< m_personagens[i].sexo << m_personagens[i].idade << m_personagens[i].descricao;
        
        }
    }


    void remove(int id) {
    } 

};

#endif