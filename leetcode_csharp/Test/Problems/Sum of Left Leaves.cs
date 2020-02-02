using System;
using System.Collections.Generic;

namespace Test.Problems
{
    public class Sum_of_Left_Leaves
    {
        public class TreeNode
        {
            public int val;
            public TreeNode left;
            public TreeNode right;

            public TreeNode(int x)
            {
                val = x;
            }
        }

        public int SumOfLeftLeaves(TreeNode root)
        {
            int ret = 0;
            ret = GetLeftSum(root, false);
            return ret;
        }

        private int GetLeftSum(TreeNode root, bool isLeft)
        {
            if (root == null)
            {
                return 0;
            }
            
            if (root.left == null && root.right == null)
            {
                if (isLeft)
                {
                    return root.val;
                }
                else
                {
                    return 0;
                }

            }
            else
            {
                return GetLeftSum(root.left, true) + GetLeftSum(root.right, false);
            }
        }

        public static void Execute()
        {
            TreeNode root = new TreeNode(3)
            {
                left = new TreeNode(9),
                right = new TreeNode(20)
                {
                    left = new TreeNode(15),
                    right = new TreeNode(7),
                    val = 20
                },
                val = 3
            };
            Sum_of_Left_Leaves cl = new Sum_of_Left_Leaves();
            Console.WriteLine(cl.SumOfLeftLeaves(root));
        }
    }
}