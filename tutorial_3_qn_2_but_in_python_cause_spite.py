import random

def imagine():  
    container = [0,0,0,0,0,0,0,0,0,0]
    no_stars = int(input("Please enter the number of stars you want: "))

    for i in range(no_stars):
        generated_number = random.randint(0,99)
        container[int(generated_number/10)] += 1
        
    for i in range(10):
        print(f"{i*10} - {i*10+9}  |", end = " ")
        print(f"{'*'*container[i]}")
    
imagine()