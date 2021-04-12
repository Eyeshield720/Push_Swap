NAME1	=	push_swap
NAME2	=	checker

CFLAGS	= -Werror -Wextra -Wall -I./include
CFLAGS	+= -fsanitize=address
CFLAGS	+= -g3

UNAME = $(shell uname)
ifeq ("$(UNAME)", Darwin)
	CC		=	gcc
	SRC_DIR	=	$(shell find ./srcs -type d)
	OBJ_DIR	=	objs/
	CFLAGS	+=	-D APPLE
else
	CC		=	clang
	SRC_DIR =	$(shell find ./srcs -type d)
	OBJ_DIR	=	objs_linux/

endif

INCLUDE	=	include

SRC_PS	=	push_swap.c utils.c parse_init.c visual.c list.c simple_ope.c rotate_ope.c double_ope.c \
			check_stack.c algo.c algo_ope.c \

SRC_CH	=	checker.c

OBJ_PS	=	$(addprefix $(OBJ_DIR),$(SRC_PS:%.c=%.o))
OBJ_CH	=	$(addprefix $(OBJ_DIR),$(SRC_CH:%.c=%.o))
vpath %.c $(SRC_DIR)

all :	$(NAME1) $(NAME2)

$(NAME1) : $(INCLUDE) $(OBJ_PS)
	$(CC) $(CFLAGS) $(OBJ_PS) -o $(NAME1)

$(NAME2) : $(INCLUDE) $(OBJ_CH)
	$(CC) $(CFLAGS) $(OBJ_CH) -o $(NAME2)

$(OBJ_DIR)%.o : %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# $(LIBS)	:
# 	@make -C ./Printf/

