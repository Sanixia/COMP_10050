//unfollow a user from follow list and the other user's follower list

#include <stdio.h>
#include <string.h>

#include "definitions_and_prototype_file.h"

void unfollow_user(twitter * twitter_system, int userNumber) {
    int i, k, l, m, o, p;                               //loop variables
    int checkValidUsername = 0, followerNumber = 0;
    char name[30];

    printf("\nHere is your list of people you follow: ");

    if (twitter_system->max_users[userNumber].num_following == 0) {
        printf("\nExcept it looks like you don't follow anyone!\n");



    } else {
        for (i = 0; i < twitter_system->max_users[userNumber].num_following; i++) {
            printf("\n-> %s", twitter_system->max_users[userNumber].following[i]);
        }



        while (checkValidUsername == 0) {
            printf("\n\nPlease enter the valid username of the person you want to unfollow: ");



            fgets(name, USR_LENGTH, stdin);

            if (name[strlen(name) - 1] == '\n') {
                name[strlen(name) - 1] = '\0';
            }



            for(k = 0;k < twitter_system->num_users;k++) {                                                                  //checks for valid inputted username
                if ((strcmp(twitter_system->max_users[k].username, name) == 0) &&
                    (strcmp(twitter_system->max_users[userNumber].username, twitter_system->max_users[k].username) != 0)) {
                    checkValidUsername = 1;
                    followerNumber = k;
                    k = twitter_system->num_users;
                }
            }




            for(o = 0; o < twitter_system->max_users[userNumber].num_following; o++){
                if(strcmp(twitter_system->max_users[userNumber].following[o], name) == 0){

                    for(p = o; p < twitter_system->max_users[userNumber].num_following; p++){


                        strcpy(twitter_system->max_users[userNumber].following[p], twitter_system->max_users[userNumber].following[p+1]);     //this copies every username after the one you want removed back by one and decreases the following list
                    }
                }
            }



            for(l = 0; l < twitter_system->max_users[followerNumber].num_followers; l++){
                if(strcmp(twitter_system->max_users[followerNumber].followers[l], twitter_system->max_users[userNumber].username) == 0){

                    for(m = l; m < twitter_system->max_users[followerNumber].num_followers; m++){


                        strcpy(twitter_system->max_users[followerNumber].followers[m], twitter_system->max_users[followerNumber].followers[m+1]);  //same thing but for the followers list, removing the user
                    }
                }
            }

            twitter_system->max_users[userNumber].num_following--;
            twitter_system->max_users[followerNumber].num_followers--;

            printf("%s has been removed from your following list!\n", name);

            printf("\nCurrent number of followers: %d \nCurrent number of users following: %d\n",
                   twitter_system->max_users[userNumber].num_followers,
                   twitter_system->max_users[userNumber].num_following);



        }

    }
}
