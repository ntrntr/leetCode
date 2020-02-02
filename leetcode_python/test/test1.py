class TestObj(object):
	pass

class Child(object):
	properties = {}
	move_duration = TestObj()
	test = move_duration

	def __init__(self):
		super(Child, self).__init__()
		self.bb = self.move_duration
		print 'set bb:%s'%self.bb


if __name__ == "__main__":
	myTest = Child()
	print "move_duration", id(myTest.move_duration)
	print "test", id(myTest.test)
	print "test bb", id(myTest.bb)
	print "after set move_duration to 999"
	setattr(myTest, 'move_duration', 999)
	print "move_duration", id(myTest.move_duration)
	print "test", id(myTest.test)
	print "test bb", id(myTest.bb)
	pass