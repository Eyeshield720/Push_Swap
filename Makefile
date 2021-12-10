# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmercier <jmercier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/26 06:11:11 by jmercier          #+#    #+#              #
#    Updated: 2021/12/10 08:44:06 by jmercier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	=	push_swap
NAME2	=	checker

CFLAGS	= -Werror -Wextra -Wall -I./include
# CFLAGS	+= -fsanitimake fze=address
# CFLAGS	+= -g3

TOTAL = $(shell find srcs -iname  "*.c" | wc -l | bc)
define Bar
	$(eval OBJ_COUNT := $(shell find $(OBJ_DIR) -iname "*.o" 2> /dev/null | wc -l | bc))
	printf $(shell if [ $(shell echo ${TOTAL} / 4 | bc) -gt $(shell echo ${OBJ_COUNT} + 1 | bc) ]; then printf "\r\033[1\;34m\|\033[31m"; \
	elif [ $(shell echo ${TOTAL} / 2.5 | bc) -gt $(shell echo ${OBJ_COUNT} + 1 | bc) ]; then printf "\r\033[1\;34m\|\033[35m"; \
	elif [ $(shell echo ${TOTAL} / 1.8 | bc) -gt $(shell echo ${OBJ_COUNT} + 1 | bc) ]; then printf "\r\033[1\;34m\|\033[38\;5\;129m"; \
	elif [ $(shell echo ${TOTAL} / 1.3 | bc) -gt $(shell echo ${OBJ_COUNT} + 1 | bc) ]; then printf "\r\033[1\;34m\|\033[38\;5\;222m"; \
	elif [ $(shell echo ${TOTAL} / 1.1 | bc) -gt $(shell echo ${OBJ_COUNT} + 1 | bc) ]; then printf "\r\033[1\;34m\|\033[2\;33m"; \
	elif [ $(shell echo ${TOTAL} / 1 | bc) -gt $(shell echo ${OBJ_COUNT} + 1 | bc) ]; then printf "\r\033[1\;34m\|\033[2\;32m"; \
	else printf "\r\033[1\;34m\|\033[32m"; fi)
	printf "█%.0s" $(shell seq 0 ${OBJ_COUNT})
	printf "█\033[0m\033[1;34m"
	$(eval COUNT := $(shell echo ${TOTAL} - ${OBJ_COUNT} | bc))
	printf "%${COUNT}s\033[0m\033[1m" "|"
	$(eval REF := $(shell echo ${OBJ_COUNT} + 1 | bc))
	$(eval PROG := $(shell echo `expr ${REF} '*' 100 / ${TOTAL}` | bc))
	$(if $(filter-out ${PROG},100), printf "[\033[1;2;37m${PROG}%%\033[0m\033[1m]\033[0m", printf "[\033[1;32m${PROG}%%\033[0m\033[1m]\033[0m")
endef

UNAME = $(shell uname)
ifeq ($(UNAME), Darwin)
	CC		=	gcc
	SRC_DIR	=	$(shell find ./srcs -type d)
	OBJ_DIR	=	objs/
	END		=	"\r\033[1;32m$(NAME1) & $(NAME2) are ready \xE2\x9C\x93\033[38;5;222m\xF0\x9F\x91\x8C\033[0m"
	NORMED	=	"\033[1;32mNormed \xE2\x9C\x93\033[38;5;222m\xF0\x9F\x91\x8C\033[0m"
	RUNNING	=	make run
else
	CC		=	clang
	SRC_DIR =	$(shell find ./srcs -type d)
	OBJ_DIR	=	objs_linux/
	END		=	-e '\r\033[1;32m$(NAME1) & $(NAME2) are ready \033[38;5;222m\xF0\x9F\x91\x8C\033[1;32m\xE2\x9C\x93\033[0m'
	NORMED	=	-e '\033[1;32mNormed \033[38;5;222m\xF0\x9F\x91\x8C\033[1;32m\xE2\x9C\x93\033[0m'
	RUNNING	=	echo -en '\033[1;33mmake run\033[0m \033[1;30mfor see all spec of your device\033[0m\n\033[1;2;34mmake norm\033[0m \033[1;30mfor check file with norminette\033[0m\n'
