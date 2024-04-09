import random
import string

def generate_random_string(length=4):
    return ''.join(random.sample(string.ascii_lowercase, length))

# Generate a list of 100 random 4-character strings with all lowercase letters and no repeating characters
random_strings = [generate_random_string() for _ in range(100)]

# Print the list of random strings
print(random_strings)
