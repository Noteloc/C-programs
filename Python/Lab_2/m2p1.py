#!/usr/bin/env python3

#Filename: m2p1.py
#Author: Cole Sanheim
#Course: ITSC203
#Details: generates a random sequence of <length> characters in <byte> bytes, then finds a substring in the sequence and returns the offset
#Resources: https://docs.python.org/3/library/

import random
import string

flag = False
sequence = []
length = int(input("Enter length of sequence to generate (100 - 1024): "))
byte = int(input("Enter bytes (4 or 8): "))

if length < 100 or length > 1024:
    print("Length out of bounds")
    flag = True
if  byte != 4 and byte != 8:
    print("Bytes not 4 or 8")
    flag = True
if flag == True:
    exit()

for i in range(int(length/byte)): # itterates as long as the length entered
    buffer = ''.join(random.choices(string.ascii_letters + string.digits, k=byte)) # generate a random sequence of characters and numbers byte long
    if buffer not in sequence: # if this sequence doesnt already exist
        sequence.append(buffer) # add it to the list
sequence = ''.join(sequence)
print(sequence)

userInput = input("Enter string to search for: ")
offset = 0
found = 0
for i in range(len(sequence)):
    if sequence[offset:offset+len(userInput)] == userInput:
        print("Sequence found at offset ", offset)
        found+=1
    offset+=1
print(found, " occurences found")

#Question 1: because the AAAA is sandwhiched inbetween other AAAA's
#Question 2: No, because they are not readable ascii characters
#Question 3: Yes, becuase they all have individual values accociated with them