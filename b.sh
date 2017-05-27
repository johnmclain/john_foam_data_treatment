#!/bin/bash

info=$(./findLargest.py)

echo $info

#echo hello

./OctaveScript $info
