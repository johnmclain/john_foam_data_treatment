#!/usr/bin/env python
import sys
file_object = open('input.txt','w')
try:
     all_the_text=sys.argv[1]
     file_object.write(all_the_text)
     print all_the_text
finally:
     file_object.close()
