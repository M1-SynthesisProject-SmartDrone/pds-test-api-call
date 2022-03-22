#include "ApiHandler.h"

#include <cpr/cpr.h>


using namespace std;

ApiHandler::ApiHandler(string rootUrl) : rootUrl(rootUrl)
{

}

ApiHandler::~ApiHandler()
{

}

void ApiHandler::get(std::string path, Response& response)
{
    auto apiResponse = cpr::Get(cpr::Url(rootUrl + path));
    response.deserialize(apiResponse.text);
}

// template <typename R, std::enable_if_t<std::is_base_of_v<Response, R>>, R>
// unique_ptr<R> ApiHandler::post(string path, Request& request)
// {

// }

// template <typename R, std::enable_if_t<std::is_base_of_v<Response, R>>, R>
// unique_ptr<R> ApiHandler::put(string path, Request& request)
// {

// }

// template <typename R, std::enable_if_t<std::is_base_of_v<Response, R>>, R>
// unique_ptr<R> ApiHandler::patch(string path, Request& request)
// {

// }

// template <typename R, std::enable_if_t<std::is_base_of_v<Response, R>>, R>
// unique_ptr<R> ApiHandler::del(string path)
// {
//     auto apiResponse = cpr::Delete(cpr::Url(rootUrl + path));
//     auto response = make_unique<R>();
//     response->deserialize(apiResponse.text);
//     return move(response);
// }
