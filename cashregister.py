"""
	Franklin Smith Cash Register Coding Challenge
	Requirements:
	Create a cash register that can keep track of money and dispense change. 
	The register should be able to handle bills of denominations 20, 10, 5, 2 and 1. 
	Given a dollar amount, the register should be able to dispense the appropriate number of bills to make that change. 
	In cases where change cannot be made using the bills in the register, you should raise an error.
	Requirements
	Must handle denominations 20, 10, 5, 2, and 1
	Must be able to represent available moneys as a string
	Must be able to add money to register
	Must be able to take money from register
	Must be able to dispense change for dollar amounts
"""
class cash_register:
	def __init__(self,ones,twos,fives,tens,twenties):
		"""
		This is a class for the cash register object
		This "cash register" is initialized with 5 
		specified input values. From left to right 
		it follows ones, twos, fives, tens, twenties which 
		represent the number of those dollar bills in the cash register
		_cash._sum is the total amount of money/cash in the drawer 
		at any time for that cash register object.
		The number of each types of bills are assigned to a variable also.
		I did this so i can keep track of the count of each type
		as well as add, subtract, and dispense change.
		the self._count and self._ bill denomination variables 
		I initialized at 0 and i used these for the make_change
		reference so I could keep track of which bills I was
		dispensing for each register object as well as
		each change transaciton.
		"""
		self._ones = ones
		self._twos = twos
		self._fives = fives
		self._tens = tens
		self._twenties = twenties
		self._cash_sum = ((1 * self._ones) + (2 * self._twos) + (5 * self._fives) + (10 * self._tens) + (20 * self._twenties))
		self._change_count = 0
		self._change_ones = 0
		self._change_twos = 0
		self._change_fives = 0
		self._change_tens = 0
		self._change_twenties = 0
	
	def show(self):
		"""
		This method when called prints the available money as a string.
		"""
		print('${} {}X20, {}X10, {}X5, {}X2, {}X1'.format(self._cash_sum, self._twenties, self._tens, self._fives, self._twos, self._ones))

	def add_money(self, add_ones, add_twos, add_fives, add_tens, add_twenties):
		"""
		This Method when called adds money to the register
		The specified 5 inputs should be integers and are 
		required to determine how many of which type
		of dollar bill you would like to add to the register.
		"""
		self._ones += add_ones
		self._twos += add_twos
		self._fives += add_fives
		self._tens += add_tens
		self._twenties += add_twenties
		self._cash_sum += ((1 * add_ones) + (2 * add_twos) + (5 * add_fives) + (10 * add_tens) + (20 * add_twenties))
		
	def take_money(self, take_ones, take_twos, take_fives, take_tens, take_twenties):
		"""
		This method when called adds money to the register
		The specified 5 inputs should be integers and are
		required to determine how many of which type
		of dollar bill you would like to subtract from the register.
		"""
		self._ones -= take_ones
		self._twos -= take_twos
		self._fives -= take_fives
		self._tens -= take_tens
		self._twenties -= take_twenties
		self._cash_sum -= ((1 * take_ones) + (2 * take_twos) + (5 * take_fives) + (10 * take_tens) + (20 * take_twenties))

	def make_change(self, change_amount):
		"""
		This method when called dispenses change for dollar amounts
		The specified input is the amount of cash given, returned 
		is the amount of cash dispensed and the representation of bill
		denominations for the register object.
		The function uses recursion
		A change count is initialized in the class, with each iteration
		of this funciton from recursion as each "dollar bill" is dispensed
		from register the sum of that amount is subtracted from the "change amount" 
		and added to the "change count". The end goal of this function is the 
		change amount to reach 0 as the change is dispensed, and the change
		count to be equivalent to the original given change_amount input which
		is the amount of cash that the change transaction was called for.
		"""
		if change_amount == 0:
			print('${} {}X20 {}X10 {}X5 {}X2 {}X1'.format(self._change_count, self._change_twenties, self._change_tens, self._change_fives, self._change_twos, self._change_ones))
			self._change_count = 0
			self._change_ones = 0
			self._change_twos = 0
			self._change_fives = 0
			self._change_tens = 0
			self._change_twenties = 0
		if change_amount > self._cash_sum:
			raise ValueError("Requested change amount larger than Register Total")
		if change_amount >= 20:
			if self._twenties >= 1:
				self._twenties -= 1
				self._change_twenties += 1
				self._change_count += 20
				change_amount -=20
				return self.make_change(change_amount)
		if 20 > change_amount and change_amount >= 10:
			if self._tens >= 1:
				self._tens -= 1
				self._change_tens += 1
				self._change_count +=10
				change_amount -= 10
				return self.make_change(change_amount)
		if 10 > change_amount and change_amount >= 5:
			if self._fives >=1:
				self._fives -= 1
				self._change_fives += 1
				self._change_count +=5
				change_amount -= 5
				return self.make_change(change_amount)
		if 5 > change_amount and change_amount >= 2:
			if self._twos >= 1:
				self._twos -= 1
				self._change_twos += 1
				self._change_count += 2
				change_amount -= 2
				return self.make_change(change_amount)
		if 2 > change_amount and change_amount >= 1:
			if self._ones >= 1:
				self._ones -= 1
				self._change_ones += 1
				self._change_count += 1
				change_amount -= 1 
				return self.make_change(change_amount)
		
