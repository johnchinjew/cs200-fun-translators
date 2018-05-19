#ifndef SPOONERISM_TRANSLATOR_H
#define SPOONERISM_TRANSLATOR_H

// Spoonerism Translator switches the first letters of every two words in your message

#include <algorithm>

#include "Translator.h"

class SpoonerismTranslator : public Translator {
public:
    std::string getLanguage() { return "Spoonerism"; }
    std::string translate(std::string&);
    std::string untranslate(std::string&);
};

// Swaps first letters of every two words
std::string SpoonerismTranslator::translate(std::string& message) {
    // Break message into words
    std::vector<std::string> words = vectorizeWords(message);

    // For every two words, swap first letters
    for(size_t i = 0; i < words.size() - 1; i += 2) {
        std::swap(words[i][0], words[i + 1][0]);
    }

    return unvectorizeWords(words);
}

std::string SpoonerismTranslator::untranslate(std::string& message) {
    // Since spoonerism only uses predictable swaps
    // The message can be reversed simply by running it through the translate function again
    return translate(message);
}

#endif
