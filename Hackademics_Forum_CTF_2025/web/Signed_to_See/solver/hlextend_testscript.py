#!/usr/bin/env python

# test script for hlextend
import hlextend
import hashlib
from os import urandom


sha = hlextend.new('sha1')
print(sha.extend(b'flag.txt', b'test.txt', 11, 'c9d4b01ce16b640782af2864a47547d88fc02cab'))
print(sha.hexdigest())
