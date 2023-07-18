def find_maximum(numbers):
    if not numbers:
        raise ValueError("The list is empty.")
    
    maximum = numbers[0]
    for num in numbers:
        if num > maximum:
            maximum = num
    return maximum

numbers = [1, 40, 2, 88, 3]
max_num = find_maximum(numbers)
print("The maximum number is:", max_num)