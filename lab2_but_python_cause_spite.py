# pylint: disable=unused-variable

def num_digits_1(number):
    return len(str(number))

def digits_pos_1(number,digit):
    number_list = list(str(number))
    number_list.reverse()
    if str(digit) not in number_list:
        return 0
    for i in number_list:
        if str(digit) == i:
            return number_list.index(i) + 1
    return 0

def square_1(number):
    adder = 1
    to_return = 0
    print(f"fwiw, {number} squared is {number**2}")
    for i in range(number):
        to_return += adder
        adder += 2
    return to_return

def imagine():
    choice = 0
    while choice <= 4:
        print("Perform the following functions ITERATIVELY: ")
        print("1:num_digits_1()")
        print("2:digit_pos_1()")
        print("3:square_1()")
        print("4:quit")
        choice = int(input("Enter your choice: "))
    
        if choice == 1:
            number = int(input("Enter the number: "))
            print(f"num_digits_1(): {num_digits_1(number)}")
        elif choice == 2:
            number = int(input("Enter the number: "))
            digit = int(input("Enter the digit: "))
            print(f"digits_pos_1(): {digits_pos_1(number, digit)}")
        elif choice == 3:
            number = int(input("Enter the number: "))
            print(f"square_1(): {square_1(number)}")
        else:
            print("Program terminating ......")
    
imagine()