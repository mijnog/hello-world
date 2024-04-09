import random
import string

def generate_random_string(length=4):
    return ''.join(random.choices(string.ascii_letters + string.digits, k=length))

# Generate a random 4-character string
random_string = generate_random_string()
print(random_string)

