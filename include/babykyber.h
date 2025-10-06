#ifndef BABYKYBER_H
#define BABYKYBER_H

#include <stdint.h>

// API for BabyKyber SDK

// Initialize the BabyKyber module
void babykyber_init(void);

// Key Generation
// Inputs: A[4][4], s[2][4], e[2][4]
// The trigger address is handled internally; users don't need to provide it.
void babykyber_keygen(uint32_t A[4][4], uint32_t s[2][4], uint32_t e[2][4]);

// Encryption
// Inputs: message, r[2][4], e1[2][4], e2[4]
// The trigger address is handled internally; users don't need to provide it.
void babykyber_encrypt(uint32_t message,
                       uint32_t r[2][4], uint32_t e1[2][4], uint32_t e2[4]);

// Decryption
// The decrypt function now only returns the decrypted message. If callers
// need the public key, secret key, ciphertext or other decrypted values,
// they can call the separate read functions after decrypt.
// Trigger decryption. The function is trigger-only; use the read helpers
// to fetch outputs into caller-provided buffers.
void babykyber_decrypt(void);

// Read-only accessors to fetch outputs after a decrypt operation.
void babykyber_read_public_key(volatile uint32_t public_key[2][4][4]);
void babykyber_read_secret_key(volatile uint32_t secret_key[2][4]);
void babykyber_read_ciphertext(volatile uint32_t ciphertext[2][2][4]);
// Read scalar decrypted outputs into caller-provided storage (accepts
// volatile pointers so file-scope volatile buffers can be passed).
void babykyber_read_decrypted_message(volatile uint32_t *decrypted_message);
void babykyber_read_decrypted_value(volatile uint32_t *decrypted_value);
void babykyber_read_decrypted_mb(volatile uint32_t *m_b);

#endif // BABYKYBER_H
