#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 100

typedef struct Entry {
    char* key;
    int value;
    struct Entry* next;
} Entry;

typedef struct HashTable {
    Entry* buckets[TABLE_SIZE];
} HashTable;

// Hash table operations
unsigned int hashFunction(const char* key);
HashTable* createHashTable();
void insert(HashTable* table, const char* key, int value);
int search(HashTable* table, const char* key, int* found);
void deleteKey(HashTable* table, const char* key);
void displayHashTable(HashTable* table);

// Utility functions
Entry* createEntry(const char* key, int value);
