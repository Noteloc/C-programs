from ctypes import *

def message(str1):
	lent = len(str1)
	print('#'*(lent+4))
	print('# '+str1+' #')
	print('#'*(lent+4))

libfunc = CDLL('/home/cole/Desktop/Semester_Two/Group_Lab/libfunc.so')
ret = libfunc.divide(100, 8)
print('Returned value: ', ret)
libfunc.divide.restype = c_float
ret = libfunc.divide(100, 8)
print('Returned value: ', ret)
ret = libfunc.divide(100, 7)
print('Returned value: ', ret)

libfunc.multiply.argtypes = [c_int, c_float, c_int]
libfunc.multiply(10, 20, 30)

try:
	libfunc.multiply(10, 'aaa', 30)
except ArgumentError as e:
	print('There was an error', e)
libfunc.multiply.argtypes = [c_int, c_int, c_int]
libfunc.multiply(10, 20, 30)
libfunc.multiply.restype = None
libfunc.multiply(10, 20, 30)
mystr2 = "WHY aren't the lines below this getting evaluated??? HOW can the code be fixed to resolve this?????"
message(mystr2)
libfunc.divide.argtypes = [c_float, c_int]
libfunc.divide(33.4, 5)
libfunc.divide.argtypes = [c_int, c_int]
libfunc.divide(20, 3)
