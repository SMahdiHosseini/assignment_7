#ifndef COMMENT_H
#define COMMENT_H

#include <iostream>

class Comment
{
public:
    Comment();
    Comment(int _id, std::string _content);
    int get_id();
    void reply_content(std::string content);
    void change_content(std::string content);
private:
    int id;
    std::string content;
    Comment* reply;
};

#endif