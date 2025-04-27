/*
* Author: Payton Garing
* Course: Computer Science 1
* Assignment: Smart Typing System
* Date: Spring 2025
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// trie npdes struct definition
typedef struct trienode_s {
    
    int flag;
    int frequency;
    int maxSubtreeFrequency;
    char mostFrequentWord[MAX_LENGTH];
    struct trienode_s *children[26];

} TrieNode;

// function to append/create trie nodes
TrieNode* createNode(){
    TrieNode *node = NULL;
    
    node = malloc(sizeof(TrieNode));
    if (node != NULL){
        // set values for each trie node
        node->flag = 0;
        node->frequency = 0;
        node->maxSubtreeFrequency = 0;
        for(int i =0; i < 26; i++){
            node->children[i] = NULL;
        }
        node->mostFrequentWord[0] = '\0';
    }
    
    return node;
}

void insertWord(TrieNode* root, const char *word, int frequency){
    // create temp node asssigned to root to traverse trie nodes
    TrieNode* temp = root;
    int length = strlen(word);
    // traverse trie nodes
    for(int level = 0; level < length; level++){
        int index = word[level] - 'a';

        if(temp->children[index] == NULL){
            temp->children[index] = createNode();
        }
        temp = temp->children[index];

        // updates mostFrequentWord if new word is more frequent
        if(frequency > temp->maxSubtreeFrequency){
            temp->maxSubtreeFrequency = frequency;
            strcpy(temp->mostFrequentWord, word);
        }
    }

    temp->flag = 1;
    temp->frequency = frequency;
    
    temp = root;
    for(int level = 0; level < length; level++){
        int index = word[level] - 'a';
        temp = temp->children[index];

        if(temp->frequency > temp->maxSubtreeFrequency){
            temp->maxSubtreeFrequency = temp->frequency;
            strcpy(temp->mostFrequentWord, word);
        }
    }
}

char* mostFrequent(TrieNode* root, char* prefix){
    TrieNode* temp = root;
    int length = strlen(prefix);
    // traverse tries 
    for(int level = 0; level < length; level++){
        int index = prefix[level] - 'a';
        // returns NULL if word not in tries
        if(temp->children[index] == NULL){
            return "unknown word\n";
        }

        temp = temp->children[index];
    }
    // returns most frequent word for given prefix
    if(temp->mostFrequentWord[0] != '\0'){
        return temp->mostFrequentWord;
    }
    return "unknown word\n";
}


int main(){
    // declare/assign necessary vraiables
    int numCommands = 0;
    int command = 0;
    int frequency = 0;
    char word[MAX_LENGTH];
    TrieNode* root = createNode();
    
    scanf("%d", &numCommands);

    // execute operations for X commands
    for(int i =0; i < numCommands; i++){
        scanf("%d", &command);
        // inserts new word into trie
        if(command == 1){

            scanf("%s %d", word, &frequency);;
            insertWord(root, word, frequency);

        // returns most frequent word for given prefix
        } else if(command == 2){

            scanf("%s", word);
            printf("%s\n", mostFrequent(root, word));
            fflush(stdout);
    }
}
    return 0;
}