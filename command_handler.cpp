#include "command_handler.h"
#include "exceptions.h"
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>   

using namespace std;

CommandHandler::CommandHandler() : valid()
{
    network = new Network();
}

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
    // if(input[INSTRUCTION_TYPE_INDEX] == GET)
    // {
    //     get_methode_instructions();
    //     return;
    // }
    // if(input[INSTRUCTION_TYPE_INDEX] == PUT)
    // {
    //     put_methode_instructions();
    //     return;
    // }
    // if(input[INSTRUCTION_TYPE_INDEX] == DELETE)
    // {
    //     delete_methode_instructions();
    //     return;
    // }
    throw BadRequest();
}

void CommandHandler::post_methode_instructions()
{
    if(input[INSTRUCTION_ACTION_INDEX] == SIGNUP)
        signup();
}

void CommandHandler::signup()
{

    int username_index = find_index("username");
    int pass_index = find_index("password");
    int age_index = find_index("age");
    int publisher_index = find_index("publisher");
    int email_index = find_index("email");
    if(valid.signup_validity(input[age_index + 1], input[email_index + 1], input[publisher_index + 1]))
    {
        network->signup(input[email_index + 1], input[username_index + 1], 
                        input[pass_index + 1], stoi(input[age_index + 1]), 
                        check_publisher(input[publisher_index + 1]));
    }
    else
        throw BadRequest();
    
}

int CommandHandler::find_index(string key)
{
    for (int i = 0; i < input.size(); i++)
        if(input[i] == key)
            return i;
    return INSTRUCTION_ACTION_INDEX;
}

bool CommandHandler::check_publisher(string publisher)
{
    if(publisher == "true")
        return true;
    if(publisher == "false" || publisher == "?")
        return false;
}   