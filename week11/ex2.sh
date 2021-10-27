sudo su
cd lofsdisk

echo "Artem" >> file1
echo "Chernitsa" >> file2

mkdir bin
mkdir lib
mkdir lib/x86_64-linux-gnu

cp /bin/bash bin/bash
cp /bin/ls bin/ls
cp /bin/cat bin/cat
cp /bin/echo bin/echo

cmd=("bash" "ls" "cat" "echo")
for i in $cmd
do
   list="$(ldd /bin/$i | awk 'NF == 4 {print $3}; NF == 2 {print $1}' | grep /lib/)"
   for j in $list
   do
      cp -v "$j" "lib/$j"
   done
done


