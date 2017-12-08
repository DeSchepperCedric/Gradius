

#ifndef GRADIUS_EXCEPTIONS_H
#define GRADIUS_EXCEPTIONS_H


#include <exception>
#include <string>

namespace exceptions {

    class TextureException : public std::exception {
    private:
        std::string message;

    public:
        TextureException(const std::string &file_name){
            message = "Cant' open texture file: " + file_name;
        }

        const char *what() const throw() override {
            return message.c_str();
        }
    };

}


#endif //GRADIUS_EXCEPTIONS_H
