gcc -o run main.c
./run 4 + 8 > out
./run 123 - 123 >> out
./run 123 - -123 >> out
./run 123 + 123 >> out
./run 123 + -123 >> out
./run 123 + 1234 >> out
./run 12334 - 789234 >> out
./run 12sd334 - -789234 >> out
./run 123312323494 - 789234 >> out
./run 7 -- 789234 >> out
./run 123394 ! 789234 >> out
