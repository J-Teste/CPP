NAME := Account
CXX := c++
FLAGS := -Wall -Wextra -Werror -std=c++98 -pedantic
SRCDIR := ./src
OBJDIR := obj
SRC := $(wildcard $(SRCDIR)/*.cpp)
OBJ := $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(FLAGS) -o $@ $^
	@echo "	_________   _________"
	@echo "   ____/      420\ /     421 \____"
	@echo " /| ------------- |  ------------ |\ "
	@echo "||| ------------- | ------------- |||"
	@echo "||| -no money---- | ------------- |||"
	@echo "||| ------- ----- | ------------- |||"
	@echo "||| ------------- | ------------- |||"
	@echo "||| ------------- | ---no money-- |||"
	@echo "|||  ------------ | ----------    |||"
	@echo "||| ------------- |  ------------ |||"
	@echo "||| --no money--- | ------------- |||"
	@echo "||| ------------- | ------ -----  |||"
	@echo "||| ------------  | ------------- |||"
	@echo "|||_____________  |  _____________|||"
	@echo "||/_____/--------\\_//--------\____\||"
	@echo "🎉✨ Build Complete! ✨🎉"
	@echo "🚀 $(NAME) is ready to roll, compiled with: 🔧 $(FLAGS) 🔧"


$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@$(CXX) $(FLAGS) -c $< -o $@

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
