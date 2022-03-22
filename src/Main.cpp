
#include <iostream>

#include <loguru/loguru.hpp>
#include <cpr/cpr.h>

#include "responses/todo/RespOneTodo.hpp"
#include "responses/todo/RespMultipleTodos.hpp"

#include "requests/todo/ReqCreateTodo.hpp"

#include "ApiHandler/ApiHandler.h"
#include "ApiHandler/ApiErrorException.h"

using namespace std;

const string URL = "https://jsonplaceholder.typicode.com";

void testRequests()
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


    LOG_F(INFO, "POST Request");
    ReqCreateTodo reqCreateTodo(1, "Create a todo with api call");
    response = cpr::Post(
        cpr::Url(URL + "/todos"),
        cpr::Header{ {"Content-Type", "application/json; charset=UTF-8"} },
        cpr::Body(reqCreateTodo.serialize())
    );
    RespOneTodo createdTodo;
    createdTodo.deserialize(response.text);
    cout << createdTodo.toString() << endl;

    LOG_F(INFO, "Error response");
    response = cpr::Get(cpr::Url(URL + "/error/501"));
    cout << "Status code : " << response.status_code << "\n"
        << "Content type : " << response.header["content-type"] << "\n"
        << "Body : " << response.text << endl;
}

void testApiHandler()
{
    ApiHandler apiHandler(URL);
    // un truc en mode send request expect answer
    // qui throw une exception si c'est pas le bon msg ou c'est une erreur (isError)
    // ==> Créer une exception ?
    RespOneTodo respOneTodo;
    apiHandler.get("/todos/1", respOneTodo);
    cout << respOneTodo << endl;

    RespMultipleTodos respMultipleTodos;
    apiHandler.get("/todos", respMultipleTodos);
    cout << respMultipleTodos << endl;

    ReqCreateTodo reqCreateTodo(1, "Create a todo with api call");
    apiHandler.post("/todos", reqCreateTodo, respOneTodo);
    cout << respOneTodo << endl;

    // This one will throw
    apiHandler.get("/error/501", respOneTodo);
}

int main(int argc, char const* argv[])
{
    try
    {
        testApiHandler();
    }
    catch (ApiErrorException& exception)
    {
        LOG_F(ERROR, "API EXCEPTION");
        cerr << exception.message() << endl;
    }
    catch (exception& exception)
    {
        LOG_F(ERROR, "EXCEPTION");
        cerr << exception.what() << endl;
    }

    return 0;
}
