# while read line; do
#     if [[ "$line" =~ ^((\([0-9]{3}\) )|[0-9]{3}-)[0-9]{3}-[0-9]{4}$ ]]; then
#         echo $line
#     fi
    
# done &lt; "file.txt"

grep -e "^[0-9]\{3\}\-[0-9]\{3\}\-[0-9]\{4\}$" -e "^([0-9]\{3\}) [0-9]\{3\}\-[0-9]\{4\}$" file.txt