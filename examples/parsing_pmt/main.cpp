//
// Created by vscode on 7/26/25.
//

#include <iostream>
#include <random>
#include <pmt/pmt.h>

int main() {
    pmt::pmt_t obj = pmt::deserialize(*std::cin.rdbuf());
    std::cout << "Deserialized: " << pmt::write_string(obj) << std::endl;
}
