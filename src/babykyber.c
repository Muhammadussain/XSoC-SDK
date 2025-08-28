#include "babykyber.h"
#include "babykyber_hal.h"
#include "babykyber_regs.h"

// BabyKyber Constants and Values

// Random vector for encryption (8 values)
const uint32_t r_vector[8] = {25, 26, 27, 28, 29, 30, 31, 32};

// Error vector 1 for encryption (8 values)
const uint32_t e1_vector[8] = {33, 34, 35, 36, 37, 38, 39, 40};

// Error vector 2 for encryption (4 values)
const uint32_t e2_vector[4] = {41, 42, 43, 44};

// Demo message value
const uint32_t demo_message = 42;

// Demo A_t matrix (4x4)
const uint32_t demo_A_t[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
};

// Demo s vector (8 values)
const uint32_t demo_s[8] = {17, 18, 19, 20, 21, 22, 23, 24};

// Demo e vector (8 values)
const uint32_t demo_e[8] = {25, 26, 27, 28, 29, 30, 31, 32};

// Demo public key (24 values for 2 polynomials)
const uint32_t demo_pk[24] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};

// Demo ciphertext (12 values for decryption)
const uint32_t demo_ct[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

int main() {
    // Use the demo constants to set up the hardware registers
    
    // Set A_t matrix - using exact addresses from main.c
    babykyber_write_reg(0x40007000, demo_A_t[0][0]);
    babykyber_write_reg(0x40007004, demo_A_t[0][1]);
    babykyber_write_reg(0x40007008, demo_A_t[0][2]);
    babykyber_write_reg(0x40007012, demo_A_t[0][3]);
    babykyber_write_reg(0x40007016, demo_A_t[1][0]);
    babykyber_write_reg(0x40007020, demo_A_t[1][1]);
    babykyber_write_reg(0x40007024, demo_A_t[1][2]);
    babykyber_write_reg(0x40007028, demo_A_t[1][3]);
    babykyber_write_reg(0x40007032, demo_A_t[2][0]);
    babykyber_write_reg(0x40007036, demo_A_t[2][1]);
    babykyber_write_reg(0x40007040, demo_A_t[2][2]);
    babykyber_write_reg(0x40007044, demo_A_t[2][3]);
    babykyber_write_reg(0x40007048, demo_A_t[3][0]);
    babykyber_write_reg(0x40007052, demo_A_t[3][1]);
    babykyber_write_reg(0x40007056, demo_A_t[3][2]);
    babykyber_write_reg(0x40007060, demo_A_t[3][3]);
    
    // Set s vector - using exact addresses from main.c
    babykyber_write_reg(0x40007064, demo_s[0]);
    babykyber_write_reg(0x40007068, demo_s[1]);
    babykyber_write_reg(0x40007072, demo_s[2]);
    babykyber_write_reg(0x40007076, demo_s[3]);
    babykyber_write_reg(0x40007080, demo_s[4]);
    babykyber_write_reg(0x40007084, demo_s[5]);
    babykyber_write_reg(0x40007088, demo_s[6]);
    babykyber_write_reg(0x40007092, demo_s[7]);
    
    // Set e vector - using exact addresses from main.c
    babykyber_write_reg(0x40007096, demo_e[0]);
    babykyber_write_reg(0x40007100, demo_e[1]);
    babykyber_write_reg(0x40007104, demo_e[2]);
    babykyber_write_reg(0x40007108, demo_e[3]);
    babykyber_write_reg(0x40007112, demo_e[4]);
    babykyber_write_reg(0x40007116, demo_e[5]);
    babykyber_write_reg(0x40007120, demo_e[6]);
    babykyber_write_reg(0x40007124, demo_e[7]);
    
    // Trigger key generation
    babykyber_write_reg(BABYKYBER_KEYGEN_TRIGGER, 0);
    
    // Set message
    babykyber_write_reg(BABYKYBER_MESSAGE, demo_message);
    
    // Set public key for encryption - using exact addresses from main.c
    babykyber_write_reg(0x40007132, demo_pk[0]);
    babykyber_write_reg(0x40007136, demo_pk[1]);
    babykyber_write_reg(0x40007140, demo_pk[2]);
    babykyber_write_reg(0x40007144, demo_pk[3]);
    babykyber_write_reg(0x40007148, demo_pk[4]);
    babykyber_write_reg(0x40007152, demo_pk[5]);
    babykyber_write_reg(0x40007156, demo_pk[6]);
    babykyber_write_reg(0x40007160, demo_pk[7]);
    babykyber_write_reg(0x40007164, demo_pk[8]);
    babykyber_write_reg(0x40007168, demo_pk[9]);
    babykyber_write_reg(0x40007172, demo_pk[10]);
    babykyber_write_reg(0x40007176, demo_pk[11]);
    babykyber_write_reg(0x40007180, demo_pk[12]);
    babykyber_write_reg(0x40007184, demo_pk[13]);
    babykyber_write_reg(0x40007188, demo_pk[14]);
    babykyber_write_reg(0x40007192, demo_pk[15]);
    babykyber_write_reg(0x40007196, demo_pk[16]);
    babykyber_write_reg(0x40007200, demo_pk[17]);
    babykyber_write_reg(0x40007204, demo_pk[18]);
    babykyber_write_reg(0x40007208, demo_pk[19]);
    babykyber_write_reg(0x40007212, demo_pk[20]);
    babykyber_write_reg(0x40007216, demo_pk[21]);
    babykyber_write_reg(0x40007220, demo_pk[22]);
    babykyber_write_reg(0x40007224, demo_pk[23]);
    
    // Set r vector - using exact addresses from main.c
    babykyber_write_reg(0x40007228, r_vector[0]);
    babykyber_write_reg(0x40007232, r_vector[1]);
    babykyber_write_reg(0x40007236, r_vector[2]);
    babykyber_write_reg(0x40007240, r_vector[3]);
    babykyber_write_reg(0x40007244, r_vector[4]);
    babykyber_write_reg(0x40007248, r_vector[5]);
    babykyber_write_reg(0x40007252, r_vector[6]);
    babykyber_write_reg(0x40007256, r_vector[7]);
    
    // Set e1 vector - using exact addresses from main.c
    babykyber_write_reg(0x40007260, e1_vector[0]);
    babykyber_write_reg(0x40007264, e1_vector[1]);
    babykyber_write_reg(0x40007268, e1_vector[2]);
    babykyber_write_reg(0x40007272, e1_vector[3]);
    babykyber_write_reg(0x40007276, e1_vector[4]);
    babykyber_write_reg(0x40007280, e1_vector[5]);
    babykyber_write_reg(0x40007284, e1_vector[6]);
    babykyber_write_reg(0x40007288, e1_vector[7]);
    
    // Set e2 vector - using exact addresses from main.c
    babykyber_write_reg(0x40007292, e2_vector[0]);
    babykyber_write_reg(0x40007296, e2_vector[1]);
    babykyber_write_reg(0x40007300, e2_vector[2]);
    babykyber_write_reg(0x40007304, e2_vector[3]);
    
    // Trigger encryption
    babykyber_write_reg(BABYKYBER_ENCRYPT_TRIGGER, 0);
    
    // Set ciphertext for decryption - using exact addresses from main.c
    babykyber_write_reg(0x40007308, demo_ct[0]);
    babykyber_write_reg(0x40007312, demo_ct[1]);
    babykyber_write_reg(0x40007316, demo_ct[2]);
    babykyber_write_reg(0x40007320, demo_ct[3]);
    babykyber_write_reg(0x40007324, demo_ct[4]);
    babykyber_write_reg(0x40007328, demo_ct[5]);
    babykyber_write_reg(0x40007332, demo_ct[6]);
    babykyber_write_reg(0x40007336, demo_ct[7]);
    babykyber_write_reg(0x40007340, demo_ct[8]);
    babykyber_write_reg(0x40007344, demo_ct[9]);
    babykyber_write_reg(0x40007348, demo_ct[10]);
    babykyber_write_reg(0x40007352, demo_ct[11]);
    
    // Trigger decryption
    babykyber_write_reg(BABYKYBER_DECRYPT_TRIGGER, 0);
    
    // Wait for completion (in real implementation, check status register)
    volatile uint32_t result = babykyber_read_reg(BABYKYBER_RESULT);
    (void)result; // Prevent unused warning
    
    while (1); // Halt
    
    return 0;
}
