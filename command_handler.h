#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <vector>
#include "network.h"

typedef std::vector<std::string> string_list;

class CommandHandler
{
public:
    CommandHandler() { };
    string_list split_string(std::string input);
    void run();
    void detect_instruction_methode();
    void post_methode_instructions();
    void get_methode_instructions();
    void put_methode_instructions();
    void delete_methode_instructions();
    void signup();
    bool check_integer(string integer);
    bool check_email(string email);
    bool check_publisher(string input);
    int find_index(std::string key);
private:
    Network* network;
    string_list input;
};

#endif