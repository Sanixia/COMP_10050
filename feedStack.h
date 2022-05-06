//
// Created by User01 on 03/05/2022.
//

#ifndef COMP_10050_FEEDSTACK_H
#define COMP_10050_FEEDSTACK_H

#endif //COMP_10050_FEEDSTACK_H



/* self-referential structure */
struct listNode {
    char data;
    struct listNode *nextPtr; /* pointer to next node */
}; /* end structure listNode */



typedef struct listNode ListNode; /* synonym for struct listNode */
typedef ListNode *ListNodePtr; /* synonym for ListNode* */





/* prototypes */
void insert( ListNodePtr *sPtr, char value[USR_LENGTH] );
//void insert( ListNodePtr *sPtr, struct twitter * twitter_system);
char delete( ListNodePtr *sPtr, char value );
int isEmpty( ListNodePtr sPtr );
void printList( ListNodePtr currentPtr );
void instructions( void );



