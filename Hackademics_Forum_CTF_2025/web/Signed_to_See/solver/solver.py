#!/usr/bin/env python3

import requests
import sys


if len(sys.argv) != 2:
	print("Usage example: python3 solver.py http://example.com:7898/")
	sys.exit()

url = sys.argv[1]

resultFile = "746573742e747874800000000000000000000000000000000000000000000000000000000000000000000000000000000000000098666c61672e747874"
resultKey = "f2a174a3134b08d8cff4d2919e12c75bbe34cb2f"

r = requests.post(url, data={"file":resultFile,"key":resultKey})

if "Invalid" not in r.text:
	print("Flag: {}".format(r.text))
	sys.exit()

print("Error: The challenge is not working as expected")
