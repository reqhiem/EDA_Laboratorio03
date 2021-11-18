#!/bin/bash

echo "Executing kNN in KD-Tree"
echo "Compiling ..."
g++ program3.cpp -o program3.out -Iann/include -Lann/lib -lANN

KNN=30

echo "Executing ..."
./program3.out -nn $KNN -df data/data100.pts -qf data/query100.pts > sample.save
./program3.out -nn $KNN -df data/data500.pts -qf data/query500.pts > sample.save
./program3.out -nn $KNN -df data/data1000.pts -qf data/query1000.pts > sample.save
./program3.out -nn $KNN -df data/data5000.pts -qf data/query5000.pts > sample.save
./program3.out -nn $KNN -df data/data10000.pts -qf data/query10000.pts > sample.save
./program3.out -nn $KNN -df data/data20000.pts -qf data/query20000.pts > sample.save
./program3.out -nn $KNN -df data/data100000.pts -qf data/query100000.pts > sample.save
./program3.out -nn $KNN -df data/data200000.pts -qf data/query200000.pts > sample.save
./program3.out -nn $KNN -df data/data350000.pts -qf data/query350000.pts > sample.save
./program3.out -nn $KNN -df data/data500000.pts -qf data/query500000.pts > sample.save
./program3.out -nn $KNN -df data/data1000000.pts -qf data/query1000000.pts > sample.save