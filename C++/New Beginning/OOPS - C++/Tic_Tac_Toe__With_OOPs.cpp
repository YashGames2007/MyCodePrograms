/* ::: File Documentation ::: */ /*
@   This is The Basic Game of Tic Tac Toe, Implemented in C++.
@       ⁎ This Code is Written in The Object Oriented Programming Style Implementation. [OOPs]
@       ⁎ This Game Includes AI Computer Players With Different Levels of Difficulty.
%               ⁎ AI Computer [Easy]
%               ⁎ AI Computer [Medium]
%               ⁎ AI Computer [Hard]
%               ⁎ AI Computer [Impossible]
@       ⁎ This Game Can Be Played by 3 Different Types.
%               ⁎ Player        v/s    Player
%               ⁎ Player        v/s    AI Computer
%               ⁎ AI Computer   v/s    AI Computer
@
#   |-*>>---   A Game By YashGames2007
*/

//* Pre Initialization Segment
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

//* Class Declarations...
class Tic_Tac_Toe_Game_Control_Setup;
typedef class Tic_Tac_Toe_Game_Control_Panel TTT_Game;

//* Player Types Declarations...
enum player_Type // Type of The Players
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
    static int possible_Combinations[8][3];

    int get_Options(char[]);
    void get_Tokens(char &, char &);

    void play_Randomly(void);
    int play_Defensively(void);
    int play_Aggressively(void);

    int minimax(char[9], int);
    int minimizer(int[], int[], int &);
    int maximizer(int[], int[], int &);
    int score(char[9], int, int);
    int is_Over(char[9]);

protected:
    int check_Game_Status(char[]);
    void display_Table(void);
    bool take_Turn(void);
    void show_Board_Status(void);
    void show_Points_Status(void);
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

int Tic_Tac_Toe_Game_Control_Panel::possible_Combinations[8][3] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6}};

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
    srand(time(0));
};

//* Min-Max Algorithm Programs...

/* Function Documentation:

@   Function That Scans all The Moves & Possible Outcomes and Takes The Most Precise Move.
*/
int Tic_Tac_Toe_Game_Control_Panel ::minimax(char ttt_Board[9], int depth = 0)
{
    depth++;
    char bot, opponent;
    get_Tokens(bot, opponent);

    if (is_Over(ttt_Board))
    {
        if (bot == 'X')
        {
            return score(ttt_Board, 0, depth);
        }
        else
        {
            return score(ttt_Board, 1, depth);
        }
    }
    else
    {
        token_Options current;

        int _Options;
        _Options = get_Options(ttt_Board);
        if (_Options % 2 == 1)
        {
            current = X;
        }
        else
        {
            current = O;
        }
        int scores[9];
        int moves[9];
        int move, index = 0;
        char possible_State[9];

        for (int i = 0; i < 9; i++)
        {
            scores[i] = 0;
            moves[i] = -1;
        }

        for (int i = 0; i < 9; i++)
        {
            if (ttt_Board[i] != 'X' && ttt_Board[i] != 'O')
            {
                move = i;

                for (int box = 0; box < 9; box++)
                {
                    possible_State[box] = ttt_Board[box];
                }

                if (current == X)
                {
                    possible_State[move] = 'X';
                }
                else
                {
                    possible_State[move] = 'O';
                }
                scores[index] = minimax(possible_State, depth);
                moves[index] = move;
                index++;
            }
        }

        if ((current == X && bot == 'X') || (current == O && bot == 'O'))
        {
            move = maximizer(scores, moves, index);
            ttt_Board[move] = bot;
            return scores[index];
        }
        else
        {
            move = minimizer(scores, moves, index);
            ttt_Board[move] = bot;
            return scores[index];
        }
    }
}

/* Function Documentation:

@   Function That Scans the Board and Returns True if Game is Over.
*/
int Tic_Tac_Toe_Game_Control_Panel ::is_Over(char ttt_Board[9])
{
    if (check_Game_Status(ttt_Board) != 0)
    {
        return 1;
    }
    for (int i = 0; i < 9; i++)
    {
        if (game_Board[i] != 'X' && game_Board[i] != 'O')
        {
            return 0;
        }
    }
    return 1;
}

/* Function Documentation:

@   Function That Checks, that the Game is Finished or Not, and Returns The Relative Score.
*/
int Tic_Tac_Toe_Game_Control_Panel ::score(char ttt_Board[9], int token, int depth)
{
    if (check_Game_Status(ttt_Board) == 0)
    {
        return 0;
    }
    else if (((check_Game_Status(ttt_Board) + 1) % 2) == token)
    {
        return (10 - depth);
    }
    else
    {
        return (depth - 10);
    }
}

/* Function Documentation:

@   Function That Scans all The Available Moves and Returns The Worst Relative Move.
*/
int Tic_Tac_Toe_Game_Control_Panel ::minimizer(int options[], int moves[], int &size)
{
    int minimum = options[0];
    int min_Index = 0;
    for (int index = 0; index < size; index++)
    {
        if (options[index] < minimum)
        {
            minimum = options[index];
            min_Index = index;
        }
    }
    size = min_Index;
    return moves[min_Index];
}

