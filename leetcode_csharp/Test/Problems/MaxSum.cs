using System;
using System.Diagnostics;

namespace Test.Problems
{
    public class MaxSum1
    {
        public int MaxSum21(int[] A)
        {
            int maxsum = int.MinValue;
            int len = A.Length;
            int sum = 0;
            for (int i = 0; i < len; ++i)
            {
                
                for (int j = i; j < len; ++j)
                {
                    sum = 0;
                    for (int k = i; k <= j; ++k)
                    {
                        sum += A[k];
                    }

                    if (sum > maxsum)
                    {
                        maxsum = sum;
                    }
                }
            }
            return maxsum;
        }
        
        public int MaxSum22(int[] A)
        {
            int maxsum = int.MinValue;
            int len = A.Length;
            int sum = 0;
            for (int i = 0; i < len; ++i)
            {
                sum = 0;
                for (int j = i; j < len; ++j)
                {
                    sum += A[j];

                    if (sum > maxsum)
                    {
                        maxsum = sum;
                    }
                }
            }
            return maxsum;
        }
        
        public int MaxSum24(int[] A)
        {
            int maxsum = int.MinValue;
            int len = A.Length;
            int sum = 0;
            return FindMaxSum(A, 0, len - 1);
        }

        private int FindMaxSum(int[]A, int low, int high)
        {
            if (low == high)
            {
                return A[low];
            }
            else
            {
                int mid = low + (high - low) / 2;
                int leftSum = FindMaxSum(A, low, mid);
                int rightSum = FindMaxSum(A, mid + 1, high);
                int crossSum = FindCrossSum(A, low, mid, high);

                return Math.Max(leftSum, Math.Max(rightSum, crossSum));
            }
        }

        private int FindCrossSum(int[] A, int low, int mid, int high)
        {
            int leftSum = int.MinValue;
            int sum = 0;
            for (int i = mid; i >= low; --i)
            {
                sum += A[i];
                leftSum = Math.Max(leftSum, sum);
            }

            int rightSum = int.MinValue;
            sum = 0;
            for (int i = mid + 1; i <= high; ++i)
            {
                sum += A[i];
                rightSum = Math.Max(rightSum, sum);
            }

            return leftSum + rightSum;
        }
        
        public int MaxSum25(int[] A)
        {
            int maxsum = int.MinValue;
            int len = A.Length;
            int sum = 0;
            int[] S = new int[len+1];
            int[] End = new int[len+1];
            S[0] = A[0];
            End[0] = A[0];
            for (int i = 1; i < len; ++i)
            {
                End[i] = Math.Max(A[i], End[i - 1] + A[i]);
                S[i] = Math.Max(S[i - 1], End[i]);
            }
            return S[len - 1];
        }
        
        public int MaxSum(int[] A)
        {
            int maxsum = int.MinValue;
            int len = A.Length;
            int sum = 0;
            int S = A[0];
            int End = A[0];
            for (int i = 1; i < len; ++i)
            {
                End = Math.Max(A[i], End + A[i]);
                S = Math.Max(S, End);
            }
            return S;
        }


        public static void Execute()
        {
            Problems.MaxSum1 t = new MaxSum1();
            Debug.Assert(t.MaxSum(new []{1,-2,3,5,-3,2}) == 8);
            Debug.Assert(t.MaxSum(new []{0,-2,3,5,-1,2}) == 9);
            Debug.Assert(t.MaxSum(new []{-9,-2,-3,-5,-3}) == -2);
            Debug.Assert(t.MaxSum(new []{-1111}) == -1111);
            //Debug.Assert(t.MaxSum(new []{}) == 0);
        }
    }
}