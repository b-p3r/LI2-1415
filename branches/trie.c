#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)
// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define MAXSTR 26
#define MAXPAL 100000

// trie node
typedef struct trie_node trie_node_t;
struct trie_node {
    int value;
    trie_node_t *children[ALPHABET_SIZE];
};

// trie ADT
typedef struct trie trie_t;
struct trie {
    trie_node_t *root;
    int count;
};

// Returns new trie node (initialized to NULLs)
trie_node_t *getNode(void)
{
    trie_node_t *pNode = NULL;

    pNode = (trie_node_t *)malloc(sizeof(trie_node_t));

    if( pNode ) {
        int i;

        pNode->value = 0;

        for(i = 0; i < ALPHABET_SIZE; i++) {
            pNode->children[i] = NULL;
        }
    }

    return pNode;
}

// Initializes trie (root is dummy node)
void initialize(trie_t *pTrie)
{
    pTrie->root = getNode();
    pTrie->count = 0;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;

    pTrie->count++;
    pCrawl = pTrie->root;

    for( level = 0; level < length; level++ ) {
        index = CHAR_TO_INDEX(key[level]);
        if( !pCrawl->children[index] ) {
            pCrawl->children[index] = getNode();
        }

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->value = pTrie->count;
}

// Returns non zero, if key presents in trie
int search(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;

    pCrawl = pTrie->root;

    for( level = 0; level < length; level++ ) {
        index = CHAR_TO_INDEX(key[level]);

        if( !pCrawl->children[index] ) {
            return 0;
        }

        pCrawl = pCrawl->children[index];
    }

    return (0 != pCrawl && pCrawl->value);
}


// Driver
int main()
{

//char linha[MAXSTR];
// Input keys (use only 'a' through 'z' and lower case)

    trie_t trie;

    char output[][32] = {"Not present in trie", "Present in trie"};

    int contador[MAXSTR], i;
    FILE *f;
    int linha = 0;
    char palavras[MAXPAL] [MAXSTR];

    f = fopen("/home/bpereira/li2039/la2_li2-2014/dicio.txt", "r");

    while (fgets(palavras[linha], MAXSTR, f) != NULL) {
        palavras[linha][strlen(palavras[linha])-1] = '\0';
        linha++;

    }
    fclose(f);
    printf("Numero de palavras = %d\n", linha);

    initialize(&trie);

    // Construct trie
    printf("Palavra %s\n", palavras[0]);
    printf("Palavra %lu\n", ARRAY_SIZE(palavras));
    for(i = 0; i < ARRAY_SIZE(palavras); i++) {

        if(palavras[i][0] == '\0')
            break;
        insert(&trie, palavras[i]);
        //printf("Palavra %d\n", palavras[i][0]);
    }

    // Search for different keys
    printf("%s --- %s\n", "otorrinolarigologistas", output[search(&trie, "otorrinolaringologistas")] );
    //printf("%s --- %s\n", "these", output[search(&trie, "these")] );
    //printf("%s --- %s\n", "their", output[search(&trie, "their")] );
    //printf("%s --- %s\n", "thaw", output[search(&trie, "thaw")] );

    return 0;
}
