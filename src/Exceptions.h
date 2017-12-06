

#ifndef GRADIUS_EXCEPTIONS_H
#define GRADIUS_EXCEPTIONS_H


#include <exception>

namespace exceptions {

    class TextureException : public std::exception {
        const char *what() const throw() override {
            return "Texture failure";
        }
    };

}


#endif //GRADIUS_EXCEPTIONS_H
