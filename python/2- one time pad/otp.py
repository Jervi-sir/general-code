'''
    PolyAlphabetic Substituation Encryption
    What it does: 
        1. get Message and key as input
        2. turn both key and Message into array
        3. check if key has same lenght as Message
            .if not , it gonna repeat the key till it reaches the same lenght as Message
        4. turn both Key and Message (array) into value with help of alphabets table
        5. compute message and key (array of values) for a return of a sum stored in array
            .note each value is smaller then the total number of alphabet 
        6. turn the sum array resulted into alphabetical each number means a letter
        7. turn the result array into string 
        8. display result
    
    
    date    : 19 sept 2020
    Author  : Gacem

'''
import string   #to get alphabets
import numpy as numpy

#####Fonctions######################### 
# convert string to list character-wise 
def Convert(string): 
    list1=[] 
    list1[:0]=string 
    return list1
    
# array to string     
def listToString(s):  
    str1 = ""  
    # traverse in the string   
    for ele in s:  
        str1 += ele   
    return str1  

# XOR of the two Binary Strings 
def xor(a, b, n): 
    ans = "" 
    # Binary Strings 
    for i in range(n): 
        # If the Character matches 
        if (a[i] == b[i]):  
            ans += "0"
        else:  
            ans += "1"
    return ans  
    
####################################### 



# initialise an array of alphabets 
table_of_alphabets = Convert(string.ascii_lowercase)

# Get from user ---------------------------------
print("PolyAlphabetical Substitution Encryption\n")
Message = input("enter your message to encrypt: ")
Key = input("enter your Encryption Key: ")
#-------------------------------------------------#

# message and key into array----------------------#
Message_table = Convert(Message)
Key_table = Convert(Key)
#-------------------------------------------------#

# make key same lenght as Message-----------------#
Message_lenght = len(Message)
Key_lenght = len(Key)

if Message_lenght != Key_lenght:
    Key_temp = []
    for x in range(0, Message_lenght, 1):
        Key_temp.append(Key_table[x % Key_lenght])
    Key_table = Key_temp
#-------------------------------------------------#


## Convert strings into values in array-----------#
# array to hold letter value
Message_value = []
Key_value = []
for x in Message_table:
    # replacing letter of message by correct values
    Message_value.append(table_of_alphabets.index(x))
for x in Key_table:
    Key_value.append(table_of_alphabets.index(x))
#-------------------------------------------------

## Convert int array into binary values array----#
# array to hold binay values
Message_binary = []
Key_binary = []
for x in Message_value:
    #replacing int of message by binary
    Message_binary.append("{0:05b}".format(x))
for x in Key_value:
    Key_binary.append("{0:05b}".format(x))
#-------------------------------------------------

## Xor the values of two arrays-----------------#  

total_value_binary_xor = []

for x in range(0, len(Message_binary), 1):
    total_value_binary_xor.append( xor(Message_binary[x], Key_binary[x], 5))

#-------------------------------------------------#

#reconverting the total_value into string--------#
Crypted_message = []
for x in total_value_binary_xor:
    Crypted_message.append(table_of_alphabets[int(x, 2)])
    
#-------------------------------------------------#

# display results --------------------------------#  
print("Message  : " + Message)
print("Key      : " + Key)
print("Crypted-Binay  : " + listToString(total_value_binary_xor))
print("Crypted-String : " + listToString(Crypted_message))





