#qn 1
import math

def qn_1():
    student_id = 0
    while student_id != -1:
        student_id = input("Please enter student id. Enter -1 to exit program: ")

        if student_id != "-1":
            student_mark = int(input("Please enter score of student: "))
            if student_mark >= 75:
                grade = "A"
            elif student_mark >= 65:
                grade = "B"
            elif student_mark >= 55:
                grade = "C"
            elif student_mark >= 45:
                grade = "D"
            else:
                grade = "F"
    
            print(f"The grade of student {student_id} is {grade}")
        else:
            break

def qn_2():
    lines = int(input("Please input number of averages you would like to calculate: "))
    for i in range(lines):
        total = val = counter = 0
        while val != -1:
            val = int(input("Please input the number, -1 to end the program "))
            if val == -1:
                break
            else:
                total += val
                counter += 1
        
        print(f"Average = {total/counter}")

def qn_3():
    height = int(input("Please enter the height of the pattern "))
    pattern = 1

    for i in range(1,height+1):
        if pattern == 4:
            pattern = 1
        print(str(pattern)*i)
        pattern += 1

def qn_4():
    val = float(input("Please input the number "))
    total = 0
    for i in range(11):
        total += (val**i)/math.factorial(i)
    print(f"e to the power of x where x is {val} is {round(total,2)}")

qn_4()