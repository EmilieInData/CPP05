NAME = Exception

CC = c++

FLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98 -pedantic -fsanitize=address -fsanitize=leak

HEADER = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.hpp Common.hpp

SRC = 	main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp

OBJDIR = Build

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

DEP = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.d))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp Makefile | $(OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $@

-include $(DEP)

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re
