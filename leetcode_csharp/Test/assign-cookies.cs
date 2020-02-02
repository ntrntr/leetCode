using System;
using System.Diagnostics;

namespace LeetCode
{
    public class assign_cookies
    {
        public int FindContentChildren(int[] g, int[] s) {
            Array.Sort(g);
            Array.Sort(s);
            int ret = 0;
            int j = 0;
            for (int i = 0; i < g.Length && j < s.Length;)
            {
                if (g[i] <= s[j])
                {
                    ret++;
                    j++;
                    i++;
                }
                else
                {
                    j++;
                }
            }
            return ret;
        }

        public static void Execute()
        {
            assign_cookies cl = new assign_cookies();
            Debug.Assert(cl.FindContentChildren(new []{1,2,3}, new []{1,1})== 1);
        }
    }
}