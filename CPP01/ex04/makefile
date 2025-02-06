NAME :=  Sed_is_for_losers
CXX := g++
FLAGS := -Wall -Wextra -Werror -std=c++98 -pedantic

SRCDIR := .
OBJDIR := tmp

SRC := \
	main.cpp \

SRCS := $(addprefix $(SRCDIR)/, $(SRC))

OBJ := $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(FLAGS) -o $@ $^
	@echo "        .▄▄ · ▄▄▄ .·▄▄▄▄         "
	@echo "        ▐█ ▀. ▀▄.▀·██▪ ██        "
	@echo "        ▄▀▀▀█▄▐▀▀▪▄▐█· ▐█▌       "
	@echo "        ▐█▄▪▐█▐█▄▄▌██. ██        "
	@echo "         ▀▀▀▀  ▀▀▀ ▀▀▀▀▀•        "
	@echo "    ▪  .▄▄ ·     ·▄▄▄      ▄▄▄   "
	@echo "    ██ ▐█ ▀.     ▐▄▄·▪     ▀▄ █· "
	@echo "    ▐█·▄▀▀▀█▄    ██▪  ▄█▀▄ ▐▀▀▄  "
	@echo "    ▐█▌▐█▄▪▐█    ██▌.▐█▌.▐▌▐█•█▌ "
	@echo "    ▀▀▀ ▀▀▀▀     ▀▀▀  ▀█▄▀▪.▀  ▀ "
	@echo "▄▄▌        .▄▄ · ▄▄▄ .▄▄▄  .▄▄ · "
	@echo "██•  ▪     ▐█ ▀. ▀▄.▀·▀▄ █·▐█ ▀. "
	@echo "██▪   ▄█▀▄ ▄▀▀▀█▄▐▀▀▪▄▐▀▀▄ ▄▀▀▀█▄"
	@echo "▐█▌▐▌▐█▌.▐▌▐█▄▪▐█▐█▄▄▌▐█•█▌▐█▄▪▐█"
	@echo ".▀▀▀  ▀█▄▀▪ ▀▀▀▀  ▀▀▀ .▀  ▀ ▀▀▀▀ "
	@echo
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
