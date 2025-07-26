//
// Created by vscode on 7/26/25.
//

#include <iostream>
#include <random>
#include <pmt/pmt.h>

#define NUM_SAMPLES (16)

std::vector<std::complex<float>>
generate_random_complex_vector(size_t num_samples) {
    std::vector<std::complex<float>> result;
    result.reserve(num_samples);

    // Random engine and distribution
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);

    for (std::size_t i = 0; i < num_samples; ++i) {
        float real = dist(gen);
        float imag = dist(gen);
        result.emplace_back(real, imag);
    }

    return result;
}

int main() {
    auto meta = pmt::make_dict();
    meta = pmt::dict_add(meta, pmt::intern("TEST"), pmt::intern("pmt"));

    auto data = pmt::init_c32vector(NUM_SAMPLES, generate_random_complex_vector(NUM_SAMPLES));

    auto pdu = pmt::cons(meta, data);

    std::cout << pmt::serialize_str(pdu);
}
