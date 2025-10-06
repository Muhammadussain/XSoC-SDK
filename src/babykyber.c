#include "babykyber.h"
#include "babykyber_hal.h"
#include "babykyber_regs.h"
#include <stdint.h>

// Implementation of BabyKyber API

void babykyber_init(void) {
    // No-op init
}

void babykyber_keygen(uint32_t A[4][4], uint32_t s[2][4], uint32_t e[2][4]) {
    hal_send_A(A);
    hal_send_s(s);
    hal_send_e(e);
    hal_trigger_keygen(BABYKYBER_KEYGEN_TRIGGER_ADDR);
}

void babykyber_encrypt(uint32_t message,
                       uint32_t r[2][4], uint32_t e1[2][4], uint32_t e2[4]) {
    hal_send_message(message);
    hal_send_r(r);
    hal_send_e1(e1);
    hal_send_e2(e2);
    hal_trigger_encrypt(BABYKYBER_ENCRYPT_TRIGGER_ADDR);
}

void babykyber_decrypt(void) {
    // Trigger decryption using internal register address
    hal_trigger_decrypt(BABYKYBER_DECRYPT_TRIGGER_ADDR);
}

void babykyber_read_public_key(volatile uint32_t public_key[2][4][4]) {
    hal_read_public_key(public_key);
}

void babykyber_read_secret_key(volatile uint32_t secret_key[2][4]) {
    hal_read_secret_key(secret_key);
}

void babykyber_read_ciphertext(volatile uint32_t ciphertext[2][2][4]) {
    hal_read_ciphertext(ciphertext);
}

void babykyber_read_decrypted_message(volatile uint32_t *decrypted_message) {
    if (decrypted_message) {
        *decrypted_message = hal_read_decrypted_message();
    }
}

void babykyber_read_decrypted_value(volatile uint32_t *decrypted_value) {
    if (decrypted_value) {
        *decrypted_value = hal_read_decrypted_value();
    }
}

void babykyber_read_decrypted_mb(volatile uint32_t *m_b) {
    if (m_b) {
        *m_b = hal_read_decrypted_mb();
    }
}
