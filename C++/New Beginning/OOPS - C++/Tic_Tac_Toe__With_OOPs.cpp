/* ::: File Documentation ::: */ /*
@   This is The Basic Game of Tic Tac Toe, Implemented in C++.
@       ⁎ This Code is Written in The Object Oriented Programming Style Implementation. [OOPs]
*/

/* Pre Initialization Segment */
#include <iostream>
#include <random>
#include <time.h>
using namespace std;

/* Class Declarations... */
class Tic_Tac_Toe_Game_Control_Setup;
typedef class Tic_Tac_Toe_Game_Control_Panel TTT_Game;

/* Player Types Declarations... */
enum player_Type // Type of The Player
{
    human,
    comp_Easy,
    comp_Medium,
    comp_Hard,
    comp_Impossible
};

//* Class Definition:
/* Class Documentation:

@   Some Setup Variables and Friend Class Rights are Declared Here.
*/
class Tic_Tac_Toe_Game_Control_Setup
{
private:
    static const char token[2]; // The Playing Tokens of The Game.
    string *player_Names;       // Name of The Two Players.
    enum token_Options          // Tokens for Option.
    {
        X,
        O
    };

    unsigned short int player1_Points;           // Player 1 Game Points.
    unsigned short int player2_Points;           // Player 2 Game Points.
    friend class Tic_Tac_Toe_Game_Control_Panel; // Class Copy Right Management.
};
const char Tic_Tac_Toe_Game_Control_Setup::token[2] = {'X', 'O'}; // Initializing Tokens...

/* Class Documentation:

@  The Main Class For The Game.
@  Game Corresponding Variables and their Respective Functions will be Declared here.
*/
class Tic_Tac_Toe_Game_Control_Panel : private Tic_Tac_Toe_Game_Control_Setup
{
private:
    char *game_Board;            // The Array of on Board Tokens of The Game.
    int total_Rounds;            // Total Number of Gaming Rounds in A Session.
    token_Options turn;          // Ongoing Token Option for Player Turn.
    player_Type player_Types[2]; // Type of Players.

    void get_Tokens(char &, char &);
    int get_Options(void);
    int check_Adjacency(int, int, int, char, char);
    void play_Randomly(void);
    int play_Defensively(void);
    int play_Aggressively(void);

protected:
    int check_Game_Status(void);
    void display_Table(void);
    bool take_Turn(void);
    void show_Game_Status(void);
    void reset_Game_Board(void);

    //* Different AI Computer Bots
    void computer_Easy(void);
    void computer_Medium(void);
    void computer_Hard(void);
    void computer_Impossible(void);

public:
    Tic_Tac_Toe_Game_Control_Panel(int, player_Type, player_Type);
    void play(void);
};

/* Constructor Function Documentation:

@   Initializer for New TTT Game Object.
*/
Tic_Tac_Toe_Game_Control_Panel::Tic_Tac_Toe_Game_Control_Panel(int total_Rounds = 3, player_Type player1_Type = human, player_Type player2_Type = human)
{
    this->player1_Points = 0;
    this->player2_Points = 0;

    this->total_Rounds = total_Rounds;
    this->turn = X;
    this->player_Names = new string[2];
    this->game_Board = new char[9];

    this->player_Types[0] = player1_Type;
    this->player_Types[1] = player2_Type;

    reset_Game_Board();

    // // Trial Checks
    // {
    //     game_Board[1] = 'O';
    //     game_Board[4] = 'O';
    //     game_Board[7] = 'O';
    // }

    // this->display_Table();
    // this->check_Game_Status();
    // cout << "Check: " << endl
    //      << "P1 Points: " << player1_Points << endl
    //      << "P2 Points: " << player2_Points << endl
    //      << endl;
};

//* Computer AI Programming...

void Tic_Tac_Toe_Game_Control_Panel::get_Tokens(char &bot_Token, char &opponent_Token)
{
    if (turn == X)
    {
        opponent_Token = 'O';
        bot_Token = 'X';
    }
    else
    {
        bot_Token = 'O';
        opponent_Token = 'X';
    }
}

