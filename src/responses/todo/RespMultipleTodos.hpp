#ifndef __RESPMULTIPLETODOS_H__
#define __RESPMULTIPLETODOS_H__

#include "responses/Response.h"

#include <vector>
#include <functional>

#include "responses/todo/RespOneTodo.hpp"

class RespMultipleTodos : public Response
{
private:
    
public:
    std::vector<RespOneTodo> todos;

    RespMultipleTodos() {}

    ~RespMultipleTodos() {}

    void deserializeDocument(rapidjson::Value& object)
    {
        for (auto& todo : object.GetArray())
        {
            RespOneTodo respTodo;
            respTodo.deserializeDocument(todo);

            todos.push_back(respTodo);
        }
    }

    std::string toString()
    {
        std::stringstream ss;
        ss << "RespMultipleTodos[\n";
        std::for_each(todos.begin(), todos.end(), [&ss](RespOneTodo todo){
            ss << "\t" << todo.toString() << "\n";
        });
        ss << "]";
        return ss.str();
    }
};

#endif // __RESPMULTIPLETODOS_H__