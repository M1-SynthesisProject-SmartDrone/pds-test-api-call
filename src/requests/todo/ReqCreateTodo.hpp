#ifndef __REQCREATETODO_H__
#define __REQCREATETODO_H__

#include "requests/Request.h"

struct ReqCreateTodo : public Request
{
    long userId;
    std::string title;
    bool completed;

    ReqCreateTodo(long userId, std::string title)
        : userId(userId), title(title)
    {
        this->completed = completed;
    }
    ~ReqCreateTodo() {}

    std::string serialize()
    {
        nlohmann::json jsonObject = {
            {"userId", userId},
            {"title", title},
            {"completed", completed},
        };
        return jsonObject.dump();
    }
};


#endif // __REQCREATETODO_H__