#include <iostream>
#include <fstream>

using namespace std;   

int main(){
    string linha;
    ifstream arq("homi.txt");
    if(!arq.is_open()){
        cout<< "falha ao abrir";
        return 0;
    }
    while (getline(arq,linha))
    {
        cout<< linha;
    }
    
}