int Tic_Tac_Toe_Game_Control_Panel::get_Options(void)
{
    int count = 0;

    for (int i = 0; i < 9; i++)
    {
        if (game_Board[i] != 'X' && game_Board[i] != 'O')
        {
            count++;
        }
    }
    return count;
}

int Tic_Tac_Toe_Game_Control_Panel::check_Adjacency(int _1, int _2, int _3, char is_Check, char is_Not_Check)
{
    char token, temp;
    get_Tokens(token, temp);
    if (game_Board[_1] == is_Check && game_Board[_2] == is_Check)
    {
        if (game_Board[_3] != is_Not_Check)
        {
            game_Board[_3] = token;
            return 1;
        }
    }
    return 0;
}

void Tic_Tac_Toe_Game_Control_Panel::play_Randomly(void)
{
    int count = get_Options();

    int empty_Boxes[count];
    int index = 0;

    for (int i = 0; i < 9; i++)
    {
        if (game_Board[i] != 'X' && game_Board[i] != 'O')
        {
            empty_Boxes[index] = i;
            index++;
        }
    }

    srand(time(0));
    int bot_Turn = (rand() % count);
    char token, opponent;
    get_Tokens(token, opponent);
    game_Board[empty_Boxes[bot_Turn]] = token;
}

int Tic_Tac_Toe_Game_Control_Panel::play_Defensively(void)
{
    int _1, _2, _3, temp; // Calculations Purpose Variables...
    char opp_Token, my_Token;
    get_Tokens(my_Token, opp_Token);

    /* Opponent Token Checks For Every Column */
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 9; j += 3)
        {
            _1 = (i + (j + 0)) % 9;
            _2 = (i + (j + 3)) % 9;
            _3 = (i + (j + 6)) % 9;

            temp = check_Adjacency(_1, _2, _3, opp_Token, my_Token);
            if (temp == 1)
            {
                return 1;
            }
        }
    }

    /* Opponent Token Checks For Every Row */
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            _1 = ((3 * i) + ((j + 0) % 3));
            _2 = ((3 * i) + ((j + 1) % 3));
            _3 = ((3 * i) + ((j + 2) % 3));

            temp = check_Adjacency(_1, _2, _3, opp_Token, my_Token);
            if (temp == 1)
            {
                return 1;
            }
        }
    }

    /* Opponent Token Checks For Diagonal 1 */
    for (int i = 0; i < 9; i += 4)
    {
        _1 = (i + 0) % 12;
        _2 = (i + 4) % 12;
        _3 = (i + 8) % 12;

        temp = check_Adjacency(_1, _2, _3, opp_Token, my_Token);
        if (temp == 1)
        {
            return 1;
        }
    }

    /* Opponent Token Checks For Diagonal 2 */
    for (int i = 0; i < 5; i += 2)
    {
        _1 = ((i + 0) % 6) + 2;
        _2 = ((i + 2) % 6) + 2;
        _3 = ((i + 4) % 6) + 2;

        temp = check_Adjacency(_1, _2, _3, opp_Token, my_Token);
        if (temp == 1)
        {
            return 1;
        }
    }
    return 0;
}

