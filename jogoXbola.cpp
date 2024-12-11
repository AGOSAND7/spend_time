#include <iostream>
#include <vector>

void imprimirCampo(char campo[][3]);//funcao para imprimir campo

void jogada(char campo[][3],int *vez,bool *maquina);//funcao para cada jogada do usuario

bool verVitoria(char campo[][3],std::string* tipo);//funcao para verificar a vitoria

bool verCampo(int pos,char campo[][3]);//funcao para verificar se o campo foi prenchido

int jogadaMaquina(char campo[][3]);//funcao que retorna o campo da maquina

void menu(bool *maquina);//funcao que imprime o menu inicial

int aleatorio(int menor, int maior);//funcao para gerar numero aleatorio em um determinado intervalo

void imprimirVitoria(char campo[][3], std::string* tipo, int *vez,bool* maquina);//funcao que imprime o campo de vitoria

void limparTela();

//estrutura para guardar todas posicoes de vitoria
struct posicaoVitoria{
    int a;
    int b;
    int c;
};
struct posicaoBoleana{
    bool a=false;
    bool b=false;
    bool c=false;
};

//----------------------------------------------INCIO_MAIN---------------------------------------------------------------------------------------
int main(int argc, char* argv[]){
    char campo[3][3]={{'-','-','-'},{'-','-','-'},{'-','-','-'}};//A matriz do xbola
    int vez=2;//decide quem comeca
    bool maquina = false;//verifica se esta jogar contra maquina ou nao
    std::string tipo;//verifica o tipo de resultado[vitoria ou empate] e quem realmente ganhou

    //inicio do programa
    menu(&maquina);

    limparTela();

    //comeca o jogo ate que haja vencedor ou termine empatado
    while(!verVitoria(campo, &tipo)){
        imprimirCampo(campo);
        jogada(campo,&vez,&maquina);
        limparTela();
    }

    //imprime o campo de vitoria e informa quem ganhou
    imprimirVitoria(campo, &tipo,&vez,&maquina);

    return 0;
}
//---------------------------------------FIM_MAIN--------------------------------------------------------------------------------------------


//----------------Impressao da matriz--------------------------------------------------------------------------------------------------------
void imprimirCampo(char campo[][3]){
    std::cout<<"\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::cout<<campo[i][j]<<"        ";//imprimir a matriz
        }
        std::cout<<"\n\n";//quebra de linha
    }
}
//-----------------------------Fim Impressao----------------------------------------------------------------------------------------------


//--------------------------Jogada na Matriz------------------------------------------------------------------------------------------------
void jogada(char campo[][3],int *vez,bool *maquina){
    int posicao,i,j;//posicao a ser jogado pelo usuario

    if(*maquina && *vez==2){
        posicao = jogadaMaquina(campo);
        bool e=verCampo(posicao, campo);//verifica se a posicao a jogar esta vazio ou nao!
        while(!e){//vai tenando ate encotrar um campo disponivel
            posicao = aleatorio(1,9);
            e=verCampo(posicao, campo);
        }
    }else{
        std::cout<<"Digite a posicao: ";
        std::cin>>posicao;
    }

    //-------------------Converter Posciao--------------------------
    switch (posicao) {
        //converte a posicao digitada em posicoes reais do campo(matriz)
        case 1:i=0;j=0;break;
        case 2:i=0;j=1;break;
        case 3:i=0;j=2;break;
        case 4:i=1;j=0;break;
        case 5:i=1;j=1;break;
        case 6:i=1;j=2;break;
        case 7:i=2;j=0;break;
        case 8:i=2;j=1;break;
        case 9:i=2;j=2;break;
    }
    //--------------------------Fim---------------------------------

    bool campoVazio=verCampo(posicao, campo);//verifica se o campo esta ou nao vazio

    //----------------------Prenche a Jogada---------------------------
    if(posicao<=0 || posicao >9){
        //verifica se o campo existe
        std::cout<<"Este campo nao existe";
    }else if(!campoVazio){//verifica se o campo foi prenchido
        std::cout<<"Este campo ja foi prenchido";
    }else{
        //troca o valor da posicao especifica por "X" ou "O"
        if(*vez==1){
            campo[i][j]='X';
            *vez=2;
        }else if(*vez==2){
            campo[i][j]='O';
            *vez=1;
        }
    }
    //------------------------------Fim------------------------------
};
//----------------------------------Fim Jogada-------------------------------------------------------------------------------------


//----------------------------------Verificar Vitoria------------------------------------------------------------------------------
bool verVitoria(char campo[][3],std::string* tipo){
    for (int i = 0; i < 3; i++) {
        // Verificar linhas e colunas
        if ((campo[i][0] != '-' && campo[i][0] == campo[i][1] && campo[i][1] == campo[i][2]) ||
            (campo[0][i] != '-' && campo[0][i] == campo[1][i] && campo[1][i] == campo[2][i])) {
            *tipo = "vitoria";
            return true;
        }
    }
    // Verificar diagonais
    if ((campo[0][0] != '-' && campo[0][0] == campo[1][1] && campo[1][1] == campo[2][2]) ||
        (campo[0][2] != '-' && campo[0][2] == campo[1][1] && campo[1][1] == campo[2][0])) {
        *tipo = "vitoria";
        return true;
    }
    int cont=0;
    //empate
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(campo[i][j] !='-'){
                cont++;
            }
        }
    }
    if(cont==9){
        *tipo="empate";
        return true;
    }
    return false;
}
//----------------------------------Fim verVitoria--------------------------------------------------------------------------------