endif

INCLUDE	=	include

SRC_PS	=	push_swap.c utils.c parse_init.c visual.c list.c check_stack.c \
			simple_ope.c rotate_ope.c double_ope.c \
			algo.c algo_ope.c algo_end.c algo_end1.c algo_end2.c algo_end3.c how_much.c \

SRC_CH	=	checker.c utils.c parse_init.c visual.c list.c check_stack.c get_next_line.c \
			simple_ope.c rotate_ope.c double_ope.c \

OBJ_PS	=	$(addprefix $(OBJ_DIR),$(SRC_PS:%.c=%.o))
OBJ_CH	=	$(addprefix $(OBJ_DIR),$(SRC_CH:%.c=%.o))
vpath %.c $(SRC_DIR)

all :	$(NAME1) $(NAME2)

$(NAME1) : $(INCLUDE) $(OBJ_PS)
	@$(CC) $(CFLAGS) $(OBJ_PS) -o $(NAME1)

$(NAME2) : $(INCLUDE) $(OBJ_CH)
	@$(CC) $(CFLAGS) $(OBJ_CH) -o $(NAME2)
	@echo ${END}
	# @$(RUNNING)

$(OBJ_DIR)%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(call Bar)

ifeq ($(UNAME), Darwin)
run :	$(NAME1) $(NAME2)
	@echo "\033c\033[38;5;034m                      ./os\`"
	@echo "\033[38;5;034m                    \`omMMMm"
	@echo "\033[38;5;034m                   /NMMMMM:			\033[38;5;027mOS info: \033[1;30mmacOS (X)Mojave $(shell sw_vers -productVersion) $(shell sw_vers -buildVersion)"
	@echo "\033[38;5;034m                  /MMMMMm:			\033[38;5;027mARCH:\033[1;30m $(shell uname -p ; uname -m)"
	@echo "\033[38;5;034m                  mMMMd/\`			\033[38;5;027mResolution:\033[1;30m$(shell system_profiler SPDisplaysDataType | grep Resolution | cut -d : -f2)"
	@echo "\033[38;5;034m       -/+oo+:.   ++:.-/osso+:.			\033[38;5;027mCPU: \033[1;30m$(shell sysctl -n machdep.cpu.brand_string)"
	@echo "\033[38;5;034m     /hNMMMMMMMMNdyshmMMMMMMMMMMms-		\033[38;5;027mMemory: \033[1;30m$(shell (system_profiler SPHardwareDataType | grep Memory | cut -d : -f2 ; system_profiler SPMemoryDataType | grep Speed | tr -d '\n' | cut -d : -f3 ; system_profiler SPMemoryDataType | grep Type | tr -d '\n' | cut -d : -f3) | sed 's/ //g')"
	@echo "\033[38;5;034m   :mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN/		\033[38;5;027mGPU:\033[1;30m$(shell system_profiler SPDisplaysDataType | grep Chipset | cut -d : -f2)$(shell system_profiler SPDisplaysDataType | grep VRAM | cut -d : -f2)"
	@echo "\033[38;5;226m  oMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNs\`		\033[38;5;027mBash:\033[1;30m $(shell bash --version | tr -d '\n'  | cut -d - -f1 | sed 's/(1)//g')"
	@echo "\033[38;5;226m :MMMMMMMMMMMMMMMMMMMMMMMMMMMMMN-"
	@echo "\033[38;5;226m dMMMMMMMMMMMMMMMMMMMMMMMMMMMMM/		\033[38;5;034m██████╗░██╗░░░██╗░██████╗██╗░░██╗░░░░░░░██████╗░██╗░░░░░░░██╗░█████╗░██████╗░"
	@echo "\033[38;5;208m\`NMMMMMMMMMMMMMMMMMMMMMMMMMMMMM.		\033[38;5;034m██╔══██╗██║░░░██║██╔════╝██║░░██║░░░░░░██╔════╝░██║░░██╗░░██║██╔══██╗██╔══██╗"
	@echo "\033[38;5;208m\`NMMMMMMMMMMMMMMMMMMMMMMMMMMMMM:		\033[38;5;226m██████╔╝██║░░░██║╚█████╗░███████║█████╗╚█████╗░░╚██╗████╗██╔╝███████║██████╔╝"
	@echo "\033[38;5;208m dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd\`		\033[38;5;208m██╔═══╝░██║░░░██║░╚═══██╗██╔══██║╚════╝░╚═══██╗░░████╔═████║░██╔══██║██╔═══╝░"
	@echo "\033[38;5;196m +MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd-		\033[38;5;196m██║░░░░░╚██████╔╝██████╔╝██║░░██║░░░░░░██████╔╝░░╚██╔╝░╚██╔╝░██║░░██║██║░░░░░"
	@echo "\033[38;5;196m  dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh/\`		\033[38;5;129m╚═╝░░░░░░╚═════╝░╚═════╝░╚═╝░░╚═╝░░░░░░╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝╚═╝░░░░░"
	@echo "\033[38;5;196m  -NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMy"
	@echo "\033[38;5;129m   :NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd\`        ..|''||    .|'''.|     '||' '|'"
	@echo "\033[38;5;129m    -mMMMMMMMMMMMMMMMMMMMMMMMMMMMMh\`        .|'    ||   ||..  '       || |"
	@echo "\033[38;5;129m     \`yMMMMMMMMMMMMMMMMMMMMMMMMMN+          ||      ||   ''|||.        ||   \033[38;5;222mCopyright© 42-2021 by \"jmercier\""
	@echo "\033[38;5;038m       :dMMMMMMMMMNNNNMMMMMMMMMy.           '|.     || .     '||      | ||  \033[38;5;231m Mojave "
	@echo "\033[38;5;038m         -shdhy+:``  \`.:oyhhy+.                '||...||  |'....|'     .|   ||.\n"
