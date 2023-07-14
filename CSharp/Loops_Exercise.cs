using System;

// namespace declaration
namespace CSharp
{

    // Class declaration
    class Loops
    {

        // Main Method
        public void Main()
        {

            Console.WriteLine("Hello World!");

            uint number;
            bool isPrime = true;
            bool play = true;

            do
            {
                Console.WriteLine("Enter a Number: ");
                number = Convert.ToUInt32(Console.ReadLine());

                if (number <= 1)
                {
                    Console.WriteLine("Not a valid number to check Primeness!");
                    goto chance;
                }
                else if (number == 2 || number == 3)
                {
                    isPrime = true;
                }
                else if (number % 2 == 0)
                {
                    isPrime = false;
                }
                else
                {
                    uint factor = 3;
                    while (factor <= ((number / 2) - 1))
                    {
                        for (int multiple = 3; (multiple * factor) <= number; multiple += 2)
                        {
                            if ((multiple * factor) == number)
                            {
                                isPrime = false;
                                break;
                            }
                        }
                        factor += 2;
                    }
                }
                if (isPrime)
                {
                    Console.WriteLine("The number {0} is Prime.", number);
                }
                else
                {
                    Console.WriteLine("The number {0} is not Prime.", number);
                }

                chance:
                    Console.WriteLine("Do you want to play again? (1 for yes, 2 for no): ");
                    play = Convert.ToByte(Console.ReadLine()) == 1 ? true : false;
        
            } while (play);
        }
    }
}