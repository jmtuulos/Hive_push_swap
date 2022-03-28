import numbers
import random

def main():
    outfile = open('10_randoms', 'w')
    numstring = ""
    count = 0
    count_of_num = 10
    while(count < count_of_num):
        num = random.randint(1, 1000)
        if str(num) not in numstring:
            numstring += str(num)
            count = count + 1
            if (count_of_num != count):
                numstring += " "
    outfile.write(numstring)
    outfile.close()

main()
