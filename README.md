# Hive_push_swap

How to sort a stack of items with a help of another stack?

In this project the challenge was the limited amount of legal moves you could do to sort the stack, meaning normal sorting algorightms wouldn't suffice (quicksort, mergesort ...).

Allowed moves to arrange the stack are: 
1. Push top of A and/or B to bottom
2. Swap top two of stack A and/or B
3. Push bottom of A and/or B to top
4. Push top of A to top of B
5. Push top of B to top of A

The below example is easy as there is only 5 different possibilities for a stack of three to be arranged. You can solve these with a maximum of two moves.

![push_swap_exampl1](https://user-images.githubusercontent.com/43127337/186123843-5f1f6763-71c8-4417-ba80-a303b151fded.png)

The more difficult part is to solve a stack of 100 or a stack of 500. With the limited move possibilities you would've to adjust your algorithm depending on how big the given stack is.

## Usage

```bash
Make
```

```
ARG=`python3 generator.py`; ./push_swap $ARG | ./checker $ARG
```

./checker outputs OK if the stack given from push_swap is actually sorted.

./push_swap outputs the moves required to sort the given stack.

