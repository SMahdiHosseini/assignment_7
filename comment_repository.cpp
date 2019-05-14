#include "comment_repository.h"
#include "exceptions.h"

using namespace std;

CommentRepository::CommentRepository()
{
    last_id = 0;
}

Comment* CommentRepository::find_comment_by_id(int comment_id)
{
    for (int i = 0; i < comments.size(); i++)
        if(comments[i]->get_id() == comment_id)
            return comments[i];
    throw Inaccessibility();
}

int CommentRepository::find_comment_index(int comment_id)
{
    for (int i = 0; i < comments.size(); i++)
        if(comments[i]->get_id() == comment_id)
            return i;
    throw Inaccessibility();
}

void CommentRepository::delete_comment(int comment_id)
{
    comments.erase(comments.begin() + find_comment_index(comment_id));
    delete find_comment_by_id(comment_id);
}