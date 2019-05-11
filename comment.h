#ifndef COMMENT_H
#define COMMENT_H

#include <iostream>

class Comment
{
public:
    Comment();
    Comment(int _id, std::string _content);
private:
    int id;
    std::string content;
    Comment* reply;
};

#endif