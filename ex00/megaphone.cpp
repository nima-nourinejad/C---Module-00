#include <cctype>
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int index = 1; index < argc; index++)
		{
			std::string str = argv[index];
			int len = static_cast<int>(str.length());
			for (int i; i < len; i++)
			{
				char c = static_cast<unsigned char>(str[i]);
				c = std::toupper(c);
				std::cout << c;
			}
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}