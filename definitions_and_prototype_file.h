//
// Created by Lili on 30/03/2022.
// Contains what the title states

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
    struct listNode *nextPtr;
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

void follow_user(twitter * twitter_system, int userNumber);

void unfollow_user(twitter * twitter_system, int userNumber);

void postTweet(twitter * twitter_system, int userNumber, int tweetNumber);

void getNewsFeed(twitter * twitter_system, int user);

//void getNewsFeed(twitter * twitter_system, * user);

int isFollowing(twitter * twitter_system,  int userNumber, int news_feedNum);

void deleteAccount(twitter * twitter_system, int userNumber, char name[]);

void removal(int *numberOf, char name[], char characters[][USR_LENGTH]);
