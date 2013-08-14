#!/bin/bash
echo Hello World
for i in {14..23}
do
  cat "Quizzes2.c++" > "tmp.c++"
  cat "tmp.c++" "Quiz${i}.c++" > "Quizzes2.c++"
  rm "tmp.c++"
done

