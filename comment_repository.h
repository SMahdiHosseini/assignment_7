#ifndef COMMENT_REPOS_H
#define COMMENT_REPOS_H

#include "comment.h"
#include <vector>

class CommentRepository
{
public:
    CommentRepository();
private:
    int last_id;
    std::vector<Comment> comments;
};

#endif