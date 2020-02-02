using System;
using System.Diagnostics;
using System.Runtime.InteropServices;

namespace Test.Problems
{
    public class NthDigit
    {
        public int FindNthDigit(int n)
        {
            int ret = 0;
            int current = 1;
            long currentStart = 1;
            while (n > 0)
            {
                currentStart =  (long) Math.Pow(10, current - 1);
                long currentBoundSize = 9 * (long) Math.Pow(10, current - 1);
                if (n <= currentBoundSize * current)
                {
                    var target = currentStart + (n - 1) / current;
                    var rightOffset = current - ((n - 1) % current) - 1;
                    while (rightOffset > 0)
                    {
                        target = target / 10;
                        rightOffset--;
                    }

                    ret = (int) (target % 10);
                    n = 0;
                }
                else
                {
                    n -= (int)currentBoundSize * current;
                }
                current++;
                
            }

            return ret;
        }
        
        public static void Test()
        {
            var test = new NthDigit();
            Debug.Assert(test.FindNthDigit(10) == 1);
            Debug.Assert(test.FindNthDigit(11) == 0);
            Debug.Assert(test.FindNthDigit(12) == 1);
            Debug.Assert(test.FindNthDigit(100) == 5);
            Debug.Assert(test.FindNthDigit(1000) == 3);
            Debug.Assert(test.FindNthDigit(1) == 1);
            Debug.Assert(test.FindNthDigit(9) == 9);
    
        }
    }
    
    
}