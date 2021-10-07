# New_pushswap

https://sketchboard.me/FCT9dMd4OaPN#/

1 5 2 7 12 6 9 10 8 11 3 4

1 5 2 7 12 6 9 10 8 11 3

4

1 5 2 7 12 6 9 10 8 11 

3 4

1 5 2 7 12 6 9 10 8

3 4 11

1 5 2 7 12 6 9 10

11 3 4 8

1 5 2 7 12 6 9

11 3 4 8 10

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





