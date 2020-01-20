#!/bin/sh
#set r30 audio throughway begin
#dafult headphone out,default headphone volume is 30
echo "set r30 audio pass through"
#amixer cset name='headphone volume' 30
#amixer cset name='AIF1IN0L Mux' 'AIF1_DA0L'
#amixer cset name='AIF1IN0R Mux' 'AIF1_DA0R'
#amixer cset name='DACL Mixer AIF1DA0L Switch' 1
#amixer cset name='DACR Mixer AIF1DA0R Switch' 1
#amixer cset name='HP_L Mux' 'DACL HPL Switch'
#amixer cset name='HP_R Mux' 'DACR HPR Switch'
#amixer cset name='Headphone Switch' 1
#set r30 audio throughway finish

#the following is set for carp
amixer cset name='AIF1IN0R Mux' 'AIF1_DA0R'
amixer cset name='AIF1IN0L Mux' 'AIF1_DA0L'
amixer cset name='DACR Mixer AIF1DA0R Switch' 1
amixer cset name='DACL Mixer AIF1DA0L Switch' 1
amixer cset name='Right Output Mixer DACR Switch' 1
amixer cset name='Left Output Mixer DACL Switch' 1
amixer cset name='SPK_L Mux' 'MIXEL_Switch'
amixer cset name='SPK_R Mux' 'MIXER_Switch'
amixer cset name='DAC volume' 160
amixer cset name='Headphone Switch' 0
amixer cset name='External Speaker Switch'  1

realtplayerdemo $1
