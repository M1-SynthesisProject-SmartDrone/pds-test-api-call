#ifndef __RESPMULTIPLETODOS_H__
#define __RESPMULTIPLETODOS_H__

#include "responses/Response.h"

#include <vector>
#include <functional>

#include "responses/todo/RespOneTodo.hpp"

struct RespMultipleTodos : public Response
{
    std::vector<RespOneTodo> todos;

    RespMultipleTodos() {}

    ~RespMultipleTodos() {}

    void deserializeJson(nlohmann::json json)
    {
        // We have an array here normally
        for (auto& todo : json)
        {
            RespOneTodo respTodo;
            respTodo.deserializeJson(todo);

            todos.push_back(respTodo);
        }
    }

    std::string toString()
    {
        std::stringstream ss;
        ss << "RespMultipleTodos[\n";
        std::for_each(todos.begin(), todos.end(), [&ss](RespOneTodo todo)
            {
                ss << "\t" << todo.toString() << "\n";
            });
        ss << "]";
        return ss.str();
    }
};

#endif // __RESPMULTIPLETODOS_H__