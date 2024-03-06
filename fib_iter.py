print("Which fibonacci number would you like me to calculate?")
n = int(input())
def fib(n):
    a = 1
    b = 0
    for i in range(n):
        next_fibonacci_number = a + b
        a = b
        b = next_fibonacci_number
    return next_fibonacci_number
print(fib(n))

#I admit this temporary variable confused me so I used chatGPT to help me with this. I hope this doesn't make me a bad person. Endless debate in my head whether I should persevere to death and make simple calculations or adapt to the times and let the AI do it for me.
