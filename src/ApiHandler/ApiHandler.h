#ifndef __APIHANDLER_H__
#define __APIHANDLER_H__

#include <type_traits>
#include <iostream>

#include "responses/Response.h"

/**
 * This is tha main class used to make api calls 
 */
class ApiHandler
{
private:
    /* data */
public:
    ApiHandler() {};
    ~ApiHandler() {};

    // This template (or generic in Java), assures that the class passed is a subclass of Response
    template <typename R, typename = std::enable_if_t<std::is_base_of_v<Response, R>>>
    R testFunc()
    {
        std::cout << "this is the response" << std::endl;
        R *r = new R();
        r->userId = 1;
        r->id = 2;
        r->title = "3";
        r->completed = false;
        return *r;
    }
};

#endif // __APIHANDLER_H__