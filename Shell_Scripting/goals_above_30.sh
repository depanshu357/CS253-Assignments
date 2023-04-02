#!/bin/bash
if test ! -f "$1";then
	echo  "$1 not found"
	exit 1
fi
awk -F ',' '$16 > 0 && $2 > 30 {print $0}' "$1" > "$2"
