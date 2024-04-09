import random
import string

def generate_random_string(length=4):
    return ''.join(random.choices(string.ascii_letters, k=length))

# Generate a list of 100 random 4-character strings without numbers
random_strings = [generate_random_string() for _ in range(100)]

# Print the list of random strings
print(random_strings)

