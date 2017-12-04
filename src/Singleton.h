/**
 * @class utils::Singleton
 *
 * @brief Singleton template class
 *
 * @author Cedric De Schepper
 *
 */
#ifndef GRADIUS_SINGLETON_H
#define GRADIUS_SINGLETON_H


namespace utils {
    template<typename T>
    class Singleton {
    public:
        /**
         * @brief returns Singleton instance and creates one if necessary
         * @return
         */
        static T &get_instance(){
            static T instance;
            return instance;
        }

    protected:
        Singleton() = default;

        ~Singleton() = default;

    public:
        /// deleted so there can't be copies of Singleton
        Singleton(Singleton const &) = delete;

        Singleton& operator=(Singleton const &) = delete;
    };
}


#endif //GRADIUS_SINGLETON_H
