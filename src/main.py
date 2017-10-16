"""Main file"""

import json
import subprocess

primeDict = {}
primeId = 0;
primeStr = subprocess.check_output(['./a.out','1000000'])
primeList = primeStr.split('\n')
for element in primeList:
	if element == "":
		continue
	primeDict[primeId] = {'prime': element.split(',')[0], 'time': element.split(',')[1]}
	primeId += 1
with open('primes.json', 'w') as file:
    json.dump(primeDict, file)
