#!/usr/bin/env python3

#Filename: m3p2.py
#Author: Cole Sanheim
#Course: ITSC203
#Details: This program trys to crack the passwords in strange
#Resources: https://docs.python.org/3/library/

import pexpect
import random
import string

def brute():
    foo = ''.join(random.choices(string.ascii_letters + string.digits, k=random.randint(1,10))) # generate a random sequeance of chars and numbers 1-10 digits long
    foo = list(foo)   # convert the string to list so we can edit its individual characters
    for i in range(len(foo)):
        foo[i] = chr((ord(foo[i]) ^ 0x22) * (len(foo) - i)) # run each character through the algorithm provided
    return ''.join(foo)  # return the new string

def main():
    jtrys = []      # list to hold the trys for jtrudeau
    rtrys = []      # list to hold the trys for rbinsburg
    btrys = []      # list to hold the trys for bobama
    successes = []  # list to hold the success prompts
    fails = ["\n\tDon't feel bad", "\n\tMission scrubbed!!!", "\n\tCongratulations, you get to try again!!!", "\n\tYou got in to the wrong part of the program", "\n\tPlease try again"]
    while True:
        buffer = ''
        child = pexpect.spawn("/bin/bash")  # generate a bash child
        child.sendline("./strange")         # start the program to crack the passwords in
        child.expect('\r')                  # get the return prompt
        child.sendline('')                  # send a blank space to the program, I do this to get proper returns dont really know why it works
        child.expect('\r')                  # get cthe return prompt 

        trys = child.before.decode()        # get the line for which user we are cracking
        
        if trys == "Please enter  jtrudeau's password: ":
            while buffer in jtrys:          # generate another random sequence if the sequence that was tried has already been tried
                buffer = brute()          
            jtrys.append(buffer)            # add the new sequence to the trys
            child.sendline(buffer)          # send the try to the program
            child.expect('\r')              
            test = child.before.decode()    # get the response
            if test not in fails:           # if the response is not a fail prompt
                if buffer not in successes: # AND if it hasnt already succeded
                    successes.append(buffer)# add it to the list of success prompts
                print(test)                 # print out the successful password

        elif trys == "Please enter rbginsburg's password: ":
            while buffer in rtrys:
                buffer = brute()
            rtrys.append(buffer)
            child.sendline(buffer)
            child.expect('\r')
            test = child.before.decode()
            if test not in fails:
                if buffer not in successes:
                    successes.append(buffer)
                print(test)

        elif trys == "Please enter bobama's password: ":
            while buffer in rtrys:
                buffer = brute()
            btrys.append(buffer)
            child.sendline(buffer)
            child.expect('\r')
            test = child.before.decode()
            if test not in fails:
                if buffer not in successes:
                    successes.append(buffer)
                print(test)
        
        if len(successes) == 5:
            print("All passwords found!")
            print("Success prompts: ", successes)
            break
    print(successes)
if __name__ == "__main__":
    main()