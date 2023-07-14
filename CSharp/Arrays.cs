using System;

// namespace declaration
namespace CSharp
{

    // Class declaration
    class Arrays
    {

        // Main Method
        public void Main()
        {

            Console.WriteLine("Hello World!");

            int[] arr = { 1, 2, 3 };

            char[] name = new char[4];

            name[0] = 'Y';
            name[1] = 'A';
            name[2] = 'S';
            name[3] = 'H';

            foreach (int element in arr)
            {
                Console.WriteLine("{0} ", element);
            }
            foreach (char item in name)
            {
                Console.Write("{0}", item);
            }

            char[,] ttt_board = new char[,] {
                                              { '1', '2', '3' },
                                              { '4', '5', '6' },
                                              { '7', '8', '9' }
                                                  };

            int[,,] coordinates = new int[3, 3, 3]
                { {
                    { 1, 2, 3 },
                    { 4, 5, 6 },
                    { 7, 8, 9 }
                },
                {
                    { 1, 2, 3 },
                    { 4, 5, 6 },
                    { 7, 8, 9 }
                },
                {
                    { 1, 2, 3 },
                    { 4, 5, 6 },
                    { 7, 8, 9 }
                } };

            Console.WriteLine("");
            foreach (int item in coordinates)
            {
                Console.Write("{0} ", item);
            }
            Console.WriteLine("{0}", coordinates[0, 1, 2]);

            // Jagged Arrays
            bool[][] conditions = {
                new bool[1] { true },
                new bool[2] { true, false },
                new bool[3] { true, false, true },
                new bool[4] { true, false, true, false },
                new bool[5] { true, false, true, false, true }
                };

            Console.WriteLine("");
            Console.WriteLine("The length of conditions is: {0}", conditions.GetLength(0));
            Console.WriteLine("The length of conditions[4] is: {0}", conditions[4].GetLength(0));
            Console.WriteLine("The length of coordinates is: {0}", coordinates.GetLength(0));
            Console.WriteLine("The length of coordinates[] is: {0}", coordinates.GetLength(1));
            Console.WriteLine("The length of coordinates[][] is: {0}", coordinates.GetLength(2));
            Console.WriteLine("");
            foreach (bool[] item in conditions)
            {
                foreach (bool element in item)
                {
                    Console.Write("{0} ", element);
                }
                Console.WriteLine("");
            }

            int[][,] var = new int[][,] {new int[, ] {{1, 3}, {5, 7}},
                                    new int[, ] {{0, 2}, {4, 6}, {8, 10}},
                                    new int[, ] {{11, 22}, {99, 88}, {0, 9}}};

            Console.WriteLine("");
            foreach (int[,] x in var)
            {
                foreach (int y in x)
                {
                    Console.Write("{0} ", y);
                }

                Console.WriteLine("");
            }
        }
    }
}