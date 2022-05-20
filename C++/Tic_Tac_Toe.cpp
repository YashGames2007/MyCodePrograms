#include <iostream>
using namespace std;

void printBox(char *characters);
int conditionCheck(char *characters);

int main()
{
    int turn;
    char array[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    cout<<endl<<"   ***   Tic Tac Toe   ***   ";
    cout<<endl<<"Player1's Turn...";
    printBox(array);

    cout<<endl<<"Type the number of position that you have to place your 'X' :- ";
    cin>>turn;

    array[turn - 1] = 'X';
    printBox(array);
    cout<<endl<<"Player1 placed his X at" <<turn<<" No. place.";

    for (int i = 0; i < 4; i++)
    {
        cout<<endl<<"Player2's Turn...";
        printBox(array);
        cout<<endl<<"Type the number of position that you have to place your 'O' :- ";
        cin>>turn;
        
        array[turn - 1] = 'O';
        printBox(array);
        cout<<endl<<"Player2 placed his O at "<<turn<<" No. place.";

        if (conditionCheck(array))
        {
            cout<<endl;
            cout<<endl<<"Player2 wins the match.";
            cout<<endl<<"   ***   Congratulations   ***";
            cout<<endl<<"      - for Player2's Victory.";
            break;
        }
        else
        {
            cout<<endl<<"Player1's Turn...";
            printBox(array);
            cout<<endl<<"Type the number of position that you have to place your 'X' :- ";
            cin>>turn;

            array[turn - 1] = 'X';
            printBox(array);
            cout<<endl<<"Player1 placed his X at "<<turn<<" No. place.";

            if (conditionCheck(array))
            {
                cout<<endl;
                cout<<endl<<"Player1 wins the match.";
                cout<<endl<<"   ***   Congratulations   ***";
                cout<<endl<<"      - for Player1's Victory.";
                break;
            }
        }
    }
    if (conditionCheck(array) == 0)
    {
        cout<<endl;
        cout<<endl<<"It's a Tie match.";
        cout<<endl<<"Well Played...";
        cout<<endl<<"Better lick next time!";
    }
    return 0;
}