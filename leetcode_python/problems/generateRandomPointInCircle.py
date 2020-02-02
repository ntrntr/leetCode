# -*- coding: utf-8 -*-
import math
import random
def generateRandomPoint(r):
    while True:
        x = random.uniform(-r, r)
        y = random.uniform(-r, r)
        if x * x + y * y <= r * r:
            return x,y

def generateRandomPoint3(r):
    x = random.uniform(-r, r)
    square = math.sqrt(r*r-x*x)
    y = random.uniform(-square, square)
    return x,y


def generateRandomPoint1(r):
    random_r = random.uniform(0, r)
    random_theta = random.uniform(0, 2 * math.pi)
    return random_r * math.cos(random_theta), random_r * math.sin(random_theta)


def generateRandomPoint2(r):
    random_r = math.sqrt(random.uniform(0, r))
    random_theta = random.uniform(0, 2 * math.pi)
    return random_r * math.cos(random_theta), random_r * math.sin(random_theta)


def generateRandomPointFromAnnulus(r1,r2):
    """
    在圆环内随机取点, r1<=r2
    :param r1: 内径
    :param r2: 外径
    :return:
    """
    assert r1<= r2
    while True:
        x = random.uniform(-r2, r2)
        y = random.uniform(-r2, r2)
        if x * x + y * y <= r2 * r2 and x * x + y * y >= r1 * r1:
            return x,y
import math
def generateRandomPointFromAnnulus1(r1,r2):
    """
    在圆环内随机取点, r1<=r2
    :param r1: 内径
    :param r2: 外径
    :return:
    """
    assert r1<= r2
    x = random.uniform(r1, r2)
    y = random.uniform(math.sqrt(x*x-r1*r1), math.sqrt(r2*r2-x*x))
    return x if random.uniform(-1,1) > 0 else -x, y if random.uniform(-1,1) > 0 else -y


import math
def generateRandomPointFromAnnulus2(r1,r2):
    """
    在圆环内随机取点, r1<=r2
    :param r1: 内径
    :param r2: 外径
    :return:
    """
    assert r1<= r2
    a = 1 / (r2*r2-r1*r1)
    random_r = math.sqrt(random.uniform(0,1) + r1 * r1)
    random_theta = random.uniform(0, 2 * math.pi)
    return random_r * math.cos(random_theta), random_r * math.sin(random_theta)


if __name__ == '__main__':
    minx = 10
    maxx = -10
    miny = 10
    maxy = -10
    avx = 0
    avy = 0
    lens = 200
    for i in xrange(lens):
        x,y = generateRandomPointFromAnnulus1(1, 2)
        avx += x
        avy += y
        minx = min(minx, x)
        maxx = max(maxx, x)
        miny = min(miny, y)
        maxy = max(maxy, y)
        print x,y
    print 'minx:%s, maxx:%s, miny:%s, maxy:%s, avx:%s, avy:%s' % (minx, maxx, miny, maxy, avx / lens, avy / lens)