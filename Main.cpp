#include <iostream>
#include <time.h>
using namespace std;

char pieces[3][3];
int choice;
char player;
int win;

class Board{
    public:
    void printBoard(){
        cout << pieces[0][0] << "|" << pieces[0][1] << "|" << pieces[0][2];
        cout << "\n-----\n";
        cout << pieces[1][0] << "|" << pieces[1][1] << "|" << pieces[1][2];
        cout << "\n-----\n";
        cout << pieces[2][0] << "|" << pieces[2][1] << "|" << pieces[2][2];
    }
    void getMove(){
        int row = 0;
        int collum = 0;
        for(;;){
            cout << "\nWhere would you like to go: ";
            cin >> choice;
            
            while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9){
                cout << "Invalid input. Please try again.";
                cout << "\nWhere would you like to go: ";
                cin >> choice;
            }

            switch(choice){
                case 1: case 2: case 3:
                    row = 0;
                    break;
                case 4: case 5: case 6:
                    row = 1;
                    break;
                case 7: case 8: case 9:
                    row = 2;
            }

            switch(choice){
                case 1: case 4: case 7:
                    collum = 0;
                    break;
                case 2: case 5: case 8:
                    collum = 1;
                    break;
                case 3: case 6: case 9:
                    collum = 2;
            }
            if(pieces[row][collum] != 'X' && pieces[row][collum] != 'O'){
                pieces[row][collum] = player;
                break;
            }
            cout << "That space is taken! Please try again. ";
        }
    }
    void checkWin(){
        if(pieces[0][0] == player && pieces[0][1] == player && pieces[0][2] == player){
            //XXX
            //
            //
            cout << "\nPlayer " << player << " wins!!!";
            win = 1;
        }else{
            if(pieces[1][0] == player && pieces[1][1] == player && pieces[1][2] == player){
                //
                //XXX
                //
                cout << "\nPlayer " << player << " wins!!!";
                win = 1;
            }else{
                if(pieces[2][0] == player && pieces[2][1] == player && pieces[2][2] == player){
                    //
                    //
                    //XXX
                    cout << "\nPlayer " << player << " wins!!!";
                    win = 1;
                }else{
                    if(pieces[0][0] == player && pieces[1][0] == player && pieces[2][0] == player){
                        //X
                        //X
                        //X
                        cout << "\nPlayer " << player << " wins!!!";
                        win = 1;
                    }else{
                        if(pieces[0][1] == player && pieces[1][1] == player && pieces[2][1] == player){
                            // X
                            // X
                            // X
                            cout << "\nPlayer " << player << " wins!!!";
                            win = 1;
                        }else{
                            if(pieces[0][2] == player && pieces[1][2] == player && pieces[2][2] == player){
                                //  X
                                //  X
                                //  X
                                cout << "\nPlayer " << player << " wins!!!";
                                win = 1;
                            }else{
                                if(pieces[0][0] == player && pieces[1][1] == player && pieces[2][2] == player){
                                    //X
                                    // X
                                    //  X
                                    cout << "\nPlayer " << player << " wins!!!";
                                    win = 1;
                                }else{
                                    if(pieces[0][2] == player && pieces[1][1] == player && pieces[2][0] == player){
                                        //  X
                                        // X
                                        //X
                                        cout << "\nPlayer " << player << " wins!!!";
                                        win = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    void rotate(int times){
        char temp[3][3];

        for(int i = 0; i < times; ++i){
            //corners
            temp[0][0] = pieces[0][0];
            temp[0][2] = pieces[0][2];
            temp[2][2] = pieces[2][2];
            temp[2][0] = pieces[2][0];

            //middles
            temp[0][1] = pieces[0][1];
            temp[1][2] = pieces[1][2];
            temp[2][1] = pieces[2][1];
            temp[1][0] = pieces[1][0];

            //corner change
            pieces[0][2] = temp[0][0];
            pieces[2][2] = temp[0][2];
            pieces[2][0] = temp[2][2];
            pieces[0][0] = temp[2][0];

            //middle change
            pieces[1][2] = temp[0][1];
            pieces[2][1] = temp[1][2];
            pieces[1][0] = temp[2][1];
            pieces[0][1] = temp[1][0];
        }
    }
}game;

class Computer{
    public:
    void middle(){
        pieces[2][0] = 'X';
        game.printBoard();
        game.getMove();
        if(pieces[1][0] == player){
            pieces[1][1] = 'X';
            game.printBoard();
            game.getMove();
            if(pieces[0][2] == player){
                pieces[2][2] = 'X';
                game.printBoard();
                cout << "\nThe Commputer has won!";
            }else{
                pieces[0][2] = 'X';
                game.printBoard();
                cout << "\nThe Commputer has won!";
            }
        }else{
            pieces[1][0] = 'X';
            game.printBoard();
            cout << "\nThe Commputer has won!";
        }
    }
    void leftMiddle(){
        pieces[0][2] = 'X';
        game.printBoard();
        game.getMove();
        if(pieces[0][1] == player){
            pieces[1][1] = 'X';
            game.printBoard();
            game.getMove();
            if(pieces[2][0] == player){
                pieces[2][2] = 'X';
                game.printBoard();
                cout << "\nThe Commputer has won!";
            }else{
                pieces[2][0] = 'X';
                game.printBoard();
                cout << "\nThe Commputer has won!";
            }
        }else{
            pieces[0][1] = 'X';
            game.printBoard();
            cout << "\nThe Commputer has won!";
        }
    }
    void corner(){
        pieces[2][2] = 'X';
        game.printBoard();
        game.getMove();
        if(pieces[1][1] = player){
            pieces[0][2] = 'X';
            game.printBoard();
            game.getMove();
            if(pieces[0][1] = player){
                pieces[1][2] = 'X';
                game.printBoard();
                cout << "\nThe Commputer has won!";
            }else{
                pieces[0][1] = 'X';
                game.printBoard();
                cout << "\nThe Commputer has won!";
            }
        }else{
            pieces[1][1] = 'X';
            game.printBoard();
            cout << "\nThe Commputer has won!";
        }
    }
    void oppCorner(){
        pieces[2][0] = 'X';
        game.printBoard();
        game.getMove();
        if(pieces[1][0] == player){
            pieces[0][2] = 'X';
            game.printBoard();
            game.getMove();
            if(pieces[0][1] == player){
                pieces[1][1] = 'X';
                game.printBoard();
                cout << "\nThe Commputer has won!";
            }else{
                pieces[0][1] = 'X';
                game.printBoard();
                cout << "\nThe Commputer has won!";
            }
        }else{
            pieces[1][0] = 'X';
            game.printBoard();
            cout << "\nThe Commputer has won!";
        }
    }

    void center(){
        pieces[2][2] = 'X';//bottom right
        game.printBoard();
        game.getMove();
        if(pieces[0][2] == player){//top right
            pieces[2][0] = 'X';//bottom left
            game.printBoard();
            game.getMove();
            if(pieces[1][0] == player){//left middle
                pieces[2][1] = 'X';//bottom middle
                game.printBoard();
                cout << "\nThe Commputer has won!";//bottom win
                win = 1;
            }else{
                pieces[1][0] = 'X';//left middle
                game.printBoard();
                cout << "\nThe Commputer has won!";//left win
                win = 1;
            }
        }else{
            if(pieces[2][0] == player){//bottom left
                pieces[0][2] = 'X';//top right
                game.printBoard();
                game.getMove();
                if(pieces[0][1] == player){//top middle
                    pieces[1][2] = 'X';//right middle
                    game.printBoard();
                    cout << "\nThe Commputer has won!";//right win
                    win = 1;
                }else{
                    pieces[0][1] = 'X';//top middle
                    game.printBoard();
                    cout << "\nThe Commputer has won!";//top win
                    win = 1;
                }
            }else{
                if(pieces[0][1] == player){//top middle
                    pieces[2][1] = 'X';//bottom middle
                    game.printBoard();
                    game.getMove();
                    if(pieces[2][0] == player){//bottom left
                        pieces[0][2] = 'X';//top right
                        game.printBoard();
                        game.getMove();
                        if(pieces[1][2] == player){//right middle
                            pieces[1][0] = 'X';//left middle
                            game.printBoard();
                            //draw
                        }else{
                            pieces[1][2] = 'X';//right middle
                            game.printBoard();
                            cout << "\nThe Commputer has won!";//right win
                            win = 1;
                        }
                    }else{
                        pieces[2][0] = 'X';//bottom left
                        game.printBoard();
                        cout << "\nThe Commputer has won!";//bottom win
                        win = 1;
                    }
                }else{
                    if(pieces[1][2] == player){//right middle
                        pieces[1][0] = 'X';//left middle
                        game.printBoard();
                        game.getMove();
                        if(pieces[2][0] == player){//bottom left
                            pieces[0][2] = 'X';//top right
                            game.printBoard();
                            game.getMove();
                            if(pieces[0][1] == player){//top middle
                                pieces[2][1] = 'X';//bottom middle
                                game.printBoard();
                                //draw
                            }else{
                                pieces[0][1] = 'X';//top middle
                                game.printBoard();
                                cout << "\nThe Commputer has won!";//top win
                                win = 1;
                            }
                        }else{
                            pieces[2][0] = 'X';//bottom left
                            game.printBoard();
                            cout << "\nThe Commputer has won!";//left win
                            win = 1;
                        }
                    }else{
                        if(pieces[2][1] == player){//bottom middle
                            pieces[0][1] = 'X';//top middle
                            game.printBoard();
                            game.getMove();
                            if(pieces[0][2] == player){//top right
                                pieces[2][0] = 'X';//bottom left
                                game.printBoard();
                                game.getMove();
                                if(pieces[1][0] == player){//left middle
                                    pieces[1][2] = 'X';//right middle
                                    game.printBoard();
                                    //draw
                                }else{
                                    pieces[1][0] = 'X';//left middle
                                    game.printBoard();
                                    cout << "\nThe Commputer has won!";//left win
                                    win = 1;
                                }
                            }else{
                                pieces[0][2] = 'X';//top right
                                game.printBoard();
                                cout << "\nThe Commputer has won!";//top win
                                win = 1;
                            }
                        }else{
                            if(pieces[1][0] == player){//left middle
                                pieces[1][2] = 'X';//right middle
                                game.printBoard();
                                game.getMove();
                                if(pieces[0][2] == player){//top right
                                    pieces[2][0] = 'X';//bottom left
                                    game.printBoard();
                                    game.getMove();
                                    if(pieces[2][1] == player){//bottom middle
                                        pieces[0][1] = 'X';//top middle
                                        game.printBoard();
                                        //draw
                                    }else{
                                        pieces[2][1] = 'X';//bottom middle
                                        game.printBoard();
                                        cout << "\nThe Commputer has won!";//bottom win
                                        win = 1;
                                    }
                                }else{
                                    pieces[0][2] = 'X';//top right
                                    game.printBoard();
                                    cout << "\nThe Commputer has won!";//right win
                                    win = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    void cornerSecond(int times){
        pieces[1][1] = 'O';//center
        game.printBoard();
        game.getMove();
        game.rotate(times);
        if(pieces[0][1] == player){//top middle
            pieces[0][2] = 'O';//top right
            game.rotate(4 - times);
            game.printBoard();
            game.getMove();
            game.rotate(times);
            if(pieces[2][0] == player){//bottom left
                pieces[1][0] = 'O';//left middle
                game.rotate(4 - times);
                game.printBoard();
                game.getMove();
                game.rotate(times);
                if(pieces[1][2] == player){//right middle
                    pieces[2][1] = 'O';//bottom middle
                    game.rotate(4 - times);
                    game.printBoard();
                    //draw
                }else{
                    pieces[1][2] = 'O';//right middle
                    game.rotate(4 - times);
                    game.printBoard();
                    cout << "\nThe Commputer has won!";//horizontal win
                    win = 1;
                }
            }else{
                pieces[2][0] = 'O';//bottom left
                game.rotate(4 - times);
                game.printBoard();
                cout << "\nThe Commputer has won!";//right diag win
                win = 1;
            }
        }else{
            if(pieces[1][0] == player){//left middle
                pieces[2][0] = 'O';//bottom left
                game.rotate(4 - times);
                game.printBoard();
                game.getMove();
                game.rotate(times);
                if(pieces[0][2] == player){//top right
                    pieces[0][1] = 'O';//top middle
                    game.rotate(4 - times);
                    game.printBoard();
                    game.getMove();
                    game.rotate(times);
                    if(pieces[2][1] == player){//bottom middle
                        pieces[2][2] = 'O';//bottom right
                        game.rotate(4 - times);
                        game.printBoard();
                        //draw
                    }else{
                        pieces[2][1] = 'O';//bottom middle
                        game.rotate(4 - times);
                        game.printBoard();
                        cout << "\nThe Commputer has won!";//vertical win
                        win = 1;
                    }
                }else{
                    pieces[0][2] = 'O';//top right
                    game.rotate(4 - times);
                    game.printBoard();
                    cout << "\nThe Commputer has won!";//right diag win
                    win = 1;
                }
            }else{
                if(pieces[0][2] == player){//top right
                    pieces[0][1] = 'O';//top middle
                    game.rotate(4 - times);
                    game.printBoard();
                    game.getMove();
                    game.rotate(times);
                    if(pieces[2][1] == player){//bottom middle
                        pieces[1][0] = 'O';//left middle
                        game.rotate(4 - times);
                        game.printBoard();
                        game.getMove();
                        game.rotate(times);
                        if(pieces[1][2] == player){//right middle
                            pieces[2][2] = 'O';//bottom right
                            game.rotate(4 - times);
                            game.printBoard();
                            //draw
                        }else{
                            pieces[1][2] = 'O';//right middle
                            game.rotate(4 - times);
                            game.printBoard();
                            cout << "\nThe Commputer has won!";//horizontal win
                            win = 1;
                        }
                    }else{
                        pieces[2][1] = 'O';//bottom middle
                        game.rotate(4 - times);
                        game.printBoard();
                        cout << "\nThe Commputer has won!";//vertical win
                        win = 1;
                    }
                }else{
                    if(pieces[2][0] == player){//bottom left
                        pieces[1][0] = 'O';//left middle
                        game.rotate(4 - times);
                        game.printBoard();
                        game.getMove();
                        game.rotate(times);
                        if(pieces[1][2] == player){//right middle
                            pieces[0][1] = 'O';//top middle
                            game.rotate(4 - times);
                            game.printBoard();
                            game.getMove();
                            game.rotate(times);
                            if(pieces[2][1] == player){//bottom middle
                                pieces[2][2] = 'O';//bottom right
                                game.rotate(4 - times);
                                game.printBoard();
                                //draw
                            }else{
                                pieces[1][2] = 'O';//right middle
                                game.rotate(4 - times);
                                game.printBoard();
                                cout << "\nThe Commputer has won!";//horizontal win
                                win = 1;
                            }
                        }else{
                            pieces[2][1] = 'O';//bottom middle
                            game.rotate(4 - times);
                            game.printBoard();
                            cout << "\nThe Commputer has won!";//vertical win
                            win = 1;
                        }
                    }else{
                        if(pieces[1][2] == player){//right middle
                            pieces[0][1] = 'O';//top middle
                            game.rotate(4 - times);
                            game.printBoard();
                            game.getMove();
                            game.rotate(times);
                            if(pieces[2][1] == player){//bottom middle
                                pieces[2][0] = 'O';//bottom left
                                game.rotate(4 - times);
                                game.printBoard();
                                game.getMove();
                                game.rotate(times);
                                if(pieces[0][2] == player){//top right
                                    pieces[2][2] = 'O';//bottom right
                                    game.rotate(4 - times);
                                    game.printBoard();
                                    //draw
                                }else{
                                    pieces[0][2] = 'O';//top right
                                    game.rotate(4 - times);
                                    game.printBoard();
                                    cout << "\nThe Commputer has won!";//right diag win
                                    win = 1;
                                }
                            }else{
                                pieces[2][1] = 'O';//bottom middle
                                game.rotate(4 - times);
                                game.printBoard();
                                cout << "\nThe Commputer has won!";//vertical win
                                win = 1;
                            }
                        }else{
                            if(pieces[2][1] == player){//bottom middle
                                pieces[1][0] = 'O';//left middle
                                game.rotate(4 - times);
                                game.printBoard();
                                game.getMove();
                                game.rotate(times);
                            if(pieces[1][2] == player){//right middle
                                pieces[0][2] = 'O';//top right
                                game.rotate(4 - times);
                                game.printBoard();
                                game.getMove();
                                game.rotate(times);
                                if(pieces[2][0] == player){//bottom left
                                    pieces[2][2] = 'O';//bottom right
                                    game.rotate(4 - times);
                                    game.printBoard();
                                    //draw
                                }else{
                                    pieces[2][0] = 'O';//bottom left
                                    game.rotate(4 - times);
                                    game.printBoard();
                                    cout << "\nThe Commputer has won!";//right diag win
                                    win = 1;
                                }
                            }else{
                                pieces[1][2] = 'O';//right middle
                                game.rotate(4 - times);
                                game.printBoard();
                                cout << "\nThe Commputer has won!";//horizontal win
                                win = 1;
                                }
                            }else{
                                if(pieces[2][2] == player){//bottom right
                                    pieces[0][1] = 'O';//top middle
                                    game.rotate(4 - times);
                                    game.printBoard();
                                    game.getMove();
                                    game.rotate(times);
                                if(pieces[2][1] == player){//bottom middle
                                    pieces[2][0] = 'O';//bottom left
                                    game.rotate(4 - times);
                                    game.printBoard();
                                    game.getMove();
                                    game.rotate(times);
                                    if(pieces[0][2] == player){//top right
                                        pieces[1][2] = 'O';//middle right
                                        game.rotate(4 - times);
                                        game.printBoard();
                                        //draw
                                    }else{
                                        pieces[0][2] = 'O';//top right
                                        game.rotate(4 - times);
                                        game.printBoard();
                                        cout << "\nThe Commputer has won!";//right diag win
                                        win = 1;
                                    }
                                }else{
                                    pieces[2][1] = 'O';//bottom middle
                                    game.rotate(4 - times);
                                    game.printBoard();
                                    cout << "\nThe Commputer has won!";//vertical win
                                    win = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    void middle(int times){
        pieces[1][1] = 'O';//center
        game.printBoard();
        game.getMove();
        game.rotate(times);
        if(pieces[0][0] == player){//top left
            pieces[0][2] = 'O';//top right
            game.rotate(4 - times);
            game.printBoard();
            game.getMove();
            game.rotate(times);
            if(pieces[2][0] == player){//bottom left
                pieces[1][0] = 'O';//left middle
                game.rotate(4 - times);
                game.printBoard();
                game.getMove();
                game.rotate(times);
                if(pieces[1][2] == player){//right middle
                    pieces[2][2] = 'O';//bottom right
                    game.rotate(4 - times);
                    game.printBoard();
                    //draw
                }else{
                    pieces[1][2] = 'O';//right middle
                    game.rotate(4 - times);
                    game.printBoard();
                    cout << "\nThe Commputer has won!";//horizontal win
                    win = 1;
                }
            }else{
                pieces[2][0] = 'O';//bottom left
                game.rotate(4 - times);
                game.printBoard();
                cout << "\nThe Commputer has won!";//right diag win
                win = 1;
            }
        }else{
            if(pieces[0][2] == player){//top right
                pieces[0][0] = 'O';//top left
                game.rotate(4 - times);
                game.printBoard();
                game.getMove();
                game.rotate(times);
                if(pieces[2][2] == player){//bottom right
                    pieces[1][2] = 'O';//right middle
                    game.rotate(4 - times);
                    game.printBoard();
                    game.getMove();
                    game.rotate(times);
                    if(pieces[1][0] == player){//left middle
                        pieces[2][0] = 'O';//bottom left
                        game.rotate(4 - times);
                        game.printBoard();
                        //draw
                    }else{
                        pieces[1][0] = 'O';//left middle
                        game.rotate(4 - times);
                        game.printBoard();
                        cout << "\nThe Commputer has won!";//horizontal win
                        win = 1;
                    }
                }else{
                    pieces[2][2] = 'O';//bottom right
                    game.rotate(4 - times);
                    game.printBoard();
                    cout << "\nThe Commputer has won!";//left diag win
                    win = 1;
                }
            }else{
                if(pieces[1][0] == player){//middle left
                    pieces[0][0] = 'O';//top left
                    game.rotate(4 - times);
                    game.printBoard();
                    game.getMove();
                    game.rotate(times);
                    if(pieces[2][2] == player){//bottom right
                        pieces[0][2] = 'O';//top right
                        game.rotate(4 - times);
                        game.printBoard();
                        game.getMove();
                        game.rotate(times);
                        if(pieces[2][0] == player){//bottom left
                            pieces[2][1] = 'O';//bottom middle
                            game.rotate(4 - times);
                            game.printBoard();
                            //draw
                        }else{
                            pieces[2][0] = 'O';//bottom left
                            game.rotate(4 - times);
                            game.printBoard();
                            cout << "\nThe Commputer has won!";//right diag win
                            win = 1;
                        }
                    }else{
                        pieces[2][2] = 'O';//bottom right
                        game.rotate(4 - times);
                        game.printBoard();
                        cout << "\nThe Commputer has won!";//left diag win
                        win = 1;
                    }
                }else{
                    if(pieces[1][2] == player){//middle right
                        pieces[0][2] = 'O';//top right
                        game.rotate(4 - times);
                        game.printBoard();
                        game.getMove();
                        game.rotate(times);
                        if(pieces[2][0] == player){//bottom left
                            pieces[0][0] = 'O';//top left
                            game.rotate(4 - times);
                            game.printBoard();
                            game.getMove();
                            game.rotate(times);
                            if(pieces[2][2] == player){//bottom right
                                pieces[2][1] = 'O';//bottom middle
                                game.rotate(4 - times);
                                game.printBoard();
                                //draw
                            }else{
                                pieces[2][2] = 'O';//bottom right
                                game.rotate(4 - times);
                                game.printBoard();
                                cout << "\nThe Commputer has won!";//left diag win
                                win = 1;
                            }
                        }else{
                            pieces[2][0] = 'O';//bottom left
                            game.rotate(4 - times);
                            game.printBoard();
                            cout << "\nThe Commputer has won!";//right diag win
                            win = 1;
                        }
                    }else{
                        if(pieces[2][0] == player){//bottom left
                            pieces[1][2] = 'O';//middle right
                            game.rotate(4 - times);
                            game.printBoard();
                            game.getMove();
                            game.rotate(times);
                            if(pieces[1][0] == player){//middle left
                                pieces[0][0] = 'O';//top left
                                game.rotate(4 - times);
                                game.printBoard();
                                game.getMove();
                                game.rotate(times);
                                if(pieces[2][2] == player){//bottom right
                                    pieces[2][1] = 'O';//bottom middle
                                    game.rotate(4 - times);
                                    game.printBoard();
                                    //draw
                                }else{
                                    pieces[2][2] = 'O';//bottom right
                                    game.rotate(4 - times);
                                    game.printBoard();
                                    cout << "\nThe Commputer has won!";//left diag win
                                    win = 1;
                                }
                            }else{
                                pieces[1][0] = 'O';//middle left
                                game.rotate(4 - times);
                                game.printBoard();
                                cout << "\nThe Commputer has won!";//horizontal win
                                win = 1;
                            }
                        }else{
                            if(pieces[2][2] == player){//bottom right
                                pieces[1][0] = 'O';//middle left
                                game.rotate(4 - times);
                                game.printBoard();
                                game.getMove();
                                game.rotate(times);
                                if(pieces[1][2] == player){//middle right
                                    pieces[0][2] = 'O';//top right
                                    game.rotate(4 - times);
                                    game.printBoard();
                                    game.getMove();
                                    game.rotate(times);
                                    if(pieces[2][0] == player){//bottom left
                                        pieces[2][1] = 'O';//bottom middle
                                        game.rotate(4 - times);
                                        game.printBoard();
                                        //draw
                                    }else{
                                        pieces[2][0] = 'O';//bottom left
                                        game.rotate(4 - times);
                                        game.printBoard();
                                        cout << "\nThe Commputer has won!";//right diag win
                                        win = 1;
                                    }
                                }else{
                                    pieces[1][2] = 'O';//middle right
                                    game.rotate(4 - times);
                                    game.printBoard();
                                    cout << "\nThe Commputer has won!";//horizontal win
                                    win = 1;
                                }
                            }else{
                                pieces[2][2] = 'O';//bottom right
                                game.rotate(4 - times);
                                game.printBoard();
                                game.getMove();
                                game.rotate(times);
                                if(pieces[0][0] == player){//top left
                                    pieces[0][2] = 'O';//top right
                                    game.rotate(4 - times);
                                    game.printBoard();
                                    game.getMove();
                                    game.rotate(times);
                                    if(pieces[2][0] == player){//bottom left
                                        pieces[1][2] = 'O';//middle right
                                        game.rotate(4 - times);
                                        game.printBoard();
                                        cout << "\nThe Commputer has won!";//right win
                                        win = 1;
                                    }else{
                                        pieces[2][0] = 'O';//bottom left
                                        game.rotate(4 - times);
                                        game.printBoard();
                                        cout << "\nThe Commputer has won!";//right win
                                        win = 1;
                                    }
                                }else{
                                    pieces[0][0] = 'O';//top left
                                    game.rotate(4 - times);
                                    game.printBoard();
                                    cout << "\nThe Commputer has won!";//right win
                                    win = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    void centerSecond(){
        if(pieces[0][1] == player){//top middle
            pieces[2][1] = 'O';//bottom middle
            game.printBoard();
            game.getMove();
            if(pieces[0][2] == player){//top right
                pieces[2][0] = 'O';//bottom right
                game.printBoard();
                game.getMove();
                if(pieces[1][0] == player){//left middle
                    pieces[2][2] = 'O';//bottom right
                    game.printBoard();
                    cout << "\nThe Commputer has won!";//bottom win
                    win = 1;
                }else{
                    pieces[1][0] = 'O';//left middle
                    game.printBoard();
                    cout << "\nThe Commputer has won!";//left win
                    win = 1;
                }
            }else{
                if(pieces[1][2] == player){//middle right
                    pieces[1][0] = 'O';//middle left
                    game.printBoard();
                    game.getMove();
                    if(pieces[2][0] == player){//bottom left
                        pieces[0][2] = 'O';//top right
                        game.printBoard();
                        //draw
                    }else{
                        pieces[2][0] = 'O';//bottom left
                        game.printBoard();
                        cout << "\nThe Commputer has won!";//left win
                        win = 1;
                    }
                }else{
                    if(pieces[2][2] == player){//bottom right
                        pieces[2][0] = 'O';//bottom left
                        game.printBoard();
                        game.getMove();
                        if(pieces[1][0] == player){//middle left
                            pieces[1][2] = 'O';//middle right
                            game.printBoard();
                            //draw
                        }else{
                            pieces[1][0] = 'O';//middle left
                            game.printBoard();
                            cout << "\nThe Commputer has won!";//left win
                            win = 1;
                        }
                    }else{
                        if(pieces[2][0] == player){//bottom left
                            pieces[0][2] = 'O';//top right
                            game.printBoard();
                            game.getMove();
                            if(pieces[1][2] == player){//middle right
                                pieces[1][0] = 'O';//middle left
                                game.printBoard();
                                //draw
                            }else{
                                pieces[1][2] = 'O';//middle right
                                game.printBoard();
                                //draw
                            }
                        }else{
                            pieces[1][2] = 'O';//middle right
                            game.printBoard();
                            game.getMove();
                            if(pieces[0][2] == player){//top right
                                pieces[2][0] = 'O';//bottom left
                                game.printBoard();
                                //draw
                            }else{
                                pieces[0][2] = 'O';//top right
                                game.printBoard();
                                //draw
                            }
                        }
                    }
                }
            }
        }else{
            if(pieces[0][2] == player){//top right
                pieces[2][0] = 'O';//bottom left
                game.printBoard();
                game.getMove();
                if(pieces[1][0] == player){//middle left
                    pieces[1][2] = 'O';//middle right
                    game.printBoard();
                    game.getMove();
                    if(pieces[2][1] == player){//bottom middle
                        pieces[0][1] = 'O';//top middle
                        game.printBoard();
                        //draw
                    }else{
                        pieces[2][1] = 'O';//bottom middle
                        game.printBoard();
                        //draw
                    }
                }else{
                    pieces[1][0] = 'O';//middle left
                    game.printBoard();
                    cout << "\nThe Commputer has won!";//right win
                    win = 1;
                }
            }else{
                if(pieces[1][2] == player){//middle right
                    pieces[1][0] = 'O';//middle left
                    game.printBoard();
                    game.getMove();
                    if(pieces[2][0] == player){//bottom left
                        pieces[0][2] = 'O';//top right
                        game.printBoard();
                        game.getMove();
                        if(pieces[0][1] == player){//top middle
                            pieces[2][1] = 'O';//bottom middle
                            game.printBoard();
                            //draw
                        }else{
                            pieces[0][1] = 'O';//top middle
                            game.printBoard();
                            cout << "\nThe Commputer has won!";//top win
                            win = 1;
                        }
                    }else{
                        pieces[2][0] = 'O';//bottom left
                        game.printBoard();
                        cout << "\nThe Commputer has won!";//left win
                        win = 1;
                    }
                }else{
                    if(pieces[2][2] == player){//bottom right
                        pieces[0][2] = 'O';//top right
                        game.printBoard();
                        game.getMove();
                        if(pieces[0][1] == player){//top middle
                            pieces[2][1] = 'O';//bottom middle
                            game.printBoard();
                            game.getMove();
                            if(pieces[1][0] == player){//left middle
                                pieces[1][2] = 'O';//right middle
                                game.printBoard();
                                //draaw
                            }else{
                                pieces[1][0] = 'O';//left middle
                                game.printBoard();
                                //draw
                            }
                        }else{
                            pieces[0][1] = 'O';//top middle
                            game.printBoard();
                            cout << "\nThe Commputer has won!";//top win
                            win = 1;
                        }
                    }else{
                        if(pieces[2][1] == player){//bottom middle
                            pieces[0][1] = 'O';//top middle
                            game.printBoard();
                            game.getMove();
                            if(pieces[0][2] == player){//top right
                                pieces[2][0] = 'O';//bottom right
                                game.printBoard();
                                game.getMove();
                                if(pieces[1][0] == player){//left middle
                                    pieces[1][2] = 'O';//middle right
                                    game.printBoard();
                                    //draw
                                }else{
                                    pieces[1][0] = 'O';//left middle
                                    game.printBoard();
                                    cout << "\nThe Commputer has won!";//left win
                                    win = 1;
                                }
                            }else{
                                pieces[0][2] = 'O';//top right
                                game.printBoard();
                                cout << "\nThe Commputer has won!";//top win
                                win = 1;
                            }
                        }else{
                            if(pieces[2][0] == player){//bottom left
                                pieces[0][2] = 'O';//top right
                                game.printBoard();
                                game.getMove();
                                if(pieces[0][1] == player){//top middle
                                    pieces[2][1] = 'O';//bottom middle
                                    game.printBoard();
                                    game.getMove();
                                    if(pieces[1][0] == player){//left middle
                                        pieces[1][2] = 'O';//right middle
                                        game.printBoard();
                                        //draw
                                    }else{
                                        pieces[1][0] = 'O';//left middle
                                        game.printBoard();
                                        //draw
                                    }
                                }else{
                                    pieces[0][1] = 'O';//top middle
                                    game.printBoard();
                                    cout << "\nThe Commputer has won!";//top win
                                    win = 1;
                                }
                            }else{
                                pieces[1][2] = 'O';//right middle
                                game.printBoard();
                                game.getMove();
                                if(pieces[0][1] == player){//top middle
                                    pieces[2][1] = 'O';//bottom middle
                                    game.printBoard();
                                    game.getMove();
                                    if(pieces[0][2] == player){//top right
                                        pieces[2][0] = 'O';//bottom left
                                        game.printBoard();
                                        //draw
                                    }else{
                                        if(pieces[2][0] == player){//bottom left
                                            pieces[0][2] = 'O';//top right
                                            game.printBoard();
                                            //draw
                                        }else{
                                            pieces[2][0] = 'O';//bottom left
                                            game.printBoard();
                                            //draw
                                        }
                                    }
                                }else{
                                    if(pieces[0][2] == player){//top right
                                        pieces[2][1] = 'O';//bottom right
                                        game.printBoard();
                                        game.getMove();
                                        if(pieces[0][1] == player){//top middle
                                            pieces[2][1] = 'O';//bottom middle
                                            game.printBoard();
                                            //draw
                                        }else{
                                            pieces[0][1] = 'O';//top middle
                                            game.printBoard();
                                            //draw
                                        }
                                    }else{
                                        if(pieces[2][2] == player){//bottom right
                                            pieces[0][2] = 'O';//top right
                                            game.printBoard();
                                            game.getMove();
                                            if(pieces[0][1] == player){//top middle
                                                pieces[2][1] = 'O';//bottom middle
                                                game.printBoard();
                                                //draw
                                            }else{
                                                pieces[0][1] = 'O';//top middle
                                                game.printBoard();
                                                cout << "\nThe Commputer has won!";//top win
                                                win = 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}computer;

void aiGoFirst(){
    player = 'O';
    pieces[0][0] = 'X';//top left
    game.printBoard();
    game.getMove();
    if(pieces[0][1] == player || pieces[1][2] == player || pieces[2][1] == player){
        computer.middle();
        win = 1;
    }else{
        if(pieces[1][0] == player){
            computer.leftMiddle();
            win = 1;
        }else{
            if(pieces[2][0] == player || pieces[0][2] == player){
                computer.corner();
                win = 1;
            }else{
                if(pieces[2][2] == player){
                    computer.oppCorner();
                    win = 1;
                }else{
                    computer.center();
                }
            }
        }
    }
}

void aiGoSecond(){
    player = 'X';
    game.printBoard();
    game.getMove();
    if(pieces[0][0] == player){//top left
        computer.cornerSecond(0); 
    }else{
        if(pieces[0][2] == player){//top right
            computer.cornerSecond(3);
        }else{
            if(pieces[2][2] == player){//bottom right
                computer.cornerSecond(2);
            }else{
                if(pieces[2][0] == player){//bottom left
                    computer.cornerSecond(1);
                }else{
                    if(pieces[0][1] == player){//top middle
                        computer.middle(0);
                    }else{
                        if(pieces[1][2] == player){//middle right
                            computer.middle(3);
                        }else{
                            if(pieces[2][1] == player){//bottom middle
                                computer.middle(2);
                            }else{
                                if(pieces[1][0] == player){//left middle
                                    computer.middle(1);
                                }else{
                                    pieces[0][0] = 'O';
                                    game.printBoard();
                                    game.getMove();
                                    computer.centerSecond();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(){
    for(;;){
        int random;
        int rotations;
        char answer;
        win = 0;
        int numPlayers;
        int turn;

        cout << "(1) Player vs Player\n"
                "(2) Player vs Computer\n"
                "What would you like to do: ";
        cin >> numPlayers;

        while(numPlayers < 1 || numPlayers > 2){
            cout << "Invalid input. Please try again.";
            cout << "(1) Player vs Player\n"
                    "(2) Player vs Computer\n"
                    "What would you like to do: ";
            cin >> numPlayers;
        }

        if(numPlayers == 2){
            cout << "(1) First\n"
                    "(2) Second\n"
                    "(3) Random\n"
                    "When would you like to go: ";
            cin >> turn;

            while(turn < 1 || turn > 3){
                cout << "Invalid input. Please try again";
                cout << "(1) First\n"
                    "(2) Second\n"
                    "(3) Random\n"
                    "When would you like to go: ";
                cin >> turn;
            }
        }    

        pieces[0][0] = '1';
        pieces[0][1] = '2';
        pieces[0][2] = '3';

        pieces[1][0] = '4';
        pieces[1][1] = '5';
        pieces[1][2] = '6';

        pieces[2][0] = '7';
        pieces[2][1] = '8';
        pieces[2][2] = '9';

        if(numPlayers == 1){
            game.printBoard();
            for(int i = 0; i < 4; i = ++i){
                player = 'X';
                game.getMove();
                game.printBoard();
                game.checkWin();
                if(win == 1){
                    break;
                }
                player = 'O';
                game.getMove();
                game.printBoard();
                game.checkWin();
                if(win == 1){
                    break;
                }
            }
        }else{
            if(turn == 1){
                aiGoSecond();
            }else{
                if(turn == 2){
                    aiGoFirst();
                }else{
                    srand(time(0));
                    random = rand() % 2;
                    if(random == 1){
                        cout << "You are going first\n";
                        aiGoSecond();
                    }else{
                        cout << "You are going second\n";
                        aiGoFirst();
                    }
                }
            }
        }

        if(win == 0){
            cout << "\nLooks like a draw!";
        }

        cout << "\nWould you like to play again (y/n): ";
        cin >> answer;

        while(answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N'){
            cout << "Invalid input. Please try again.";
            cin >> answer;
        }

        if(answer == 'n' || answer == 'N'){
            return 0;
        }
    }
}
