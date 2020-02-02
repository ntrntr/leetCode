using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace LeetCode.Code
{
    public class minimum_number_of_arrows_to_burst_balloons452
    {
        public minimum_number_of_arrows_to_burst_balloons452()
        {
        }
        
        public struct MyStruct
        {
            public int lowBound;
            public int upBound;
        }
        
        public int FindMinArrowShots(int[,] points)
        {
            int ret = 0;
            List<MyStruct> datas = new List<MyStruct>();
            for (int i = 0; i < points.GetLength(0); i++)
            {
                datas.Add(new MyStruct
                {
                    lowBound = points[i, 0],
                    upBound = points[i,1]
                        
                });
            }

            if (datas.Count <= 1)
            {
                return datas.Count;
            }
            
            datas.Sort(delegate(MyStruct a, MyStruct b)
            {
                if (a.upBound == b.upBound)
                {
                    return a.lowBound < b.lowBound ? -1 : 1;
                }
                else
                    return a.upBound < b.upBound ? -1 : 1;
            });

            //PrintData(datas);

            bool exits = false;
            int candidate = -1;
            
            for (int i = 0; i < datas.Count;)
            {
                if (!exits)
                {
                    exits = true;
                    candidate = datas[i].upBound;
                    ret++;
                    i++;
                }
                else
                {
                    if (datas[i].lowBound <= candidate)
                    {
                        i++;
                    }
                    else
                    {
                        exits = false;
                    }
                }
                
            }
            
            return ret;
        }

        private static void PrintData(List<MyStruct> datas)
        {
            foreach (MyStruct myStruct in datas)
            {
                Console.WriteLine("{0}:{1}", myStruct.lowBound, myStruct.upBound);
            }
        }

        public static void Exectue()
        {
            var test = new minimum_number_of_arrows_to_burst_balloons452();
            var ret = test.FindMinArrowShots(new int[,]
            {
                {10, 16},
                {2, 8},
                {1, 6},
                {7, 12}
            });
            Debug.Assert(ret == 2);
            Console.WriteLine(ret);
            ret = test.FindMinArrowShots(new int[,]
            {
                {10, 16},
                {2, 8},
                {8, 6},
                {7, 12}
            });
        }
        
    }
}
