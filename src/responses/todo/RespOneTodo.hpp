#ifndef __RESPONETODO_H__
#define __RESPONETODO_H__

#include "responses/Response.h"

class RespOneTodo : public Response
{
private:

public:
    long userId;
    long id;
    std::string title;
    bool completed;

    RespOneTodo() {}

    ~RespOneTodo() {}

    void deserializeDocument(rapidjson::Value& object)
    {
        userId = object["userId"].GetInt64();
        id = object["id"].GetInt64();
        title = object["title"].GetString();
        completed = object["completed"].GetBool();
    }

    std::string toString()
    {
        std::stringstream ss;
        ss << "RespOneTodo[uid=" << userId << ", id=" << id << ", title=\"" << title << "\", completed=" << completed << "]";
        return ss.str();
    }
};

#endif // __RESPONETODO_H__