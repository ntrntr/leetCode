using System;
using System.Collections.Generic;

namespace Test.Problems
{
//    A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
//    Each LED represents a zero or one, with the least significant bit on the right.
    public class Binary_Watch
    {
        private const int hsize = 5;
        private static List<List<int>> Hours = new List<List<int>>(hsize);
        private static readonly int HoursMax = 11;
        private const int msize = 7;

        private static List<List<int>> Minutes = new List<List<int>>(msize);
        private static readonly int MinutesMax = 59;

        static Binary_Watch()
        {
            InitHours();
            InitMinutes();
        }

        private static void InitMinutes()
        {
            
            for (int i = 0; i < msize; ++i)
            {
                Minutes.Add(new List<int>());
            }

            for (int i = 0; i <= MinutesMax; ++i)
            {
                Minutes[OneCount(i)].Add(i);
            }
        }

        private static void InitHours()
        {
            for (int i = 0; i < hsize; ++i)
            {
                Hours.Add(new List<int>());
            }

            for (int i = 0; i <= HoursMax; ++i)
            {
                Hours[OneCount(i)].Add(i);
            }
        }

        public IList<string> ReadBinaryWatch(int num) {
            List<string> ret = new List<string>();
            for (int i = 0; i <= num && i < Hours.Count; ++i)
            {
                int j = num - i;
                if (j < Minutes.Count)
                {
                    foreach (int s in Hours[i])
                    {
                        foreach (int s1 in Minutes[j])
                        {
                            ret.Add(string.Format("{0}:{1:00}", s, s1));
                        }
                    }
                }
            }
            return ret;
        }
        
        public static int OneCount(int x)
        {
            int ret = 0;
            while (x > 0)
            {
                x = x & (x - 1);
                ret++;
            }

            return ret;
        }

        public static void Execute()
        {
            Binary_Watch test = new Binary_Watch();

            while (true)
            {
                var data = test.ReadBinaryWatch(int.Parse(Console.ReadLine()));
                foreach (string s in data)
                {
                    Console.WriteLine(s);
                }
            }
            
        }

        
    }
}