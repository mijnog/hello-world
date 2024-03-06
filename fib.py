

def fib(n):

  if n == 1:
    return 1
  elif n == 2:
    return 1
  else:
    return fib(n-1) + fib (n-2)

print("Which fib number you wanna calculate?")
n = int(input())
nth_fib = fib(n)
print("The ", n, "th fibonacci term is ", nth_fib)
