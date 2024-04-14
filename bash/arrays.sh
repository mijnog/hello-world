#!/bin/bash

#Set an array

IP_ADDR=(192.168.1.1 192.168.1.27 192.168.1.33 192.168.42)

#Print all elements in the array (all IP_ADDResses)

echo "${IP_ADDR[*]}"

#Print first element

echo "${IP_ADDR[0]}"

#Print second element

echo "${IP_ADDR[1]}"

#Testing what happens if I try to access an element that is out of bounds

echo "${IP_ADRR[3]}"
