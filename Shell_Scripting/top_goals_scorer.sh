#1/bin/bash
if test ! -f "$1" ; then
 echo "File not present"
 exit 1
fi
tmp_file=$(mktemp)
head -n 1 "$1" > "$2"
sort -t ',' -k16,16nr "$1" >"$tmp_file"
awk -F"," '{if(!seen[$16]){b[$16]++}; if(length(b)>10) exit; seen[$16] }1' "$tmp_file" >> "$2"
 