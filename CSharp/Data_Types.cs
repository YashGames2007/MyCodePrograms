using System;

// namespace declaration
namespace CSharp
{

    // Class declaration
    class Data_Types
    {
        enum Days
        {
            Monday,
            Tuesday,
            Wednesday,
            Thursday,
            Friday,
            Saturday,
            Sunday
        }

        // Main Method
        public void Main()
        {
            unsafe
            {
                // declaring character
                char a = 'G';

                // Integer data type is generally
                // used for numeric values
                int i = (int)Days.Friday;

                short s = 56;

                // this will give error as number
                // is larger than short range
                // short s1 = 87878787878;

                // long uses Integer values which
                // may signed or unsigned
                long l = 4564;

                // UInt data type is generally
                // used for unsigned integer values
                uint ui = 95;

                ushort us = 76;
                // this will give error as number is
                // larger than short range

                // ulong data type is generally
                // used for unsigned integer values
                ulong ul = 3624573;

                // by default fraction value
                // is double in C#
                double d = 8.358674532;

                // for float use 'f' as suffix
                float f = 3.7330645f;

                // for float use 'm' as suffix
                decimal dec = 389.5m;
                int* _d = &i;

                int x = i < ui ? 1 : 2;

                Console.WriteLine("char: " + a);
                Console.WriteLine("integer: " + i);
                Console.WriteLine("short: " + s);
                Console.WriteLine("long: " + l);
                Console.WriteLine("float: " + f);
                Console.WriteLine("double: " + d);
                Console.WriteLine("decimal: " + dec);
                Console.WriteLine("Unsigned integer: " + ui);
                Console.WriteLine("Unsigned short: " + us);
                Console.WriteLine("Unsigned long: " + ul);
                Console.WriteLine("Pointer Address: " + (int)_d);
                Console.WriteLine("Pointer Value: " + (int)*_d);

            }
        }
    }
} 