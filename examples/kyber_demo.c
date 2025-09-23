#include "babykyber.h"
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

int main() {
    // Initialize
    babykyber_init();

    uint32_t public_key[2][4][4];
    uint32_t secret_key[2][4];

    // Key generation
    babykyber_keygen(A, s, e, public_key, secret_key);

    // Encryption inputs (from testbench)
    uint32_t message = 11; // expected_message in tb
    uint32_t ciphertext[2][2][4];

    babykyber_encrypt(message, public_key, r, e1, e2, ciphertext);

    // Decryption
    uint32_t decrypted_message, decrypted_value, m_b;
    babykyber_decrypt(ciphertext, secret_key, &decrypted_message, &decrypted_value, &m_b);

    // No host printf: results available in memory or via simulator memory reads

    return 0;
}
