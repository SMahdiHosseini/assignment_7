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
    void run();
    string_list split_string(std::string input);
    void detect_instruction_methode(string_list input);
    void post_methode_instructions(string_list input);
    void get_methode_instructions(string_list input);
    void put_methode_instructions(string_list input);
    void delete_methode_instructions(string_list input);
private:
    Network* network;
};

#endif