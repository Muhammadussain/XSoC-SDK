#include "babykyber.h"
#include "babykyber_regs.h"
#include <stdint.h>
#include <inttypes.h>

// Global arrays with initializers
uint32_t A[4][4] = {
    {4,3,2,1},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}
};
uint32_t s[2][4] = {
    {1, 16, 0, 1},
    {16, 0, 1, 16}
};
uint32_t e[2][4] = {
    {0,1,16,0},
    {1,16,0,1}
};
uint32_t r[2][4] = {
    {16,0,1,16},
    {0,1,16,0}
};
uint32_t e1[2][4] = {
    {1,0,16,1},
    {16,0,1,16}
};
uint32_t e2[4] = {0,16,1,0};
volatile uint32_t message; // Global declaration without initializer
// File-scope output buffers so a simulator or host can inspect results
volatile uint32_t public_key[2][4][4];
volatile uint32_t secret_key[2][4];
volatile uint32_t ciphertext[2][2][4];
volatile uint32_t decrypted_value;
volatile uint32_t m_b;
volatile uint32_t decrypted_message;

int main() {
    message = 11; // Initialize in main

    /* Demo sequence */
    babykyber_init();
    babykyber_keygen(A, s, e);
    babykyber_encrypt(message, r, e1, e2);

    /* Trigger decrypt and read outputs into file-scope buffers */
    babykyber_decrypt();
    babykyber_read_public_key(public_key);
    babykyber_read_secret_key(secret_key);
    babykyber_read_ciphertext(ciphertext);
    babykyber_read_decrypted_message(&decrypted_message);
    babykyber_read_decrypted_value(&decrypted_value);
    babykyber_read_decrypted_mb(&m_b);

    // No host printf: results available in memory or via simulator memory reads

    return 0;
}
