#ifndef vetor_hpp
#define vetor_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include "personagens.hpp"

using namespace std;

class Vetor {
    private:
    personagem* m_personagens;//parametros do array 
    int m_tamanho  = 20;//parametro do tamanho
    int position = 0 ;//posição atua do vetor 

    personagem atribui_x( string &linha){
        personagem personaI;
        stringstream linhaI(linha);
        string dado;
        getline(linhaI,dado,';');
        personaI.id = stoi(dado);

        getline(linhaI,personaI.nome,';');
        getline(linhaI,personaI.classe,';');
        getline(linhaI,personaI.raca,';');
        getline(linhaI,personaI.sexo,';');
        
        getline(linhaI,dado,';');
        personaI.idade =stoi(dado);

        getline(linhaI,dado,';');
        personaI.persona_s.lv =  stoi(dado);

        getline(linhaI,personaI.descricao);

        return personaI;
    }

    void atualiza_vetor(){
        int novo_tamanho = m_tamanho + 10;
        personagem* novo_vetor = new personagem [novo_tamanho];

        for(int i = 0; i < m_tamanho; i++){
            novo_vetor[i] = m_personagens[i];
        }
        delete[] m_personagens;
        m_personagens = novo_vetor;
        m_tamanho = novo_tamanho;
    }

    void recebe(){
        position = 0;
        string linhas;
        ifstream arq("./src/fichas.txt");
        if(!arq.is_open()){
            cout <<"erro ao abrir o arquivo"<<endl;
            return;
        }
        while(getline(arq,linhas)){
            m_personagens[position] = atribui_x(linhas);
            position++;
            if(position == m_tamanho){
                atualiza_vetor();
            }    
        }
        arq.close();

}
    
    
    public:
    Vetor(personagem* personagens, int tamanho, int pos): m_personagens(personagens), m_tamanho(tamanho), position(pos) {}


    void escreve_lista(){
        ofstream arq_atualizaso("n.txt");
        string linha;
        int i;
       
             arq_atualizaso<< m_personagens[0].id<< ";"<<m_personagens[0].nome<<";"<<m_personagens[0].raca<<";"<<m_personagens[0].sexo<<";"<<m_personagens[0].idade<<";"<<m_personagens[0].descricao<< endl;
        arq_atualizaso.close();
    }


    void inicializa(){
        recebe();
    }

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
        novo_jogador.id = position;
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
    void add_lista(){
        personagem novo_personagem = cadasdastro();//faz o cadastro do novo personagem e retorna na variavel;
        int ultimo_p = position;
        if(position +1 >= m_tamanho ){
            atualiza_vetor();
            m_personagens[ultimo_p] = novo_personagem;
        }else{
            m_personagens[ultimo_p] = novo_personagem;
        }
        position++;
    }
    void imprime_jogadores() {
        int voltar = -2;
        cout << "#id|#" << " #nome#"<<" #clase#"<<" #raça#"<<" #sexo#"<<" #idade#"<<" #descrição#"<<endl;
        
        for(int i = 0;i < m_tamanho;i++){
            cout <<"|id: "<<m_personagens[i].id <<" |nome: "<< m_personagens[i].nome <<" |classe: "<< m_personagens[i].classe <<" |raça: "<< m_personagens[i].raca<<" |sexo: "<<m_personagens[i].sexo <<" |idade: "<< m_personagens[i].idade<<" |level: "<<m_personagens[i].persona_s.lv<<" |descrição: "<< m_personagens[i].descricao<<endl;
        }
        while(voltar !=-1)
        {
            cout<<"escolha o jogador que deseja detalhar pelo id, senão digite -1:";
            cin >> voltar;
        }
        
    }

};
/*
        string s_novopersonagem;
        //adiciona o novo personagem em um arquivo 
        ofstream novo_("./src/novo.txt");
        novo_ << novo_personagem.id<< ";"<<novo_personagem.nome<<";"<<novo_personagem.raca<<";"<<novo_personagem.sexo<<";"<<novo_personagem.idade<<";"<<novo_personagem.descricao;
        novo_.close();
        //coloca o personagem em uma string 
        ifstream le_novo("./src/novo.txt");
        getline(le_novo,s_novopersonagem);
        
        //fazer o vetor aumentar de tamanho caso ele n tenha mais espaço se não somente colocar na proxima posição
        return s_novopersonagem;
*/

#endif