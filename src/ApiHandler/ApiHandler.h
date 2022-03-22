#ifndef __APIHANDLER_H__
#define __APIHANDLER_H__

#include <type_traits>
#include <iostream>
#include <memory>

#include "responses/Response.h"
#include "requests/Request.h"


/**
 * This is tha main class used to make api calls.
 * This class is designed to make http requests and wait a specific answer.
 *
 * For each call made (get, delete, post, etc.), you must provide the expected object to map
 * response in. If an error is recevied, an instance of ApiErrorException will be thrown
 * 
 * @author Aldric Vitali Silvestre
 */
class ApiHandler
{
private:
    std::string rootUrl;
public:
    ApiHandler(std::string rootUrl);
    ~ApiHandler();

    void get(std::string path, Response& response);

    // template <typename R, std::enable_if_t<std::is_base_of_v<Response, R>>, R>
    // std::unique_ptr<R> post(std::string path, Request& request);

    // template <typename R, std::enable_if_t<std::is_base_of_v<Response, R>>, R>
    // std::unique_ptr<R> put(std::string path, Request& request);

    // template <typename R, std::enable_if_t<std::is_base_of_v<Response, R>>, R>
    // std::unique_ptr<R> patch(std::string path, Request& request);

    // template <typename R, std::enable_if_t<std::is_base_of_v<Response, R>>, R>
    // std::unique_ptr<R> del(std::string path);
};

#endif // __APIHANDLER_H__