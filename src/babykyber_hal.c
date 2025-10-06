#include "babykyber_hal.h"
#include "babykyber_regs.h"
#include <stdint.h>

// Send A matrix (4x4)
void hal_send_A(uint32_t A[4][4]) {
    volatile uint32_t *ptr;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            ptr = (volatile uint32_t *)(BABYKYBER_A_ADDR + (i*4 + j) * 4);
            *ptr = A[i][j];
        }
    }
}

// Send s (2x4)
void hal_send_s(uint32_t s[2][4]) {
    volatile uint32_t *ptr;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            ptr = (volatile uint32_t *)(BABYKYBER_S_ADDR + (i*4 + j) * 4);
            *ptr = s[i][j];
        }
    }
}

// Send e (2x4)
void hal_send_e(uint32_t e[2][4]) {
    volatile uint32_t *ptr;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            ptr = (volatile uint32_t *)(BABYKYBER_E_ADDR + (i*4 + j) * 4);
            *ptr = e[i][j];
        }
    }
}

// Send message
void hal_send_message(uint32_t message) {
    volatile uint32_t *ptr = (volatile uint32_t *)BABYKYBER_MESSAGE_ADDR;
    *ptr = message;
}

// Send r (2x4)
void hal_send_r(uint32_t r[2][4]) {
    volatile uint32_t *ptr;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            ptr = (volatile uint32_t *)(BABYKYBER_R_ADDR + (i*4 + j) * 4);
            *ptr = r[i][j];
        }
    }
}

// Send e1 (2x4)
void hal_send_e1(uint32_t e1[2][4]) {
    volatile uint32_t *ptr;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            ptr = (volatile uint32_t *)(BABYKYBER_E1_ADDR + (i*4 + j) * 4);
            *ptr = e1[i][j];
        }
    }
}

// Send e2 (4 words)
void hal_send_e2(uint32_t e2[4]) {
    volatile uint32_t *ptr;
    for (int i = 0; i < 4; i++) {
        ptr = (volatile uint32_t *)(BABYKYBER_E2_ADDR + i * 4);
        *ptr = e2[i];
    }
}

// Read ciphertext (2x2x4 = 16 words)
void hal_read_ciphertext(volatile uint32_t ciphertext[2][2][4]) {
    volatile uint32_t *ptr;
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                ptr = (volatile uint32_t *)(BABYKYBER_CIPHERTEXT_ADDR + (k*8 + i*4 + j) * 4);
                ciphertext[k][i][j] = *ptr;
            }
        }
    }
}

// Triggers: simple MMIO write of 1
void hal_trigger_keygen(uint32_t trigger_addr) {
    volatile uint32_t *ptr = (volatile uint32_t *)trigger_addr;
    *ptr = 1;
}

void hal_trigger_encrypt(uint32_t trigger_addr) {
    volatile uint32_t *ptr = (volatile uint32_t *)trigger_addr;
    *ptr = 1;
}

void hal_trigger_decrypt(uint32_t trigger_addr) {
    volatile uint32_t *ptr = (volatile uint32_t *)trigger_addr;
    *ptr = 1;
}

// Read public key (2x4x4 = 32 words)
void hal_read_public_key(volatile uint32_t public_key[2][4][4]) {
    volatile uint32_t *ptr;
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                ptr = (volatile uint32_t *)(BABYKYBER_PUBLIC_KEY_ADDR + (k*16 + i*4 + j) * 4);
                public_key[k][i][j] = *ptr;
            }
        }
    }
}

// Read secret key (2x4 = 8 words)
void hal_read_secret_key(volatile uint32_t secret_key[2][4]) {
    volatile uint32_t *ptr;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            ptr = (volatile uint32_t *)(BABYKYBER_SECRET_KEY_ADDR + (i*4 + j) * 4);
            secret_key[i][j] = *ptr;
        }
    }
}

// Read decrypted message
uint32_t hal_read_decrypted_message() {
    volatile uint32_t *ptr = (volatile uint32_t *)BABYKYBER_DECRYPTED_MESSAGE_ADDR;
    return *ptr;
}

// Read decrypted value
uint32_t hal_read_decrypted_value() {
    volatile uint32_t *ptr = (volatile uint32_t *)BABYKYBER_DECRYPTED_VALUE_ADDR;
    return *ptr;
}

// Read decrypted m_b
uint32_t hal_read_decrypted_mb() {
    volatile uint32_t *ptr = (volatile uint32_t *)BABYKYBER_DECRYPTED_MB_ADDR;
    return *ptr;
}

// Check if key generation is done (commented out for now)
// int hal_is_key_done() {
//     volatile uint32_t *ptr = (volatile uint32_t *)BABYKYBER_KEY_DONE_ADDR;
//     return *ptr;
// }

// Check if encryption is done (commented out for now)
// int hal_is_encrypt_done() {
//     volatile uint32_t *ptr = (volatile uint32_t *)BABYKYBER_ENCRYPT_DONE_ADDR;
//     return *ptr;
// }

// Check if decryption is done (commented out for now)
// int hal_is_decrypt_done() {
//     volatile uint32_t *ptr = (volatile uint32_t *)BABYKYBER_DECRYPT_DONE_ADDR;
//     return *ptr;
// }
