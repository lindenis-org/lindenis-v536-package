#!/bin/sh
#set v3 audio throughway begin
#dafult headphone out,default headphone volume is 30
echo "set v3 audio pass through"
amixer cset iface=MIXER,name='Lineout volume' 31
#set v3 audio throughway finish
realtplayerdemo $1
