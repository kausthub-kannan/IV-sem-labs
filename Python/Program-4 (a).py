numbers = []
while True:
    num = int(input("Enter a number (or a negative number to exit): "))
    if num < 0:
        break
    
numbers.append(num)
total = sum(numbers)
print("The sum of the numbers is:", total)