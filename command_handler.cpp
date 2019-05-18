#include "command_handler.h"
#include "exceptions.h"
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>   
#include <map>

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
    if(input[INSTRUCTION_ACTION_INDEX] == LOGIN)
        login();
    if(input[INSTRUCTION_ACTION_INDEX] == POST_FILM)
        add_film();
}

void CommandHandler::signup()
{
    map<string, string> elements;
    elements[USERNAME] = input[find_index(USERNAME) + 1];
    elements[PASS] = input[find_index(PASS) + 1];
    elements[AGE] = input[find_index(AGE) + 1];
    elements[PUBLISHER] = input[find_index(PUBLISHER) + 1];
    elements[EMAIL] = input[find_index(EMAIL) + 1];
    if(valid.signup_validity(elements))
    {
        network->signup(elements[EMAIL], elements[USERNAME], elements[PASS], 
                        stoi(elements[AGE]), check_publisher(elements[PUBLISHER]));
    }
    else
        throw BadRequest();
}

void CommandHandler::login()
{
    map<string, string> elements;
    elements[USERNAME] = input[find_index(USERNAME)];
    elements[PASS] = input[find_index(PASS)];
    if(valid.login_validity(elements))
        network->login(elements[USERNAME], elements[PASS]);
}

void CommandHandler::post_money()
{
    network->get_money();
}

void CommandHandler::add_film()
{
    map<string, string> elements;
    elements[NAME] = input[find_index(NAME) + 1];
    elements[YEAR] = input[find_index(YEAR) + 1];
    elements[LENGTH] = input[find_index(LENGTH) + 1];
    elements[PRICE] = input[find_index(PRICE) + 1];
    elements[SUMMARY] = input[find_index(SUMMARY) + 1];
    elements[DIRECTOR] = input[find_index(DIRECTOR) + 1];
    if(valid.add_film_validity(elements))
        network->add_film(elements[NAME], stoi(elements[YEAR]),
                            stoi(elements[LENGTH]), stoi(elements[PRICE]),
                            elements[SUMMARY], elements[DIRECTOR]);
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