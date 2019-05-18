#include "command_handler.h"
#include "exceptions.h"
#include "definitions.h"
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>   

using namespace std;

void CommandHandler::run()
{
    string input_string;
    while (getline(cin, input_string))
    {
        try
        {
            input = split_string(input_string);
            detect_instruction_methode();   
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

void CommandHandler::detect_instruction_methode()
{
    if(input[INSTRUCTION_TYPE_INDEX] == POST)
    {
        post_methode_instructions();
        return;
    }
    if(input[INSTRUCTION_TYPE_INDEX] == GET)
    {
        get_methode_instructions();
        return;
    }
    if(input[INSTRUCTION_TYPE_INDEX] == PUT)
    {
        put_methode_instructions();
        return;
    }
    if(input[INSTRUCTION_TYPE_INDEX] == DELETE)
    {
        delete_methode_instructions();
        return;
    }
    throw BadRequest();
}

void CommandHandler::post_methode_instructions()
{
    if(input[INSTRUCTION_ACTION_INDEX] == SIGNUP)
    {

    }
}

int CommandHandler::find_index(string key)
{
    for (int i = 0; i < input.size(); i++)
        if(input[i] == key)
            return i;
    return INSTRUCTION_ACTION_INDEX;
}