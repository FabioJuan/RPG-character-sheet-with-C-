#ifndef vetor_hpp
#define vetor_hpp

#include <iostream>
#include "personagens.hpp"

using namespace std;

class Vetor {
    private:
    personagem* m_personagens;//parametros do array 
    int m_tamanho;//parametro do tamanho
    int position;

    void le_arquivo(){
        //le o arquivo principal de todos os personagens
    }
    void backup(){
        //escreve em um outro arquivo todos os personagens no arquivo principal e backup
    }
    public:
    Vetor::Vetor(personagem* personagens, int tamanho, int pos): m_personagens(personagens), m_tamanho(tamanho), position(pos) {}
    


    status padrao(status Spadrao){
        //status padrão de um novo personagem level 1 
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

        padrao(novo_jogador.persona_s);

        while (novo_jogador.sexo != "f" and novo_jogador.sexo != "F" and 
                novo_jogador.sexo != "m" and novo_jogador.sexo != "M" and 
                novo_jogador.sexo != "n" and novo_jogador.sexo != "N")
        {
            cin >> novo_jogador.sexo;
        }

        return novo_jogador;

    }
    void add_lista(){
        personagem novo_personagem = cadasdastro();
        //fazer o vetor aumentar de tamanho caso ele n tenha mais espaço se não somente colocar na proxima posição
        position++;

    }
    void imprime_jogadores() {
        cout << "#id|#" << " #nome#"<<" #clase#"<<" #raça#"<<" #sexo#"<<" #idade#"<<" #descrição#";
        
        for(int i = 0;i <= m_tamanho;i++){
            cout << m_personagens[i].id << m_personagens[i].nome << m_personagens[i].classe << m_personagens[i].raca<< m_personagens[i].sexo << m_personagens[i].idade << m_personagens[i].descricao;
        
        }
    }

    int ultimo_elemento(){
        int len = 0;        
        for(int i = 0;i <= m_tamanho;i++){
            len++;                
        }
        return len;
    }


    void remove() {
        imprime_jogadores();
    //criar a função que remove um personagem pelo id 
        position--;
    } 

};

#endif