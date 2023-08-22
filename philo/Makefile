NAME = philo

C_BLUE  = \033[0;34m
C_CYAN  = \033[0;36m
C_RESET = \033[0m

CC      = cc

RM      = rm -rf

CFLAGS  = -Wall -Wextra -Werror -pthread

HEADER  = include/philo.h

O_DIR   := OBJ_DER

M_SRCS = philo.c \
    philo_utils/ft_atoi.c \
    philo_utils/ft_calloc.c \
    philo_utils/get_time.c \
    philo_utils/ft_error.c \
    philo_utils/print_str.c \
    philo_utils/is_all_digit.c \
    philo_utils/ft_lstadd_back.c\
    handling/philo_fin.c \
    handling/philo_eating.c \
    handling/philo_take_forks.c \
    handling/philo_puts_forks.c \
    handling/philo_sleep_think.c \
    handling/routine_ph.c \
    src/check_arg.c \
    src/get_args.c \
    src/init_philo.c

M_OBJS = $(patsubst %.c,$(O_DIR)/%.o,$(M_SRCS))

all: $(NAME)

$(NAME): $(M_OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(M_OBJS) -o $(NAME)
	@printf "$(C_BLUE)    - Compilation Mandatory finished!....$(C_RESET)\n"

$(O_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(O_DIR)
	@printf "$(C_CYAN)    - Removed Object Directory finished!....$(C_RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(C_CYAN)    - Removed executable finished!....$(C_RESET)\n"

re: fclean all

.PHONY: all clean fclean re
