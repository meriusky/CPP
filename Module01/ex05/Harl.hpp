#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
        void (Harl::*_ptr[4])(void);// array of pointers to the member function
        std::string _levels[4];//array of strings
    public:
        Harl();
        ~Harl();
        void complain(std::string);

};

#endif
