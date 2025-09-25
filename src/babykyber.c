#include "babykyber.h"
#include "babykyber_hal.h"
#include "babykyber_regs.h"
#include <stdint.h>

// Implementation of BabyKyber API

void babykyber_init() {
    // Initialization if needed
}

void babykyber_keygen(uint32_t A[4][4], uint32_t s[2][4], uint32_t e[2][4],
                      uint32_t keygen_trigger_addr) {
    // Send A matrix
    hal_send_A(A);

    // Send s
    hal_send_s(s);

    // Send e
    hal_send_e(e);

    // Trigger key generation
    hal_trigger_keygen(keygen_trigger_addr);
}

void babykyber_encrypt(uint32_t message,
                       uint32_t r[2][4], uint32_t e1[2][4], uint32_t e2[4],
                       uint32_t encrypt_trigger_addr) {
    // Send message
    hal_send_message(message);

    // Send r
    hal_send_r(r);

    // Send e1
    hal_send_e1(e1);

    // Send e2
    hal_send_e2(e2);

    // Trigger encryption
    hal_trigger_encrypt(encrypt_trigger_addr);
}

void babykyber_decrypt(uint32_t decrypt_trigger_addr,
                       uint32_t public_key[2][4][4], uint32_t secret_key[2][4],
                       uint32_t ciphertext[2][2][4],
                       uint32_t *decrypted_message, uint32_t *decrypted_value, uint32_t *m_b) {
    // Trigger decryption
    hal_trigger_decrypt(decrypt_trigger_addr);

    // Read outputs
    hal_read_public_key(public_key);
    hal_read_secret_key(secret_key);
    hal_read_ciphertext(ciphertext);
    *decrypted_message = hal_read_decrypted_message();
    *decrypted_value = hal_read_decrypted_value();
    *m_b = hal_read_decrypted_mb();
}
