#!/bin/bash
if test ! -f "$1" ; then
	echo "File not present"
	exit 1
fi
tmp_file=$(mktemp)
tmp_file1=$(mktemp)
tmp_file2=$(mktemp)
sed 's/Goalkeeper/111/g; s/Defender/222/g; s/Midfielder/333/g; s/Forward/444/g' "$1" > "$tmp_file"
sort -t ',' -k16,16nr -k7,7 "$tmp_file" > "$tmp_file1"
sed  's/111/Goalkeeper/g; s/222/Defender/g; s/333/Midfielder/g; s/444/Forward/g' "$tmp_file1" > "$tmp_file2"
echo "full_name,position,nationality,goals_overall" > "$2"
awk -F',' '{print $1 "," $7 "," $12 "," $16}' "$tmp_file2" >> "$2"