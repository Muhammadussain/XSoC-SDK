#ifndef BABYKYBER_REGS_H
#define BABYKYBER_REGS_H

// Base address for BabyKyber registers
#define BABYKYBER_BASE 0x40007000

// Key Generation Input Registers (A matrix: 4x4 = 16 words)
#define BABYKYBER_A_ADDR (BABYKYBER_BASE + 0x000)  // 16 writes

// Secret key s (2x4 = 8 words)
#define BABYKYBER_S_ADDR (BABYKYBER_BASE + 0x040)  // 8 writes

// Error e (2x4 = 8 words)
#define BABYKYBER_E_ADDR (BABYKYBER_BASE + 0x060)  // 8 writes

// Encryption Inputs
#define BABYKYBER_MESSAGE_ADDR (BABYKYBER_BASE + 0x080)  // 1 write
#define BABYKYBER_R_ADDR (BABYKYBER_BASE + 0x084)  // 8 writes
#define BABYKYBER_E1_ADDR (BABYKYBER_BASE + 0x0A4)  // 8 writes
#define BABYKYBER_E2_ADDR (BABYKYBER_BASE + 0x0C4)  // 4 writes

// Triggers
#define BABYKYBER_KEYGEN_TRIGGER_ADDR (BABYKYBER_BASE + 0x164)  // 1 write
#define BABYKYBER_ENCRYPT_TRIGGER_ADDR (BABYKYBER_BASE + 0x168)  // 1 write
#define BABYKYBER_DECRYPT_TRIGGER_ADDR (BABYKYBER_BASE + 0x16C)  // 1 write

// Outputs (Read-only) -- addresses moved after input region to avoid overlap
#define BABYKYBER_PUBLIC_KEY_ADDR      (BABYKYBER_BASE + 0x200)  // 32 reads (2x4x4)
#define BABYKYBER_SECRET_KEY_ADDR      (BABYKYBER_BASE + 0x2CC)  // 8 reads (2x4)
#define BABYKYBER_CIPHERTEXT_ADDR      (BABYKYBER_BASE + 0x280)  // 16 reads (2x2x4)
#define BABYKYBER_DECRYPTED_MESSAGE_ADDR (BABYKYBER_BASE + 0x2C0)  // 1 read
#define BABYKYBER_DECRYPTED_VALUE_ADDR   (BABYKYBER_BASE + 0x2C4)  // 1 read
#define BABYKYBER_DECRYPTED_MB_ADDR      (BABYKYBER_BASE + 0x2C8)  // 1 read

// Status registers (commented out for now)
// #define BABYKYBER_KEY_DONE_ADDR (BABYKYBER_BASE + 0x300)  // 1 read
// #define BABYKYBER_ENCRYPT_DONE_ADDR (BABYKYBER_BASE + 0x304)  // 1 read
// #define BABYKYBER_DECRYPT_DONE_ADDR (BABYKYBER_BASE + 0x308)  // 1 read

#endif // BABYKYBER_REGS_H
