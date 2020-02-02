using System.Diagnostics;
using System.Linq;
using System.Text;

namespace Test.Problems
{
    public class Add_Strings
    {
        public string AddStrings(string nums1, string nums2) {
            int len1 = nums1.Length;
            int len2 = nums2.Length;
            if (len1 > len2)
            {
                return AddStrings(nums2, nums1);
            }

            StringBuilder ret = new StringBuilder(5200);
            int i = 0;
            int jinwei = 0;
            for (i = 0; i < len1; ++i)
            {
                int current = GetInt(nums1[len1 - 1 - i]) + GetInt(nums2[len2 - 1 - i]) + jinwei;
                ret.Append(GetString(current % 10));
                jinwei = current / 10;
            }
        
            for (;i < len2; ++i)
            {
                int current =  GetInt(nums2[len2 - 1 - i]) + jinwei;
                ret.Append(GetString(current % 10));
                jinwei = current / 10;
            }
        
            if (jinwei > 0)
            {
                ret.Append(GetString(jinwei));
            }

            return ReverseString(ret.ToString());
        }
    
        private int GetInt(char c)
        {
            return (int)c - '0';
        }
    
        private string GetString(int x)
        {
            return x.ToString();
        }

        private string ReverseString(string s)
        {
            StringBuilder ret = new StringBuilder(5200);
            for (int i = s.Length - 1; i >= 0; --i)
            {
                ret.Append(s[i]);
            }

            return ret.ToString();
        }

        public static void Execute()
        {
            Add_Strings cl = new Add_Strings();
            Debug.Assert(cl.AddStrings("12", "1") == "13");
        }
    }
}