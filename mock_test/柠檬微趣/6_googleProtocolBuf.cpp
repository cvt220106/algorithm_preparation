//
// Created by jacky on 24-7-30.
//
#include <bits/stdc++.h>
using namespace std;

/**
Varint 编码是一种将整数编码为一个或多个字节的技术。它使用每个字节的最高位作为继续位（标识后续字节是否存在），其余 7 位用于存储数据。

编码规则
最高位（MSB）为 1 表示后续字节存在，为 0 表示这是最后一个字节。
其余 7 位用于存储数据的一部分。
例如，编码整数 300：

二进制表示： 0000 0001 0010 1100
分段： 0000 0001 和 0010 1100
添加继续位：
0010 1100 (44 in decimal) -> 1010 1100 (0xAC)
0000 0001 (1 in decimal) -> 0000 0001 (0x01)
最终字节序列： 0xAC 0x01
*/

void encodeVarint(uint32_t value, vector<uint8_t>& output) {
    while (value > 0x7F) {
        output.push_back((value & 0x7F) | 0x80);
        value >>= 7;
    }
    output.push_back(value & 0x7F);
}

uint32_t decodeVarint(const vector<uint8_t>& input) {
    uint32_t result = 0;
    int shift = 0;
    size_t offset = 0;
    while (offset < input.size()) {
        uint8_t byte = input[offset++];
        result |= (byte & 0x7F) << shift;
        if (!(byte & 0x80)) {
            break;
        }
        shift += 7;
    }
    return result;
}

char convert(int num) {
    return (num < 10) ? ('0' + num) : ('A' + (num - 10));
}

int main() {
    vector<uint8_t> encoded;
    uint32_t number = 204416;

    encodeVarint(number, encoded);

    cout << "Original: " << number << "\n";
    cout << "Encoded: ";
    stringstream output;
    for (uint8_t byte : encoded) {
        output << "0X";
        output << convert(byte / 16) << convert(byte % 16);
    }
    cout << output.str();

    vector<uint8_t> nums;
    std::string hexString = "0x80XBD0X8C";
    stringstream ss(hexString.substr(2, hexString.size() - 2));
    string num;
    while (getline(ss, num, 'X')) {
        num = num.substr(0, 2);
        nums.push_back(static_cast<uint8_t>(stoi(num, nullptr, 16)));
    }

    uint32_t decoded = decodeVarint(nums);

    cout << "\nDecoded: " << decoded << "\n";

    return 0;
}
