#!/bin/sh
#set T7 audio throughway begin
#dafult speaker out,default speaker volume is 45
echo "set T7 audio pass through"
amixer cset name='Left Output Mixer DACL Switch' 1
amixer cset name='Right Output Mixer DACR Switch' 1
amixer cset name='Phone Out Mixer LOMIX Switch' 1
amixer cset name='Phone Out Mixer ROMIX Switch' 1
amixer cset name='phoneout volume' 4
amixer cset name='digital volume' 45
amixer cset name='Phoneout Speaker Switch' 1
#set T7 audio throughway finish
realtplayerdemo $1
