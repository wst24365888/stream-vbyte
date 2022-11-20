#ifndef DECODE_SCALAR
#define DECODE_SCALAR

#include "branch_prediction.h"
#include <chrono>
#include <iostream>

static inline uint32_t decode_data(uint8_t control_bits, const uint8_t** data_stream_ptr) {
    uint32_t value = 0;
    switch (control_bits) {
        case 0:
            value = **data_stream_ptr;
            *data_stream_ptr += 1;
            break;
        case 1:
            value = *(reinterpret_cast<const uint16_t*>(*data_stream_ptr));
            *data_stream_ptr += 2;
            break;
        case 2:
            value = *(reinterpret_cast<const uint32_t*>(*data_stream_ptr)) & 0x00FFFFFF;
            *data_stream_ptr += 3;
            break;
        case 3:
            value = *(reinterpret_cast<const uint32_t*>(*data_stream_ptr));
            *data_stream_ptr += 4;
            break;
    }

    return value;
}

static const uint8_t* decode_scalar(uint32_t* out, std::size_t& count, const uint8_t* control_stream, const uint8_t* data_stream) {
    auto start = std::chrono::high_resolution_clock::now();
    std::size_t original_count = count;

    uint8_t shift = 0;
    uint32_t control_bits = *control_stream;
    for (std::size_t i = 0; LIKELY(i < original_count); i++) {
        uint32_t val = decode_data((control_bits >> shift) & 0b11, &data_stream);
        *out++ = val;
        shift += 2;

        if (UNLIKELY(shift == 8)) {
            shift = 0;
            control_bits = *control_stream++;
        }

        count--;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "decode_scalar: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns, processed " << original_count - count << " elements" << std::endl;

    return data_stream;
}

#endif