def QA_tests():
	"""
	This function tests the 3 methods above as well as
	class initialization.
	"""
	k = cash_register(1,2,3,4,5)
	#initialized register with 160$
	#Starting with 1X1 2X2 3X5 4X10 5X20
	if k._cash_sum == 160:
		print("160 Dollars initialized correctly to register, total 160$")
	else:
		raise ValueError("cash register amount incorrect")
	if k._ones == 1:
		if k ._twos == 2:
			if k._fives == 3:
				if k._tens == 4:
					if k._twenties == 5:
						print("number of bills in register correct after initializing register")
						print("Available Money 1X1 2X2 3X5 4X10 5X20")
					else:
						raise ValueError("number of twenty dollar bills in register incorrect")
				else:
					raise ValueError("number of ten dollar bills in register incorrect")
			else:
				raise ValueError("number of five dollar bills in register incorrect")
		else:
			raise ValueError("number of two dollar bills in register incorrect")
	else:
		raise ValueError("number of one dollar bills in register incorrect")	
	k.show()
	print("\n")
	k.add_money(1,1,1,1,1)
	#added one of each bill to register
	#Added 1x1 1x2 1x5 1x10 1x20
	if k._cash_sum == 198:
		print("38 Dollars added correctly to register, new total 198$")
	else:
		raise ValueError("Incorrect amount added to register")
	if k._ones == 2:
		if k ._twos == 3:
			if k._fives == 4:
				if k._tens == 5:
					if k._twenties == 6:
						print("number of bills in register correct after adding to register")
						print("Available Money 2X1 3X2 4X5 5X10 6X20")
					else:
						raise ValueError("number of twenty dollar bills in register incorrect")
				else:
					raise ValueError("number of ten dollar bills in register incorrect")
			else:
				raise ValueError("number of five dollar bills in register incorrect")
		else:
			raise ValueError("number of two dollar bills in register incorrect")
	else:
		raise ValueError("number of one dollar bills in register incorrect")
	k.show()
	print("\n")
	k.take_money(1,1,1,1,0)
	#Subtracted one of each bill from register, 38$ taken out
	#Subtracted 1X1 1X2 1X5 1X10 1X20
	if k._cash_sum == 180:
		print("18 dollars subtracted correctly from register, new total 180$")
	else:
		raise ValueError("Incorrect amount subtracted from register")
	if k._ones == 1:
		if k ._twos == 2:
			if k._fives == 3:
				if k._tens == 4:
					if k._twenties == 6:
						print("number of bills in register correct after subtracting from register")
						print("Available Money 1X1 2X2 3X5 4X10 6X20")
					else:
						raise ValueError("number of twenty dollar bills in register incorrect")
				else:
					raise ValueError("number of ten dollar bills in register incorrect")
			else:
				raise ValueError("number of five dollar bills in register incorrect")
		else:
			raise ValueError("number of two dollar bills in register incorrect")
	else:
		raise ValueError("number of one dollar bills in register incorrect")
	k.show()
	print("\n")
	print("Change given for specified amount below")
	k.make_change(45)#keep in mind when altering int input for change amount
	#register initalization at the beginning of this test function needs to be greater than
	#or equal to this int input. Impossible to give change for amount greater than
	#register total. Will raise value error.
	#See line 99 & 100
	print("\n")

def QA_test2():
	"""
	this function tests the initialization of the register class,
	and the take money method.
	"""
	g = cash_register(0,0,0,0,0)
	g.show()
	print("\n")
	f = cash_register(10,4,6,4,2)
	#initialized register with 128$
	#Starting with 10X1 4X2 6X5 4X10 2X20
	if f._cash_sum == 128:
		print("128 Dollars initialized correctly to register, total 128$")
	else:
		raise ValueError("cash register amount incorrect")
	print("\n")
	f.take_money(10,0,3,4,1)
	if f._cash_sum == 43:
		print("85$ taken from register remaining amount 43$")#take from register 
	else:
		raise ValueError("Subtraction amount from register incorrect")
	f.show()
	print("\n")

QA_tests()
#QA_test2()