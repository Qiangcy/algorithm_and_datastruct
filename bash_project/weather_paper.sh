#!/bin/bash

#Copyright (c) 2015 YongHaoHu
#
#Permission is granted to anyone to use this software for any purpose,
#This notice may not be removed or altered from any source
#distribution.

Cur_Dir=$(pwd)/weather
cd $Cur_Dir
today=$(date +%m-%d)
weather_table=(01-05 01-20 02-03 02-18 03-05 03-20 04-04 04-19 05-05 05-20 06-05 06-21 07-06
                07-22 08-07 08-22 09-07 09-22 10-08 10-23 11-07 11-22 12-06 12-21)
i=0
for var in ${weather_table[@]};
do
    let i+=1;
    if [ $today = $var ];then
        photo="$i".jpg
        break
    elif [ $today \> $var ];then
        photo="$i".jpg
    fi
done
gsettings set org.gnome.desktop.background picture-uri "file://$Cur_Dir/$photo"
