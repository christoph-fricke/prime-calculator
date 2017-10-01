"""Main file"""

from prime import Prime
import timeit
import json

primeDict = {}
primeId = 0
for i in range(1000000):
    start_time = timeit.default_timer()
    result = Prime.is_prime(i)
    end_time = timeit.default_timer()
    if result:
        primeDict[primeId] = {'prime': i, 'time': end_time - start_time}
        primeId += 1
with open('primes.json', 'w') as file:
    json.dump(primeDict, file)
