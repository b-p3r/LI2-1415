#!/bin/bash
FILES=../tests_current/*
for f in $FILES
do
	echo "Processing $f file..."   
	cat -T $f
	echo -e "\n"

done
