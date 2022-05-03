#include <stdio.h>
#include "twitter_create.h"


int main() {

    twitter twitter_system;
    create_twitter_system(&twitter_system);


    for(int i = 0; i < twitter_system.num_users; i++){
        user printUser = twitter_system.max_users[i];
        printf("User: %s; Followers: %d; Following: %d\n",printUser.username, printUser.num_followers, printUser.num_followers );
    }






}
