#include <iostream>
#include <cstdlib>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
using namespace std;
void jogada(char xbola[][3],int*minhaVez,int posicao, bool *quemganhou);
bool vitoria(char xbola[][3],char *p);
void imprime(char xbola[][3]);
int quemComeca(int jogador1, int jogador2);
void imprime_vitoria(char xbola[][3], char *posicao_vitoria);

int main(){
    int posicao;
    char array[3][3]={{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    srand((unsigned)time(0));
    int minhaVez = quemComeca(1,2);
    bool quemganhou;
    char posicao_vitoria;

    while(vitoria(array,&posicao_vitoria)==false){
        imprime(array);
        cout <<"Jogador " << ANSI_COLOR_RED<< minhaVez<< ANSI_COLOR_RESET <<" Digite a Posicao: ";
        cin >>posicao;
        system("clear");
        // quemganhou=vitoria(array);
        jogada(array,&minhaVez,posicao,&quemganhou);
        cout << endl;
    }

    system("clear");
    imprime_vitoria(array,&posicao_vitoria);
    cout<<endl;
    if(quemganhou)
    {
        cout << "Victoria Jogador " << ANSI_COLOR_RED << minhaVez-1 << ANSI_COLOR_RESET;
    }else{
        cout << "Victoria Jogador " << ANSI_COLOR_RED << minhaVez+1 << ANSI_COLOR_RESET;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void imprime_vitoria(char xbola[][3], char *posicao_vitoria){
    for(int i=0;i<3;i++)
    {
        for(int j=0; j < 3;j++)
        {
            //cima
            if(*posicao_vitoria == 'c' && i==0){
                cout << "    " << ANSI_COLOR_RED <<xbola[i][j] << ANSI_COLOR_RESET << "    ";
            }else if(*posicao_vitoria=='c'){
                cout << "    " << xbola[i][j] << "    ";
            }
            //meio_horizontal
            if(*posicao_vitoria == 'h' && i==1){
                cout << "    " << ANSI_COLOR_RED <<xbola[i][j] << ANSI_COLOR_RESET << "    ";
            }else if(*posicao_vitoria=='h'){
                cout << "    " << xbola[i][j] << "    ";
            }
            //baixo horizontal
            if(*posicao_vitoria == 'b' && i==2){
                cout << "    " << ANSI_COLOR_RED <<xbola[i][j] << ANSI_COLOR_RESET << "    ";
            }else if(*posicao_vitoria=='b'){
                cout << "    " << xbola[i][j] << "    ";
            }
        }
        cout << endl<<endl;
    }
    //esquerda
    if(*posicao_vitoria =='e'){
        cout << "    " <<ANSI_COLOR_RED <<xbola[0][0] << ANSI_COLOR_RESET << "    ";
        cout << "    " <<xbola[0][1] << "    ";
        cout << "    " <<xbola[0][2] << "    ";
        cout <<endl<< endl;
        cout << "    " <<ANSI_COLOR_RED <<xbola[1][0] << ANSI_COLOR_RESET << "    ";
        cout << "    " <<xbola[1][1] << "    ";
        cout << "    " <<xbola[1][2] << "    ";
        cout <<endl<< endl;
        cout << "    " <<ANSI_COLOR_RED <<xbola[2][0] << ANSI_COLOR_RESET << "    ";
        cout << "    " <<xbola[2][1] << "    ";
        cout << "    " <<xbola[2][2] << "    ";
    }
    //meio horizontal
    if(*posicao_vitoria =='v'){
        cout << "    " <<xbola[0][0] << "    ";
        cout << "    " <<ANSI_COLOR_RED <<xbola[0][1] << ANSI_COLOR_RESET << "    ";
        cout << "    " <<xbola[0][2] << "    ";
        cout <<endl<< endl;
        cout << "    " <<xbola[1][0] << "    ";
        cout << "    " <<ANSI_COLOR_RED <<xbola[1][1] << ANSI_COLOR_RESET << "    ";
        cout << "    " <<xbola[1][2] << "    ";
        cout <<endl<< endl;
        cout << "    " <<xbola[2][0] << "    ";
        cout << "    " <<ANSI_COLOR_RED <<xbola[2][1] << ANSI_COLOR_RESET << "    ";
        cout << "    " <<xbola[2][2] << "    ";
    }
    //direita
    if(*posicao_vitoria =='d'){
        cout << "    " <<xbola[0][0] << "    ";
        cout << "    " <<xbola[0][1] << "    ";
        cout << "    " <<ANSI_COLOR_RED <<xbola[0][2] << ANSI_COLOR_RESET << "    ";
        cout <<endl<< endl;
        cout << "    " <<xbola[1][0] << "    ";
        cout << "    " <<xbola[1][1] << "    ";
        cout << "    " <<ANSI_COLOR_RED <<xbola[1][2] << ANSI_COLOR_RESET << "    ";
        cout <<endl<< endl;
        cout << "    " <<xbola[2][0] << "    ";
        cout << "    " <<xbola[2][1] << "    ";
        cout << "    " <<ANSI_COLOR_RED <<xbola[2][2] << ANSI_COLOR_RESET << "    ";
    }
    //diagonal direita
    if(*posicao_vitoria =='r'){
        cout << "    " <<xbola[0][0] << "    ";
        cout << "    " <<xbola[0][1] << "    ";
        cout << "    " <<ANSI_COLOR_RED <<xbola[0][2] << ANSI_COLOR_RESET << "    ";
        cout <<endl<< endl;
        cout << "    " <<xbola[1][0] << "    ";
        cout << "    " <<ANSI_COLOR_RED <<xbola[1][1] << ANSI_COLOR_RESET << "    ";
        cout << "    " <<xbola[1][2] << "    ";
        cout <<endl<< endl;
        cout << "    " <<ANSI_COLOR_RED <<xbola[2][0] << ANSI_COLOR_RESET << "    ";
        cout << "    " <<xbola[2][1] << "    ";
        cout << "    " <<xbola[2][2] << "    ";
    }
    //diagonal esquerda
    if(*posicao_vitoria =='l'){
        cout << "    " <<ANSI_COLOR_RED <<xbola[0][0] << ANSI_COLOR_RESET << "    ";
        cout << "    " <<xbola[0][1] << "    ";
        cout << "    " <<xbola[0][2] << "    ";
        cout <<endl<< endl;
        cout << "    " <<xbola[1][1] << "    ";
        cout << "    " <<ANSI_COLOR_RED <<xbola[1][1] << ANSI_COLOR_RESET << "    ";
        cout << "    " <<xbola[1][2] << "    ";
        cout << endl<<endl;
        cout << "    " <<xbola[2][0] << "    ";
        cout << "    " <<xbola[2][1] << "    ";
        cout << "    " <<ANSI_COLOR_RED <<xbola[2][2] << ANSI_COLOR_RESET << "    ";
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void imprime(char xbola[][3]){
    for(int i=0;i<3;i++)
    {
        for(int j=0; j < 3;j++)
        {
            cout << "    " << xbola[i][j] << "    ";
        }
        cout << endl<<endl;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int quemComeca(int jogador1, int jogador2)
{
    return rand()%(jogador2-jogador1+1) + jogador1;
}
void jogada(char xbola[][3],int*minhaVez,int posicao,bool *quemganhou){
    int i=0;int j=0;
    bool posicaoValida = true;
    switch (posicao) {
        case 1:
            i=0;
            j=0;
            break;
        case 2:
            i=0;
            j=1;
            break;
        case 3:
            i=0;
            j=2;
            break;
        case 4:
            i=1;
            j=0;
            break;
        case 5:
            i=1;
            j=1;
            break;
        case 6:
            i=1;
            j=2;
            break;
        case 7:
            i=2;
            j=0;
            break;
        case 8:
            i=2;
            j=1;
            break;
        case 9:
            i=2;
            j=2;
            break;
        default:
            posicaoValida=false;
            break;
    }
    if(posicaoValida == true){
        if(*minhaVez==1){
            if(xbola[i][j] != 'X' && xbola[i][j] != 'O' ){
                xbola[i][j] ='O';
                *minhaVez=2;
                *quemganhou=true;
            }else{
                printf(ANSI_COLOR_RED "Esse campo ja foi prenchido!" ANSI_COLOR_RESET);
            }
        }else{
            if(xbola[i][j] != 'X' && xbola[i][j] != 'O'){
                xbola[i][j]='X';
                *minhaVez=1;
                *quemganhou=false;
            }else{
                printf(ANSI_COLOR_RED "Esse campo ja foi prenchido!" ANSI_COLOR_RESET);
            }
        }
    }else{
        cout << ANSI_COLOR_RED "Poscicao Invalida" ANSI_COLOR_RESET;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool vitoria(char xbola[][3],char *p){
    bool ganhou = false;
    int contagem = 0;
    //esquerda
    if(xbola[0][0]==xbola[1][0] && xbola[0][0] ==xbola[2][0] && xbola[0][0]!='-' && xbola[2][0] !='-')
    {
        contagem = 2;
        *p='e';
    }
    //meio_vertical
    if(xbola[0][1]==xbola[1][1] && xbola[1][1] ==xbola[2][1] && xbola[0][1]!='-' && xbola[2][1] !='-')
    {
        contagem = 2;
        *p='v';
    }
    //direita
    if(xbola[0][2]==xbola[1][2] && xbola[1][2] ==xbola[2][2] && xbola[0][2]!='-' && xbola[2][2] !='-')
    {
        contagem = 2;
        *p='d';
    }
    //cima
    if(xbola[0][0]==xbola[0][1] && xbola[0][1] == xbola[0][2] && xbola[0][0]!='-' && xbola[0][2] !='-')
    {
        contagem = 2;
        *p='c';
    }
    //meio_horizontal
    if(xbola[1][0]==xbola[1][1] && xbola[1][1] == xbola[1][2] && xbola[1][0]!='-' && xbola[1][2] !='-')
    {
        contagem = 2;
        *p='h';
    }
    //baixo
    if(xbola[2][0]==xbola[2][1] && xbola[2][1] == xbola[2][2] && xbola[2][0]!='-' && xbola[2][2] !='-')
    {
        contagem = 2;
        *p='b';
    }
    //diagonal direita
    if(xbola[0][2]==xbola[1][1] && xbola[0][2] ==xbola[2][0] && xbola[0][2]!='-' && xbola[0][2] !='-')
    {
        contagem = 2;
        *p='r';
    }
    //diagonal esquerda
    if(xbola[0][0]==xbola[1][1] && xbola[1][1] ==xbola[2][2] && xbola[0][0]!='-' && xbola[2][2] !='-')
    {
        contagem = 2;
        *p='l';
    }
    if(contagem==2){
        ganhou=true;
    }else{
        ganhou=false;
    }
    return ganhou;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//--17/10/2024--17:54 -- 18/10/2024 -- 19:23
