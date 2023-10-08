#include "xor_encrypt.h"

/* generate_key(char*, int)
 * generates a random key same size as text
 * params: str text : plain text to generate key on
 *         str size : size of text
 * returns: str key, remember to free it 
*/
char* generate_key(char* text, size_t size)
{   
    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    char* key = (char*)malloc(sizeof(char) * size);

    // Fails if we cant allocate
    if (key == NULL)
    {
        fprintf(stderr, "Failed to allocate size for key\n");
        return NULL;
    }   

    // get a random character from the list and append it to key[n]
    for (int i = 0; i < size; i++)
        key[i] = characters[rand() % strlen(characters)];

    return key;
} 

/* xor_encrypt(char*, char*, int)
 * encrypts text and returns the encrypted text
 * params: str text : plain text to encrypts
 *         str key : key generated beforehand
 *         int size : size of plain text, key is same size as well
 * returns: str encrypted message, remember to free this
*/
char* xor_encrypt(char* text, char* key, size_t size)
{
    char* encrypted = (char*)malloc(sizeof(char) * size);
   
    // fails if we cant allocate
    if (encrypted == NULL)
    {
        fprintf(stderr, "Failed to allocate size for encrypted message\n");
        return NULL;
    }

    // xor with key through every byte in the text
    for (int i = 0; i < size; i++)
        encrypted[i] = text[i] ^ key[i % strlen(key)];
    
    // null character termination
    encrypted[size] = '\0';

    return encrypted;
}

/* xor_decrypt(char*, char*, int)
 * decrypts the text using the key used to encrypts
 * params: str encrypted : encrypted text to decrypt
 *         str key : key used to encrypt
 *         int size : size of strings, size is same for key, plain text, and encrypted text
 * returns: str decrypted message, remember to free this 
*/
char* xor_decrypt(char* encrypted, char* key, size_t size)
{
    char* decrypted = (char*)malloc(sizeof(char) * size);

    // fails if we cant allocate
    if (decrypted == NULL)
    {
        fprintf(stderr, "Failed to allocate size for decrypted message\n");
        return NULL;
    }

    // xors through every byte of the encrypted text with the key, reverses the encrypt operation
    for (int i = 0; i < size; i++)
        decrypted[i] = encrypted[i] ^ key[i % strlen(key)];

    // null character termination
    decrypted[size] = '\0';

    return decrypted;
}

