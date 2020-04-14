#pragma once

#ifndef _SIMON_6496_H
#define _SIMON_6496_H

#define BLOCK_SIZE 8
#define IV_LEN 8
#define KEY_LEN 12
#define KEY 3
#define KEY_ROUND 42

#include "utils.h"
#include <string.h>

void inline SimonKeySchedule(uint32_t K[], uint32_t rk[])
{
    uint32_t i, c = 0xfffffffc;
    uint64_t z = 0x7369f885192c0ef5LL;
    rk[0] = K[0];
    rk[1] = K[1];
    rk[2] = K[2];
    for (i = 3; i < 42; i++)
    {
        rk[i] = c ^ (z & 1) ^ rk[i - 3] ^ ROTR32(rk[i - 1], 3) ^ ROTR32(rk[i - 1], 4);
        z >>= 1;
    }
}

void inline SimonEncrypt(uint32_t Pt[], uint32_t Ct[], uint32_t rk[])
{
    uint32_t i;
    Ct[1] = Pt[1];
    Ct[0] = Pt[0];
    for (i = 0; i < 42;)
        R32x2(Ct[1], Ct[0], rk[i++], rk[i++]);
}

/**
 * For every block:
 * 1. Concat/xor/add nonce  with counter (random nonce)
 * 2. Encrypt nonce
 * 3. XOR between encrypted nonce and plain
 * 4. Increment counter
 */
MAVLINK_HELPER void Simon6496(uint8_t *nonce, uint8_t *key, uint8_t *plaintext, int length)
{
    uint32_t K[KEY];
    uint32_t rk[KEY_ROUND];

    BytesToWords32(key, K, KEY_LEN);
    SimonKeySchedule(K, rk);

    int block = 0;
    int last_block;
    uint8_t counter[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    uint32_t Pt[2];
    uint32_t Ct[2];
    uint8_t workingNonce[BLOCK_SIZE];
    uint8_t ct[length];

    last_block = length - BLOCK_SIZE;

    if (length > BLOCK_SIZE)
    {
        for (block = 0; block < last_block; block += BLOCK_SIZE)
        {
            //STEP 1
            memcpy(workingNonce, nonce, BLOCK_SIZE);
            xored(counter, workingNonce, BLOCK_SIZE);

            BytesToWords32(workingNonce, Pt, BLOCK_SIZE);
            SimonEncrypt(Pt, Ct, rk);
            Words32ToBytes(Ct, ct, 2);

            //STEP3
            xored(ct, &plaintext[block], BLOCK_SIZE);

            //STEP 4
            uint8_t count[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01};
            byteAdd(counter, BLOCK_SIZE, count);
        }
    }

    /*******************************last block**********************************/

    //STEP 1
    memcpy(workingNonce, nonce, BLOCK_SIZE);
    xored(counter, workingNonce, BLOCK_SIZE);

    //STEP 2

    BytesToWords32(workingNonce, Pt, BLOCK_SIZE);
    SimonEncrypt(Pt, Ct, rk);
    Words32ToBytes(Ct, ct, 2);

    //STEP3
    xored(ct, &plaintext[block], length - block);
}

#endif
