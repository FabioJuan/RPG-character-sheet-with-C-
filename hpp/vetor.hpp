#ifndef vetor_hpp
#define vetor_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include "personagens.hpp"
#include "telas.hpp"
#include <algorithm>

using namespace std;

class Vetor {
    private:
    personagem* m_personagens;//parametros do array 
    int m_tamanho  = 20;//parametro do tamanho
    int position = 0 ;//posição atual do vetor 

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
        int novo_tamanho = m_tamanho + 10;//aumenta o tamanho
        personagem* novo_vetor = new personagem [novo_tamanho];//cria um vetor dinamico

        for(int i = 0; i < m_tamanho; i++){
            novo_vetor[i] = m_personagens[i];//copia os dados do vetor antigo
        }
        delete[] m_personagens;//deleta o vetor antigo
        m_personagens = novo_vetor;//atribui o novo vetor em m_personagens
        m_tamanho = novo_tamanho;//atualiza o tamanho
    }

    void recebe(){//recebe a linha especifica e atribui a m_personagens[x]
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
        //id 
        getline(dados_linha,dado,';');
        int pos_id = busca_id_SI(stoi(dado));//busca o id especifico da linha
        //cada geline lê ate o ; do arquivo
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
    void atribui_itens(string &linhas_itens){//pega a linha de recebe itens e adiciona os itens daquela linha no vetor x
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
    void recebe_itens(){//le cada linha do arquivo dos itens para atribuir os itens de todo o vetor
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
    int gera_id(){//gera um id diferente de todos os existentes 
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
    
    string lower_(string text){
        transform(text.begin(),text.end(),text.begin(), ::tolower);
        return text;
    }
    public:
    Vetor(personagem* personagens, int tamanho, int pos): m_personagens(personagens), m_tamanho(tamanho), position(pos) {}

    //escreve no arquivo a lista de jogadores serve tambem para quando fro atualizar o vetor e o arquivo em add e remover 
    void escreve_lista(){//escreve os personagens no arquivo fichas .txt
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
    void escreve_lista_status(){//escreve os atributos dos personagens em status fichas.txt
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
    void escreve_inv(){//escreve os itens dos vetores em itens fichas.txt
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
    void sort_personagens(){//organiza os vetores por id
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
        recebe();//coloca as fichas nos vetores personagens em fichas.txt
        recebe_status();//coloca os atributos dos personagens em status_fichas
        recebe_itens();//coloca os itens do status itens
        sort_personagens();//organiza os vetores por id
    }
    void escreve_arquivos(){//escreve os 3 arquivos em sequencia
        escreve_lista();//
        escreve_lista_status();
        escreve_inv();
    }
    void atualiza(){//escreve o vetor atualizado e recebe 
        escreve_arquivos();
        receba_();
    }
    itens padrao_inv(itens inventario){//itens padrão para um novo jogador(pode editr dps se quiser)
        inventario.arma = "graveto";
        inventario.armadura = "fita curativa";
        inventario.acessorio ="moeda de prata";
        return(inventario);
    }
    //status padarão para um novo jogador pode mudar se quiser
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
    personagem cadastro(){
        personagem novo_jogador;
        novo_jogador.id = gera_id();
        cout<<"digite o seu nome:";
        cin.ignore();
        getline(cin >> ws,novo_jogador.nome);//ws limpa o buffer assim a setença inteira é atribuida

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
                novo_jogador.sexo != "n" and novo_jogador.sexo != "N")//verifica se é  um sexo valido uhhhh lacração 
        {
            cin >> novo_jogador.sexo;
        }
        novo_jogador.inventario = padrao_inv(novo_jogador.inventario);
        return novo_jogador;

    }
    //adiciona um jogador na lista do arquivo  e no vetor 
    void add_lista(){
        personagem novo_personagem = cadastro();//faz o cadastro do novo personagem e retorna na variavel;
        int ultimo_p = position;
        if(position +1 >= m_tamanho ){//verifica se o vetor está cheio
            atualiza_vetor();//se estiver cheio atualiza os vetores;
            m_personagens[ultimo_p] = novo_personagem;
        }else{//adiciona o novo personagem
            m_personagens[ultimo_p] = novo_personagem;
        }
        position++;//aumenta a posição final
        sort_personagens();//organiza os ids
        escreve_arquivos();//reescreve os arquivos atualizado
    }
    //função para imprimir todos os jogadores funciona para o lista e remove 
    void imprime_jogadores() {
        limpa_tela();
        cout << "#id|#" << " #nome#"<<" #clase#"<<" #raça#"<<" #sexo#"<<" #idade#"<<" #descrição#"<<endl;
        //printa na ordem a cima
        for(int i = 0;i < position;i++){
            if(m_personagens[i].id >= 0){
                cout <<endl<<"|id: "<<m_personagens[i].id 
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
            if (busca_id_SI(voltar) != -1){//vai para tela do jogador mais detalhada
                detalhe_personagem(m_personagens[busca_id_SI(voltar)]);//busca o id escolhido e detalha função em telas.hpp
            }else{//se o jogador não existe ele volta ao menu
                menu();
                cout<<"personagem não encontrado";
            }
            
        }  
        escreve_arquivos();//reescreve em caso de modificação 
            
    }
    //sistema de busca
    //imprime padrão para qualquer busca que o usuario quiser
    void imprime_elem_esp(int x){//imprime somente um elemento especifico
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
    bool busca_intervalo(){
        int x, y;
        cout<< "digite o intervalo que deseja (ex x = 10 y = 20)";
        cin >> x >> y;
        if(y < position && (x < y && (x > 0 && y > 0))){
            for(int i = x;i<=y;i++){
                imprime_elem_esp(i);
            }
            return true;
        }else{
            cout<< "intervalo invalido"<<endl;
            return false;
        }
    }
    //busca por nome
    bool busca_nome(string elm_c){
        bool achou = false;
        for(int i = 0;i < position;i++){
            if(lower_(elm_c) == lower_(m_personagens[i].nome)){
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
            if(lower_(elm_c) == lower_(m_personagens[i].classe)){
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
            if(lower_(elm_r) == lower_(m_personagens[i].raca)){
                imprime_elem_esp(i);
                achou = true;
            }
        }
        return achou;
    }
    void busca(){
        limpa_tela();
        int escolha, detalhe;
        int x,y;
        string busca_;
        bool encontrado;
        char outra_b = 'n';
        cout<<"você deseja buscar por? \n"<<"(1)id\n"<<"(2)nome\n"<<"(3)classe\n"<<"(4)raça\n"<<"(5)busca por intervalo do vetor\nqualquer tra tecla para voltar;";
        cin>> escolha;
        limpa_tela();
        if(escolha >=1 && escolha <=5){

            switch(escolha){
                case 1:cout<< "digite o elemento que deseja buscar: ";
                        cin.ignore();
                        getline(cin,busca_);
                        encontrado = busca_id(stoi(busca_)); 
                    break;
                case 2:cout<< "digite o elemento que deseja buscar: ";
                        cin.ignore();
                        getline(cin,busca_);
                        encontrado = busca_nome(busca_);
                    break;
                case 3: cout<< "digite o elemento que deseja buscar: ";
                        cin.ignore();
                        getline(cin,busca_);
                        encontrado = busca_classe(busca_);
                    break;
                case 4:cout<< "digite o elemento que deseja buscar: ";
                        cin.ignore();
                        getline(cin,busca_);
                        encontrado = busca_raca(busca_);
                    break;
                case 5:encontrado = busca_intervalo();
            }
            if(!encontrado ){
                cout << "jogador não encontrado"<<endl;
            }else{
                //

                cout <<"deseja detallhar algum pernsonagem?[digite o id,se não digite -1]: ";
                cin >> detalhe;
                if(detalhe >= 0){
                    detalhe_personagem(m_personagens[busca_id_SI(detalhe)]);//detlha o personagem que for escolhido no sistema de busca
                }else{//verifica se deseha buscar outro
                    cout << "deseja buscar outro jogador(es) [s/n]: ";
                    cin >>outra_b;
                }
            }
            //se sim ele retorna ele mesmo
            if(outra_b == 's' || outra_b == 'S'){
                busca();
            }
        }
    }
    //fim de sistema de busca

    //sistema para remover 
    void remove(){
        int id_remove;//digita do jogador para remover
        imprime_jogadores();//imprime a lista de todos os jogadores
        bool encontrado = false;//serve para saber se o jogador foi encontrado
        cout<<"digite o id do jogador que deseje remover:";
        cin >> id_remove;//recebe o jogador para remover
        for(int i =0; i <= position;i++){//procura o jogador
            if(m_personagens[i].id == id_remove){
                m_personagens[i].id = -1;//atribui um valor neativo no id(o arquivo não le id negativos então ele some do arquivo)
                encontrado = true;//encontrou o jogador
            }
        }
        if(!encontrado){//se não for encontrado ele avisa
            cout<<"jogador não encontrado"<<endl;
        }
        position --;
        cout<< position<<endl;
        atualiza();//atualiza o arquivo para eleminar de ambos(personagem some do arquivo e do vetor)
    }
}; 

#endif