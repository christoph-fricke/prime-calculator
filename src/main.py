"""Main file"""

from prime import Prime

for i in range(100):
    if Prime.is_prime(i):
        print(i)
