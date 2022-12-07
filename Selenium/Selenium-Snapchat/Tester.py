import random
from math import factorial

wlist = set()

counter = 1

while counter <= 100:
    created = random.choices("",k=3)
    created = "".join(created)
    wlist.add(created)
    counter += 1

wlist = list(wlist)

wlist.sort()
print("*************************")
print(wlist)

counter2 = 0

while counter2 < len(wlist):
    print(wlist[counter2])
    counter2 += 1

z = "123"
z2 = "512"
z3 = "125"
z4 = "2002"
z5 = "02"

wordlist1 = [x]
wordlist2 = [y,y2]
wordlist3 = [z,z1,z2,z3,z4,z5]

