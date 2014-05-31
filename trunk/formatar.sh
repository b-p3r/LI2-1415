

#astyle -A3SPk3Qs4"code/*"
#!/bin/bash
DIR=$1
FILES=$DIR*
for f in $FILES
do
	astyle -A3SPk3Qns4 $f
	# take action on each file. $f store current file name
done

