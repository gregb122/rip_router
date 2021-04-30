//Grzegorz Bielecki 288388

#include "helpers.h"

int32_t to_mask(int _mask_len){
    int32_t mask = 0x80000000;
    mask >>= _mask_len - 1;
    return mask;
}