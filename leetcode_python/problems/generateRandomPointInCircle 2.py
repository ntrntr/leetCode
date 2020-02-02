import random
def generateRandomPoint(r):
    while True:
        x = random.uniform(-r, r)
        y = random.uniform(-r, r)
        if x * x + y * y <= r * r:
            return x,y
import math
def generateRandomPoint1(r):
    random_r = random.uniform(0, r)
    random_theta = random.uniform(0, 2 * math.pi)
    return random_r * math.cos(random_theta), random_r * math.sin(random_theta)

import math
def generateRandomPoint2(r):
    random_r = math.sqrt(random.uniform(0, r))
    random_theta = random.uniform(0, 2 * math.pi)
    return random_r * math.cos(random_theta), random_r * math.sin(random_theta)

if __name__ == '__main__':
    minx = 10
    maxx = -10
    miny = 10
    maxy = -10
    avx = 0
    avy = 0
    lens = 100
    for i in xrange(lens):
        x,y = generateRandomPoint2(1)
        avx += x
        avy += y
        minx = min(minx, x)
        maxx = max(maxx, x)
        miny = min(miny, y)
        maxy = max(maxy, y)
        print x,y
    print 'minx:%s, maxx:%s, miny:%s, maxy:%s, avx:%s, avy:%s' % (minx, maxx, miny, maxy, avx / lens, avy / lens)