//----------------------------Imprimir Vitoria-----------------------------------------------------------------------------------
void imprimirVitoria(char campo[][3], std::string* tipo, int *vez,bool*maquina){
    if(*tipo == "empate"){
        std::cout<<"Empate";
        imprimirCampo(campo);
    }else if(*vez ==1 && *maquina){//se estiver jogando contra maquina
        std::cout<<"A maquina Venceu";
        imprimirCampo(campo);
    }else if(*vez==2){
        std::cout<<"Jogador "<<*vez-1<<" Venceu";
        imprimirCampo(campo);
    }else if(*vez==1){
        std::cout<<"Jogador "<<*vez+1<<" Venceu";
        imprimirCampo(campo);
    }
}
//-----------------------------------Fim Vitoria---------------------------------------------------------------------------------


//--------------------------------Verificar Campo---------------------------------------------------------------------------------
bool verCampo(int pos,char campo[][3]){
    bool cont=true;
    int i,j;
    switch (pos) {
        //converte a posicao digitada em posicoes reais do campo(matriz)
        case 1:i=0;j=0;break;
        case 2:i=0;j=1;break;
        case 3:i=0;j=2;break;
        case 4:i=1;j=0;break;
        case 5:i=1;j=1;break;
        case 6:i=1;j=2;break;
        case 7:i=2;j=0;break;
        case 8:i=2;j=1;break;
        case 9:i=2;j=2;break;
    }
    if(campo[i][j]=='O'||campo[i][j]=='X'){
        cont=false;
    }
    return cont;
}
//-------------------------------------Fim----------------------------------------------------------------------------------------


//-------------------------------------Jogada de Maquina--------------------------------------------------------------------------
int jogadaMaquina(char campo[][3]){
    posicaoVitoria posV[8]={{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,3},{3,5,7}};//todas possiveis campo de vitoria
    posicaoBoleana posB;
    std::vector<int> dadosJogado;//armazena as posicoes jogada pela maquina
    std::vector<char> dadosCampo;//armazena dados do campo


    //----------Armazena todos campos"Char" no vector--------------
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            dadosCampo.push_back(campo[i][j]);
        }
    }
    //------------------------FIM-----------------------------------

    int it=dadosCampo.size();
    //----------Armazena as posicoes como "int" no vetor---------------
    for(int i=0; i<it; i++){
        if(dadosCampo[i] == 'O'){
            dadosJogado.push_back(i+1);
        }
    }
    //----------------------Fim---------------------------------------

    int tam=dadosJogado.size();
    int jogarAqui;//campo de retorno
    jogarAqui=aleatorio(1,9);//atribui uma campo aletorio para retornar

    //---------------------Vendo Possibilidade de ganhar-----------------------
    for(int i=0;i<8;i++){

        for(int j=0;j<tam;j++){
            if(posV[i].a == dadosJogado[j]){
                posB.a=true;
            }
            if(posV[i].b == dadosJogado[j]){
                posB.b=true;
            }
            if(posV[i].b == dadosJogado[j]){
                posB.c=true;
            }
        }
        //Caso haja possibilidade de ganhar e o proximo campo a prencher estiver vazio ele vai ganhar
        if(posB.a==true && posB.b==true){
            if(verCampo(posV[i].c, campo)){
                jogarAqui=posV[i].c;
                break;
            }
        }else if(posB.a==true && posB.c==true){
            if(verCampo(posV[i].b, campo)){
                jogarAqui=posV[i].b;
                break;
            }
        }else if (posB.b==true && posB.c==true) {
            if(verCampo(posV[i].a, campo)){
                jogarAqui=posV[i].a;
                break;
            }
        }
        posB.a=false;
        posB.b=false;
        posB.c=false;
        //removendo os elementos atuais para colocar novos
    }
    //--------------------Fim----------------------------------------------
    return jogarAqui;//retorna a posicao de vitoria ou um aleatorio
}
//--------------------------------------Fim----------------------------------------------------------------------------------


//-----------MENU------------------------------------------------------------------------------------------------------------
void menu(bool *maquina){
    int opc;
    std::cout <<"========BEM VINDO=========";
    std::cout <<"\n1.Vs Maquina";
    std::cout <<"\n2.TWO-PLAYERS";
    std::cout <<"\nEscolha a opcao: ";
    std::cin >> opc;
    if(opc == 1)
    {
        *maquina=true;
    }
}
//-------------FIM-------------------------------------------------------------------------------------------------------------


//------------aleatorio--------------------------------------------------------------------------------------------------------
int aleatorio(int menor, int maior)
{
    srand((unsigned)time(0));
    return rand()%(maior-menor+1) + menor;
}
//---------------FIM------------------------------------------------------------------------------------------------------------


//--------------------------Limpar Tela------------------------------------------------------------------------------------------
void limparTela(){
    system("clear");
}
//---------------------------Fim------------------------------------------------------------------------------------------

//AGOSTINHO SAND
//Seja a mundanca que deseja ver no mundo
//--17/10/2024--17:54 -- 18/10/2024 -- 19:23