int Tic_Tac_Toe_Game_Control_Panel::play_Aggressively(void)
{
    int _1, _2, _3; // Calculations Purpose Variables...
    int played;
    char opp_Token, my_Token;
    get_Tokens(my_Token, opp_Token);

    /* Winning Condition Checks For Every Column */
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 9; j += 3)
        {
            _1 = (i + (j + 0)) % 9;
            _2 = (i + (j + 3)) % 9;
            _3 = (i + (j + 6)) % 9;

            played = check_Adjacency(_1, _2, _3, my_Token, opp_Token);
            if (played)
            {
                return 1;
            }
        }
    }

    /* Opponent Token Checks For Every Row */
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            _1 = ((3 * i) + ((j + 0) % 3));
            _2 = ((3 * i) + ((j + 1) % 3));
            _3 = ((3 * i) + ((j + 2) % 3));

            played = check_Adjacency(_1, _2, _3, my_Token, opp_Token);
            if (played)
            {
                return 1;
            }
        }
    }

    /* Opponent Token Checks For Diagonal 1 */
    for (int i = 0; i < 9; i += 4)
    {
        _1 = (i + 0) % 12;
        _2 = (i + 4) % 12;
        _3 = (i + 8) % 12;

        played = check_Adjacency(_1, _2, _3, my_Token, opp_Token);
        if (played)
        {
            return 1;
        }
    }

    /* Opponent Token Checks For Diagonal 2 */
    for (int i = 0; i < 5; i += 2)
    {
        _1 = ((i + 0) % 6) + 2;
        _2 = ((i + 2) % 6) + 2;
        _3 = ((i + 4) % 6) + 2;

        played = check_Adjacency(_1, _2, _3, my_Token, opp_Token);
        if (played)
        {
            return 1;
        }
    }
    return 0;
}

/* Function Documentation:

@   Easy AI Computer Bot For Tic Tac Toe Game.
@   This Ai Will  Place His Move Randomly, Choosing From Empty Boxes.
*/
void Tic_Tac_Toe_Game_Control_Panel::computer_Easy(void)
{
    play_Randomly();
}

/* Function Documentation:

@   Medium AI Computer Bot For Tic Tac Toe Game.
@   This AI Will Try To Win The Tic Tac Toe Game.
*/
void Tic_Tac_Toe_Game_Control_Panel::computer_Medium(void)
{
    int _1, _2, _3; // Indices of The Three Boxes To Be checked.
    int played;

    int count = get_Options();

    if (count <= 5)
    {
        play_Randomly();
    }
    else
    {
        played = play_Defensively();

        if (!played)
        {
            play_Randomly();
        }
    }
}

/* Function Documentation:

@   Hard AI Computer Bot For Tic Tac Toe Game.
*/
void Tic_Tac_Toe_Game_Control_Panel::computer_Hard(void)
{
    int played;

    played = play_Aggressively();

    if (!played)
    {
        played = play_Defensively();

        if (!played)
        {
            play_Randomly();
        }
    }
}

/* Function Documentation:

@   Impossible AI Computer Bot For Tic Tac Toe Game.
*/
void Tic_Tac_Toe_Game_Control_Panel::computer_Impossible(void)
{
}

//* Class Methods --- Tic Tac Toe Game Control Panel:
/* Function Documentation:

@   Function That Shows Current Tic Tac Toe Game Status.
*/
void Tic_Tac_Toe_Game_Control_Panel::show_Game_Status(void)
{
    cout << endl
         << "Current Board Status...";
    display_Table();

    cout << endl
         << "Current Points Status..." << endl
         << endl
         << player_Names[0] << "'s Points: " << player1_Points << endl
         << player_Names[1] << "'s Points: " << player2_Points << endl
         << endl;
}

