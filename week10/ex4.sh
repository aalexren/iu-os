mkdir tmp
cd tmp
touch file1
touch file2
link file1 link1
link file1 link2
cd ..
gcc ex4.c -o ex4
./ex4 >> ex4.txt

