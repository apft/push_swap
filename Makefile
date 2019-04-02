# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apion <apion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 11:28:44 by apion             #+#    #+#              #
#    Updated: 2019/04/02 14:15:10 by apion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		:= /bin/sh
RM			:= /bin/rm
CC			:= gcc
ifndef NOERR
CFLAGS		:= -Wall -Wextra -Werror
endif
CINCLUDES	= $(addprefix -I, $(H_DIR))
CPPFLAGS	= -MMD -MP -MF $(O_DIR)/$*.d

# --- LIBS ---
LIBFT_PATH		:= libft
LIBFT			:= $(LIBFT_PATH)/libft.a
FT_PRINTF_PATH	:= ft_printf
FT_PRINTF		:= $(FT_PRINTF_PATH)/libftprintf.a

NAME		:= both
CHECKER		:= checker
PUSH_SWAP	:= push_swap

CHECKER_FILES		= checker.c $(C_FILES)
CHECKER_O_FILES		= $(CHECKER_FILES:%.c=%.o)
CHECKER_D_FILES		= $(CHECKER_FILES:%.c=%.d)
PUSH_SWAP_FILES		= push_swap.c $(C_FILES)
PUSH_SWAP_O_FILES	= $(PUSH_SWAP_FILES:%.c=%.o)
PUSH_SWAP_D_FILES	= $(PUSH_SWAP_FILES:%.c=%.d)

C_DIR		:= srcs
H_DIR		:= incs $(LIBFT_PATH) $(FT_PRINTF_PATH)
O_DIR		:= .obj
C_FILES		:= \
	srcs/get_next_line.c \
	srcs/stack_del.c \
	srcs/stack_print.c \
	srcs/stack_push.c \
	srcs/stack_rotate.c \
	srcs/stack_swap.c
O_TREE		= $(shell find $(O_DIR) -type d -print 2> /dev/null | tail -r)

.SECONDEXPANSION:

.PHONY: all
all: $(NAME)

$(NAME): $(CHECKER) $(PUSH_SWAP)

$(LIBFT) $(FT_PRINTF): .FORCE
	@echo "Compiling $@..."
	@$(MAKE) -C $(@D)

$(CHECKER): $(addprefix $(O_DIR)/, $(CHECKER_O_FILES)) $(LIBFT) $(FT_PRINTF)
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) $(CINCLUDES) -o $@ $^
	@echo "Done."

$(PUSH_SWAP): $(addprefix $(O_DIR)/, $(PUSH_SWAP_O_FILES)) $(LIBFT) $(FT_PRINTF)
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) $(CINCLUDES) -o $@ $^
	@echo "Done."

$(O_DIR)/%.o: %.c
$(O_DIR)/%.o: %.c $(O_DIR)/%.d | $$(@D)/.
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -o $@ -c $<

.PRECIOUS: $(O_DIR)/. $(O_DIR)%/.
$(O_DIR)/. $(O_DIR)%/.:
	@echo "Creating directory $@..."
	@mkdir -p $@

.PRECIOUS: %.d
%.d: ;

.PHONY: clean
clean:
	@echo "Cleaning object files..."
	@-$(RM) $(addprefix $(O_DIR)/, $(CHECKER_O_FILES)) 2> /dev/null
	@-$(RM) $(addprefix $(O_DIR)/, $(PUSH_SWAP_O_FILES)) 2> /dev/null
	@echo "Cleaning dependencies files..."
	@-$(RM) $(addprefix $(O_DIR)/, $(CHECKER_D_FILES)) 2> /dev/null
	@-$(RM) $(addprefix $(O_DIR)/, $(PUSH_SWAP_D_FILES)) 2> /dev/null
	@echo "Removing $(O_DIR) tree..."
	@-echo $(O_TREE) | xargs rmdir 2> /dev/null
	@[ -d $(O_DIR) ] \
		&& echo "Could not remove $(O_DIR) tree." \
		|| echo "Successfully clean."

.PHONY: fclean
fclean: clean
	@echo "Removing file $(NAME)..."
	@-$(RM) $(NAME) 2> /dev/null
	@[ -f $(NAME) ] \
		&& echo "Could not remove $(NAME) file." \
		|| echo "Successfully clean."

.PHONY: re
re: fclean all

.FORCE:

-include $(addprefix $(O_DIR)/, $(CHECKER_D_FILES))
-include $(addprefix $(O_DIR)/, $(PUSH_SWAP_D_FILES))