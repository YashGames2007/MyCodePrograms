// 4.2 Hrs
using System;
// namespace declaration
namespace CSharp
{
    class TTT_Player
    {
        private string player_Name;
        private char player_Token;
        private uint player_Points;

        public TTT_Player(string name, char token)
        {
            this.player_Name = name;
            this.player_Token = token;
        }

        public string name
        {
            get { return this.player_Name; }
            set { this.player_Name = value; }
        }

        public char token
        {
            get { return this.player_Token; }
            set { this.player_Token = value; }
        }

        public uint points
        {
            get { return this.player_Points; }
            set { this.player_Points = value; }
        }

        public void get_Info()
        {
            Console.WriteLine($"Name  : {this.player_Name}");
            Console.WriteLine($"Token : {this.player_Token}");
            Console.WriteLine($"Points: {this.player_Points}");
        }
    }

    // Game Class
    class Tic_Tac_Toe
    {
        // Player Attributes:
        private string[] player_Names;
        private char[] player_Tokens;
        private uint[] player_Points;
        private bool isNamePredefined = false;

        private enum Token { X, O };
        private enum Players { P1, P2 };

        // Game Attributes:
        private char[] game_Board;
        private uint total_Rounds;
        private uint current_Round;

        //Class Constructor
        public Tic_Tac_Toe(uint total_Rounds = 3, params string[] player_Names)
        {
            this.instance_Construction(total_Rounds);

            for (int i = 0; i < 2; i++)
            {
                this.player_Names[i] = player_Names[i];
            }

            this.isNamePredefined = true;
        }

        //Class Constructor (without player names):
        public Tic_Tac_Toe(uint total_Rounds = 3) { this.instance_Construction(total_Rounds); }

        private void instance_Construction(uint total_Rounds)
        {
            this.player_Names = new string[2] { "", "" };
            this.player_Tokens = new char[2] { 'X', 'O' };
            this.player_Points = new uint[2] { 0, 0 };
            this.game_Board = new char[9];
            this.game_Board_Cleanup();

            this.total_Rounds = total_Rounds;
        }

        private void game_Board_Cleanup()
        {
            int index = 0;
            for (char i = '1'; i <= '9'; i++)
            {
                this.game_Board[index] = i;
                index++;
            }
        }

        private void make_Turn(int current_Player, TTT_Player[] players)
        {
        Retry:
            Console.Write($"{players[current_Player].name}, Enter the number at the position where you want to place your '{players[current_Player].token}': ");
            try
            {
                int turn = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("");
                if ((!((turn < 1) || (turn > 9)) && (this.game_Board[turn - 1] != 'X') && (this.game_Board[turn - 1] != 'O')))
                {
                    this.game_Board[turn - 1] = players[current_Player].token;
                }
                else
                {
                    Console.WriteLine("Invalid Entry! Please Type Correct Number.");
                    goto Retry;
                }
            }
            catch (System.Exception)
            {

                Console.WriteLine("Invalid Entry! Please Type Correct Number.");
                goto Retry;
            }
        }

        private int check_Status()
        {
            int[,] conditions = new int[8, 3] {
                { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 },  // Horizontal Checks
                { 0, 3, 6 }, { 1, 4, 7 }, { 2, 5, 8 },  // Vertical Checks
                { 0, 4, 8 }, { 2, 4, 6 }        // Cross-Directional Checks
            };

            for (int i = 0; i < 8; i++)
            {
                for (int token = 0; token < 2; token++)
                {
                    if ((this.game_Board[conditions[i, 0]] == this.game_Board[conditions[i, 1]]) && (this.game_Board[conditions[i, 1]] == this.game_Board[conditions[i, 2]]))
                    {
                        if (this.game_Board[conditions[i, 0]] == 'X') { return 0; }
                        else if (this.game_Board[conditions[i, 0]] == 'O') { return 1; }
                    }
                }
            }
            return -1;
        }

