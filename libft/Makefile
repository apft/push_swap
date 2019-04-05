# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apion <apion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 11:28:44 by apion             #+#    #+#              #
#    Updated: 2019/04/05 12:36:28 by apion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		:= /bin/sh
RM			:= /bin/rm
CC			:= gcc
ifndef NOERR
CFLAGS		:= -Wall -Wextra -Werror
endif
CINCLUDES	= $(addprefix -I, $(H_DIR))
CPPFLAGS	= -MMD -MP -MF $(D_DIR)/$*.d

NAME		:= libft.a
C_DIR		:= srcs
H_DIR		:= incs
O_DIR		:= .obj
D_DIR		:= $(O_DIR)
C_FILES		:= \
	srcs/bitwise/ft_bw_count_bits.c \
	srcs/char/ft_isalnum.c \
	srcs/char/ft_isalpha.c \
	srcs/char/ft_isascii.c \
	srcs/char/ft_isdigit.c \
	srcs/char/ft_islowc.c \
	srcs/char/ft_isprint.c \
	srcs/char/ft_issign.c \
	srcs/char/ft_isspace.c \
	srcs/char/ft_isuppc.c \
	srcs/char/ft_tolower.c \
	srcs/char/ft_toupper.c \
	srcs/ft_atoi.c \
	srcs/ft_istype_str.c \
	srcs/ft_itoa.c \
	srcs/ft_print_mem.c \
	srcs/ft_swap.c \
	srcs/list/ft_lstadd.c \
	srcs/list/ft_lstdel.c \
	srcs/list/ft_lstdelone.c \
	srcs/list/ft_lstiter.c \
	srcs/list/ft_lstmap.c \
	srcs/list/ft_lstnew.c \
	srcs/mem/ft_bzero.c \
	srcs/mem/ft_memalloc.c \
	srcs/mem/ft_memccpy.c \
	srcs/mem/ft_memchr.c \
	srcs/mem/ft_memcmp.c \
	srcs/mem/ft_memcpy.c \
	srcs/mem/ft_memdel.c \
	srcs/mem/ft_memmove.c \
	srcs/mem/ft_memset.c \
	srcs/output/ft_putchar.c \
	srcs/output/ft_putchar_fd.c \
	srcs/output/ft_putendl.c \
	srcs/output/ft_putendl_fd.c \
	srcs/output/ft_putnbr.c \
	srcs/output/ft_putnbr_base.c \
	srcs/output/ft_putnbr_fd.c \
	srcs/output/ft_putnbr_hex.c \
	srcs/output/ft_putstr.c \
	srcs/output/ft_putstr_fd.c \
	srcs/str/ft_strcat.c \
	srcs/str/ft_strchr.c \
	srcs/str/ft_strclr.c \
	srcs/str/ft_strcmp.c \
	srcs/str/ft_strcpy.c \
	srcs/str/ft_strdel.c \
	srcs/str/ft_strdup.c \
	srcs/str/ft_strequ.c \
	srcs/str/ft_stricmp.c \
	srcs/str/ft_striter.c \
	srcs/str/ft_striteri.c \
	srcs/str/ft_strjoin.c \
	srcs/str/ft_strlcat.c \
	srcs/str/ft_strlen.c \
	srcs/str/ft_strmap.c \
	srcs/str/ft_strmapi.c \
	srcs/str/ft_strncat.c \
	srcs/str/ft_strncmp.c \
	srcs/str/ft_strncpy.c \
	srcs/str/ft_strnequ.c \
	srcs/str/ft_strnew.c \
	srcs/str/ft_strnicmp.c \
	srcs/str/ft_strnstr.c \
	srcs/str/ft_strrchr.c \
	srcs/str/ft_strrev.c \
	srcs/str/ft_strsplit.c \
	srcs/str/ft_strstr.c \
	srcs/str/ft_strsub.c \
	srcs/str/ft_strtrim.c
O_FILES		:= $(C_FILES:%.c=%.o)
D_FILES		:= $(C_FILES:%.c=%.d)
O_TREE		= $(shell find $(O_DIR) -type d -print 2> /dev/null | tail -r)

.SECONDEXPANSION:

.PHONY: all
all: $(NAME)

$(NAME): $(addprefix $(O_DIR)/, $(O_FILES))
	@echo "Compiling library $@..."
	@$(AR) rsc $@ $?
	@echo "Done."

$(O_DIR)/%.o: %.c
$(O_DIR)/%.o: %.c $(D_DIR)/%.d | $$(@D)/.
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
	@-$(RM) $(addprefix $(O_DIR)/, $(O_FILES)) 2> /dev/null
	@echo "Cleaning dependencies files..."
	@-$(RM) $(addprefix $(D_DIR)/, $(D_FILES)) 2> /dev/null
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

-include $(addprefix $(D_DIR)/, $(D_FILES))
