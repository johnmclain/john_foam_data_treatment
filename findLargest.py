#!/usr/bin/env python2

import os
fileDir = './surfaces/'
A = []
for root, dirs, files in os.walk(fileDir): 
	for names in dirs:
		A.append(int(names))
print max(A)
