using System;

// namespace declaration
namespace CSharp
{

    // Class declaration
    class MarkSheet
    {

        // Main Method
        public void Main()
        {

            Console.Write("Enter the name of the Student: ");
            string name = Console.ReadLine();
            Console.Write("Enter the En. No. of the Student: ");
            string enrollment = Console.ReadLine();
            
            Console.Write("Enter the name of the 1st Subject: ");
            string subject_1 = Console.ReadLine();
            Console.Write("Enter the name of the 2nd Subject: ");
            string subject_2 = Console.ReadLine();
            Console.Write("Enter the name of the 3rd Subject: ");
            string subject_3 = Console.ReadLine();

            Console.Write("Enter the marks in {0}: ", subject_1);
            ushort marks_1 = Convert.ToUInt16(Console.ReadLine());
            Console.Write("Enter the marks in {0}: ", subject_2);
            ushort marks_2 = Convert.ToUInt16(Console.ReadLine());
            Console.Write("Enter the marks in {0}: ", subject_3);
            ushort marks_3 = Convert.ToUInt16(Console.ReadLine());


            Console.WriteLine("\nResult::");
            Console.WriteLine("Student Name: " + name);
            Console.WriteLine("Student En.No.: " + enrollment);
            Console.WriteLine("1st Subject Marks: {0}", marks_1);
            Console.WriteLine("2nd Subject Marks: {0}", marks_2);
            Console.WriteLine("3rd Subject Marks: {0}", marks_3);

            if (marks_1 < 35 || marks_2 < 35 || marks_3 < 35)
            {
                Console.WriteLine("Sorry, {0}, You are failed, Better Luck Next time!", name);
            }
            else if ((marks_1 + marks_2 + marks_3) < 120)
            {
                Console.WriteLine("Sorry, {0}, You are failed, Better Luck Next time!", name);
            }
            else
            {
                Console.WriteLine("Congratulations, {0}! You are Passed!", name);
            }

        }
    }
}