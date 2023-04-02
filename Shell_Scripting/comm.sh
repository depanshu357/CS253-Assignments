#!/bin/bash
if test ! -f "$1";then
	echo  "$1 not found"
	exit 1
fi
if test ! -f "$2";then
	echo  "$2 not found"
	exit 1
fi

tmp_file1=$(mktemp)
tmp_file2=$(mktemp)

grep -v '^$' "$1" > "$tmp_file1"
grep -v '^$' "$2" > "$tmp_file2"

sed -i '/^$/d' "$tmp_file1"  
sed -i '/^$/d' "$tmp_file2" 

while read line1;
do
	while read line2; 
	do
		if [[ ^${line1}\s*$ =~ ^${line2}\s*$ ]] || [[ "$line2" =~ ^${line1}\s*$ ]]
		then
			echo "$line1"
			break
		fi
	done < $tmp_file2
done < $tmp_file1
