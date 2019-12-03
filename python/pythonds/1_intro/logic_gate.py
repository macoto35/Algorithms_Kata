class LogicGate:
	def __init__(self, n):
		self.label = n
		self.output = None
	
	def getLabel(self):
		return self.label
	
	def getOutput(self):
		self.output = self.performGateLogic()
		return self.output

class BinaryGate(LogicGate):
	def __init__(self, n):
		super().__init__(n)		
		self.pinA = None
		self.pinB = None
	
	def getPinA(self):
		if self.pinA is None:
			return int(input('Enter Pin A input for gate ' + self.getLabel() + '--->'))
		else:
			return self.pinA.getFrom().getOutput()
	
	def getPinB(self):
		if self.pinB is None:
			return int(input('Enter Pin B input for gate ' + self.getLabel() + '--->'))
		else:
			return self.pinB.getFrom().getOutput()
	
	def setNextPin(self, source):
		if self.pinA is None:
			self.pinA = source
			print('Set pinA: ' + source.getTitle())
		elif self.pinB is None:
			self.pinB = source
			print('Set pinB: ' + source.getTitle())
		else:
			raise RuntimeError('Error: No Empty Pins!')

class UnariGate(LogicGate):
	def __init__(self, n):
		super().__init__(n)
		self.pin = None
	
	def getPin(self):
		if self.pin is None:
			return int(input('Enter Pin input for gate ' + self.getLabel() + '--->'))
		else:
			return self.pin.getFrom().getOutput()
	
	def setNextPin(self, source):
		if self.pin is None:
			self.pin = source
		else:
			raise RuntimeError('Error: No Empty Pin!')

class AndGate(BinaryGate):
	def __init__(self, n):
		super().__init__(n)
	
	def performGateLogic(self):
		a = self.getPinA()
		b = self.getPinB()
		
		return 1 if a == 1 and b == 1 else 0

class NandGate(AndGate):
	def performGateLogic(self):
		return 0 if super().performGateLogic() == 1 else 1

class OrGate(BinaryGate):
	def __init__(self, n):
		super().__init__(n)
	
	def performGateLogic(self):
		a = self.getPinA()
		b = self.getPinB()
		
		return 0 if a == 0 and b == 0 else 1

class NorGate(OrGate):
	def performGateLogic(self):
		return 0 if super().performGateLogic() == 1 else 1

class NotGate(UnariGate):
	def __init__(self, n):
		super().__init__(n)
	
	def performGateLogic(self):
		pin = self.getPin()
		return 1 if pin == 0 else 0

class Connector:
	def __init__(self, fgate, tgate, title):
		self.fromgate = fgate
		self.togate = tgate
		self.title = title
		
		tgate.setNextPin(self)
	
	def getTitle(self):
		return self.title
	
	def getFrom(self):
		return self.fromgate
	
	def getTo(self):
		return self.togate

'''g1 = AndGate('G1')
print(g1.getOutput())
g2 = OrGate('G2')
print(g2.getOutput())
g3 = NotGate('G3')
print(g3.getOutput())
g4 = NandGate("G4")
print(g4.getOutput())
g5 = NorGate("G5")
print(g5.getOutput())
'''

#G4:not ((G1:A and B) G3:or (G2:C and D))
g1 = AndGate("G1")
g2 = AndGate("G2")
g3 = OrGate("G3")
g4 = NotGate("G4")
c1 = Connector(g1,g3, "C1")
c2 = Connector(g2,g3, "C2")
c3 = Connector(g3,g4, "C3")
print(g4.getOutput())

# (G5:A Nand B) G7:and (G6:C Nand D)
g5 = NandGate("G5")
g6 = NandGate("G6")
g7 = AndGate("G7")
c4 = Connector(g5, g7, "C4")
c5 = Connector(g6, g7, "C5")
print(g7.getOutput())