# ifeq ("$(UNAME)", Darwin)
# run :	$(NAME)
# 	@echo "\033c\033[38;5;034m                      ./os\`"
# 	@echo "\033[38;5;034m                    \`omMMMm"
# 	@echo "\033[38;5;034m                   /NMMMMM:			\033[38;5;027mOS info: \033[1;30mmacOS (X)Mojave $(shell sw_vers -productVersion) $(shell sw_vers -buildVersion)"
# 	@echo "\033[38;5;034m                  /MMMMMm:			\033[38;5;027mARCH:\033[1;30m $(shell uname -p ; uname -m)"
# 	@echo "\033[38;5;034m                  mMMMd/\`			\033[38;5;027mResolution:\033[1;30m$(shell system_profiler SPDisplaysDataType | grep Resolution | cut -d : -f2)"
# 	@echo "\033[38;5;034m       -/+oo+:.   ++:.-/osso+:.			\033[38;5;027mCPU: \033[1;30m$(shell sysctl -n machdep.cpu.brand_string)"
# 	@echo "\033[38;5;034m     /hNMMMMMMMMNdyshmMMMMMMMMMMms-		\033[38;5;027mMemory: \033[1;30m$(shell (system_profiler SPHardwareDataType | grep Memory | cut -d : -f2 ; system_profiler SPMemoryDataType | grep Speed | tr -d '\n' | cut -d : -f3 ; system_profiler SPMemoryDataType | grep Type | tr -d '\n' | cut -d : -f3) | sed 's/ //g')"
# 	@echo "\033[38;5;034m   :mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN/		\033[38;5;027mGPU:\033[1;30m$(shell system_profiler SPDisplaysDataType | grep Chipset | cut -d : -f2)$(shell system_profiler SPDisplaysDataType | grep VRAM | cut -d : -f2)"
# 	@echo "\033[38;5;226m  oMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNs\`		\033[38;5;027mBash:\033[1;30m $(shell bash --version | tr -d '\n'  | cut -d - -f1 | sed 's/(1)//g')"
# 	@echo "\033[38;5;226m :MMMMMMMMMMMMMMMMMMMMMMMMMMMMMN-"
# 	@echo "\033[38;5;226m dMMMMMMMMMMMMMMMMMMMMMMMMMMMMM/"
# 	@echo "\033[38;5;208m\`NMMMMMMMMMMMMMMMMMMMMMMMMMMMMM.		\033[38;5;034m███    ███ ██ ███    ██ ██ ███████ ██   ██ ███████ ██      ██"
# 	@echo "\033[38;5;208m\`NMMMMMMMMMMMMMMMMMMMMMMMMMMMMM:		\033[38;5;226m████  ████ ██ ████   ██ ██ ██      ██   ██ ██      ██      ██"
# 	@echo "\033[38;5;208m dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd\`		\033[38;5;208m██ ████ ██ ██ ██ ██  ██ ██ ███████ ███████ █████   ██      ██"
# 	@echo "\033[38;5;196m +MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd-		\033[38;5;196m██  ██  ██ ██ ██  ██ ██ ██      ██ ██   ██ ██      ██      ██"
# 	@echo "\033[38;5;196m  dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh/\`		\033[38;5;129m██      ██ ██ ██   ████ ██ ███████ ██   ██ ███████ ███████ ███████"
# 	@echo "\033[38;5;196m  -NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMy"
# 	@echo "\033[38;5;129m   :NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd\`        ..|''||    .|'''.|     '||' '|'"
# 	@echo "\033[38;5;129m    -mMMMMMMMMMMMMMMMMMMMMMMMMMMMMh\`        .|'    ||   ||..  '       || |"
# 	@echo "\033[38;5;129m     \`yMMMMMMMMMMMMMMMMMMMMMMMMMN+          ||      ||   ''|||.        ||   \033[38;5;222mCopyright© 42-2020 by \"Shellori\""
# 	@echo "\033[38;5;038m       :dMMMMMMMMMNNNNMMMMMMMMMy.           '|.     || .     '||      | ||  \033[38;5;231m Mojave "
# 	@echo "\033[38;5;038m         -shdhy+:``  \`.:oyhhy+.                '||...||  |'....|'     .|   ||.\n"
# else
# run	:	$(NAME)
# 	@echo "\033c\033[38;5;33m\033[1m              .:oshdmmNmmmdys+-\`"
# 	@echo "\033[38;5;33m          \`/yNMMMMMMMMMMMMMMMMMMds:"
# 	@echo "\033[38;5;33m        /hMMMMMMMMMMMMMMMMMMMMMMMMMNs-"
# 	@echo "\033[38;5;33m      +mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh-		\033[38;5;7mOS info: \033[38;5;124m$(shell uname -o | tr -d '\n' ; inxi -S | grep Distro | cut -d : -f2 | tr -d LTS)"
# 	@echo "\033[38;5;33m    :mMMMMMMMMMMMMMMMMMMMMMMMmsMMMMMMMMMy\`		\033[38;5;7mARCH: \033[38;5;124m$(shell uname -p)"
# 	@echo "\033[38;5;33m   oMMMMMMMMMMMMNs+sNMMMMMMMM+/MMMN/+MMMMm-		\033[38;5;7mResolution: \033[38;5;124m$(shell inxi -G | grep Resolution | cut -d : -f2 | sed 's/@/ /g')"
# 	@echo "\033[38;5;33m  sMMMMMMMNysmMM:   .MMMMMMMM\`+MMd.-MMMMMMN-		\033[38;5;7mCPU: \033[38;5;124m$(shell lscpu | grep Nom | cut -d : -f2 | tr -d ' ')"
# 	@echo "\033[38;5;33m +MMMMMMMM.   sM:    hMMMMMMh hMh\`-NMMMMMMMN.		\033[38;5;7mMemory: \033[38;5;124mUnknow"
# 	@echo "\033[38;5;33m\`NMMMMMMMM\`    oy    sMMMMMMs-Mh :NMMMMMMMMMy		\033[38;5;7mGPU:\033[38;5;124m$(shell inxi -G | grep Card | cut -d : -f3)"
# 	@echo "\033[38;5;33m+MMMMMMMMMo     /    ./+oyhmmmMosMMMMMMMMMMMM\`		\033[38;5;7mShell/Bash: $(shell bash --version | tr -d '\n'  | cut -d - -f1 | sed 's/(1)//g')"
# 	@echo "\033[38;5;33mhMMMMMMMMM+                  .:ohNMMMMMMMMMMM/"
# 	@echo "\033[38;5;33mdMMMMMMMMh                        :dMMMMMMMMM/"
# 	@echo "\033[38;5;33myMMMMMMMM-                          yMMMMMMMM:		\033[1;30m███    ███ ██ ███    ██ ██ ███████ ██   ██ ███████ ██      ██"
# 	@echo "\033[38;5;33m+MMMMMMMN                           sMMMMMMMN\`		\033[1;30m████  ████ ██ ████   ██ ██ ██      ██   ██ ██      ██      ██"
# 	@echo "\033[38;5;33m\`mMMMMMMd                         /dMMMMMMMMo		\033[1;30m██ ████ ██ ██ ██ ██  ██ ██ ███████ ███████ █████   ██      ██"
# 	@echo "\033[38;5;33m :MMMMMMm                     \`/yNMMMMMMMMMd		\033[1;30m██  ██  ██ ██ ██  ██ ██ ██      ██ ██   ██ ██      ██      ██"
# 	@echo "\033[38;5;33m  /MMMMMM+                \`:sdMMMMMMMMMMMMm.		\033[1;30m██      ██ ██ ██   ████ ██ ███████ ██   ██ ███████ ███████ ███████"
# 	@echo "\033[38;5;33m   -mMMMMMs.         .:+ymMMMMMMMMMMMMMMMh\`"
# 	@echo "\033[38;5;33m    \`yMMMMMMmhyssyhmNMMMMMMMMMMMMMMMMMMN+"
# 	@echo "\033[38;5;33m      -hMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNo\`	\ \/ /   _| |__  _   _ _ __ | |_ _   _ "
# 	@echo "\033[38;5;33m        .smMMMMMMMMMMMMMMMMMMMMMMMMh/\`		 \  / | | | '_ \| | | | '_ \| __| | | |"
# 	@echo "\033[38;5;33m           -ohNMMMMMMMMMMMMMMMMds/\`		 /  \ |_| | |_) | |_| | | | | |_| |_| |"
# 	@echo "\033[38;5;33m               \`-/+syyhhyyso/-\`			/_/\_\__,_|_.__/ \__,_|_| |_|\__|\__,_|	\033[38;5;231m$(shell inxi -S | grep Distro | cut -d : -f2 | tr -d LTS)"
# 	@echo "     							 \033[38;5;30mCopyright© 42-2020 by Shellori\n"
# endif

clean :
	rm -rf $(OBJ_DIR)
	@rm -f *_out

fclean : clean
	@make fclean -C ./Printf/
	rm -f $(NAME1) $(NAME2)

re : fclean all

# norm :
# 	norminette include/*.h
# 	norminette srcs/utils/*.c
# 	norminette srcs/*.c

.PHONY: all clean fclean re #run norm