#ifndef COMMENT_H
#define COMMENT_H

#include <iostream>

class Comment
{
public:
private:
    int id;
    std::string content;
    Comment* reply;
};

#endif