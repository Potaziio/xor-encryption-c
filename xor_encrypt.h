/*
 * XOR ENCRYPTION/DECRYPTION IMPLEMENTATION IN C
 *
 * plain text >> key >> encrypted message
 * encrypted message >> key >> plain text
*/

#ifndef XOR_ENCRYPT_H
#define XOR_ENCRYPT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

char* generate_key(char* text, size_t size);
char* xor_encrypt(char* text, char* key, size_t size);
char* xor_decrypt(char* encrypted, char* key, size_t size);

#endif

