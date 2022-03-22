#ifndef __REQCREATETODO_H__
#define __REQCREATETODO_H__

#include "requests/Request.h"

class ReqCreateTodo : public Request
{
private:
    /* data */
public:
    long userId;
    std::string title;
    bool completed;

    ReqCreateTodo(long userId, std::string title) 
    : userId(userId), title(title) 
    {
        this->completed = completed;
    }
    ~ReqCreateTodo() {}

    void serializeObject(rapidjson::Writer<rapidjson::StringBuffer>& writer)
    {
        writer.StartObject();
            writer.String("userId");
            writer.Int64(userId);
            
            writer.String("title");
            writer.String(title.c_str());
            
            writer.String("completed");
            writer.Bool(completed);
        writer.EndObject();
    }
};


#endif // __REQCREATETODO_H__