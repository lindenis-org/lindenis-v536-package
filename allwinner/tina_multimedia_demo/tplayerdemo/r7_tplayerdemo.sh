#!/bin/sh
#set R7 audio throughway begin
echo "set R7 audio throughway"
amixer -D hw:audiocodec cset name='SPK_L Mux' 0
amixer -D hw:audiocodec cset name='SPK_R Mux' 0
amixer -D hw:audiocodec cset name='Lineout volume' 25
amixer -D hw:audiocodec cset name='Right Output Mixer DACR Switch' 1
amixer -D hw:audiocodec cset name='Left Output Mixer DACL Switch' 1
amixer -D hw:audiocodec cset name='digital volume' 6
#set R7 audio throughway finish
realtplayerdemo $1
