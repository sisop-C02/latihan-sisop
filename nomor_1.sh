#!/bin/bash

divider=2
condition=0

let arg_num=$#%$divider

if [ $arg_num == $condition ]
then
  echo "Anda belum beruntung, coba lagi."
else
  total=0
  for num in $*
  do
    total=`expr $total + $num`
  done
  echo $total
fi
