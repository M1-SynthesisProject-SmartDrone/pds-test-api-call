#ifndef __REQUEST_H__
#define __REQUEST_H__

#include <string>

#include <rapidjson/writer.h>

class Request
{
private:
    
public:
    Request();
    ~Request();

    virtual std::string serialize();

    // To implement in child classes
    virtual void serializeObject(rapidjson::Writer<rapidjson::StringBuffer>& writer) = 0;
};

#endif // __REQUEST_H__