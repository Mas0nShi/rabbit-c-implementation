#include "ecrypt-sync.h"
#include "stdio.h"
#include "stdint.h"
#include "string.h"

void print_hex(const char *tag, uint8_t *arg, int len) {
    printf("%12s: ", tag);    
    for (int i = 0; i < len; i++) printf("%02X ", arg[i]);
    printf("\n");
}

int main(int argc, char **argv) {
    uint8_t buf[16] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };
    uint8_t out[16] = {};

    uint8_t key[16] = { 0x91, 0x28, 0x13, 0x29, 0x2E, 0xED, 0x36, 0xFE, 0x3B, 0xFC, 0x62, 0xF1, 0xDC, 0x51, 0xC3, 0xAC };
    uint8_t iv[8] = { 0xC3, 0x73, 0xF5, 0x75, 0xC1, 0x26, 0x7E, 0x59 };
    
    ECRYPT_ctx ctx;
    

    ECRYPT_keysetup(&ctx, key, 16, 8);
    ECRYPT_ivsetup(&ctx, iv);

    ECRYPT_encrypt_bytes(&ctx, buf, out, 16);

    printf("======Rabbit encrypt unit 1======\n");  
    print_hex("plaintext", buf, 16);
    print_hex("key", key, 16); 
    print_hex("iv", iv, 8);
    print_hex("out", out, 16);

    ECRYPT_keysetup(&ctx, key, 16, 8);
    ECRYPT_ivsetup(&ctx, iv);

    ECRYPT_decrypt_bytes(&ctx, out, buf, 16);

    printf("\n");

    printf("======Rabbit decrypt unit 1======\n");  
    print_hex("ciphertext", out, 16);
    print_hex("key", key, 16); 
    print_hex("iv", iv, 8);
    print_hex("out", buf, 16);

    printf("\n\n");
    // See: https://www.cryptopp.com/wiki/Rabbit
    uint8_t buf2[25] = "Rabbit stream cipher test";
    uint8_t out2[25] = {};
    uint8_t key2[16] = { 0x23,0xc2,0x73,0x1e,0x8b,0x54,0x69,0xfd,0x8d,0xab,0xb5,0xbc,0x59,0x2a,0x0f,0x3a };
    uint8_t iv2[8] = { 0x71,0x29,0x06,0x40,0x5e,0xf0,0x32,0x01 };
    
    ECRYPT_keysetup(&ctx, key2, 16, 0);
    ECRYPT_ivsetup(&ctx, iv2);

    ECRYPT_encrypt_bytes(&ctx, buf2, out2, 25);

    printf("======Rabbit encrypt unit 2======\n");  
    print_hex("plaintext2", buf2, 25);
    print_hex("key2", key2, 16); 
    print_hex("iv2", iv, 8);
    print_hex("out2", out2, 25);


    printf("\n");

    ECRYPT_keysetup(&ctx, key2, 16, 0);
    ECRYPT_ivsetup(&ctx, iv2);
    ECRYPT_decrypt_bytes(&ctx, out2, buf2, 25);

    printf("======Rabbit decrypt unit 2======\n");  
    print_hex("ciphertext2", out2, 25);
    print_hex("key2", key2, 16); 
    print_hex("iv2", iv, 8);
    print_hex("out2", buf2, 25);
}


