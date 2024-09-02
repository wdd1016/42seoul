NAME = minishell

CC = cc

CFLAG = -Wall -Wextra -Werror

INC = -I./includes/

UNAME := $(shell uname -s)

ifeq ($(UNAME), Linux)
    R_FLAG = -lreadline
	R_INC = 
else ifeq ($(UNAME), Darwin)
    R_FLAG = -lreadline -L/opt/homebrew/opt/readline/lib
	R_INC = -I/opt/homebrew/opt/readline/include
endif

# 42seoul
# R_FLAG = -lreadline -L${HOME}/.brew/opt/readline/lib
# R_INC = -I${HOME}/.brew/opt/readline/include

RM = rm -f

SRC = main.c \
	./builtin/builtin.c ./builtin/cd.c ./builtin/echo.c \
	./builtin/env.c ./builtin/exit.c ./builtin/export.c \
	./builtin/pwd.c ./builtin/unset.c \
	./execute/command_exception.c ./execute/command.c \
	./execute/double_bar.c ./execute/execute.c ./execute/expansion.c \
	./execute/pipe.c ./execute/redirect.c ./execute/symbol_process.c \
	./execute/wildcard_process.c ./execute/wildcard_util.c \
	./parse/build_tree.c ./parse/env_node.c ./parse/heredoc.c \
	./parse/token_node.c ./parse/token_redirect.c ./parse/token.c \
	./parse/tokenize.c \
	./utils/char_util.c ./utils/env_util.c ./utils/error.c \
	./utils/exit_status.c ./utils/quick_sort.c ./utils/release.c \
	./utils/signal_handler.c ./utils/signal.c ./utils/split_util.c \
	./utils/string_util1.c ./utils/string_util2.c ./utils/string_util3.c \
	./utils/wrapper_directory.c ./utils/wrapper_util.c

SRC_DIR = ./srcs/
BONUS_DIR = ./bonus/

OBJS = $(SRCS:.c=.o)
SRCS = $(addprefix $(SRC_DIR), $(SRC))


all : $(NAME)

bonus : $(NAME)

.c.o:
	@$(CC) $(CFLAG) $(INC) $(R_INC) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAG) $^ $(R_FLAG) -o $@
	@printf	"Get Ready for the Minishell\n"

clean :
	@$(RM) $(OBJS)
	@printf	"Run to Clean\n"

fclean :
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@printf	"Run to fClean\n"

re : fclean all

.PHONY : all clean fclean re