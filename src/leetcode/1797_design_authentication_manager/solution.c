//
// Created by Ábrahám Dávid on 2026. 05. 10..
//

#include <stdlib.h>
#include <string.h>

typedef struct Token {
    char *tokenId;
    int expire;
    struct Token *next;
} Token;

typedef struct AuthenticationManager {
    int timeToLive;
    Token *head;
} AuthenticationManager;


AuthenticationManager *authenticationManagerCreate(int timeToLive) {
    AuthenticationManager *manager = calloc(1, sizeof(AuthenticationManager));
    manager->timeToLive = timeToLive;
    manager->head = NULL;

    return manager;
}

void authenticationManagerGenerate(AuthenticationManager *manager, char *tokenId, int currentTime) {
    Token *new_token = calloc(1, sizeof(Token));
    new_token->tokenId = strdup(tokenId);
    new_token->expire = manager->timeToLive + currentTime;

    new_token->next = manager->head;
    manager->head = new_token;
}

void authenticationManagerRenew(AuthenticationManager *manager, char *tokenId, int currentTime) {
    Token *current = manager->head;
    while (current != NULL) {
        if (strcmp(current->tokenId, tokenId) == 0) {
            if (current->expire > currentTime) {
                current->expire = currentTime + manager->timeToLive;
            }
        }

        current = current->next;
    }
}

int authenticationManagerCountUnexpiredTokens(AuthenticationManager *manager, int currentTime) {
    int count = 0;
    Token *current = manager->head;
    while (current != NULL) {
        if (current->expire > currentTime) count++;

        current = current->next;
    }

    return count;
}

void authenticationManagerFree(AuthenticationManager *manager) {
    Token *current = manager->head;
    while (current != NULL) {
        Token *next = current->next;
        free(current->tokenId);
        free(current);
        current = next;
    }

    free(manager);
    manager = NULL;
}
