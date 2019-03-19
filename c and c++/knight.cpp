#include <iostream>
#include <stack>
using namespace std;

int board[8][8];
stack <int> stackX;
stack <int> stackY;

void printBoard(){
    //iterate through board and print coordinates
    for (int i = 0; i < 8;i++)
    {
        for (int j = 0; j < 8; j++){
            cout<< board[i][j]<< " ";
        }
        //endl after every 8 entries to make board appearance
        cout<<endl;
    }
}
bool checkMove(int x, int y){
    if (x >= 0 && x<8 && y >=0 && y < 8 && board[x][y] == -1)
        return true;
    else
        return false;

    //check for a valid move and return
}

bool tour(int x, int y, int counter, int xPos[8], int yPos[8]){
    int newX, newY;

    if (counter == 64){
        return true;
    }

    for (int i = 0; i < 8; i++){
        newX = x + xPos[i];
        newY = y + yPos[i];

        if(checkMove(newX, newY)){
            board[newX][newY] = counter;

            if(tour(newX, newY, counter + 1, xPos, yPos))
                return true;
            else
                board[newX][newY] = -1;
        }
    }
    return false;
}
void getOrigin(){
    int x,y;
    cout<<"Enter the original x and y coords" << endl;
    cout<<"Enter x";
    cin >> x;
    cout<<endl;
    cout << "Enter y";
    cin >> y;
    cout<<endl;

    stackX.push(x);
    stackY.push(y);
}

bool game(){
    for(int x = 0; x < 8; x++){
        for(int y = 0; y < 8; y++){
            board[x][y] = -1;
        }
    }

	int xLoc[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yLoc[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    int xOrigin = stackX.top();
    int yOrigin = stackY.top();

    cout<< "origin is at " << xOrigin<< " "<< yOrigin<<endl;

    board[xOrigin][yOrigin] = 0;

    if(!tour(xOrigin,yOrigin,1,xLoc,yLoc)){
        return false;
    }
    else
        printBoard();

    return true;

}
void getPos(){
    bool stackEmpty = false;
    stack<int> tempX;
    stack<int> tempY;
    int size;
    size = stackX.size();
    for(int i = 0; i < size; i++){
        tempX.push(stackX.top());
        stackX.pop();
        tempY.push(stackY.top());
        stackY.pop();

    }
    for (int i=0; i<size; i++){
        stackX.push(tempX.top());
        tempX.pop();
        stackY.push(tempY.top());
        tempY.pop();
    }

}


int main(){
    bool stackEmpty = false;
    getOrigin();
    getPos();
    int size;

    if (stackX.empty() == true){
        cout<< "no entry detected" <<endl;
        stackEmpty = true;
    }
    while(!stackEmpty){
        cout<< "moved" <<endl;
        game();
        stackX.pop();
        stackY.pop();
        if (stackX.empty()==true)
            stackEmpty = true;

    }
        return 0;
}

