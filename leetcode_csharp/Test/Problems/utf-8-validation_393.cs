using System;
using System.Collections.Generic;

namespace Test.Problems
{
    public class utf_8_validation_393
    {
        public bool ValidUtf8(int[] data)
                 {
                     bool ret = true;
                     bool newDigit = true;
                     int leftCount = 0;
                     for (int i = 0; i < data.Length; ++i)
                     {
                         if (leftCount == 0)
                         {
                             newDigit = true;
                         }
                         if (newDigit)
                         {
                             var count = GetCount(data[i]);
                             if (count <= 0)
                             {
                                 ret = false;
                                 break;
                             }
         
                             leftCount = count - 1;
                             newDigit = false;
         
                         }
                         else if (leftCount > 0)
                         {
                             if (isValidNext(data[i]))
                             {
                                 leftCount--;
                             }
                             else
                             {
                                 ret = false;
                                 break;
                             }
                         }
                     }
                     return ret && leftCount == 0;
                 }
                 
                 private static readonly List<KeyValuePair<int,int>> Counts = new List<KeyValuePair<int, int>>()
                 {
                     new KeyValuePair<int, int>(1 << 7, 0),
                     new KeyValuePair<int, int>(7 << 5, 6 << 5),
                     new KeyValuePair<int, int>(15 << 4, 14 << 4),
                     new KeyValuePair<int, int>(31 << 3, 30 << 3)
                 };
         
                 private static readonly KeyValuePair<int,int> ValidNext = new KeyValuePair<int, int>(3 << 6, 2 << 6);
                 
                 private int GetCount(int data)
                 {
                     for (int i = Counts.Count - 1; i >= 0; --i)
                     {
                         if ((data & Counts[i].Key) == Counts[i].Value)
                         {
                             return i + 1;
                         }
                     }
         
                     return -1;
                 }
         
                 private bool isValidNext(int data)
                 {
                     return (data & ValidNext.Key) == ValidNext.Value;
                 }

        public static void Execute()
        {
            var utf8Validation393 = new utf_8_validation_393();
            List<int> data = new List<int>()
            {
                //197,130,1
                //248,130,130,130
                235, 140, 4
            };
            Console.WriteLine("{0}", utf8Validation393.ValidUtf8(data.ToArray()));
        }
    }
    
    
}