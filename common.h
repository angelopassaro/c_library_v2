#ifndef _COMMON_H
#define _COMMON_H

#include <stdint.h>

#define ROTL32(x, r) (((x) << (r)) | (x >> (32 - (r))))
#define ROTR32(x, r) (((x) >> (r)) | ((x) << (32 - (r))))

#define f32(x) ((ROTL32(x, 1) & ROTL32(x, 8)) ^ ROTL32(x, 2))
#define R32x2(x, y, k1, k2) (y ^= f32(x), y ^= k1, x ^= f32(y), x ^= k2)

#define ER32(x, y, k) (x = ROTR32(x, 8), x += y, x ^= k, y = ROTL32(y, 3), y ^= x)
#define DR32(x, y, k) (y ^= x, y = ROTR32(y, 3), x ^= k, x -= y, x = ROTL32(x, 8))

#define ROTL64(x, r) (((x) << (r)) | (x >> (64 - (r))))
#define ROTR64(x, r) (((x) >> (r)) | ((x) << (64 - (r))))

#define f64(x) ((ROTL64(x, 1) & ROTL64(x, 8)) ^ ROTL64(x, 2))
#define R64x2(x, y, k1, k2) (y ^= f64(x), y ^= k1, x ^= f64(y), x ^= k2)

#define ER64(x, y, s) (x = (ROTR64(x, 8) + y) ^ (s), y = ROTL64(y, 3) ^ x)
#define DR64(x, y, k) (y ^= x, y = ROTR64(y, 3), x ^= k, x -= y, x = ROTL64(x, 8))

#endif
