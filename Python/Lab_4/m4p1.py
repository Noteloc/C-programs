#!/usr/bin/env python3

#Filename: m4p1.py
#Author: Cole Sanheim
#Course: ITSC203
#Details: A program that creates a class that takes the PID of the process running and returns values accociated with it
#Resources: https://docs.python.org/3/library/

import os

buffer = '' # used to allow the get function to work properly

class LinuxProcess():
    def __init__(self, pid):
        self.pid = pid
        self.stat = "/proc/" + str(pid) + "/stat"
        file = open(self.stat, "r")                 # Here I am opening the file provided by the PID, then reading that file and setting each value accordingly
        buffer = file.read()
        self.name = str(buffer.split(" ")[1])
        self.ppid = buffer.split(" ")[3]
        self.rss = hex(int(buffer.split(" ")[23]))
        self.rsslim = hex(int(buffer.split(" ")[24]))
        self.start_code = hex(int(buffer.split(" ")[25]))
        self.end_code = hex(int(buffer.split(" ")[26]))
        self.start_stack = hex(int(buffer.split(" ")[27]))
        self.start_data = hex(int(buffer.split(" ")[44]))
        self.end_data = hex(int(buffer.split(" ")[45]))
        self.start_brk = hex(int(buffer.split(" ")[46]))
        self.arg_start = hex(int(buffer.split(" ")[47]))
        self.arg_end = hex(int(buffer.split(" ")[48]))
        self.env_start = hex(int(buffer.split(" ")[49]))
        self.env_end = hex(int(buffer.split(" ")[50]))

    def get(self, title): # using exec (and some weirdness) to dynamically return the value of a variable with only being passed the name of the variable
        command = "global buffer\nbuffer = buffer + str(self." + title + ")"
        exec(command)
        return buffer

    def set(self, title, arg): # using exec to change the value of self.title to be arg
        command = "self." + title + " = '" + arg + "'"
        exec(command) 

    def printData(self):    # printing out each variable of the class
        print("name:\t\t", self.name)
        print("pid:\t\t", self.pid)
        print("ppid:\t\t", self.ppid)
        print("rss:\t\t", self.rss)
        print("rsslim:\t\t", self.rsslim)
        print("start_code:\t", self.start_code)
        print("end_code:\t", self.end_code)
        print("start_stack:\t", self.start_stack)
        print("start_data:\t", self.start_data)
        print("end_data:\t", self.end_data)
        print("start_brk:\t", self.start_brk)
        print("arg_start:\t", self.arg_start)
        print("arg_end:\t", self.arg_end)
        print("env_start:\t", self.env_start)
        print("env_end:\t", self.env_end)


def main():
    x = LinuxProcess(os.getpid())
    x.printData()
    print("input a name of a variable to wish to change: ")
    name = input()
    print("input the value you wish to change it to: ")
    arg = input()
    x.set(name, arg)
    print("input name of variable you wish to see: ")
    name = input()
    print(x.get(name))

if __name__ == '__main__':
    main()