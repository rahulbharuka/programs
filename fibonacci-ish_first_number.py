#!/usr/bin/python
"""
The Fibonacci Sequence is a famous integer series in the field of mathematics. The sequence is recursively defined for n > 1 by the formula f(n) = f(n-1) + f(n-2). In plain english, each term in the sequence is found by adding the previous two terms together. Given the starting values of f(0) = 0 and f(1) = 1 the first ten terms of the sequence are:

    0 1 1 2 3 5 8 13 21 34

We will notice however that some numbers are left out of the sequence and don't get any of the fame, 9 is an example. However, if we were to start the sequence with a different value for f(1) we will generate a new sequence of numbers. Here is the series for f(1) = 3:

    0 3 3 6 9 15 24 39 102 165

We now have a sequence that contains the number 9. What joy!
Today you will write a program that will find the lowest positive integer for f(1) that will generate a Fibonacci-ish sequence containing the desired integer (let's call it x).

Input description

Your input will be a single positive integer x.

Sample Input 1: 21

Sample Input 2: 84 

Output description

The sequence of integers generated using the recursion relation starting from 0 and ending at the desired integer x with the lowest value of f(1).

Sample Output 1: 0 1 1 2 3 5 8 13 21

Sample Output 2: 0 4 4 8 12 20 32 52 84

Challenge Inputs

Input 1: 0
Input 2: 578
Input 3: 123456789 

Notes/Hints

Large inputs (such as input 3) may take some time given your implementation. However, there is a relationship between sequences generated using f(1) > 1 and the classic sequence that can be exploited

"""


import functools, itertools, math, sys

FIBS_CACHE = {}
def fib(f1, index):
    """ Calculate the index-th fib number if f(1)=f1. Use a dict cache. """
    if index == 0:
        return 0
    if index == 1:
        return f1
    if (f1, index) not in FIBS_CACHE:
        FIBS_CACHE[f1, index] = fib(f1, index-1) + fib(f1, index-2)
    return FIBS_CACHE[f1, index]

def find_fib_factor(n):
    """ Search the regular fib sequence for the highest factor of n (for lowest multiple)
    Return the index on success. If not found, return 1. """
    max_factor = 1
    for i in itertools.count(3): # Start search at 3rd number; 0 1 1 are uninteresting
        if n % fib(1, i) == 0:
            max_factor = i
        if fib(1, i) > n: # There can be no factors greater than this
            return max_factor

def main():
    if len(sys.argv)>1:
        N = sys.argv[1]
    else:
        N = input("Number to have in your fib sequence? ")

    N = int(N)

    fib_factor_index = find_fib_factor(N)
    fib_multiple = N // fib(1, fib_factor_index)

    fibs = [ str(fib(fib_multiple, i)) for i in range(fib_factor_index+1) ]
    print(" ".join(fibs))
    

if __name__ == "__main__":
    main()
