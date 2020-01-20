#!/bin/sh
#set r311 audio throughway begin
#dafult headphone out,default headphone volume is 30
echo "set r311 audio pass through"
amixer cset name='AIF1IN0R Mux' 'AIF1_DA0R'
amixer cset name='AIF1IN0L Mux' 'AIF1_DA0L'
amixer cset name='DACR Mixer AIF1DA0R Switch' 1
amixer cset name='DACL Mixer AIF1DA0L Switch' 1
amixer cset name='HP_R Mux' 'DACR_HPR_Switch'
amixer cset name='HP_L Mux' 'DACL_HPL_Switch'
amixer cset name='Headphone Switch' 1
amixer cset name='headphone volume' 40
#set r311 audio throughway finish
realtplayerdemo $1
