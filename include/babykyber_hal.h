#ifndef BABYKYBER_HAL_H
#define BABYKYBER_HAL_H

#include <stdint.h>

// Hardware Abstraction Layer functions

// Send A matrix (4x4 = 16 words)
void hal_send_A(uint32_t A[4][4]);

// Send s (2x4 = 8 words)
void hal_send_s(uint32_t s[2][4]);

// Send e (2x4 = 8 words)
void hal_send_e(uint32_t e[2][4]);

// Send message
void hal_send_message(uint32_t message);

// Send r (2x4 = 8 words)
void hal_send_r(uint32_t r[2][4]);

// Send e1 (2x4 = 8 words)
void hal_send_e1(uint32_t e1[2][4]);

// Send e2 (4 words)
void hal_send_e2(uint32_t e2[4]);

// Trigger key generation
void hal_trigger_keygen(uint32_t trigger_addr);

// Trigger encryption
void hal_trigger_encrypt(uint32_t trigger_addr);

// Trigger decryption
void hal_trigger_decrypt(uint32_t trigger_addr);

// Read public key (2x4x4 = 32 words)
void hal_read_public_key(uint32_t public_key[2][4][4]);

// Read secret key (2x4 = 8 words)
void hal_read_secret_key(uint32_t secret_key[2][4]);

// Read ciphertext (2x2x4 = 16 words)
void hal_read_ciphertext(uint32_t ciphertext[2][2][4]);

// Read decrypted message
uint32_t hal_read_decrypted_message();

// Read decrypted value
uint32_t hal_read_decrypted_value();

// Read decrypted m_b
uint32_t hal_read_decrypted_mb();

// Check if key generation is done (commented out for now)
// int hal_is_key_done();

// Check if encryption is done (commented out for now)
// int hal_is_encrypt_done();

// Check if decryption is done (commented out for now)
// int hal_is_decrypt_done();

#endif // BABYKYBER_HAL_H
