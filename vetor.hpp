#ifndef vetor_hpp
#define vetor_hpp

#include <iostream>
#include <fstream>
#include "personagens.hpp"

using namespace std;

class Vetor {
    private:
    personagem* m_personagens;//parametros do array 
    int m_tamanho  = 70;//parametro do tamanho
    int position;//posição atua do vetor 


    void atualiza_vetor(){
        int novo_tamanho = m_tamanho + 10;
        m_personagens = new personagem[m_tamanho];
        personagem* novo_vetor = new personagem [novo_tamanho];

        for(int i = 0; i < m_tamanho; i++){
            novo_vetor[i] = m_personagens[i];
        }
        delete[] m_personagens;
        m_personagens = novo_vetor;
        m_tamanho = novo_tamanho;
    }

    void add_em_vetor(){
        ifstream fichas("./src/fichas.txt");
        int tamanho_linhas = conta_linhas();
        string dado;
        for(int i = 0 ;i < tamanho_linhas; i++){
            if(position == m_tamanho){//atualiza o vetor se necessario
            atualiza_vetor();
            }
            while(getline(fichas,dado,';')){
                
            }

        }
            
    }
    int conta_linhas(){
        int linhas = 0;
        string cont;
        ifstream arq("./src/fichas.txt");
        while (getline(arq,cont))
        {
            linhas++;
        }
        arq.close();
        position = linhas -1;
        return linhas;
    }
    
    public:
    Vetor(personagem* personagens, int tamanho, int pos): m_personagens(personagens), m_tamanho(tamanho), position(pos) {}
    


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
        cout<<"digite o seu nome:";
        cin.ignore();
        getline(cin,novo_jogador.nome);

        cout<<endl <<"digite o sua idade:";
        cin >> novo_jogador.idade;

        cout<<endl<<"digite o sua classe:";
        cin.ignore();
        getline(cin,novo_jogador.classe);

        cout<<endl<<"digite o sua raça:";
        cin.ignore();
        getline(cin,novo_jogador.raca);

        cout<<endl<<"digite sua historia:";
        cin.ignore();
        getline(cin,novo_jogador.descricao);

        cout<<endl<<"digite o seu sexo:";
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
    string add_lista(){
        personagem novo_personagem = cadasdastro();//faz o cadastro do novo personagem e retorna na variavel;
        string s_novopersonagem;
        //adiciona o novo personagem em um arquivo 
        ofstream novo_("./src/novo.txt");
        novo_ << novo_personagem.id<< ";"<<novo_personagem.nome<<";"<<novo_personagem.raca<<";"<<novo_personagem.sexo<<";"<<novo_personagem.idade<<";"<<novo_personagem.descricao;
        novo_.close();
        //coloca o personagem em uma string 
        ifstream le_novo("./src/novo.txt");
        getline(le_novo,s_novopersonagem);
        le_novo.close();
        //fazer o vetor aumentar de tamanho caso ele n tenha mais espaço se não somente colocar na proxima posição
        return s_novopersonagem;
    }
    void imprime_jogadores() {
        cout << "#id|#" << " #nome#"<<" #clase#"<<" #raça#"<<" #sexo#"<<" #idade#"<<" #descrição#";
        
        for(int i = 0;i <= m_tamanho;i++){
            cout <<"id: "<<m_personagens[i].id <<" nome: "<< m_personagens[i].nome <<" classe: "<< m_personagens[i].classe <<" raça: "<< m_personagens[i].raca<<" sexo"<<m_personagens[i].sexo <<" idade: "<< m_personagens[i].idade<<" level"<<m_personagens[i].persona_s.lv<<" descrição: "<< m_personagens[i].descricao;
        }
    }

    int ultimo_elemento(){
        int len = 0;        
        for(int i = 0;i <= m_tamanho;i++){
            len++;                
        }
        return len;
    }
    void ln(){
        
        cout << conta_linhas();
    }

    void remove() {
        imprime_jogadores();
        position--;
    } 

};

#endif