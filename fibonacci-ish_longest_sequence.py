#!usr/bin/python
"""
Yash has recently learnt about the Fibonacci sequence and is very excited about it. He calls a sequence Fibonacci-ish if the sequence consists of at least two elements f_0 and f_1 are arbitrary f_n+2 = f_n+1 + f_n for all n >= 0.

You are given some sequence of integers a_1, a_2,...,a_n. Your task is rearrange elements of this sequence in such a way that its longest possible prefix is Fibonacci-ish sequence.
Input

The first line of the input contains a single integer n (2 <= n <= 1000) - the length of the sequence a_i.
The second line contains n integers a_1, a_2,...,a_n (|a_i| <= 10^9).

Output

Print the length of the longest possible Fibonacci-ish prefix of the given sequence after rearrangement.

Input
3
1 2 -1
Output
3

Input
5
28 35 7 14 21
Output
4

Note

In the first sample, if we rearrange elements of the sequence as -1, 2, 1 the whole sequence ai would be Fibonacci-ish.

In the second sample, the optimal way to rearrange elements is 7 14 21 35.

"""

def go(a,b):
    ret,c=0,a+b
    if d.get(c) and d[c]>0:
        d[c]-=1
        ret=go(b,c)+1
        d[c]+=1
    return ret

input("Enter the size of the array: ")
d={}
for i in map(int,input("Now enter elements of the array: ").split()):
    if d.get(i):d[i]+=1
    else: d[i]=1

ans=2
for a in d:
    for b in d:
        if a!=b or d[a]>1:
            d[a]-=1
            d[b]-=1
            temp=go(a,b)+2
            ans=max(temp,ans)
            d[a]+=1
            d[b]+=1
print(ans)
