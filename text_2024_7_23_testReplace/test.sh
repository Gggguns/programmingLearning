#!usr/bin/bash


function myfun(){
  cnt=1;
  while [ $cnt -le 10 ]
  do
    echo "hello $cnt"
    let cnt++
  done
}

echo "hello Linux"
echo "hello Linux"
echo "hello Linux"
echo "hello Linux"

ls -a -l

myfun
