# First get the number of test cases, T
T = int(input("Enter number of test cases >>> "))

# Check T is in the interval 1<= T <= 100
while T < 1 or T > 100:
    print("\nThe value of T must be in the range [1, 100]\n")
    T = int(input("Re-enter number of test cases >>> "))
    
# List of valid characters
valid_set = ['C', 'J', '?']

# Function to check for validity
def validity(char: str):
    valid = True
    char_split = list(char)
    for i in char_split:
        if i in valid_set:
            continue
        else:
            valid = False
            
    return valid

# Function to check for length of S on input
def valid_length(char: str, val1: int, val2: int):
    valid = True
    if len(char) < 1 or len(char) > 1000:
        valid = False
        
    if val1 < -100 or val1 > 100:
        valid = False
    
    if val2 < -100 or val2 > 100:
        valid = False
            
    return valid

# Get T cases from user, S
# Knowing that each time, the user enters also the value of X and Y
# And that for each entry we must check if it's in valid list
# And also calculate the least value for the sum of X and Y
cases = []
vals = []
for i in range(T):
    print("\n\nEntries for case #",i+1)
    S_in = input("Enter the case >>> ").upper()
    # X = int(input("Enter the value of X >>> "))
    # Y = int(input("Enter the value of Y >>> "))
    # S = input("Enter the case >>> ").upper()
    
    S_split = S_in.split(" ")
    X = int(S_split[0])
    Y = int(S_split[1])
    S = S_split[2]
    
    # Check for S
    if validity(S) and valid_length(S, X, Y):
        cases.append(S)
    else:
        print("Case #",i+1, " failed.")
        
    min_val = S.replace('?', '').count('CJ') * X + S.replace('?', '').count('JC') * Y
    vals.append(min_val)
        
for i in range(len(cases)):
    print("Case #",i+1,": ",vals[i])