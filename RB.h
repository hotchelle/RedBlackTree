// Bottom-up red-black tree header file

// These will have to change if data in node is more than just an int.

//Name: Abdulla Sakallah                                         Student ID: 1001846204
// Compiling instructions on Omega:-
//==================================
// gcc driver.c
// ./a.out < a.txt
typedef int Key;
typedef Key Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define eq(A, B) (key(A) == key(B))

typedef struct STnode *link;

struct STnode
{
    Item item; // Data for this node
    link l, r; // left & right links
    char red;  // RB color
    int N;     // subtree size
    int sign; //optional sign
};

extern Item NULLitem;

void STinit(); // Initialize tree with just a sentinel

Item STsearch(Key v); // Find node for a key

Item STselect(int k); // Treat tree as flattened into an ordered array

int STinvSelect(Key v); // Inverse of STselect

void extendedTraceOn(); // Full tracing of intermediate trees

void basicTraceOn(); // Just trace down and up passes for insert

void traceOff(); // Run silent

void STinsert(Item item); // Insert an item.  No uniqueness check

void verifyRBproperties(); // Ensure that tree isn't damaged

void STprintTree(); // Dumps out tree

void cleanUpUnbalanced(link h); // Includes subtree sizes and verifies a tree || built without balancing

void STserialize(link root, char * output); // Flattens current tree into a pre-order string

void STdeserialize(char *str); // Parses string to current red-black tree

link getHead(); // gets the head of the red-black tree

void freeMemory(); // Frees the memory allocated for nodes

