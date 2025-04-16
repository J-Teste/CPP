NAME := convert
CXX := c++
CXXFLAGS := -std=c++98 -Wall -Wextra -Werror -g 

SRCDIR := ./src
OBJDIR := tmp

SRC := \
	main.cpp \
	ScalarConverter.cpp



SRCS := $(addprefix $(SRCDIR)/, $(SRC))

OBJ := $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "🎉✨ Build Complete! ✨🎉"
	@echo "🚀 $(NAME) is ready to roll, compiled with: 🔧 $(CXXFLAGS) 🔧"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	@echo "🧹 Cleaning up..."
	@echo "🗑️  Object files have been swept away!"


fclean: clean
	@rm -f $(NAME)
	@echo "💣 Full cleanup in progress..."
	@echo "💀 $(NAME) has been OBLITERATED!"


re: fclean all

.PHONY: all clean fclean re
