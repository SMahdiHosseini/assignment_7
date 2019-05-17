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
    void detect_instruction(string_list input);
private:
    Network* nework;
};

#endif