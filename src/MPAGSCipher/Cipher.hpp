#ifndef CIPHER_HPP
#define CIPHER_HPP

class Cipher
{
public:
    virtual std::string applyCipher(const std::string &input, const CipherMode mode) const = 0;

    Cipher() = default;
    Cipher(const Cipher &rhs) = default;
    Cipher(Cipher &&rhs) = default;
    Cipher &operator=(const Cipher &rhs) = default;
    Cipher &operator=(Cipher &&rhs) = default;
    virtual ~Cipher() = default;
};

#endif