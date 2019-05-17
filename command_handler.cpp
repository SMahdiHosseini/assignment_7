#include "command_handler.h"
#include "exceptions.h"
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>   

#define INSTRUCTION_TYPE_INDEX 0
#define INSTRUCTION_ACTION_INDEX 1
#define INSTRUCTION_SEPERATOR_INDEX 2
#define POST "POST"
#define DELETE "DELETE"
#define GET "GET"
#define PUT "PUT"
#define SEPERATOR "?"
#define SIGNUP "signup"

using namespace std;

void CommandHandler::run()
{
    string input;
    while (getline(cin, input))
    {
        try
        {
            detect_instruction_methode(split_string(input));   
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

void CommandHandler::detect_instruction_methode(string_list input)
{
    if(input[INSTRUCTION_TYPE_INDEX] == POST)
    {
        post_methode_instructions(input);
        return;
    }
    if(input[INSTRUCTION_TYPE_INDEX] == GET)
    {
        get_methode_instructions(input);
        return;
    }
    if(input[INSTRUCTION_TYPE_INDEX] == PUT)
    {
        put_methode_instructions(input);
        return;
    }
    if(input[INSTRUCTION_TYPE_INDEX] == DELETE)
    {
        delete_methode_instructions(input);
        return;
    }
    throw BadRequest();
}