import numbers
import random
import numpy as np

def main():
    outfile = open("100_randoms", 'r')
    str1 = outfile.readlines()
    outfile.close()
    outfile = open(1, 'w')
    for line in str1:
        outfile.write(line)
    outfile.close()

main()