/* Function Documentation:

@   Checking All Possible Winning Conditions of The Tic Tac Toe Game.
*/
int Tic_Tac_Toe_Game_Control_Panel::check_Game_Status(void)
{
    int win = -1;
    int got = -1;

    //* Checking Vertical Columns ::: ...
    //# Column 1:
    if ((game_Board[0] == game_Board[1]) && (game_Board[1] == game_Board[2]))
    {
        got = 1;
    }
    //# Column 2:
    else if ((game_Board[3] == game_Board[4]) && (game_Board[4] == game_Board[5]))
    {
        got = 4;
    }
    //# Column 3:
    else if ((game_Board[6] == game_Board[7]) && (game_Board[7] == game_Board[8]))
    {
        got = 7;
    }

    //* Checking Horizontal Rows ::: ...
    //# Row 1:
    else if ((game_Board[0] == game_Board[3]) && (game_Board[3] == game_Board[6]))
    {
        got = 3;
    }
    //# Row 2:
    else if ((game_Board[1] == game_Board[4]) && (game_Board[4] == game_Board[7]))
    {
        got = 4;
    }
    //# Row 3:
    else if ((game_Board[2] == game_Board[5]) && (game_Board[5] == game_Board[8]))
    {
        got = 5;
    }

    //* Checking Cross Diagonals ::: ...
    //# Diagonal 1:
    else if ((game_Board[0] == game_Board[4]) && (game_Board[4] == game_Board[8]))
    {
        got = 4;
    }
    //# Diagonal 2:
    else if ((game_Board[2] == game_Board[4]) && (game_Board[4] == game_Board[6]))
    {
        got = 4;
    }

    //* Final Conditional Check...
    if (got == -1)
    {
        win = 0;
    }
    else
    {
        if (game_Board[got] == 'X')
        {
            win = 1;
        }
        else if (game_Board[got] == 'O')
        {
            win = 2;
        }
    }
    return win;
}

/* Function Documentation:

@   Displaying The 3 X 3 Grid Table of The Tic Tac Toe Game.
*/
void Tic_Tac_Toe_Game_Control_Panel::display_Table(void)
{
    const string space = "   ";
    cout << endl
         << endl
         << space << " " << game_Board[0] << " | " << game_Board[1] << " | " << game_Board[2] << " " << endl
         << space << "===|===|===" << endl
         << space << " " << game_Board[3] << " | " << game_Board[4] << " | " << game_Board[5] << " " << endl
         << space << "===|===|===" << endl
         << space << " " << game_Board[6] << " | " << game_Board[7] << " | " << game_Board[8] << " " << endl
         << endl;
}

/* Function Documentation:

@   Getting Current Turn of The Tic Tac Toe Game.
*/
bool Tic_Tac_Toe_Game_Control_Panel::take_Turn(void)
{
    show_Game_Status();

    int option = 0;
    char _Option;
    char token;

    if (turn == X)
    {
        token = 'X';
    }
    else
    {
        token = 'O';
    }

    if (player_Types[turn] == human)
    {
        cout << player_Names[turn] << "'s Turn.." << endl;

        cout << "Type The Number In The Box Where You Want To Place Your '" << token << "': " << endl;
        cin >> _Option;
        option = _Option - '0';

        if (_Option < '1' || _Option > '9')
        {
            cerr << "!!! INVALID ENTRY !!! Unexpected Input, Please Type Correctly!" << endl;
            cin.clear();
            flush(cout);
            cin.clear();
            return false;
        }
        else if (game_Board[option - 1] == 'X' || game_Board[option - 1] == 'O')
        {
            cout << "!!! INVALID ENTRY !!! Box Already Filled, Try Another One!" << endl;
            return false;
        }
        else
        {
            cout << "Placing Your Turn...: " << option << endl;
            game_Board[option - 1] = token;
        }
        cout << "Turn Played Successfully!" << endl;
        show_Game_Status();
    }
    else
    {
        cout << "Computer Turn..." << endl;
        // game_Board[option] = token;

        if (player_Types[turn] == comp_Easy)
        {
            computer_Easy();
        }
        else if (player_Types[turn] == comp_Medium)
        {
            computer_Medium();
        }
        else if (player_Types[turn] == comp_Hard)
        {
            computer_Hard();
        }
        else //(player_Types[turn] == comp_Impossible)
        {
            computer_Impossible();
        }
        cout << "Computer Played His Turn Successfully!" << endl;
        show_Game_Status();
    }
    return true;
}

/* Function Documentation:

@   Functions That Sets The On-Board Values To there Default Values.
*/
void Tic_Tac_Toe_Game_Control_Panel::reset_Game_Board(void)
{
    int zero = 48; // Asci Value of Zero Number.

    for (int i = 1; i <= 9; i++)
    {
        game_Board[i - 1] = char(zero + i);
    }
}

