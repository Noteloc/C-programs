#!/usr/bin/env python3

textfile = open("profile.txt")
profiles = textfile.read().split()

for profile in profiles:
    print(profile.split('_')[1].split(':')[0], profile.split('_')[0], "->", profile.split(':')[1])

textfile.close()

def outMeminfo(name):
    textfile = open(name)
    info = textfile.read().split('\n')
    
    for i in info:
        if i.split()[0] == 'MemTotal:':
            buffer = int((int(i.split()[1]) / 1024) / 1024)
            print("Total Memory:", i.split()[1], '(' + str(buffer), "GB)")

    for i in info:
        if i.split()[0] == 'MemFree:':
            buffer = int(int(i.split()[1]) / 1024)
            print("Free Memory:", i.split()[1], '(' + str(buffer), "MB)")

    for i in info:
        if i.split()[0] == 'MemAvailable:':
            buffer = int(int(i.split()[1]) / 1024)
            print("Available Memory:", i.split()[1], '(' + str(buffer), "MB)")

    for i in info:
        if i.split()[0] == 'MemActive:':
            buffer = int((int(i.split()[1]) / 1024) / 1024)
            print("Active Memory:", i.split()[1], '(' + str(buffer), "GB)")

    for i in info:
        if i.split()[0] == 'CacheFree:':
            buffer = int((int(i.split()[1]) / 1024) / 1024)
            print("Free Cache:", i.split()[1], '(' + str(buffer), "GB)")
    

def main():
    name = input("Enter Name of File: ")
    outMeminfo(name)

if __name__ == '__main__':
    main()