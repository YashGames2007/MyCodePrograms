using System;

// namespace declaration
namespace CSharp
{
    class ID
    {
        private int identity_No;
        private string student_Name;
        private static int total_Students = 0;

        public ID(string name, int identity_No)
        {
            this.name = name;
            this.identity_No = identity_No;
            CSharp.ID.total_Students++;
        }

        ~ID()
        {
            this.show_Details();
            CSharp.ID.total_Students--;
            Console.WriteLine(CSharp.ID.get_No_of_Students());
        }

        public int identity
        {
            get { return this.identity_No; }
            set { this.identity_No = value; }
        }

        public string name
        {
            get { return this.student_Name; }
            set { this.student_Name = value; }
        }

        public virtual void show_Details()
        {
            Console.WriteLine("Name: {0}\nID: {1}", this.name, this.identity);
        }

        public static int get_No_of_Students()
        {
            return CSharp.ID.total_Students;
        }
    }

    class Result : CSharp.ID
    {
        string[] subjects;
        int[] marks;

        public Result(string name, int identity_No, params string[] subjects) : base(name, identity_No)
        {
            this.constructor(subjects.GetLength(0), subjects);
        }

        public Result(CSharp.ID old_ID, params string[] subjects) : base(old_ID.name, old_ID.identity)
        {
            this.constructor(subjects.GetLength(0), subjects);
        }

        private void constructor(int no_of_Subjects, string[] subjects)
        {
            this.subjects = new string[no_of_Subjects];
            this.marks = new int[no_of_Subjects];

            for (int i = 0; i < no_of_Subjects; i++)
            {
                this.subjects[i] = subjects[i];
            }
        }
        public void set_Marks(params int[] marks)
        {
            if (marks.GetLength(0) != this.subjects.GetLength(0))
            {
                Console.WriteLine("Not given enough sequence of marks!");
                return;
            }

            for (int i = 0; i < this.subjects.GetLength(0); i++)
            {
                this.marks[i] = marks[i];
            }
        }

        public override void show_Details()
        {
            base.show_Details();
            Console.WriteLine("\nSubject: Marks");
            for (int i = 0; i < this.subjects.GetLength(0); i++)
            {
                Console.WriteLine("{0}: {1}", this.subjects[i], this.marks[i]);
            }
            Console.WriteLine("");
        }
    }

    // Class declaration
    class Object_Orientation
    {

        // Main Method
        public void Main()
        {

            Console.WriteLine("Hello World!");


            ID id_1 = new ID("Yash Bhavsar", 224002);
            id_1.show_Details();


            ID id_2 = new ID("Tushar Ambhore", 224001);
            id_2.show_Details();

            ID id_3 = new ID("Mayur Gaikwad", 224008);
            id_3.show_Details();

            Result result_1 = new Result("Anand Pathade", 222240, "English", "Maths", "Physics");
            result_1.set_Marks(85, 90, 95);
            result_1.show_Details();

            Result result_2 = new Result(id_1, "English", "Maths", "Physics");
            result_2.set_Marks(98, 95, 100);
            result_2.show_Details();
        }
    }
}//!