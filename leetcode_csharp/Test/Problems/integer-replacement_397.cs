using System;
using System.Collections.Generic;
using System.Reflection;
using System.Security.Cryptography.X509Certificates;

namespace Test.Problems
{
    public class integer_replacement_397
    {
        public int IntegerReplacement(int n)
        {
          
            var ret = Decrise(n);


            return (int)Math.Min(ret, FinalData(n));
        }

        private long FinalData(long n)
        {
            long cur = 0;
            if (n == 1)
            {
                return cur;
            }
            
            if (n % 2 == 0)
            {
                cur = Math.Min(1 + FinalData(n / 2), Increase(n));
            }
            else
            {
                cur = Math.Min(1 + FinalData(n + 1),Math.Min(1 + FinalData(n - 1), Increase(n)));
            }

            return cur;
        }

        private long Increase(long n)
        {
            var target = NextOrEqualPowOf2(n);
            long upFrom = UpStep(n, target);
            return upFrom + Decrise(target);
        }

        private long UpStep(long from, long to)
        {
            long ret = 0;
            while (to > from * 2)
            {
                from = from * 2;
                ret++;
            }

            ret += (to - from);

            return ret;
        }

        private long Decrise(long n)
        {
            var bits = NumToBit(n);
            if (bits.Count <= 1)
            {
                return 0;
            }

            long ret = bits.Count - 1;
            for (int i = bits.Count - 2; i >= 0; --i)
            {
                if (bits[i] == 1)
                {
                    ret++;
                }
            }
            return ret;

        }

        private List<int> NumToBit(long n)
        {
            List<int> ret = new List<int>();
            while (n > 0)
            {
                if ((n & 0x00000001) == 1)
                {
                    ret.Add(1);
                }
                else
                {
                    ret.Add(0);
                }

                n = (n >> 1);
            }
            return ret;
        }
        

        public long NextOrEqualPowOf2(long n)
        {
            if (IsPow2(n))
            {
                return n;
            }

            int offset = 0;
            while (n > 0)
            {
                n = (n >> 1);
                offset++;
            }

            return (1 << offset);
        }
        
        public bool IsPow2(long n)
        {
            return  (n > 0) && ((n & (n - 1)) == 0);
        }

        public int PowOfN(int x)
        {
            int ret = 0;
            while (x > 0)
            {
                x = (x >> 1);
                ret++;
            }

            return ret;
        }

        public static void Execute()
        {
            while (true)
            {
                var input  = Console.ReadLine();
                var solution = new integer_replacement_397();
                Console.WriteLine("in:{0}, out:{1}", int.Parse(input), solution.IntegerReplacement(int.Parse(input)));
            }
            
        }

        
    }
}