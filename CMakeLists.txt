cmake_minimum_required(VERSION 3.21)
project(COMP_10050 C)

set(CMAKE_C_STANDARD 11)

add_executable(COMP_10050 main.c twitter_create.c definitions_and_prototype_file.h follow.c feedStack.c feedStack.h unfollow.c postTweet.c getNewsFeed.c)
