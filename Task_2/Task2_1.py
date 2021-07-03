a = input("Please input a number!\n")
while(1):
    if 0 < int(a) < 10 :
        print("you have input the right answer")
        break
    else:
        print("Try again")
        a = input("Please input a number!\n")
print("now next game!")