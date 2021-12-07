#!/usr/bin/env python3

class Proc(object):
      def __init__(self, pid, name, state, msg):
            self.pid = pid
            self.name = name
            self.state = state
            self.msg = msg

      def getPID(self):
            return self.pid
      def getMSG(self):
            return self.msg
      def getState(self):
            return self.state
      def setState(self, input):
            if input == "Running" or input == "Sleep":
                  self.state = input
            else:
                  print("Invalid state entered, please enter either 'Sleep' or 'Running'")
      def getName(self):
            return self.name


pid = int(input("Enter a PID: "))

newObj = Proc(pid, "Proc1", "Running", "Welcome to Proc1")

pid = newObj.getPID( )

msg = newObj.getMSG( )

state = newObj.getState( )

newObj.setState("Sleep")

nom = newObj.getName( )








class Test:
    def __init__(self, name, val1, val2):
        self.val1 = val1
        self.val2 = val2
        self.name = name
    def message(self, msg): 
        print(msg + ", did you know, this is an object called: " + self.name)
        print(self.name, "has values " + str(self.val1), "and " + str(self.val2))
        return(0)

    def func2(self, a, b):
        return(int(a/(b*10)))

obj1 = Test("obj1", 34, 23)                                  # Do not modify this line
obj1.message("Preach")                                       # Do not modify this line
print("This is an easy: ",obj1.func2(200, 2), "pts")         # Do not modify this line







class myBlueprint():
      def __init__(self, str, val1, val2):
            self.str = str
            self.val1 = val1
            self.val2 = val2
      
      def printAttribute(self, name):
            command = 'self.' + name
            print(eval(command))

newObj1 = myBlueprint( "string", 10, 20)
newObj2 = myBlueprint( "string", 30, 40)

newObj1.var1 = 6
newObj2.var2 = 7
newObj1.var2 = 17

newObj1.str1 = "Pay Attention"
newObj2.str1 = "Slow Down"

sum1 = newObj1.var1 + newObj2.var2
strnew = newObj1.str1 + " " + newObj2.str1

print(f"{newObj1.var1} + {newObj2.var2} = {sum1}")
print(f"newObj1's + newObj2's string: {strnew}")
newObj1.printAttribute( "var1")
newObj2.printAttribute( "var2")