
#include <iostream>

#include <loguru/loguru.hpp>
#include <cpr/cpr.h>

#include "responses/todo/RespOneTodo.hpp"
#include "responses/todo/RespMultipleTodos.hpp"

using namespace std;

const string URL = "https://jsonplaceholder.typicode.com";

int main(int argc, char const *argv[])
{
    // Fetch one element from the collection
    LOG_F(INFO, "GET request");
    cpr::Response response = cpr::Get(cpr::Url(URL + "/todos/1"));

    cout << "Status code : " << response.status_code << "\n"
        << "Content type : " << response.header["content-type"] << endl;

    RespOneTodo respOneTodo;
    respOneTodo.deserialize(response.text);

    cout << respOneTodo.toString() << endl;

    LOG_F(INFO, "GET request (list)");
    response = cpr::Get(cpr::Url(URL + "/todos"));
    RespMultipleTodos respMultipleTodos;
    respMultipleTodos.deserialize(response.text);
    cout << respMultipleTodos.toString() << endl;

    return 0;
}
