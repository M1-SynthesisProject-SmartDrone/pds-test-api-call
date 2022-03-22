#ifndef __RESPONETODO_H__
#define __RESPONETODO_H__

#include "responses/Response.h"


struct RespOneTodo : public Response
{
    long userId;
    long id;
    std::string title;
    bool completed;

    RespOneTodo() {}

    ~RespOneTodo() {}

    void deserializeJson(nlohmann::json json)
    {
        userId = json["userId"];
        id = json["id"];
        title = json["title"];
        completed = json["completed"];
    }

    std::string toString()
    {
        std::stringstream ss;
        ss << "RespOneTodo[uid=" << userId << ", id=" << id << ", title=\"" << title << "\", completed=" << completed << "]";
        return ss.str();
    }
};

#endif // __RESPONETODO_H__