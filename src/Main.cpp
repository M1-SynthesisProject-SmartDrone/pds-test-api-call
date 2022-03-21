
#include <iostream>

#include <cpr/cpr.h>

using namespace std;

const string URL = "https://jsonplaceholder.typicode.com";

int main(int argc, char const *argv[])
{
    // Fetch one element from the collection
    cpr::Response response = cpr::Get(cpr::Url(URL + "/todos/1"));

    cout << "Status code : " << response.status_code << "\n"
        << "Content type : " << response.header["content-type"] << "\n"
        << "Payload : " << response.text << endl;

    return 0;
}
