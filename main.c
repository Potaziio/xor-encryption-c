#include "xor_encrypt.h"

// generate key, encrypt plain text with key, decrypt encrypted text
int main(int argc, char** argv)
{
    // Seeds time 
    time_t t;
    time(&t);
    srand((unsigned int)t);

    char* plain_text = argc > 1 ? argv[1] : "";
    size_t text_size = strlen(plain_text);

    char* key = generate_key(plain_text, text_size);

    if (key == NULL) return 0;

    char* encrypted = xor_encrypt(plain_text, key, text_size);

    if (encrypted == NULL) return 0;

    char* decrypted = xor_decrypt(encrypted, key, text_size);

    printf("Plain: %s\n", plain_text);
    printf("Key: %s\n", key);
    printf("Encrypted: ");

    // Checks if the character is printable, dont want to spook users
    for (int i = 0; i < text_size; i++) {
        if (isprint(encrypted[i])) {
            putchar(encrypted[i]);
        } else {
            printf("\\x%02X", (unsigned char)encrypted[i]);
        }
    }

    putchar('\n');
    printf("Decrypted: %s\n", decrypted);

    // deallocate memory like a good boi
    free(key);
    free(encrypted);
    free(decrypted);

    return 0;
}