else
run	:	$(NAME1) $(NAME2)
	@echo "\033c\033[38;5;33m\033[1m              .:oshdmmNmmmdys+-\`"
	@echo "\033[38;5;33m          \`/yNMMMMMMMMMMMMMMMMMMds:"
	@echo "\033[38;5;33m        /hMMMMMMMMMMMMMMMMMMMMMMMMMNs-"
	@echo "\033[38;5;33m      +mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh-		\033[38;5;027mOS info: $(shell uname -o | tr -d '\n' ; inxi -S | grep Distro | cut -d : -f2 | tr -d LTS)"
	@echo "\033[38;5;33m    :mMMMMMMMMMMMMMMMMMMMMMMMmsMMMMMMMMMy\`		\033[38;5;027mARCH: $(shell uname -p)"
	@echo "\033[38;5;33m   oMMMMMMMMMMMMNs+sNMMMMMMMM+/MMMN/+MMMMm-		\033[38;5;7mResolution:\033[1;30m$(shell inxi -G | grep Resolution | cut -d : -f2 | sed 's/@/ /g')"
	@echo "\033[38;5;33m  sMMMMMMMNysmMM:   .MMMMMMMM\`+MMd.-MMMMMMN-		\033[38;5;7mCPU: \033[1;30m$(shell lscpu | grep Nom | cut -d : -f2 | tr -d ' ')"
	@echo "\033[38;5;33m +MMMMMMMM.   sM:    hMMMMMMh hMh\`-NMMMMMMMN.		\033[38;5;124mMemory: \033[1;30m$(shell inxi | grep Mem | cut -d '~' -f6 | tr -d HDD)"
	@echo "\033[38;5;33m\`NMMMMMMMM\`    oy    sMMMMMMs-Mh :NMMMMMMMMMy		\033[38;5;124mGPU:\033[1;30m$(shell inxi -G | grep Card | cut -d : -f3)"
	@echo "\033[38;5;33m+MMMMMMMMMo     /    ./+oyhmmmMosMMMMMMMMMMMM\`		\033[38;5;027mShell/Bash: $(shell bash --version | tr -d '\n'  | cut -d - -f1 | sed 's/(1)//g')"
	@echo "\033[38;5;33mhMMMMMMMMM+                  .:ohNMMMMMMMMMMM/"
	@echo "\033[38;5;33mdMMMMMMMMh                        :dMMMMMMMMM/		\033[1;30m██████╗░██╗░░░██╗░██████╗██╗░░██╗░░░░░░░██████╗░██╗░░░░░░░██╗░█████╗░██████╗░"
	@echo "\033[38;5;33myMMMMMMMM-                          yMMMMMMMM:		\033[1;30m██╔══██╗██║░░░██║██╔════╝██║░░██║░░░░░░██╔════╝░██║░░██╗░░██║██╔══██╗██╔══██╗"
	@echo "\033[38;5;33m+MMMMMMMN                           sMMMMMMMN\`		\033[1;30m██████╔╝██║░░░██║╚█████╗░███████║█████╗╚█████╗░░╚██╗████╗██╔╝███████║██████╔╝"
	@echo "\033[38;5;33m\`mMMMMMMd                         /dMMMMMMMMo		\033[1;30m██╔═══╝░██║░░░██║░╚═══██╗██╔══██║╚════╝░╚═══██╗░░████╔═████║░██╔══██║██╔═══╝░"
	@echo "\033[38;5;33m :MMMMMMm                     \`/yNMMMMMMMMMd		\033[1;30m██║░░░░░╚██████╔╝██████╔╝██║░░██║░░░░░░██████╔╝░░╚██╔╝░╚██╔╝░██║░░██║██║░░░░░"
	@echo "\033[38;5;33m  /MMMMMM+                \`:sdMMMMMMMMMMMMm.		\033[1;30m╚═╝░░░░░░╚═════╝░╚═════╝░╚═╝░░╚═╝░░░░░░╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝╚═╝░░░░░"
	@echo "\033[38;5;33m   -mMMMMMs.         .:+ymMMMMMMMMMMMMMMMh\`"
	@echo "\033[38;5;33m    \`yMMMMMMmhyssyhmNMMMMMMMMMMMMMMMMMMN+"
	@echo "\033[38;5;33m      -hMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNo\`	\ \/ /   _| |__  _   _ _ __ | |_ _   _ "
	@echo "\033[38;5;33m        .smMMMMMMMMMMMMMMMMMMMMMMMMh/\`		 \  / | | | '_ \| | | | '_ \| __| | | |"
	@echo "\033[38;5;33m           -ohNMMMMMMMMMMMMMMMMds/\`		 /  \ |_| | |_) | |_| | | | | |_| |_| |"
	@echo "\033[38;5;33m               \`-/+syyhhyyso/-\`			/_/\_\__,_|_.__/ \__,_|_| |_|\__|\__,_|	\033[38;5;231m$(shell inxi -S | grep Distro | cut -d : -f2 | tr -d LTS)"
	@echo "     							 \033[38;5;30mCopyright© 42-2021 by jmercier\n"
endif

clean :
	@rm -rf $(OBJ_DIR)
	@echo "\033[38;5;129mBinary's objects has cleaned\033[0m";

fclean : clean
	@rm -f $(NAME1) $(NAME2)
	@echo "\033[38;5;038mBinarys has cleanned\033[0m";

norm :
	@printf "\033[1;34m"
	@ruby ~/.norminette/norminette.rb ./include/*
	@ruby ~/.norminette/norminette.rb ./srcs/*
	@echo $(NORMED)

re : fclean all

.PHONY: all clean fclean re run
