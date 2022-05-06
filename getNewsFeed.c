//
// Created by User01 on 05/05/2022.
//

#include <stdio.h>
#include <string.h>
#include "definitions_and_prototype_file.h"




void getNewsFeed(twitter * twitter_system, int user)
{
    int i, j=twitter_system->num_tweets;


    // if no one has posted anything

    if (j==0){
        printf("\n\nThe newsFeed is empty");
    }


    // if news feed has tweets but you dont follow the users

    else if (twitter_system->max_users[user].num_following == 0 && j>0) {
        printf("\n\nFollow some users to see a newsFeed!");
    }

    else {
        printf("\n\nThe news feed of the most recent tweets is as follows:\n");


        // iterates through all the tweets
        // goes backwards from the list ie from most recent
        // stops when either when it has gone through all tweets or reached a limit of 10

        while(j>(twitter_system->num_tweets-10) || j>0)
        {
            if (strcmp(twitter_system->max_users[user].username, twitter_system->news_feed[j].user) == 0
            || isFollowing(twitter_system , user, j))
            {
                printf("\nUser: %s Tweet %d: %s", twitter_system->news_feed[j].user, twitter_system->news_feed[j].id+1,
                       twitter_system->news_feed[j].msg);

            }
            j--;
        }
        printf("\n\n");
    }
}


//// function isFollowing

// compares the current tweet's author against every person followed
// if they match 1 is returned , else 0 is returned

int isFollowing(twitter * twitter_system,  int userNumber, int news_feedNum) {
    for (int i=0; i<twitter_system->max_users[userNumber].num_following; i++)
    {
        if(strcmp(twitter_system->max_users[userNumber].following[i], twitter_system->news_feed[news_feedNum].user) == 0){
            return 1;
        }

    }
    return 0;
}




















/*
void getNewsFeed (twitter * twitter_system, int userNumber){

    int j=0, i;
    char user[USR_LENGTH];
    int following = twitter_system->max_users[userNumber].num_following;
    struct twitter *twitter2 = twitter_system;

    strcpy( user, twitter_system->max_users[userNumber].username);






    for (i=0; i<MAX_TWEETS; i++)
    {
        while(j<10)
        {

            if (strcmp(twitter_system->news_feed[i].user, user) == 0 || isFollowing(twitter2 , twitter_system->news_feed[i].user, following, userNumber)) {
                printf("\nUser: %s Tweet %d: %s", twitter_system->news_feed[j].user, twitter_system->news_feed[j].id,
                       twitter_system->news_feed[j].msg);
                j++;
            }

        }
    }
}



int isFollowing(twitter * twitter_system, char username[USR_LENGTH], int following, int userNumber) {
    for (int i=0; i<following; i++) {
        if(strcmp(twitter_system->max_users[userNumber].following[i], username) == 0){
            return 1;
        }

    }
    return 0;
}
*/
