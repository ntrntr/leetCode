using System;

namespace Test.Problems
{
    public class Convert_a_Number_to_Hexadecimal
    {
        public string ToHex(int num)
        {

           return Convert.ToString(num, 16);
        }

        public static void Execute()
        {
            Convert_a_Number_to_Hexadecimal cls = new Convert_a_Number_to_Hexadecimal();
            while (true)
            {
                int test = int.Parse(Console.ReadLine());
                Console.WriteLine(cls.ToHex(test));
            }
        }
    }
}