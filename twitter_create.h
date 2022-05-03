//
// Created by Lili on 30/03/2022.
//

#ifndef ASSIGNMENT2_TWITTER_CREATE_H
#define ASSIGNMENT2_TWITTER_CREATE_H

#endif //ASSIGNMENT2_TWITTER_CREATE_H

//Max length of a tweet
#define TWEET_LENGTH 270

//Max length of a username
#define USR_LENGTH 100

//Max num of a followers
#define MAX_FOLLOWERS 30

//Max num of following users
#define MAX_FOLLOWING 30

//Max num of tweets in the news feed
#define MAX_TWEETS 100

//Max num of users
#define MAX_USERS 100

typedef struct tweet{
    int id;
    char msg[TWEET_LENGTH];
    char user[USR_LENGTH];

}tweet;

typedef struct user{
    char username[USR_LENGTH];

    char followers[MAX_FOLLOWERS][USR_LENGTH];
    int num_followers;

    char following[MAX_FOLLOWING][USR_LENGTH];
    int num_following;
}user;

typedef struct twitter{
    user max_users[MAX_USERS];
    tweet news_feed[MAX_TWEETS];
    int num_tweets;
    int num_users;


} twitter;

void create_twitter_system(twitter * twitter_system);

