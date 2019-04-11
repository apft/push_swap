seq ${1} ${2} | shuf -n ${3} | tr '\n' ' ' | sed 's/ $//'
