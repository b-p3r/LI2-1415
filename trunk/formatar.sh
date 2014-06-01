

#astyle -A3SPk3Qs4"code/*"
#!/bin/bash
DIR=$1
FILES=$DIR*
for f in $FILES
do
	#astyle -A3SPk3Qns4xL $f
	astyle -A9SPk3QHns4xLmYFxe $f
	# take action on each file. $f store current file name
done

