#!/usr/bin/env bash

NOPATH=FALSE
UPDATED=FALSE

if [ "$SHELL" == "/bin/bash" ]; then
	source $HOME/.bash_profile
elif [ "$SHELL" == "/bin/zsh" ]; then
	source $HOME/.zprofile
fi

case :$PATH:
	in *:$1:*) ;;
		*) NOPATH=TRUE;;
esac

if [ "$NOPATH" == "TRUE" ]; then
	printf "\e[35mHEXRGB >\e[m Installation directory %s is not in \$PATH\n" $1
	printf "\e[35mHEXRGB >\e[m Add %s to \$PATH? [Y/n] " $1
	while read -s -N 1 IN; do
		if [ "$IN" == "n" -o "$IN" == "N" -o "$IN" == "y" -o "$IN" == "Y" ]; then
			break ;
		fi
	done
	printf "\n"
	if [ "$IN" != "n" -a "$IN" != "N" ]; then
		if [ "$SHELL" == "/bin/bash" ]; then
			printf "\e[32mHEXRGB >\e[m Updating \$PATH in ~/.bash_profile\n"
			printf "\ncase :\$PATH:\n" >> $HOME/.bash_profile
			printf "\tin *:$1:*) ;;\n" >> $HOME/.bash_profile
			printf "\t\t*) export PATH=\"\${PATH}:$1\"\n" >> $HOME/.bash_profile
			printf "esac\n" >> $HOME/.bash_profile
			UPDATED=TRUE
		elif [ "$SHELL" == "/bin/zsh" ]; then
			printf "\e[32mHEXRGB >\e[m Updating \$PATH in ~/.zprofile\n"
			printf "\ncase :\$PATH:\n" >> $HOME/.zprofile
			printf "\tin *:$1:*) ;;\n" >> $HOME/.zprofile
			printf "\t\t*) export PATH=\"\${PATH}:$1\"\n" >> $HOME/.zprofile
			printf "esac\n" >> $HOME/.zprofile
			UPDATED=TRUE
		fi
	fi
	if [ "$UPDATED" == "TRUE" ]; then
		printf "\e[32mHEXRGB >\e[m \$PATH updated, don't forget to source\n"
	fi
fi
