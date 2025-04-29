NAME = Exception

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -fsanitize=address -fsanitize=leak

SRC = 	main.cpp \
		Bureaucrat.cpp

OBJDIR = Build

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

all: $(OBJDIR)/$(NAME)

$(OBJDIR)/$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp Makefile | $(OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re
