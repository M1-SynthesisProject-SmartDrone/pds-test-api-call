#ifndef __RESPONSE_H__
#define __RESPONSE_H__

#include <string>

#include <rapidjson/document.h>
#include <rapidjson/writer.h>

class Response
{
private:
    
public:
    Response();
    ~Response();

    /**
     * Fill the object attributes with fields in the json string
     */
    virtual void deserialize(std::string str);

    // To implement in child classes
    // All exceptions are handled by main method
    virtual void deserializeDocument(rapidjson::Value& object) = 0;
};

#endif // __RESPONSE_H__