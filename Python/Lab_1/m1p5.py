#!/usr/bin/env python3
#I changed the shebang so it works

int_var1 = [1,2,3,4]
str_var1 = "This is a string" 
flt_var1 = 123.445 #deleted the '' around the number here to chang it from a string to a float
tup_var1 = tuple(int_var1)

sumflt = flt_var1 + int_var1[0]
sumflt = sumflt + int_var1[1]
sumflt = sumflt + int_var1[2]
sumflt = sumflt + int_var1[3]
#I changed the above lines so it acually was accessing the indexes of the the list

#I deleted a line here as it was editing a tuple and a tuple is non mutable

print("sumflt is: ", sumflt)
print("flt_var1" + " ", flt_var1) #changed it so it says its printing out flt_var1
print("flt_var1 * 4 ", flt_var1 * 4) #changed it so it says its printing out flt_var1
print("str_var1 + 4 " + str_var1, 4)
#I altered the above print statments, as it did not allow to concatenate a float onto a string, so I changed some '+' to ',' to make them work