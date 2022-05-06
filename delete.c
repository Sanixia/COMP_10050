//
// Created by chant on 06/05/2022.
//

#include <stdio.h>
#include <string.h>
#include "definitions_and_prototype_file.h"



void deleteAccount(twitter * twitter_system, int userNumber, char name[]){
    int i;
    for(i = 0; i < twitter_system->num_users;i++){

        removal(&twitter_system->max_users[userNumber].num_followers, twitter_system->max_users[i].username, &twitter_system->max_users[userNumber].followers[0]);
        removal(&twitter_system->max_users[userNumber].num_following, twitter_system->max_users[i].username, &twitter_system->max_users[userNumber].following[0]);
    }


}




