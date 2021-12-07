#!/usr/bin/env python3

#Filename: m2p2.py
#Author: Cole Sanheim
#Course: ITSC203
#Details: This program takes a command line argument of a directory path then goes to that directory and produces information about the files in that folder
#Resources: https://docs.python.org/3/library/


import sys
import os
import datetime
from datetime import datetime # dont know why but datetime.fromtimestamp.strftime needs this
import pathlib
from pathlib import Path

print("In directory:  ", sys.argv[1])
p = Path(sys.argv[1]) # p is a list containing the absolute paths of files in the directory entered

for i in p.iterdir():
   info = os.stat(i) # a list containing the info collected from os.stat
   print("Name: ", os.path.basename(i), "| Absolute Path: ", i, "| Time Last Modified: ", datetime.fromtimestamp(int(os.path.getmtime(i))).strftime("%A, %B %d, %Y %I:%M:%S"), "| Size: ", os.path.getsize(i), "| Inode: ", info[1])
#        os.path.basename returns the name,                                            datetime.fromtimestamp.strftime returns the time in a readable format from os.path.getmtime         this gets size                   from the tuple os.stat                                     
#                                                                                                                              These characters format the print of the time