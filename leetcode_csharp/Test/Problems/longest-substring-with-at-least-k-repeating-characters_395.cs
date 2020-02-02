using System;
using System.Collections.Generic;

namespace Test.Problems
{
    public class longest_substring_with_at_least_k_repeating_characters_395
    {
        private static int _letterLen = (int) 'z' - (int) 'a' + 1;
        public class LetterCount:ICloneable
        {
            public int[] data = null;

            public LetterCount()
            {
                data = new int[_letterLen];
            }
            
            public bool IsValid(int k)
            {
                foreach (int i in data)
                {
                    if (i > 0 && i < k)
                    {
                        return false;
                    }
                }

                return true;
            }

            public object Clone()
            {
                var letterCount = new LetterCount();
                for (int i = 0; i < data.Length; ++i)
                {
                    letterCount.data[i] = data[i];
                }
                return letterCount;
            }
        }

        public int LongestSubstring(string s, int k)
        {
            int ret = 0;
            if (k == 1)
            {
                return s.Length;
            }

            int currentLen = k;
            
            Dictionary<int, LetterCount> dict = new Dictionary<int, LetterCount>();
            
            LetterCount prevLetter = new LetterCount();

            for (int i = 0; i < s.Length; ++i)
            {
                LetterCount curLetter = prevLetter.Clone() as LetterCount;
                curLetter.data[(int) s[i] - (int) 'a']++;
                dict.Add(i, curLetter);
                prevLetter = curLetter;
            }

            for (int lastPos = s.Length - 1; lastPos >= 0; --lastPos)
            {
                for (int startPos = 0; startPos <= lastPos; ++startPos)
                {
                    if (lastPos - startPos + 1 <= ret)
                    {
                        break;
                    }

                    ret = Math.Max(ret, Sub(dict[lastPos], dict[startPos], k, s[startPos]));
                }
            }
            return ret;
        }

        private int Sub(LetterCount right, LetterCount left, int k, char c)
        {
            int ret = 0;
            right.data[(int) c - (int) 'a']++;
            for (int i = 0; i < right.data.Length; ++i)
            {
                var l = right.data[i] - left.data[i];
                if (l > 0 && l < k)
                {
                    ret = 0;
                    break;
                }

                ret += l;
            }
            right.data[(int) c - (int) 'a']--;
            return ret;
        }

        public static void Execute()
        {
            var str = Console.ReadLine();
            var k = int.Parse(Console.ReadLine());
            var solute = new longest_substring_with_at_least_k_repeating_characters_395();
            Console.WriteLine("result:{0}", solute.LongestSubstring(str, k));
        }
    }
}