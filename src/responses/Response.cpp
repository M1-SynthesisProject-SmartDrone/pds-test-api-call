#include "Response.h"

#include <algorithm>
#include <loguru/loguru.hpp>

using namespace std;
using namespace rapidjson;

Response::Response() {}

Response::~Response() {}

void Response::deserialize(std::string str)
{
    rapidjson::Document document;

    document.Parse<kParseStopWhenDoneFlag>(str.c_str());
    if (document.HasParseError())
    {
        throw invalid_argument("Cannot parse json properly");
    }

    try
    {
        deserializeDocument(document);
    }
    catch(const std::exception& e)
    {
        str.erase(remove(str.begin(), str.end(), '\n'), str.end());
        LOG_F(ERROR, "Cannot parse json \"%s\" : %s", str.c_str(), e.what());
        throw invalid_argument("Json value is not parsable");
    }
}
