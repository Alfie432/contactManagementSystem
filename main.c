#include <stdio.h>
#include <stdlib.h>

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

// functions prototypes
void clearBuffer(void);
void addContact(Contact *head, char nameToEnter[], char emailToEnter[], char phoneToEnter[]);
void getInfo(void);
void printAllContacts(Contact *head);

// define it here so it can be accessed by any function
Values storage;

int main(void)
{   
    Contact *head = NULL; // an empty linked list
    int choice = 0;

    // keep on asking for user choice until they decide to exit
    while (1)
    {
        printf("1) Add Contact\n2) View Contact\n3) View All Contacts\n4) Remove Contact\n5) Restore\n6) Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        clearBuffer();

        // decide what to do based of input
        switch (choice)
        {
        case 1:
            getInfo();
            addContact(head, storage.name, storage.email, storage.phone);
            break;
        case 2:
            break;
        case 3:
            printAllContacts(head);
            break;
        case 4:
            break;
        case 5: 
            break;
        case 6:
            return 0;
            break;
        default:
            continue;
        }
    }


    return 0;
}


void clearBuffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && (ch != EOF))
    {
        // do nothing
    }
}


void addContact(Contact *head, char nameToEnter[], char emailToEnter[], char phoneToEnter[])
{
    Contact *current = head; // start at the beginning of the linked list


    // go to the last node
    if (current->next == NULL) // ! this line produces a segfault 
    {
        current->next = (Contact *) malloc(sizeof(Contact)); // create the new node
    }
    else
    {
        while (current->next != NULL) 
        {
            current = current->next;
        }

        current->next = (Contact *) malloc(sizeof(Contact)); // create the new node 
    }

    if (current->next == NULL)
    {
        return; // there was an error allocating
    }

    
    // asign values to it
    // start at the memory address of current, go to the next node (the created one), and access the name/email/phone property
    *current->next->name = *nameToEnter;
    *current->next->email = *emailToEnter;
    *current->next->phone = *phoneToEnter;
    current->next->next = NULL;
}


void getInfo(void) 
{
    // get the input
    printf("Enter the contact's name: ");
    fgets(storage.name, N_MAX, stdin);

    printf("Enter the contact's email: ");
    fgets(storage.email, E_MAX, stdin);

    printf("Enter the contact's phone: ");
    fgets(storage.phone, P_MAX, stdin);
}


void printAllContacts(Contact *head)
{
    // traverse until the end of the linked list
    Contact *current = head;

    while (current->next != NULL)
    {
        current = current->next;
        printf("Name: %s\n", current->name);
        printf("Email: %s\n", current->email);
        printf("Phone: %s\n", current->phone);

        printf("\n"); // just for spacing
    }
}
