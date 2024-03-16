#!/usr/bin/env bash

if [  -f $2/$1 ]; then
	VERSION1=$($2/$1 -v)
	VERSION2=$(./$1 -v)
	if [ "$VERSION1" == "$VERSION2" ]; then
		printf "\e[32mHEXRGB >\e[m Reinstalling %s\n" $1
	else
		printf "\e[32mHEXRGB >\e[m Updating %s\n" $1
	fi
else
	printf "\e[32mHEXRGB >\e[m Installing %s\n" $1
fi