        private void show_Board()
        {
            Console.WriteLine(" {0} | {1} | {2} ", this.game_Board[0], this.game_Board[1], this.game_Board[2]);
            Console.WriteLine("---|---|---");
            Console.WriteLine(" {0} | {1} | {2} ", this.game_Board[3], this.game_Board[4], this.game_Board[5]);
            Console.WriteLine("---|---|---");
            Console.WriteLine(" {0} | {1} | {2} ", this.game_Board[6], this.game_Board[7], this.game_Board[8]);
            Console.WriteLine("\n");
        }

        // 0 for player1, 1 for player2 and -1 for no one.
        private bool are_Both_Same(uint a, uint b)
        {
            // If Both are Even...
            if ((a % 2 == 0) && (b % 2 == 0)) { return true; }
            // If Both are Odd...
            else if ((a % 2 != 0) && (b % 2 != 0)) { return true; }
            // If One is Even and other is Odd...
            else { return false; }
        }

        // Main Controller Method of the Game:
        public void play()
        {
            Console.WriteLine("\n\n!!! Tic Tac Toe Game !!!\n\n");

            // Taking Player Names as Input...
            if (!this.isNamePredefined)
            {
                Console.Write("Enter Player 1 Name: ");
                this.player_Names[0] = Console.ReadLine();
                Console.Write("Enter Player 2 Name: ");
                this.player_Names[1] = Console.ReadLine();

                Console.WriteLine("\n");
            }

            // Creating Players...
            TTT_Player[] players = new TTT_Player[2];
            for (int i = 0; i < 2; i++)
            {
                players[i] = new TTT_Player(this.player_Names[i], this.player_Tokens[i]);
                players[i].points = this.player_Points[i];
            }

            Console.WriteLine($"Get ready, {players[(int)Players.P1].name} & {players[(int)Players.P2].name} ...\n");
            int current_Player;

            for (this.current_Round = 1; this.current_Round <= this.total_Rounds; this.current_Round++)
            {
                Console.WriteLine($"Round No. {this.current_Round} starts...\n");
                this.game_Board_Cleanup();
                for (uint turn = 1; turn <= 9; turn++)
                {
                    if (this.are_Both_Same(this.current_Round, turn)) { current_Player = (int)Players.P1; }
                    else { current_Player = (int)Players.P2; }

                    Console.WriteLine($"{players[current_Player].name}'s Turn...\n");
                    this.show_Board();
                    this.make_Turn(current_Player, players);
                    this.show_Board();

                    int winner = this.check_Status();
                    if (winner != -1)
                    {
                        Console.WriteLine($"{players[winner].name} wins the round.!");
                        players[winner].points++;
                        break;
                    }
                    if (turn == 9 && winner == -1) { Console.WriteLine("It's a Tie Round!"); }
                }
                Console.WriteLine($"\nCurrent Score:\n{players[(int)Players.P1].name}'s Points: {players[(int)Players.P1].points}\n{players[(int)Players.P2].name}'s Points: {players[(int)Players.P2].points}\n");
            }

            int match_Winner = -1;
            if (players[(int)Players.P1].points == players[(int)Players.P2].points)
            {
                Console.Write("Oops! It's a Tie Match, Better Luck Next Time!!!");
            }
            else if (players[(int)Players.P1].points < players[(int)Players.P2].points)
            {
                match_Winner = 1;
            }
            else if (players[(int)Players.P1].points > players[(int)Players.P2].points)
            {
                match_Winner = 0;
            }
            Console.WriteLine($"Congratulations!!! {players[match_Winner].name} wins the Match by {(players[match_Winner].points - players[(match_Winner + 1) % 2].points)} point(s).!");
        }

    }

    // Class declaration
    class TTT
    {
        // Main Method
        public void Main()
        {
            Console.WriteLine("Hello World!");

            Tic_Tac_Toe new_Game = new Tic_Tac_Toe();
            new_Game.play();
        }
    }
}