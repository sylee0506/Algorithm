def first_recurring(given_str):
    myDict = {}
    for char in given_str:
        if char in myDict:
            return char
        else:
            myDict[char] = 1
    return None

input_str = input("Input String: ")
print(first_recurring(input_str))
        
