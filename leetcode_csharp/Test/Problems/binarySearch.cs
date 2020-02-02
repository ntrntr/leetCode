using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace leetcode_csharp
{
    class binarySearch
    {
        public int BinarySearch(int[] data, int target)
        {
            int ret = -1;
            int n = data.Length;
            int l = 0;
            int r = n-1;
            int oldSize;
            int size = n;
            while(l <= r)
            {
                int mid = (l + r) / 2;
                if (data[mid] == target)
                {
                    Debug.Assert(data[mid] == target && mid >= 0 && mid < n);
                    ret = mid;
                    break;
                }
                else if (data[mid] > target)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }

                oldSize = size;
                size = r - l + 1;
                Debug.Assert(size < oldSize);
            }
            return ret;
        }
        
        public int BadSearch(int[] data, int target)
        {
            int ret = -1;
            int n = data.Length;
            int l = 0;
            int r = n-1;
            while(l <= r)
            {
                int mid = (l + r) / 2;
                //脚手架
                Console.WriteLine("{0} {1} {2}", l, mid,r);
                if (data[mid] == target)
                {
                    
                    ret = mid;
                    break;
                }

                if (data[mid] > target)
                {
                    r = mid;
                }
                else
                {
                    l = mid;
                }
            }
            return ret;
        }
        
        public int BadSearch2(int[] data, int target)
        {
            int ret = -1;
            int l = 0;
            int r = data.Length-1;
            while(l <= r)
            {
                int mid = (l + r) / 2;
                if (data[mid] == target)
                {
                    //Debug.Assert();
                    ret = mid;
                    break;
                }

                if (data[mid] > target)
                {
                    r = mid;
                }
                else
                {
                    l = mid;
                }
            }
            return ret;
        }
        
        
        
        public static void main(string[] args)
        {
            var test = new binarySearch();
            int count = 1000000;
            List<int> testData = new List<int>();
            testData.Clear();
            int testi = 1;
            for (int i = 0; i < count; ++i)
            {
                
                
                testData.Add(i * 10);
                var array = testData.ToArray();
                var tick = DateTime.Now;
                for(int j = 0;j  < array.Length; ++j)
                {
                    var index2 = test.BinarySearch(array, array[j]);
                    Debug.Assert(index2 == j, $"error, search:{array[j]}, return index:{index2}, expected:{j}");
                }

                var times = (DateTime.Now - tick).Milliseconds;
                if (i == testi)
                {
                    Console.WriteLine("{0},{1}", i, times);
                    testi *= 10;
                }
                Debug.Assert(test.BinarySearch(array, 1) == -1);
                Debug.Assert(test.BinarySearch(array, -5) == -1);
            }
            
        }

    }
}
