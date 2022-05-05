//
// Created by chant on 05/05/2022.
//

#include <stdio.h>
#include <string.h>
#include "definitions_and_prototype_file.h"
#include "feedStack.h"


ListNodePtr startPtr = NULL; // initially there are no nodes


void postTweet(twitter * twitter_system, int userNumber, int tweetNumber){


    printf("\nPlease type in your tweet (max 270 characters): ");

    fgets(twitter_system->news_feed->msg, TWEET_LENGTH, stdin);
    if(twitter_system->news_feed->msg[strlen(twitter_system->news_feed->msg) - 1]  == '\n'){
        twitter_system->news_feed->msg[strlen(twitter_system->news_feed->msg) - 1] = '\0';      //replaces the end of each input with \0 instead of \n otherwise it wouldn't work correctly
    }

    strcpy(twitter_system->news_feed[tweetNumber].user, twitter_system->max_users[userNumber].username);
    twitter_system->news_feed->id = tweetNumber;


    printf("%d", twitter_system->news_feed->id);
    //insert(ListNodePtr *startPtr, &twitter_system,struct twitter_system->tweet[userNumber]);

}


