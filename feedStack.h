//
// Created by User01 on 03/05/2022.
//

#ifndef COMP_10050_FEEDSTACK_H
#define COMP_10050_FEEDSTACK_H

#endif //COMP_10050_FEEDSTACK_H





typedef struct tweet ListNode;
typedef ListNode *ListNodePtr;



/* prototypes */
void insert( ListNodePtr *sPtr, char value[USR_LENGTH] );
//void insert( ListNodePtr *sPtr, struct twitter * twitter_system);
char delete( ListNodePtr *sPtr, char value );
int isEmpty( ListNodePtr sPtr );
void printList( ListNodePtr currentPtr );
void instructions( void );



