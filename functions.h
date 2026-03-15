#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// macros
#define N_MAX 24
#define E_MAX 32
#define P_MAX 20

// define the contact struct, each contact will have this info stored in the contacts file
typedef struct node
{
    char name[N_MAX];
    char email[E_MAX];
    char phone[P_MAX];
    struct node *next;
} Contact;

typedef struct Values
{
    char name[N_MAX];
    char email[E_MAX];
    char phone[P_MAX];
} Values;

extern Values storage; // this struct exists, memory isn't allocated for it yet (will be done in another file)

// functions prototypes
void clearBuffer(void);
void addContact(Contact *head, char nameToEnter[], char emailToEnter[], char phoneToEnter[]);
void getInfo(void);
void printAllContacts(Contact *head);
void restore(Contact *head, int length);
int countLength(Contact *head);
int getContactNum();
void removeContact(Contact *head, int num, int maxLength);
void printContact(Contact *head, int num, int maxLength);

#endif