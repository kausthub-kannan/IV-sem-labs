def filter_words_with_prefix(word_list, prefix):
    filtered_words = [word for word in word_list if word.startswith(prefix)]
    return filtered_words

word_list = input("Enter a list of words (separated by spaces): ").split()
prefix = input("Enter the prefix to filter: ")
filtered_words = filter_words_with_prefix(word_list, prefix)
print("Filtered words:")

for word in filtered_words:
    print(word)