#!/usr/bin/env bash

if [ "$1" == "user" ]; then
	if [  -f ~/.local/bin/hexrgb ]; then
		VERSION1=$(~/.local/bin/hexrgb -v)
		VERSION2=$(./hexrgb -v)
		if [ "$VERSION1" == "$VERSION2" ]; then
			printf "\e[35mHEXRGB >\e[m Reinstalling %s\n" $2
		else
			printf "\e[35mHEXRGB >\e[m Updating %s\n" $2
		fi
	else
		printf "\e[35mHEXRGB >\e[m Installing %s\n" $2
	fi
else
	if [  -f /usr/local/bin/hexrgb ]; then
		VERSION1=$(/usr/local/bin/hexrgb -v)
		VERSION2=$(./hexrgb -v)
		if [ "$VERSION1" == "$VERSION2" ]; then
			printf "\e[35mHEXRGB >\e[m Reinstalling %s\n" $2
		else
			printf "\e[35mHEXRGB >\e[m Updating %s\n" $2
		fi
	else
		printf "\e[35mHEXRGB >\e[m Installing %s\n" $2
	fi
fi
