gcc -o run main.c
./run 4 + 8 > out
./run 123 - 123 >> out
./run 123 - -123 >> out
./run 123 + 123 >> out
./run 123 + -123 >> out
./run 
