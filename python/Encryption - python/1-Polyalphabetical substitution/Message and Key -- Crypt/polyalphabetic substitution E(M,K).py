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


## Convery strings into values in array-----------#
# array to hold letter value
Message_value = []
Key_value = []
for x in Message_table:
    # replacing letter of message by correct values
    Message_value.append(table_of_alphabets.index(x))
for x in Key_table:
    Key_value.append(table_of_alphabets.index(x))
#-------------------------------------------------#

 
## compute the two arrays that hold values--------#  
total_value = numpy.add(Message_value,Key_value)
# make all values smaller the the lenght of alphabets
for x in range(0, len(total_value), 1):
    total_value[x] = total_value[x] % len(table_of_alphabets)
#-------------------------------------------------#

# reconverting the total_value into string--------#
Crypted_message = []
for x in total_value:
    Crypted_message.append(table_of_alphabets[x])
#-------------------------------------------------#

# display results --------------------------------#  
print("Message  : " + Message)
print("Key      : " + Key)
print("Crypted  : " + listToString(Crypted_message))





