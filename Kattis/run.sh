#!/bin/sh
read command
if [ ${command} == "create" ]; then
  read filename
  cp template.cpp ${filename}.cpp
  echo CREATING NEW FILE
elif [ ${command} == "compile" ]; then
  read filename
  g++ ${filename}.cpp -o A -std=c++17
  if [ $? -eq 0 ]; then
    echo "COMPILATION SUCCESSFUL !"
  else 
    echo "COMPILATION FAILED !"
  fi
else
  echo "INVALID COMMAND !"
fi
  
