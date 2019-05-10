#ifndef COMMENT_H
#define COMMENT_H

#include <iostream>

using namespace std;

class Comment
{
public:
private:
    int id;
    string content;
    Comment* reply;
};

#endif