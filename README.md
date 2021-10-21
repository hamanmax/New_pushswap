# New_pushswap

https://sketchboard.me/FCT9dMd4OaPN#/

1 5 2 7 12 6 9 10 8 11 3 4

1 5 2 7 12 6 9 10 8 11 3

4

1 5 2 7 12 6 9 10 8 11 

4 3

1 5 2 7 12 6 9 10 8

4 3 11

1 5 2 7 12 6 9 10

4 3 11 8

1 5 2 7 12 6 9

8 4 3 11 10

1 5 2 7 12 6

10 11 3 4 8 9

1 5 2 7 12

8 9 10 11 3 4 6

12 1 5 2

8 9 10 11 3 4 6 7

2 12 1

6 7 8 9 10 11 3 4 5

2 12

3 4 5 6 7 8 9 10 11 1

12

3 4 5 6 7 8 9 10 12 1 2


Si stack_a peut se contenir entre Stack_b et stack_b->next alors on peut le push | stack_b < stack_a > stack_b->bot

sinon comptez le nombre de modification qu'il faut pour que ce soit le cas en stack_b

Enregistrer ce nombre

incrementer l'index de la pile_a

refaire le test de la stack avec la stack_b

etc jusqu'a la fin de la stack a

garder la valeur la plus faible en nombre d'operation (Comment ?)

garder un pointeur de stack_a sur la valeur la plus faible

tant qu'il existe un stack_a-> prev rotate

1 5 2 7 12

Si la valeur est plus petit que next et plus grande que prev on push

Sinon Si la valeur est la plus grande on la met a la fin

Sinon Si la valeur est la plus petite on la met au debut

Sinon on modifie le Next et le Prev

10 11 3 4 6 8 9

9-3-6-4-10  7

9-3-6-2-8 5

4-2-6-2-8 4

9-3-12-2-10 5

Si c'est le plus grand de ma liste le mettre dans la transition
Si c'est le plus petit le mettre dans la transition




3 5 6 2 0 66

3
5
6
2
0
66

6   5
2   3
0
66

ARG=$(python3 -c "import random;a = random.sample(range(1000), 100)
for x in range(len(a)): print(a[x], end=\" \")");./a.out $ARG

ARG=$(python3 -c "import random;a = random.sample(range(1000), 100)
for x in range(len(a)): print(a[x], end=\" \")");./a.out $ARG | wc -l >> test-100

ARG=$(python3 -c "import random;a = random.sample(range(1000), 100)
for x in range(len(a)): print(a[x], end=\" \")");./a.out $ARG | wc -l >> test-500