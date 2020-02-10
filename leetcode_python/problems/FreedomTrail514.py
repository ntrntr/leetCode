import unittest
import math

class Solution1(object):
    getKeyStepCache = {}
    dfsCache = {}
    def findRotateSteps(self, ring, key):
        """
        :type ring: str
        :type key: str
        :rtype: int
        """
        import sys
        ret = [sys.maxint]
        charMap = {}
        for index, data in enumerate(ring):
            if charMap.get(data, None) is not None:
                charMap[data].append(index)
            else:
                charMap[data] = [index]
        self.getKeyStepCache = {}
        self.dfsCache = {}
        self.dfs(charMap, key, 0, 0,len(ring), 0,ret)
        return ret[0]

    def getKeyStep(self, char, mapChar, currentIndex, ringlen):
        if self.getKeyStepCache.get((char, currentIndex, ringlen, ), None) is not None:
            # print "get from cache", (char, currentIndex, ringlen, )
            return self.getKeyStepCache[(char, currentIndex, ringlen, )]
        indexs = mapChar[char]
        # return next index, step
        ret = []
        def getStep(current_index, target_index, ringlen):
            if target_index >= current_index:
                ret = min(target_index - current_index, current_index + ringlen - target_index)
            else:
                ret = min(current_index - target_index, target_index + ringlen - current_index)
            return ret

        for index in indexs:
            ret.append((index, getStep(currentIndex, index, ringlen),))
        ret.sort(key=lambda x: x[1])
        self.getKeyStepCache[(char, currentIndex, ringlen,)] = ret
        return ret


    def dfs(self, charMap, key, keyIndex, ringIndex, ringlen, current_step, return_value):
        if keyIndex >= len(key):
            if return_value[0] >= current_step:
                # print 'update chache', current_step
                return_value[0] = current_step
            return
        if current_step + self.dfsCache.get((keyIndex, ringIndex), len(key) - keyIndex) > return_value[0]:
            return
        steps = self.getKeyStep(key[keyIndex], charMap, ringIndex, ringlen)
        for next_ring_index, step in steps:
            self.dfs(charMap, key, keyIndex + 1, next_ring_index, ringlen, current_step + step + 1, return_value)
            tmp_key = (keyIndex+1, next_ring_index, )
            if self.dfsCache.get(tmp_key, None) is not None:
                self.dfsCache[tmp_key] = min(self.dfsCache[tmp_key], return_value[0] - (current_step + step + 1))
            else:
                self.dfsCache[tmp_key] = return_value[0] - (current_step + step + 1)


class Solution(object):
    def findRotateSteps(self, ring, key):
        """
        :type ring: str
        :type key: str
        :rtype: int
        """
        charMap = {}
        for index, data in enumerate(ring):
            if charMap.get(data, None) is not None:
                charMap[data].append(index)
            else:
                charMap[data] = [index]
        ringLen = len(ring)
        keyLen = len(key)
        prev_state = [0] * ringLen
        import sys


        def getStep(j, match_ring_index, ringLen):
            if match_ring_index >= j:
                ret = min(match_ring_index - j, j + ringLen - match_ring_index)
            else:
                ret = min(j - match_ring_index, match_ring_index + ringLen - j)
            return ret

        for i in range(keyLen-1, -1, -1):
            # reset
            current_state = [sys.maxint] * ringLen
            # find current key match the ring char
            current_ring_char = key[i]
            for match_ring_index in charMap.get(current_ring_char):
                # update current state
                current_state[match_ring_index] = prev_state[match_ring_index] + 1
                # we no the key char current count, we can calc from other char to current char step count
                for j in range(ringLen):
                    if j == match_ring_index:
                        continue
                    current_state[j] = min(current_state[j], current_state[match_ring_index] + (min(j - match_ring_index, match_ring_index + ringLen - j) if j >= match_ring_index else min(match_ring_index - j, j + ringLen - match_ring_index)))
            prev_state = current_state

        return prev_state[0]




class MyTestCase(unittest.TestCase):

    def setUp(self):
        self.solution = Solution()

    def test_something1(self):
        self.assertEqual(4, self.solution.findRotateSteps("godding", 'gd'))
        self.assertEqual(137, self.solution.findRotateSteps("caotmcaataijjxi", 'oatjiioicitatajtijciocjcaaxaaatmctxamacaamjjx'))



    def test_something2(self):
        pass

    def test_something3(self):
        self.assertEqual(True, True)

    def tearDown(self):
        self.solution = None

if __name__ == '__main__':
    unittest.main()