/* Function Documentation:

@   Function That Scans all The Available Moves and Returns The Best Relative Move.
*/
int Tic_Tac_Toe_Game_Control_Panel ::maximizer(int options[], int moves[], int &size)
{
    int maximum = options[0];
    int max_Index = 0;
    for (int index = 0; index < size; index++)
    {
        if (options[index] > maximum)
        {
            maximum = options[index];
            max_Index = index;
        }
    }
    size = max_Index;
    return moves[max_Index];
}

//* AI Computer Helper Functions...

/* Function Documentation:

@   Function That Gives The Opponent and AI Token for The Current Turn.
*/
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

/* Function Documentation:

@   Function That Returns The Number of Options Available for The Current Turn.
*/
int Tic_Tac_Toe_Game_Control_Panel::get_Options(char ttt_Board[] = NULL)
{
    if (ttt_Board == NULL)
    {
        ttt_Board = game_Board;
    }

    int count = 0;

    for (int i = 0; i < 9; i++)
    {
        if (ttt_Board[i] != 'X' && ttt_Board[i] != 'O')
        {
            count++;
        }
    }
    return count;
}

/* Function Documentation:

@   Function That Places The AI Token Randomly.
*/
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

    int bot_Turn = (rand() % count);
    char token, opponent;
    get_Tokens(token, opponent);
    game_Board[empty_Boxes[bot_Turn]] = token;
}

/* Function Documentation:

@   Function That Places The AI Token To Block The Opponent Winnings.
*/
int Tic_Tac_Toe_Game_Control_Panel::play_Defensively(void)
{
    char opp_Token, my_Token;
    get_Tokens(my_Token, opp_Token);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (game_Board[possible_Combinations[i][j]] == game_Board[possible_Combinations[i][(j + 1) % 3]] && game_Board[possible_Combinations[i][(j + 1) % 3]] == opp_Token)
            {
                game_Board[possible_Combinations[i][(j + 2) % 3]] = my_Token;
                return 1;
            }
        }
    }
    return 0;
}

/* Function Documentation:

@   Function That Places The AI Token To Win The Game.
*/
int Tic_Tac_Toe_Game_Control_Panel::play_Aggressively(void)
{
    char opp_Token, my_Token;
    get_Tokens(my_Token, opp_Token);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (game_Board[possible_Combinations[i][j]] == game_Board[possible_Combinations[i][(j + 1) % 3]] && game_Board[possible_Combinations[i][(j + 1) % 3]] == my_Token)
            {
                game_Board[possible_Combinations[i][(j + 2) % 3]] = my_Token;
                return 1;
            }
        }
    }
    return 0;
}

//* Computer AI Programs...

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
    cout << "Thinking..." << endl;
    minimax(game_Board);
}

//* Class Methods --- Tic Tac Toe Game Control Panel:

/* Function Documentation:

@   Function That Shows Current Tic Tac Toe Game Board Status.
*/
void Tic_Tac_Toe_Game_Control_Panel::show_Board_Status(void)
{
    cout << endl
         << "Current Board Status...";
    display_Table();
}

/* Function Documentation:

@   Function That Shows Current Tic Tac Toe Game Points Status.
*/
void Tic_Tac_Toe_Game_Control_Panel::show_Points_Status(void)
{
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
int Tic_Tac_Toe_Game_Control_Panel::check_Game_Status(char ttt_Board[] = NULL)
{
    if (ttt_Board == NULL)
    {
        ttt_Board = game_Board;
    }

    for (int i = 0; i < 8; i++)
    {
        if (ttt_Board[possible_Combinations[i][0]] == ttt_Board[possible_Combinations[i][1]] && ttt_Board[possible_Combinations[i][1]] == ttt_Board[possible_Combinations[i][2]])
        {
            if (ttt_Board[possible_Combinations[i][1]] == 'X')
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
    return 0;
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
    show_Board_Status();
    show_Points_Status();

    int option;
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
        cin >> option;

        if (option < 1 || option > 9)
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
        show_Board_Status();
        show_Points_Status();
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
        show_Board_Status();
        show_Points_Status();
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
    int is_Win = 0, _Play = 0;
    player1_Points = 0;
    player2_Points = 0;
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
    show_Points_Status();

    int winner = -1;
    if (player1_Points == player2_Points)
    {
        cout << "OOPS !!! IT's A Tie Game. !!!" << endl
             << "Better Luck Next Time !!!" << endl;
    }
    else
    {
        int winnings = abs(player1_Points - player2_Points);
        if (player1_Points > player2_Points)
        {
            winner = 0;
        }
        else
        {
            winner = 1;
        }

        cout << "Congratulations !!!" << endl
             << player_Names[winner] << " Wins The Game. !!! By ";

        if (winnings != 1)
        {
            cout << winnings << " Points. !!!" << endl;
        }
        else
        {
            cout << "1 Point. !!!" << endl;
        }
    }
}

//* Main Method Of The File...
int main()
{
    TTT_Game a(5, human, comp_Impossible);
    a.play();

    return 0;
}