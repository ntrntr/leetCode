using System;
using System.Collections.Generic;

namespace Test.Problems
{
    public class rotate_function_396
    {
        public int MaxRotateFunction(int[] A)
        {
            if (A.Length == 0)
            {
                return 0;
            }

            long ret = Sum(A, 0);
            for (int i = 1; i < A.Length; ++i)
            {
                ret = Math.Max(ret, Sum(A, i));
            }
            return (int)ret;
        }

        private long Sum(int[] A, int offset)
        {
            long ret = 0;
            int len = A.Length;
            for (int i = 0; i < A.Length; ++i)
            {
                ret += A[i] * ((i + offset) % len);
            }

            return ret;
        }

        public static void Execute()
        {
            var rotta = new rotate_function_396();
            List<int> data = new List<int>
            {
                4,3,2,6
            };
            Console.WriteLine("{0}", rotta.MaxRotateFunction(data.ToArray()));
        }
    }
}