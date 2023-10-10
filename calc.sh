#!/bin/bash
ANS=0
history=()
if [ -f ans.txt ]
then 
    read ANS < ans.txt
fi

while true; do
    read -p ">> " expression
    if [[ "$expression" == "EXIT" ]]; then
        break
    elif [[ "$expression" == "HIST" ]]; then
        for ((i=0; i < 5 && i < ${#history[@]}; i++)); do
            index=$((${#history[@]} - $i - 1))
            echo "${history[$index]}"
        done
    elif ! echo "$expression" | grep -q '[+x/%-]' || (! echo "$expression" | grep -q '[0-9]' && [[ "$expression" != *"ANS"* ]]) || [[ "$expression" != *" "* ]]; then
        echo "SYNTAX ERROR"
    else
        expression_replace_ANS="${expression//ANS/$ANS}"
        expression_replace_x="${expression_replace_ANS//x/*}"
        if [[ $expression_replace_x != *"%"* ]]; then
            result=$(echo "scale=3; $expression_replace_x" | bc 2>&1)
        else
            result=$(echo "$expression_replace_x" | bc 2>&1)
        fi

        
        if [[ "$result" == *"syntax error"* ]]; then
            echo "SYNTAX ERROR"
        elif [[ "$result" == *"Divide by zero"* ]]; then
            echo "MATH ERROR"
        else  
            if [[ $result == *.* ]]; then
            result=$(printf "%.2f" "$result") 
            fi

            echo "$result"
            history+=("$expression = $result")
            ANS=$result
            echo $ANS > ans.txt
        fi
    fi
    read -n 1
    clear;
done