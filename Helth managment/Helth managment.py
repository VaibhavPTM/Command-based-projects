#Helth management sysytem
def getDate():
    import datetime
    return datetime.datetime.now()
def x():
    f.write("\n\n")
    f.write(str(getDate()))
    f.write("\n")
    f.write(write)

num2=int(input("enter 0 for lock and 1 for retrive>>\n")) #for lock or r option
if num2==0:
    num = int(input("enter 0 for show the food list or enter 1 for show the exercise list>>\n"))# for food or e.
    if num==0:
        name = input("enter your name>>\n") # custoers mane input
        if name=='vaibhav':
            with open("vaibhav food.txt") as f:
                a = f.read()
                print(a)
        elif name=='mitul':
            with open("mitul food.txt") as f:
                a = f.read()
                print(a)
        elif name=='jogi':
            with open("jogi food.txt") as f:
                a = f.read()
                print(a)
    elif num==1:
        name = input("enter your name>>\n")  # custoers mane input
        if name == 'vaibhav':
            with open("vaibhav e.txt") as f:
                a = f.read()
                print(a)
        elif name == 'mitul':
            with open("mitul e.txt") as f:
                a = f.read()
                print(a)
        elif name == 'jogi':
            with open("jogi e.txt") as f:
                a = f.read()
                print(a)
elif num2==1:
    num = int(input("enter 0 for write the food list or enter 1 for write the exercise list>>\n"))  # for food or e.
    if num == 0:
        name = input("enter your name>>\n")  # custoers mane input
        if name == 'vaibhav':
            z="\n"
            write=input("What are you eat today>>\n")
            with open("vaibhav food.txt","a") as f:
                x()
                print("Your file have written succesfully")
        elif name == 'mitul':
            write = input("What are you eat today>>\n")
            with open("mitul food.txt", "a") as f:
                x()
                print("Your file have written succesfully")
        elif name == 'jogi':
            write = input("What are you eat today>>\n")
            with open("jogi food.txt", "a") as f:
                x()
                print("Your file have written succesfully")
    elif num == 1:
        name = input("enter your name>>\n")  # custoers mane input
        if name == 'vaibhav':
            write = input("What do yoy do today?>>\n")
            with open("vaibhav e.txt" ,"a") as f:
                x()
                print("Your file have written succesfully")
        elif name == 'mitul':
            write = input("What do yoy do today>>\n")
            with open("mitul e.txt" ,"a") as f:
                x()
                print("Your file have written succesfully")
        elif name == 'jogi':
            write = input("What do yoy do today>>\n")
            with open("jogi e.txt" ,"a") as f:
                x()
                print("Your file have written succesfully")