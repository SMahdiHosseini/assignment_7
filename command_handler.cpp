#include "command_handler.h"
#include "exceptions.h"
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>   

using namespace std;

void CommandHandler::run()
{
    string input;
    while (getline(cin, input))
    {
        try
        {
            detect_instruction(split_string(input));   
        }
        catch(BadRequest& e)
        {
            cout << e.what() << '\n';
        }
        catch(Inaccessibility& e)
        {
            cout << e.what() << '\n';
        }
        catch(NotFound& e)
        {
            cout << e.what() << '\n';
        }
    }
}

string_list CommandHandler::split_string(string input)
{
    stringstream input_string_stream(input);
    return vector<string>(istream_iterator<string>(input_string_stream),
            istream_iterator<string>());
}