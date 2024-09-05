NAME = phonebook
CXX = c++
RM = rm -f
CXXFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp \
	   Contact.cpp \
	   PhoneBook.cpp \
		
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean fclean re c11 test rmtest

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

c11: CXXFLAGS += -std=c++11
c11: re

TEST = test
TSRC = test.cpp
test: $(TSRC)
	@$(CXX) $(CXXFLAGS) $(TSRC) -o $(TEST)

rmtest:
	@$(RM) $(TEST)
