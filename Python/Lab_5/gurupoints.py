#!/usr/bin/env python3
from ctypes import *

val1 = c_int
val4 = c_char_p

libc = cdll.LoadLibrary('libc.so.6')

printf = libc.printf
scanf = libc.scanf

printf.argtypes = [c_char_p]
scanf.argtypes = [c_int, c_char_p]

printf(b"Please enter a number and string: ")
scanf(" %d %s", val1, val4)

printf.argtypes = [c_char_p, c_int, c_char_p]
printf(b"%d %s\n", val1, val4)