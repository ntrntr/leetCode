def consumer():
    r = 'consumer start now!!!'
    while True:
        i = yield r
        print 'consuming task %s' % i
        r = '%s Done' % i


def producer(c):
    start_up = c.next()
    print 'start_up is %s' % start_up
    n = 5
    i = 0
    while i < n:
        i += 1
        print 'producing task is %s' % i
        res = c.send(i)
        print 'consumer done ,res: %s' % res

    c.close()


c = consumer()
producer(c)