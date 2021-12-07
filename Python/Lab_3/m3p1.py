#!/usr/bin/env python3

#Filename: m3p1.py
#Author: Cole Sanheim
#Course: ITSC203
#Details: Reads the directories of subdirectories of a directory tree and displays the tree, and then copies the files over into new directories
#Resources: https://docs.python.org/3/library/

import os
from pathlib import Path
import hashlib

def copi(hashname, path, ext, filename): # A function that will copy a file into a new directory based on its extention
    root = "/home/cole/Desktop/Semester_Two/Lab_3/" # define root as the folder we are operating in
    if not Path(root+ext).is_dir():                 # if the new directory doesnt alreay exist
        os.mkdir(root+ext)                          # create the new directory
    os.system("cp %s %s/%s.%s" % (str(path)+'/'+filename, root+ext, hashname, ext))
    # use the os.system function to use the cp linux command to copy the old file into the new location and rename it using the hash generated

def hashs(pathname): # A function that creates a hash based on the name of the file
    h = str(pathname)           # convert the posixpath into a string
    h = h.encode()              # use the encode function to create the hash
    shaHash = hashlib.sha512(h) # actually create the hash using sha512
    return(shaHash.hexdigest()) # return the hash in a hex format
            
def listdirec(pathname, tabs):      # A function that will list out the directory tree, pathname is the path of the root directory and tabs is used for formatting
    path = Path(pathname)           # convert the pathname to a posixpath type
    for i in path.iterdir():        # itterate through each file/directory in the root
        if os.path.isdir(i):        # if its a directory
            x = 0                   
            while x < tabs:         # simple while loop will print out the amount of tabs specified    
                print('\t', end = '')
                x+=1
            print(os.path.basename(i)) # print out the name of the subdirectory
            listdirec(i, tabs+1)    # Then go into that subdirectory and repeat the process
        elif os.path.isfile(i):     # if its a file
            copi(hashs(i), path, os.path.basename(i).split('.')[1], os.path.basename(i)) # copy the file
            x = 0                   
            while x < tabs:         # same loop as above
                print('\t', end = '')
                x+=1
            print(os.path.basename(i), hashs(i)) # print out the name of the file and the hash

def main():
    pathname = "/home/cole/Desktop/Semester_Two/Lab_3/folder056" # the root folder we are starting in
    listdirec(pathname, 0) # call the listdirec function and give it the root folder and the amount of tabs we need (right now 0)

if __name__ == "__main__":
    main()

# Questions:
# ===================================================================================================================================================
# 1. its creats a unique name that cannot be recreated? (honestly im not too sure why we are creating a hash based on the name and renaming the file)
# 2. NTLM, LANMAN
#       a. I used sha512 because there is a larger pool of potential hashes
# 3. No, because people can disguise a file as a different file type pretty easily
# 4. You can use a checksum file
# 5. So you can analyze the copies without putting the system that the orginal infected at risk
# ===================================================================================================================================================