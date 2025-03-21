#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define EMPTY short(0)
#define SIZE 9

void print( short b[SIZE][SIZE] )
{
     for(int i = 0; i < SIZE; i++){
        if(i != 0 && i % 3 == 0)
            std::cout << "------------------------\n";
        for(int j = 0; j < SIZE; j++){
            if(j != 0 && j % 3 == 0)
                std::cout << " | ";
            std::cout << b[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool is_valid( short b[SIZE][SIZE] )
{
    int soma;
    // Linha
    for(int i = 0; i < SIZE; i++){
        soma = 0;
        for(int j = 0; j < SIZE; j++){
            soma += b[i][j];
        }
        if(soma != 45)
            return false;
    } 
    // Coluna
    for(int i = 0; i < SIZE; i++){
        soma = 0;
        for(int j = 0; j < SIZE; j++){
            soma += b[j][i];
        }
        if(soma != 45)
            return false;
    }    
    return true; 
}

short** ler_arquivo( string nome )
{
    string line;
    ifstream myfile (nome);
    string boardss[SIZE] ;
    short board2[SIZE][SIZE];
    int myint;
    vector<string> tokens;
    int x=0;

    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            boardss[x] += line;
            x++;
        }
        myfile.close();
    }

   else cout << "Unable to open file"; 

    for(int i = 0; i < SIZE; i++){
        istringstream tokenizer {  boardss[i] };
        string token;
        while (tokenizer >> token){
            tokens.push_back(token);
        }
        for(int j = 0; j < SIZE; j++){
            myint = std::stoi(tokens[j+(9*i)]);
            board2[i][j]=myint;
        }
    }
}

int main(void)
{
    int n_boards{8}; // Number of boards...
    short board[8][SIZE][SIZE]  {
        {
        { 1, 3, 4, 6, 7, 8, 5, 9, 2 },
        { 6, 7, 2, 1, 9, 5, 3, 4, 8 },
        { 5, 9, 8, 3, 4, 2, 1, 6, 7 },
        { 8, 5, 9, 7, 6, 1, 4, 2, 3 },
        { 4, 2, 6, 8, 5, 3, 9, 7, 1 },
        { 7, 1, 3, 4, 2, 9, 8, 5, 6 },
        { 9, 6, 1, 5, 3, 7, 2, 8, 4 },
        { 2, 8, 7, 9, 1, 4, 6, 3, 5 },
        { 3, 4, 5, 2, 8, 6, 7, 1, 9 } 
        },
        {
        { 1, 6, 2, 8, 5, 7, 4, 9, 3 },
        { 5, 3, 4, 1, 2, 9, 6, 7, 8 },
        { 7, 8, 9, 6, 4, 3, 5, 2, 1 },
        { 4, 7, 5, 3, 1, 2, 9, 8, 6 },
        { 9, 1, 3, 5, 8, 6, 7, 4, 2 },
        { 6, 2, 8, 7, 9, 4, 1, 3, 5 },
        { 3, 5, 6, 4, 7, 8, 2, 1, 9 },
        { 2, 4, 1, 9, 3, 5, 8, 6, 7 },
        { 8, 9, 7, 2, 6, 1, 3, 5, 4 } 
        },
        {
        { 5, 3, 4, 6, 7, 8, 9, 1, 2 },
        { 6, 7, 2, 1, 9, 5, 3, 4, 8 },
        { 1, 9, 8, 3, 4, 2, 5, 6, 7 },
        { 8, 5, 9, 7, 6, 1, 4, 2, 3 },
        { 4, 2, 6, 8, 5, 3, 7, 9, 1 },
        { 7, 1, 3, 9, 2, 4, 8, 5, 6 },
        { 9, 6, 1, 5, 3, 7, 2, 8, 4 },
        { 2, 8, 7, 4, 1, 9, 6, 3, 5 },
        { 3, 4, 5, 2, 8, 6, 1, 7, 9 } 
        },
        {
        { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
        { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
        { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
        { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
        { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
        { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
        { 7, 3, 9, 2, 4, 1, 8, 5, 6 },
        { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
        { 3, 5, 2, 8, 6, 4, 1, 7, 9 }
        },
        {
        { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
        { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
        { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
        { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
        { 4, 6, 8, 5, 3, 2, 5, 9, 1 },
        { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
        { 7, 3, 9, 2, 4, 1, 8, 5, 6 },
        { 9, 3, 5, 3, 7, 6, 2, 8, 4 },
        { 3, 5, 2, 8, 6, 4, 1, 7, 9 } 
        },
        {
        { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
        { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
        { 1, 8, 3, 4, 2, 19, 5, 6, 7 },
        { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
        { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
        { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
        { 7, -3, 9, 2, 4, 1, 8, 5, 6 },
        { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
        { 3, 5, 2, 8, 6, 4, 1, 7, 9 } 
        },
        {
        { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
        { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
        { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
        { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
        { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
        { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
        { 7, 3, 9, 2, 4, 1, 0, 5, 6 },
        { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
        { 3, 5, 2, 8, 6, 4, 1, 7, 9 } 
        },
        {
        { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
        { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
        { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
        { 8, 9, 7, 3, 1, 5, 4, 2, 3 },
        { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
        { 5, 4, 6, 7, 8, 6, 9, 1, 2 },
        { 7, 3, 9, 2, 4, 1, 8, 5, 6 },
        { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
        { 3, 5, 2, 8, 6, 4, 1, 7, 9 } 
        }
        };

    // for ( int i{0}; i < n_boards ; ++i )
    // {
    //     std::cout << "Board #" << (i+1) << ": \n";
    //     print( board[i] );
    //     std::cout << "Is valid? " << std::boolalpha << is_valid( board[i] ) << std::endl;
    //     std::cout << "\n";
    // }

    string line;
    ifstream myfile ("numeros.txt");
    string boardss[SIZE] ;
    short board2[SIZE][SIZE];
    int myint;
    vector<string> tokens;
    int x=0;

    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            boardss[x] += line;
            x++;
        }
        myfile.close();
    }

   else cout << "Unable to open file"; 

    for(int i = 0; i < SIZE; i++){
        istringstream tokenizer {  boardss[i] };
        string token;
        while (tokenizer >> token){
            tokens.push_back(token);
        }
        for(int j = 0; j < SIZE; j++){
            myint = std::stoi(tokens[j+(9*i)]);
            board2[i][j]=myint;
        }
    }
    print(board2);
  return 0;
}
