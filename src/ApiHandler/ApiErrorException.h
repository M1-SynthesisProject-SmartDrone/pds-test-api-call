#ifndef __APIERROREXCEPTION_H__
#define __APIERROREXCEPTION_H__

#include <sstream>
#include <exception>

struct ApiErrorException : public std::exception
{
    std::string type;
    int16_t status;
    std::string detail;

    ApiErrorException(std::string type, int16_t status, std::string detail)
    {
        this->type = type;
        this->detail = detail;
        this->status = status;
    }

    const char* what() const throw()
    {
        std::stringstream ss;
        ss << "Error " << this->status << " of type \"" << this->type
            << "\" : " << this->detail;
        return ss.str().c_str();
    }
};

#endif // __APIERROREXCEPTION_H__