// Standard library includes
#include <string>
#include <algorithm>
#include <iostream>

// Out project headers
#include "VigenereCipher.hpp"

VigenereCipher::VigenereCipher(const std::string &key)
{
    setKey(key);
}

void VigenereCipher::setKey(const std::string &key)
{
    // Store the key
    key_ = key;
    // Make sure the key is uppercase
    std::transform(std::begin(key_), std::end(key_), std::begin(key_), ::toupper);
    // Remove non-alphabet characters
    key_.erase(std::remove_if(std::begin(key_), std::end(key_), [](char c) { return !std::isalpha(c); }),
               std::end(key_));
    // Check if the key is empty and replace with default if so
    if (key_ == "")
    {
        key_ = "KEY";
    }

    // loop over the key
    for (size_t i = 0; i < key_.size(); i++)
    {
        // Find the letter position in the alphabet

        // Every letter has an ASCII value which can be represented in binary form.
        // Performing the bitwise and of this value with the number 31 will give the letter’s position in the alphabets.
        long unsigned int position = ((key_[i] & 31) - 1);

        // Create a CaesarCipher using this position as a key
        CaesarCipher cipher{position};

        // Insert a std::pair of the letter and CaesarCipher into the lookup
        charLookup_.insert(std::make_pair(key_[i], cipher));
    }
}

std::string VigenereCipher::applyCipher(const std::string &inputText, const CipherMode cipherMode) const
{
    std::string outputText = "";

    // For each letter in input:
    for (size_t i = 0; i < inputText.size(); i++)
    {
        // Find the corresponding letter in the key
        // repeating/truncating as required
        // Find the Caesar cipher from the lookup
        // Run the (de)encryption
        // Add the result to the output
        const CaesarCipher &cipher{charLookup_.at(key_[i % key_.size()])};
        const std::string oldChar{inputText[i]};
        outputText += cipher.applyCipher(oldChar, cipherMode);
    }
    return outputText;
}