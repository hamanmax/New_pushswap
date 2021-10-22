# New_pushswap

https://sketchboard.me/FCT9dMd4OaPN#/

0 1 2

0 2 1

1 2 0
rra

1 0 2
sa

2 1 0


2 0 1
ra


ARG=$(python3 -c "import random;a = random.sample(range(1000), 100)
for x in range(len(a)): print(a[x], end=\" \")");./a.out $ARG

ARG=$(python3 -c "import random;a = random.sample(range(1000), 100)
for x in range(len(a)): print(a[x], end=\" \")");./a.out $ARG | wc -l >> test-100

ARG=$(python3 -c "import random;a = random.sample(range(1000), 100)
for x in range(len(a)): print(a[x], end=\" \")");./a.out $ARG | wc -l >> test-500