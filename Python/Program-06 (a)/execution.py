import string

def count_words(input_file, output_file):
    word_count = {}
    with open(input_file, 'r') as file:
        for line in file:
            line = line.translate(str.maketrans('', '', string.punctuation))
            line = line.lower()
            words = line.split()

            for word in words:
                if word in word_count:
                    word_count[word] += 1
                else:
                    word_count[word] = 1

    with open(output_file, 'w') as file:
        for word, count in word_count.items():
            file.write(f"{word}: {count}\n")

input_file = "Program-6 (a).py\input.txt"
output_file = "Program-6 (a).py\output.txt"
count_words(input_file, output_file)