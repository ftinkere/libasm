# Name
NAME			=	libasm.a
NAME_H			=	$(NAME:.a=.h)
HEADERS			=	$(NAME_H)

# External tools
SHELL			=	/bin/sh
CC				=	nasm
AR				=	ar
RANLIB			=	ranlib

CFLAGS			= -f elf64
ARFLAGS			= -rc

# Dirs
SRCS_DIR	= srcs
OBJS_DIR	= objs

# Sources
SOURCES_RAW		= \
	ft_strlen \
	ft_strcpy \
	ft_strcmp \
	ft_write \
	ft_read \
	ft_strdup

SOURCES_C		=	$(addsuffix .c, $(SOURCE_RAW))
SOURCES			= $(addprefix $(SRCS_DIR)/, $(SOURCES_C))

OBJS_O			=	$(addsuffix .o, $(SOURCES_RAW))
OBJS			= $(addprefix $(OBJS_DIR)/, $(OBJS_O))


all: $(NAME)

allc: all clean

bonus: all

fclean: clean
	rm -f $(NAME)
	@echo -e "\x1b[38;5;3m""FCleaned""\x1b[0m"

clean:
	-rm -rf $(OBJS_DIR)
	@echo -e "\x1b[38;5;3m""Cleaned""\x1b[0m"

re: fclean all

beep:
	@echo -e "\07"

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)
	@echo -e "\x1b[38;5;6m""Maked $@""\x1b[0m"

$(OBJS): $(OBJS_DIR)/%.o: $(SRCS_DIR)/%.s $(NAME_H) | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(SRCS_DIR)/$*.s -o $(OBJS_DIR)/$*.o
	@echo -e "\x1b[38;5;2m""Compiled $*"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)