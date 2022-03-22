#include "Request.h"

Request::Request() {}

Request::~Request() {}

std::string Request::serialize()
{
    rapidjson::StringBuffer stringBuffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(stringBuffer);
    serialize(writer);
    return stringBuffer.GetString();
}