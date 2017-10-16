"""Main file"""

import json
import subprocess

primeDict = {}
primeId = 0;
primeStr = subprocess.check_output(['./a.out','1000000'])
primeList = primeStr.split(b'\n')
for element in primeList:
	if element == b"":
		continue
	primeDict[primeId] = {'prime': str(element.split(b',')[0]), 'time': str(element.split(b',')[1])}
	primeId += 1
with open('primes.json', 'w') as file:
    json.dump(primeDict, file)
