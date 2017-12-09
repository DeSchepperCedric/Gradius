

#ifndef GRADIUS_EXCEPTIONS_H
#define GRADIUS_EXCEPTIONS_H

#include <exception>
#include <string>

namespace exceptions {

    /**
     * @class CustomMessageException
     * @brief handles exceptions with a message
     */
    class CustomMessageException: public std::exception {
    private:
        std::string message;

    public:
        explicit CustomMessageException(const std::string& message) : message(message) {}

        const char *what() const throw() override {
            return message.c_str();
        }
    };

    /**
     * @class TextureFileException
     * @brief handles exception when texture file can't be found
     */
    class TextureFileException : public CustomMessageException{

    public:
        explicit TextureFileException(const std::string &file_name) :
                CustomMessageException("Cant' open texture file: " + file_name) {}
    };

    /**
     * @class TextureKeyException
     * @brief handles exception when key in texture map doesn't exist
     */
    class TextureKeyException : public CustomMessageException {
    public:
        explicit TextureKeyException(const std::string &key) : CustomMessageException("No texture with key: " + key) {}

    };



}


#endif //GRADIUS_EXCEPTIONS_H
