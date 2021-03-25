#!/usr/bin/env bash
##
## EPITECH PROJECT, 2021
## Untitled (Workspace)
## File description:
## test
##

test1()
{
    echo " " | ./my_sokoban $1 &> data
    if [[ $? == 1 ]]
    then
        echo -e "\E[0;32m Test exit map \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test exit map \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data
}

testerror()
{
    ./my_sokoban "allo" 2>/dev/null
    if [[ $? == 84 ]]
    then
        echo -e "\E[0;32m Test argument is not a file \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test argument is not a file \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data

    ./my_sokoban "maps/map_invalid_1" 2>/dev/null
    if [[ $? == 84 ]]
    then
        echo -e "\E[0;32m Test invalid map \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test invalid map \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data

    ./my_sokoban 2>/dev/null
    if [[ $? == 84 ]]
    then
        echo -e "\E[0;32m Test no argument \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test no argument \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data

    ./my_sokoban "maps/map_ice_1" "maps/map_test_4" 2>/dev/null
    if [[ $? == 84 ]]
    then
        echo -e "\E[0;32m Test too much arguments (-) \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test too much arguments (-) \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data

    ./my_sokoban "-h" > data 
    if [[ $? == 0 && data ]]
    then
        echo -e "\E[0;32m Test display usage \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test display usage \e[0m \e[41mNOT PASSED\E[0m"
    fi
    rm -f data
}

echo -e "\E[0m \e[90m\e[1m TEST 1 SUBJECT \e\e[0m"
test1 "maps/map_test_1"
echo -e "\E[0m \e[90m\e[1m TEST ERROR HANDLING \e\e[0m"
testerror 

rm -f data