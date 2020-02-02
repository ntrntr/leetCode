import traceback

class NodePorperty(object):

	def __init__(self, name, ptype, title, desc, default=0):
		self.name = name
		if type(ptype) is type:
			self.type = ptype
		elif type(ptype) is tuple:
			self.type, self.subtype = ptype
		else:
			raise TypeError, 'Invalid %s type: %s'% (self.__class__.__name__, type)
		self.title = title
		self.description = desc
		self.default = self.type(default)

	def __get__(self, instance, cls=None):
		print "getName,:%s, \nstack:%s\n"%(self.name, traceback.extract_stack())
		return instance.properties.get( self.name, self.default )

	def __set__(self, instance, value):
		print "set:%s to %s \n %s\n"%(self.name, value,traceback.extract_stack())
		instance.properties[self.name] = self.type(value)

	def __delete__(self, instance):
		del instance.properties[self.name]

class Child(object):
	properties = {}
	move_duration = NodePorperty('move_duration', float, 'move_duration', 'abc', 0.2)
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