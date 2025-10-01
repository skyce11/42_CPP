#include <iostream>
#include <cctype>


int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } else {
        for (int i = 1; i < argc; ++i) {
            if (i > 1)
                std::cout << " ";
            std::string arg = argv[i];
            for (size_t j = 0; j < arg.length(); ++j) {
                std::cout << (char)std::toupper(arg[j]);
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
