#1/bin/bash
if test ! -f "$1" ; then
 echo "File not present"
 exit 1
fi
tmp_file=$(mktemp)
head -n 1 "$1" > "$2"
sort -t ',' -k16,16nr "$1" >"$tmp_file"
awk -F"," '{if(!seen[$16]){b[$16]++}; if(length(b)>10) exit; seen[$16] }1' "$tmp_file" >> "$2"
 
# awk -F"," '{if(NR==1 || $16 in a) {b[$16]++}; if(length(b)==10) exit; a[$16]}1' "$tmp_file" > "$2"
# awk -F"," '{if(NR==1 || $16 in a) {b[$16]++}; for (i in b) {count++}; if(count==10) exit; a[$16]; count=0}1' "$tmp_file" > "$2"
# uniq -f 1 -c "$tmp_file" | sort -nr | awk '{print $0} NR==10{exit}' > "$2"
# sort -t ',' -k 2 -nr "$1" > "$2"
exit 1