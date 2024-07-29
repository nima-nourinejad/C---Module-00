NAME = phonebook
CXX = c++
RM = rm -f
CXXFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp \
	   Contact.cpp \
	   PhoneBook.cpp \
		
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean fclean re c98

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) -o $@

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

c98: CXXFLAGS += -std=c++98
c98: re
