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