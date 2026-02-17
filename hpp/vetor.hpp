#ifndef vetor_hpp
#define vetor_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include "personagens.hpp"
#include "telas.hpp"

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
        //cout<<"tentando converter ["<<dado<<"] id"<<endl;
        personaI.id = stoi(dado);

        getline(linhaI,personaI.nome,';');
        getline(linhaI,personaI.classe,';');
        getline(linhaI,personaI.raca,';');
        getline(linhaI,personaI.sexo,';');
        
        getline(linhaI,dado,';');
        //cout<<"tentando converter ["<<dado<<"] idade"<<endl;
        personaI.idade = stoi(dado);

        getline(linhaI,dado,';');
        //cout<<"tentando converter ["<<dado<<"] lv"<<endl;
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
        //cout << "consegui cenverter";
        arq.close();
    }
    //busca a posição do id especifico no vetor
    int busca_id_SI(int id_do_personagem){
        int position_personagem = 0;
        for(int i = 0; i < position;i++){
            if(m_personagens[i].id == id_do_personagem){
                position_personagem = i;
                return position_personagem;
            }
        }
        return -1;
    }
    //atribui os status ara casa personagem
    void atrubui_status(string &linha_s){
        //atribui status de cada jogador
        stringstream dados_linha(linha_s);
        string dado;
        getline(dados_linha,dado,';');
        int pos_id = busca_id_SI(stoi(dado));
        
        getline(dados_linha,dado,';');
        m_personagens[pos_id].persona_s.hp = stoi(dado);

        getline(dados_linha,dado,';');
        m_personagens[pos_id].persona_s.lv = stoi(dado);

        getline(dados_linha,dado,';');
        m_personagens[pos_id].persona_s.atk = stoi(dado);

        getline(dados_linha,dado,';');
        m_personagens[pos_id].persona_s.def = stoi(dado);

        getline(dados_linha,dado,';');
        m_personagens[pos_id].persona_s.inteligencia = stoi(dado);

        getline(dados_linha,dado,';');
        m_personagens[pos_id].persona_s.percepcao = stoi(dado);

        getline(dados_linha,dado);
        m_personagens[pos_id].persona_s.carisma = stoi(dado);
        //cout<<pos_id<<";"<<m_personagens[pos_id].persona_s.hp<<";"<<m_personagens[pos_id].persona_s.atk<<endl;
    }
    void recebe_status(){
        ifstream arq("./src/status_fichas.txt");
        string linhas;
        if(!arq.is_open()){
            cout<<"arquivo de status não encontrado"<<endl;
            cin >> linhas;
        }
        while(getline(arq,linhas)){
            atrubui_status(linhas);
        }
        arq.close();

    }
    void atribui_itens(string &linhas_itens){
        stringstream dados_itens(linhas_itens);
        string dado;
        getline(dados_itens,dado,';');
        int pos_id_itens = busca_id_SI(stoi(dado));

        getline(dados_itens,dado,';');
        m_personagens[pos_id_itens].inventario.arma = dado;

        getline(dados_itens,dado,';');
        m_personagens[pos_id_itens].inventario.armadura = dado;

        getline(dados_itens,dado);
        m_personagens[pos_id_itens].inventario.acessorio = dado;
    }
    void recebe_itens(){
        ifstream arq("./src/itens_fichas.txt");
        string linhas;
        if(!arq.is_open()){
            cout<<"arquivo de status não encontrado"<<endl;
            cin >> linhas;
        }
        while(getline(arq,linhas)){
            atribui_itens(linhas);
        }
        
    }
    int gera_id(){
        if(m_personagens[0].id != 0){
            return 0;
        }else{
            for(int i = 0;i < position;i++){
                if(m_personagens[i].id +1 != m_personagens[i+1].id){
                    return m_personagens[i].id +1;
                }
            }
        }
        return m_personagens[position-1].id +1;
    }
    
    
    public:
    Vetor(personagem* personagens, int tamanho, int pos): m_personagens(personagens), m_tamanho(tamanho), position(pos) {}

    //escreve no arquivo a lista de jogadores serve tambem para quando fro atualizar o vetor e o arquivo em add e remover 
    void escreve_lista(){
        ofstream arq_atualizaso("./src/fichas.txt");
        for (int i = 0; i <position;i++){
            if(m_personagens[i].id >= 0){
                arq_atualizaso<< m_personagens[i].id<< ";"
                                <<m_personagens[i].nome<<";"
                                <<m_personagens[i].classe<<";"
                                <<m_personagens[i].raca<<";"
                                <<m_personagens[i].sexo<<";"
                                <<m_personagens[i].idade<<";"
                                <<m_personagens[i].persona_s.lv
                                <<";"<<m_personagens[i].descricao
                                << endl;
            }
        }
        arq_atualizaso.close();
    }
    void escreve_lista_status(){
        ofstream aqr_status_a("./src/status_fichas.txt");
        for(int i = 0;i<position;i++){
            if(m_personagens[i].id >=0){
                aqr_status_a<<m_personagens[i].id<<";"
                <<m_personagens[i].persona_s.hp<<";"
                <<m_personagens[i].persona_s.lv<<";"
                <<m_personagens[i].persona_s.atk<<";"
                <<m_personagens[i].persona_s.def<<";"
                <<m_personagens[i].persona_s.inteligencia<<";"
                <<m_personagens[i].persona_s.percepcao<<";"
                <<m_personagens[i].persona_s.carisma<<endl;

            }
        }
        aqr_status_a.close();
    }
    void escreve_inv(){
        ofstream arq_inv("./src/itens_fichas.txt");
        for(int i = 0;i<position;i++){
            if(m_personagens[i].id >= 0){
                arq_inv << m_personagens[i].id<<";"
                <<m_personagens[i].inventario.arma<<";"
                <<m_personagens[i].inventario.armadura<<";"
                <<m_personagens[i].inventario.acessorio<<endl;
            }
        }
    }
    void sort_personagens(){
        personagem aux;
        for(int i = 0;i < position -1;i++){

            for(int j = 0;j <position -i -1;j++){

                if(m_personagens[j].id > m_personagens[j+1].id){
                    aux = m_personagens[j];
                    m_personagens[j] = m_personagens[j+1];
                    m_personagens[j+1] = aux;
                }
            }
            
        }
    }

    //inicializa colocando todos os elementos do arquivo no vetor 
    void receba_(){
        recebe();
        recebe_status();
        recebe_itens();
        sort_personagens();
    }
    void escreve_arquivos(){
        escreve_lista();
        escreve_lista_status();
        escreve_inv();
    }
    void atualiza(){
        escreve_arquivos();
        receba_();
        cout << position;
    }
    itens padrao_inv(itens inventario){
        inventario.arma = "graveto";
        inventario.armadura = "fita curativa";
        inventario.acessorio ="moeda de prata";
        return(inventario);
    }
    //status padarão (n sei se vou continuar com essa idaia)
    status padrao(status Spadrao){
        //status padrão de um novo personagem level 1 
        Spadrao.lv = 1;
        Spadrao.hp = 20;
        Spadrao.def = 10;
        Spadrao.atk = 10;
        Spadrao.carisma = 15;
        Spadrao.inteligencia = 15;
        Spadrao.percepcao = 15;
        return Spadrao;
    }
    //faz o cadastro de um novo jogador
    personagem cadasdastro(){
        personagem novo_jogador;
        novo_jogador.id = gera_id();
        cout<<"digite o seu nome:";
        cin.ignore();
        getline(cin >> ws,novo_jogador.nome);

        cout<<endl <<"digite o sua idade:";
        cin >> novo_jogador.idade;

        cout<<endl<<"digite o sua classe:";
        //cin.ignore();
        getline(cin >> ws,novo_jogador.classe);

        cout<<endl<<"digite o sua raça:";
        //cin.ignore();
        getline(cin >> ws,novo_jogador.raca);

        cout<<endl<<"digite sua historia:";
        //cin.ignore();
        getline(cin >> ws,novo_jogador.descricao);

        cout<<endl<<"digite o seu sexo:";
        cin >> novo_jogador.sexo;

        novo_jogador.persona_s = padrao(novo_jogador.persona_s);

        while (novo_jogador.sexo != "f" and novo_jogador.sexo != "F" and 
                novo_jogador.sexo != "m" and novo_jogador.sexo != "M" and 
                novo_jogador.sexo != "n" and novo_jogador.sexo != "N")
        {
            cin >> novo_jogador.sexo;
        }
        novo_jogador.inventario = padrao_inv(novo_jogador.inventario);
        return novo_jogador;

    }
    //adiciona um jogador na lista do arquivo  e no vetor 
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
        sort_personagens();
        escreve_arquivos();
    }
    //função para imprimir todos os jogadores funciona para o lista e remove 
    void imprime_jogadores() {
        system("clear");
        system("cls");
        cout << "#id|#" << " #nome#"<<" #clase#"<<" #raça#"<<" #sexo#"<<" #idade#"<<" #descrição#"<<endl;
        
        for(int i = 0;i < position;i++){
            if(m_personagens[i].id >= 0){
                cout <<"|id: "<<m_personagens[i].id 
                <<" |nome: "<< m_personagens[i].nome 
                <<" |classe: "<< m_personagens[i].classe 
                <<" |raça: "<< m_personagens[i].raca
                <<" |sexo: "<<m_personagens[i].sexo 
                <<" |idade: "<< m_personagens[i].idade
                <<" |level: "<<m_personagens[i].persona_s.lv
                <<" |descrição: "<< m_personagens[i].descricao<<endl;
            }
        }
    }
    //lista os jogadores com um criterio de parada para o usuario ver 
    void lista_jogadores(){
        bool alterado = false;
        imprime_jogadores();
        int voltar = 0;
        if(voltar >=0){
            cout<<"escolha o jogador que deseja detalhar pelo id, senão digite -1:";
            cin >> voltar;
            if (busca_id_SI(voltar) != -1){
                detalhe_personagem(m_personagens[busca_id_SI(voltar)]);
            }else{
                menu();
                cout<<"personagem não encontrado";
            }
            
        }  
        escreve_arquivos();
            
    }
    //sistema de busca
    // FAZER UM VERIFICADOR SE O ELEMENTO FOI ENCONTRADO E SE O ID É UM INTEIRO
    //imprime padrão para qualquer busca que o usuario quiser
    void imprime_elem_esp(int x){
        cout <<"|id: "<<m_personagens[x].id 
        <<" |nome: "<< m_personagens[x].nome 
        <<" |classe: "<< m_personagens[x].classe 
        <<" |raça: "<< m_personagens[x].raca
        <<" |sexo: "<<m_personagens[x].sexo 
        <<" |idade: "<< m_personagens[x].idade
        <<" |level: "<<m_personagens[x].persona_s.lv
        <<" |descrxião: "<< m_personagens[x].descricao<<endl;
    }

    //busca por id
    bool busca_id(int elm_id){
        for(int i = 0;i < position;i++){
            if(elm_id == m_personagens[i].id){
                imprime_elem_esp(i);
                return true;
            }
        }
        return false;
    }
    //busca por nome
    bool busca_nome(string elm_c){
        bool achou = false;
        for(int i = 0;i < position;i++){
            if(elm_c == m_personagens[i].nome){
                imprime_elem_esp(i);
                achou = true;
            }
        }
        return achou;
    }
    //busca por classe
    bool busca_classe(string elm_c){
        bool achou = false;
        for(int i = 0;i < position;i++){
            if(elm_c == m_personagens[i].classe){
                imprime_elem_esp(i);
                achou = true;
            }
        }
        return achou;
    }
    //busca por raça
    bool busca_raca(string elm_r){
        bool achou = false;
        for(int i = 0;i < position;i++){
            if(elm_r == m_personagens[i].raca){
                imprime_elem_esp(i);
                achou = true;
            }
        }
        return achou;
    }
    void busca(){
        system("clear");
        system("cls");
        int escolha, detalhe;
        string busca_;
        bool encontrado;
        char outra_b;
        cout<<"você deseja buscar por? \n"<<"(1)id\n"<<"(2)nome\n"<<"(3)classe\n"<<"(4)raça\n";
        cin>> escolha;
        system("clear");
        system("cls");
        cout<< "digite o elemento que deseja buscar: ";
        cin.ignore();
        getline(cin,busca_);
        switch(escolha){
            case 1:encontrado = busca_id(stoi(busca_)); break;
            case 2:encontrado = busca_nome(busca_);break;
            case 3:encontrado = busca_classe(busca_); break;
            case 4:encontrado = busca_raca(busca_); break;
        }
        if(!encontrado){
            cout << "jogador não encontrado"<<endl;
        }else{
            cout <<"deseja detallhar algum pernsonagem?[digite o id,se não digite -1]: ";
            cin >> detalhe;
            if(detalhe != -1){
                detalhe_personagem(m_personagens[busca_id_SI(detalhe)]);
            }else{
                cout << "deseja buscar outro jogador(es) [s/n]: ";
                cin >>outra_b;
            }
        }
        
        if(outra_b == 's' || outra_b == 'S'){
            busca();
        }
    }
    //fim de sistema de busca

    //sistema para remover 
    void remove(){
        int id_remove;
        imprime_jogadores();
        bool encontrado = false;
        cout<<"digite o id do jogador que deseje remover:";
        cin >> id_remove;
        for(int i =0; i <= position;i++){
            if(m_personagens[i].id == id_remove){
                m_personagens[i].id = -1;
                encontrado = true;
            }
        }
        if(!encontrado){
            cout<<"jogador não encontrado"<<endl;
        }
        atualiza();
    }
}; 

#endif