/* Function Documentation:

@   The Main Function To Start The Tic Tac Toe Game Session.
@   Function Can Be Accessed Globally.
*/
void Tic_Tac_Toe_Game_Control_Panel::play(void)
{
    int is_Win = 0;
    player1_Points = 0;
    player2_Points = 0;
    int _Play = 0;
    string p_Type[2];

    for (int i = 0; i < 2; i++)
    {
        if (player_Types[i] == human)
        {
            p_Type[i] = "Human";
        }
        else if (player_Types[i] == comp_Easy)
        {
            p_Type[i] = "AI Computer [Easy]";
        }
        else if (player_Types[i] == comp_Medium)
        {
            p_Type[i] = "AI Computer [Medium]";
        }
        else if (player_Types[i] == comp_Hard)
        {
            p_Type[i] = "AI Computer [Hard]";
        }
        else // (player_Types[i] == comp_Impossible)
        {
            p_Type[i] = "AI Computer [Impossible]";
        }
    }

    //* Starting of The Game...
    cout << "*** *** Welcome To Tic Tac Toe Game *** ***" << endl
         << endl;

    cout << "Enter Player 1 Name: ";
    getline(cin, player_Names[0]);
    cout << "Enter Player 2 Name: ";
    getline(cin, player_Names[1]);

    cout << endl
         << endl
         << "Game Information ::: " << endl
         << endl
         << "     Total Rounds  : " << total_Rounds << endl
         << "     Player 1 Name : " << player_Names[0] << endl
         << "     Player 1 Type : " << p_Type[0] << endl
         << "     Player 2 Name : " << player_Names[1] << endl
         << "     Player 2 Type : " << p_Type[1] << endl
         << endl
         << endl
         << "Now The Game Begins..." << endl
         << endl;

    for (int rounds = 0; rounds < total_Rounds; rounds++)
    {
        cout << endl
             << "Round No. " << (rounds + 1) << " Starts..." << endl;

        for (int _Turn = 0; _Turn < 9; _Turn++)
        {
            if (_Turn % 2 == 0)
            {
                turn = X;
            }
            else
            {
                turn = O;
            }

            _Play = take_Turn();
            is_Win = check_Game_Status();

            if (_Play == false)
            {
                _Turn--;
                cin.clear();

                continue;
            }
            if (is_Win)
            {
                cout << "Congratulations !!!" << endl
                     << player_Names[turn] << " Wins The Round !!!" << endl;

                if (turn == X)
                {
                    player1_Points++;
                }
                else
                {
                    player2_Points++;
                }
                break;
            }
        }
        if (!is_Win)
        {
            cout << "Oops...!!! IT's A Tie Round!!!" << endl;
        }
        reset_Game_Board();
    }
    cout << "All Rounds Ended Successfully..." << endl
         << endl;

    cout << endl
         << "Current Points Status..." << endl
         << endl
         << player_Names[0] << "'s Points: " << player1_Points << endl
         << player_Names[1] << "'s Points: " << player2_Points << endl
         << endl;

    int winner = -1;
    if (player1_Points == player2_Points)
    {
        cout << "OOPS !!! IT's A Tie Game. !!!" << endl
             << "Better Luck Next Time !!!" << endl;
    }
    else
    {
        if (player1_Points > player2_Points)
        {
            winner = 0;
        }
        else
        {
            winner = 1;
        }

        cout << "Congratulations !!!" << endl
             << player_Names[winner] << " Wins The Game. !!!" << endl;
    }
}

/* Main Method Of The File. */
int main()
{
    TTT_Game a(3, comp_Easy, comp_Hard);
    a.play();
    return 0;
}
/*

        0 | 1 | 2
       ===|===|===
        3 | 4 | 5
       ===|===|===
        6 | 7 | 8

        0 | 1 | 2
       ---|---|---
        3 | 4 | 5
       ---|---|---
        6 | 7 | 8

*/