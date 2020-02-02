using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace LeetCode.Code
{
    public class minimum_moves_to_equal_array_elements
    {
        public int MinMoves(int[] nums)
        {
            int ret = 0;
            var datas = new List<int>(nums);
            datas.Sort();
            if (datas.Count <= 1)
            {
                return 0;
            }

            int len = datas.Count;
            var maxData = datas[len-1];
            while (datas[0] < datas[len-1])
            {
                Print(datas);
                int idx = binarySearchLess(datas, datas[len - 1]);
                Console.WriteLine(idx);
                var lesser = datas[idx];
                var delta = datas[len - 1] - lesser;
                ret += delta;
                for (int i = 0; i < datas.Count - 1; ++i)
                {
                    datas[i] += delta;
                }
                Print(datas);
                idx = binarySearchLess(datas, datas[len - 1]);
                Console.WriteLine("insert idx:{0}", idx);
                var tmp = datas[len - 1];
                datas[len - 1] = datas[idx+1];
                datas[idx+1] = tmp;
                Print(datas);
                Console.WriteLine("-----------");
            }
            return ret;
        }

        public void Print(List<int> nums)
        {
            foreach (int num in nums)
            {
                Console.Write("{0},", num);
            }
            Console.WriteLine();
        }

        public static void Execute()
        {
            var test = new minimum_moves_to_equal_array_elements();
            Debug.Assert(3 == test.MinMoves(new []{1,2,2,3}));
        }

        private int binarySearchLess(List<int> nums, int data)
        {
            int lower = 0;
            int upper = nums.Count - 2;
            while (lower <= upper)
            {
                int mid = lower + (upper - lower) / 2;
                if (nums[mid] < data)
                {
                    lower = mid + 1;
                }
                else if (nums[mid] == data)
                {
                    upper = mid - 1;
                }
                else
                {
                    upper = mid - 1;
                }
            }

            int ret = Math.Min(lower, upper);
            if (ret < 0)
            {
                ret = 0;
            }

            if (ret > nums.Count - 2)
            {
                ret = nums.Count - 2;
            }

            return ret;
        }
    }
}