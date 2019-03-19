#include <iostream>
using namespace std;

int main(){
    int top;
    top = 100;
    int bottom;
    bottom = 0;
    int guess;
    string answer = "";
    guess = (top + bottom) / 2;
    bool keepGoing = true;
	while (keepGoing){
        cout << guess << "(H)igh, (L)ow, or (C)orrect";
        cin >> answer;
        if ((answer == "H")||(answer == "h")){
            cout << "High" << endl;
            top = guess;
            guess = (bottom + top) / 2;

        }//end if
        else if ((answer == "L")||(answer == "l")){
            cout << "Low" <<endl;
            bottom = guess;
            guess = (bottom + top) / 2;
        }//end elif
        else if (answer == "C"){
            cout << "Your number is "<< guess << endl;
            keepGoing = false;
        }//end elif
	}//end while
}// end main