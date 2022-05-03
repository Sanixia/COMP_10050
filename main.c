#include <stdio.h>
#include "twitter_create.h"
#include "followAndUnfollow.h"



int main() {

    twitter twitter_system;
    create_twitter_system(&twitter_system);
    printf("test 4");


    for(int i = 0; i < twitter_system.num_users; i++){  //for loop to print out the username, followers and users following for each user

        printf("User: %s; Followers: %d; Following: %d\n",
               twitter_system.max_users[i].username,
               twitter_system.max_users[i].num_followers,
               twitter_system.max_users[i].num_followers );
    }
































    // michal section



}
