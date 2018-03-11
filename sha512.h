#ifndef HEADER_SHA_H
# define HEADER_SHA_H

# define SHA_LONG             unsigned int
# define SHA_LBLOCK           16
# define SHA512_DIGEST_LENGTH 64
# define SHA512_CBLOCK        (SHA_LBLOCK*8)
# define SHA_LONG64           unsigned long long
# define U64(C)     C##ULL
# define NULL 0

typedef unsigned int size_t;
typedef unsigned char byte;

typedef struct SHA512state_st {
    SHA_LONG64 h[8];
    SHA_LONG64 Nl, Nh;
    union {
        SHA_LONG64 d[SHA_LBLOCK];
        unsigned char p[SHA512_CBLOCK];
    } u;
    unsigned int num, md_len;
} SHA512_CTX;

int SHA512_Init(SHA512_CTX *c);
int SHA512_Update(SHA512_CTX *c, const void *data, size_t len);
int SHA512_Final(unsigned char *md, SHA512_CTX *c);
unsigned char *SHA512(const unsigned char *d, size_t n, unsigned char *md);
void SHA512_Transform(SHA512_CTX *c, const unsigned char *data);

void memset(byte * ptr, byte value, size_t num);
void memcpy(byte *destination, const byte *source, size_t num);
#endif

