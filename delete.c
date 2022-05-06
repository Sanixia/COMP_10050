

#include <stdio.h>
#include <string.h>
#include "definitions_and_prototype_file.h"



void deleteAccount(twitter * twitter_system, int userNumber, char name[]){
    int i;
    for(i = 0; i < twitter_system->num_users;i++){

        removal(&twitter_system->max_users[userNumber].num_followers, twitter_system->max_users[i].username, &twitter_system->max_users[userNumber].followers[0]);
        removal(&twitter_system->max_users[userNumber].num_following, twitter_system->max_users[i].username, &twitter_system->max_users[userNumber].following[0]); //these two delete followers and following from the user
        removal(&twitter_system->max_users[i].num_followers, name, &twitter_system->max_users[i].followers[0]);
        removal(&twitter_system->max_users[i].num_following, name, &twitter_system->max_users[i].following[0]); //these two delete user name from any follower and who followed the user
    }


}




