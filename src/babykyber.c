#include "babykyber.h"
#include "babykyber_hal.h"
#include "babykyber_regs.h"
#include <stdint.h>

// Implementation of BabyKyber API

void babykyber_init() {
    // Initialization if needed
}

void babykyber_keygen(uint32_t A[4][4], uint32_t s[2][4], uint32_t e[2][4],
                      uint32_t public_key[2][4][4], uint32_t secret_key[2][4]) {
    // Send A matrix
    hal_send_A(A);

    // Send s
    hal_send_s(s);

    // Send e
    hal_send_e(e);

    // Trigger key generation
    hal_trigger_keygen();

    // Wait for completion
    while (!hal_is_key_done());

    // Read public key
    hal_read_public_key(public_key);

   
}

void babykyber_encrypt(uint32_t message, uint32_t public_key[2][4][4],
                       uint32_t r[2][4], uint32_t e1[2][4], uint32_t e2[4],
                       uint32_t ciphertext[2][2][4]) {
    // Send message
    hal_send_message(message);

    // Send r
    hal_send_r(r);

    // Send e1
    hal_send_e1(e1);

    // Send e2
    hal_send_e2(e2);

    // Trigger encryption
    hal_trigger_encrypt();

    // Wait for completion
    while (!hal_is_encrypt_done());

    // Read ciphertext
    hal_read_ciphertext(ciphertext);
}

void babykyber_decrypt(uint32_t ciphertext[2][2][4], uint32_t secret_key[2][4],
                       uint32_t *decrypted_message, uint32_t *decrypted_value, uint32_t *m_b) {
    // Ciphertext is already in hardware from encryption, or assume it's set

    // Trigger decryption
    hal_trigger_decrypt();

    // Wait for completion
    while (!hal_is_decrypt_done());

    // Read outputs
    *decrypted_message = hal_read_decrypted_message();
    *decrypted_value = hal_read_decrypted_value();
    *m_b = hal_read_decrypted_mb();
}
