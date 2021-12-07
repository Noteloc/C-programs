#!/usr/bin/env python3

#Filename: m2p4.py
#Author: Cole Sanheim
#Course: ITSC203
#Details: This program will take input of a subnet and will generate information based on that, it is hardcoded only to accpet a subnet of /26
#Resources: https://docs.python.org/3/library/

userInput = input("Enter subnet: ")
subnet = userInput.split('/')[1]
network = userInput.split('/')[0]
start = list(userInput.split('/')[0])
start = "".join(start[:-4])
tail = int(userInput.split('.')[3].split('/')[0])

print("Subnet Network Addres: ", network)
print("Subnet First Address: ", start + "." + str(int(tail)+1))
if(int(tail) >= 192):
    last = 254
    broadcast = 255
elif(int(tail) >= 128):
    last = 190
    broadcast = 191
elif(int(tail) >= 64):
    last = 126
    broadcast = 127
elif(int(tail) >= 0):
    last = 62
    broadcast = 63
print("Subnet Last Address: ", start + "." + str(last))
print("Subnet Broadcast Address: ", start + "." + str(broadcast))
print("Range of IP Address to be scanned: ", end = '')
for i in range(last - int(tail)+1):
    print(start + "." + str(int(tail)+i) + ", ", end = '')
print()