#!/bin/sh
#set c200s audio throughway begin
#dafult headphone out,default headphone volume is 30
echo "set c200s audio pass through"
amixer cset iface=MIXER,name='head phone volume' 30
#set c200s audio throughway finish
realtplayerdemo $1
