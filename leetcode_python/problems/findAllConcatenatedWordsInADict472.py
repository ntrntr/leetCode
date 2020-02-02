import unittest
class TrieTree(object):

    def __init__(self, data):
        self.data = data
        self.isWorld = False
        self.next = {}

class Solution(object):

    def findAllConcatenatedWordsInADict(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        ret = []
        self.root = TrieTree(-1)
        for word in words:
            self.createTri(word)
        for word in words:
            if self.judge(word) > 1:
                ret.append(word)
        return ret



    def createTri(self, word):
        cur = self.root
        for char in word:
            if not cur.next.get(char, None):
                cur.next[char] = TrieTree(char)
            cur = cur.next.get(char)
        cur.isWorld = True

    def judge(self, word):
        # print 'judge, ', word
        ret = 0
        cur = self.root
        if not word:
            # print 'ret',ret, word
            return 0
        for idx,char in enumerate(word):
            next = cur.next.get(char, None)
            if next:
                if next.isWorld:
                    if idx + 1 == len(word):
                        ret += 1
                        break
                    else:
                        jj = self.judge(word[idx + 1:])
                        if jj > 0:
                            ret += 1 + jj
                            break
                cur = next
            else:
                ret = -999
                break
        # print 'ret', ret, word
        return ret



class MyTest(unittest.TestCase):
    S = None
    @classmethod
    def setUpClass(cls):
        cls.S = Solution()

    @classmethod
    def tearDownClass(cls):
        pass

    def setUp(self):
        pass

    def test_test1(self):
        ret = MyTest.S.findAllConcatenatedWordsInADict(["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"])
        expect = ["catsdogcats","dogcatsdog","ratcatdogcat"]
        self.assertEqual(ret, expect, (ret,expect))


