echo 'enter server PID'
read pid
echo 'enter string'
read string

start=`date +%s`

./client $pid $string

finish=`date +%s`
diff=$( echo "$finish - $start" | bc -l )

echo 'start:' $start
echo 'finish:' $finish
echo 'diff:' $diff