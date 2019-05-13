#include "comment.h"

using namespace std;

int Comment::get_id()
{
    return id;
}

void Comment::reply_content(string _content)
{
    reply->change_content(_content);
}

void Comment::change_content(string _content)
{
    content = _content;
}