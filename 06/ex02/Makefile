# **************************************************************************** #
#                                    Colors                                    #
# **************************************************************************** #

C_STD		= \033[0;39m
C_GRAY		= \033[0;90m
C_RED		= \033[0;91m
C_GREEN		= \033[0;92m
C_YELLOW	= \033[0;93m
C_BLUE		= \033[0;94m
C_MAGENTA	= \033[0;95m
C_CYAN		= \033[0;96m
C_WHITE		= \033[0;97m

# **************************************************************************** #
#                                    Names                                     #
# **************************************************************************** #

NAME		= exec

# **************************************************************************** #
#                                    Path's                                    #
# **************************************************************************** #

SRC_PATH	= src/
BUILD_PATH	= .build/
INC_PATH	= include/

VPATH		= .

# **************************************************************************** #
#                                    Files                                     #
# **************************************************************************** #

FILES		+= main
FILES		+= Base
FILES		+= aux

SRCS		= $(addprefix ./, $(addsuffix .cpp, $(FILES)))
OBJS		= $(addprefix $(BUILD_PATH), $(addsuffix .o, $(FILES)))
DEPS		= $(addprefix $(BUILD_PATH), $(addsuffix .d, $(FILES)))

# **************************************************************************** #
#                                  Compiler                                    #
# **************************************************************************** #

VERSION		= -std=c++98
CC			= c++ $(VERSION)
CFLAGS		= -Wall -Wextra -Werror
IFLAGS		= -MMD -I$(INC_PATH)
MAKE		= make --no-print-directory
RM			= rm -rf

# **************************************************************************** #
#                                    Comands                                   #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(BUILD_PATH) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "\r$(C_YELLOW)[%s] Files compiled $(C_STD)%-30s\n" $$(echo $(OBJS) | wc -w) " "
	@printf "$(C_MAGENTA)✔ Build finished: $(NAME)$(C_STD)\n"

$(BUILD_PATH)%.o: %.cpp
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@printf "\r$(C_YELLOW)[CC] %-60s$(C_STD)" "$<"

$(BUILD_PATH):
	@mkdir -p $(BUILD_PATH)

-include $(DEPS)

clean:
	@$(RM) $(BUILD_PATH)
	@$(RM) *_shrubbery


fclean: clean
	@$(RM) $(NAME)

re: fclean all
