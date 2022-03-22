#ifndef __RESPONSE_H__
#define __RESPONSE_H__

#include <string>

#include <nlohmann/json.hpp>

struct Response
{
    Response() {};
    ~Response() {};

    /**
     * Check if the response is an error or not
     */
    virtual bool isErrorResponse()
    {
        return false;
    }

    virtual void deserialize(std::string string)
    {
        auto jsonParsed = nlohmann::json::parse(string);
        deserializeJson(jsonParsed);
    }

    /**
     * Fill the object attributes with fields in the json string
     */
    virtual void deserializeJson(nlohmann::json json) = 0;
};

#endif // __RESPONSE_H__