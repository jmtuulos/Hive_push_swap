import numbers
import random
import numpy as np

def main():
    numbers = 500
    lst = random.sample(range (-500, 500), numbers)
    string = " ".join(map(str, lst))
    print(string)
main()
