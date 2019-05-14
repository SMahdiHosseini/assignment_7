#ifndef COMMENT_REPOS_H
#define COMMENT_REPOS_H

#include "comment.h"
#include <vector>

class CommentRepository
{
public:
    CommentRepository();
    Comment* find_comment_by_id(int commetn_id);
    int find_comment_index(int comment_id);
    void delete_comment(int comment_id);
private:
    int last_id;
    std::vector<Comment*> comments;
};

#endif