#ifndef BABYKYBER_H
#define BABYKYBER_H

#include <stdint.h>

// API for BabyKyber SDK

// Initialize the BabyKyber module
volatile void babykyber_init();

// Key Generation
// Inputs: A[4][4], s[2][4], e[2][4], keygen_trigger_addr
volatile void babykyber_keygen(uint32_t A[4][4], uint32_t s[2][4], uint32_t e[2][4],
                      uint32_t keygen_trigger_addr);

// Encryption
// Inputs: message, r[2][4], e1[2][4], e2[4], encrypt_trigger_addr
volatile void babykyber_encrypt(uint32_t message,
                       uint32_t r[2][4], uint32_t e1[2][4], uint32_t e2[4],
                       uint32_t encrypt_trigger_addr);

// Decryption
// Inputs: decrypt_trigger_addr
// Outputs: public_key[2][4][4], secret_key[2][4], ciphertext[2][2][4], decrypted_message, decrypted_value, m_b
volatile void babykyber_decrypt(uint32_t decrypt_trigger_addr,
                       uint32_t public_key[2][4][4], uint32_t secret_key[2][4],
                       uint32_t ciphertext[2][2][4],
                       uint32_t *decrypted_message, uint32_t *decrypted_value, uint32_t *m_b);

#endif // BABYKYBER_H
