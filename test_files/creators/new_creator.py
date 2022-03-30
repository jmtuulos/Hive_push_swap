import numbers
import random
import numpy as np

def main():

    outfile = open("100_randoms", 'w')
    lst = random.sample(range (0, 100), 100)
    string = " ".join(map(str, lst))
    outfile.write(string)
    outfile.close()

main()
