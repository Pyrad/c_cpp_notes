#!/usr/bin/python

import random

# Double
#print random.uniform(10, 20)
#print random.uniform(10, 20)

# Integer
#print random.randint(10, 20)
#print random.randint(10, 20)

lower_bound=0
upper_bound=10

lower_value_bound=-100
upper_value_bound=101

times=10

for cnt in range(10):
    for i in range(lower_bound, upper_bound):
        print random.randint(lower_value_bound, upper_value_bound),
    print ""
