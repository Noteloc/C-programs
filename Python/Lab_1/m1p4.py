#!/usr/bin/env python3
#Filename: m1p4.py
#Course: ITSC203
#Details: This program prints a table of user information
#Resources: The python help pages

table = [['kenny rogers', '/home/users/KRogers'],['tony robbins', '/home/TRobbins'],['johnny cash', '/home/users/JCash'],['tito jackson', '/home/hut/TJackson'],['tim tzuyu', '/home/users/TTzuyu'], ['kareena kapoor', '/home/users2/KKapoor']]

nameLength = 0
locationLength = 0
buffer = 0
for i in table:
    if len(i[0]) > nameLength:
        nameLength = len(i[0])
    if len(i[1]) > locationLength:
        locationLength = len(i[1])
        
print("+", end = '')
buffer = nameLength+3
while buffer > 0:
    print("-", end = '')
    buffer-=1
print("+", end = '')
buffer = locationLength+3
while buffer > 0:
    print("-", end = '')
    buffer-=1
print("+")    
for i in table:
    print("|", i[0].title(), end = '')
    buffer = len(i[0])
    while buffer < (nameLength+2):
        print(" ", end = '')
        buffer+=1
    print("|", i[1], end = '')
    buffer = len(i[1])
    while buffer < (locationLength+2):
        print(" ", end = '')
        buffer+=1
    print("|")
print("+", end = '')
buffer = nameLength+3
while buffer > 0:
    print("-", end = '')
    buffer-=1
print("+", end = '')
buffer = locationLength+3
while buffer > 0:
    print("-", end = '')
    buffer-=1
print("+")   