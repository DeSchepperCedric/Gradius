//
// Created by Cedric De Schepper on 27/11/17.
//

#ifndef GRADIUS_SINGLETON_H
#define GRADIUS_SINGLETON_H


namespace utils {
    template<typename T>
    class Singleton {
    public:
        static T &get_instance(){
            static T instance;
            return instance;
        }

    protected:
        Singleton() = default;

        ~Singleton() = default;

    public:
        Singleton(Singleton const &) = delete;

        Singleton& operator=(Singleton const &) = delete;
    };
}


#endif //GRADIUS_SINGLETON_H
