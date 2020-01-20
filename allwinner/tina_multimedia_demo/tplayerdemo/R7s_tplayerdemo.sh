#!/bin/sh
#set R7s audio throughway begin
echo "set R7s audio throughway"
amixer -D hw:audiocodec cset name='SPK_L Mux' 1
amixer -D hw:audiocodec cset name='SPK_R Mux' 1
amixer -D hw:audiocodec cset name='Lineout volume' 25
amixer -D hw:audiocodec cset name='Right Output Mixer DACR Switch' 1
amixer -D hw:audiocodec cset name='Left Output Mixer DACL Switch' 1
amixer -D hw:audiocodec cset name='digital volume' 6
amixer -D hw:audiocodec cset name='headphone volume' 30
#set R7s audio throughway finish
realtplayerdemo $1
