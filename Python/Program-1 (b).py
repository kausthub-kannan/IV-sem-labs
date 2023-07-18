numbers = input("Enter a list of numbers, separated by spaces: ").split()
numbers = [int(num) for num in numbers]
even_sum = sum(num for num in numbers if num % 2 == 0)
print("The sum of even numbers is:", even_sum)