import numbers
import random
import numpy as np

def main():

    outfile = open("500_randoms", 'w')
    lst = random.sample(range (0, 500), 500)
    string = " ".join(map(str, lst))
    outfile.write(string)
    outfile.close()

main()
