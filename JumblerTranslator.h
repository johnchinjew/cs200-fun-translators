#ifndef JUMBLER_TRANSLATOR_H
#define JUMBLER_TRANSLATOR_H

// Jumbler Translator rearranges the words in your message

#include <algorithm>

#include "Translator.h"

class JumblerTranslator : public Translator {
public:
    std::string getLanguage() { return "Jumbler"; }
    std::string translate(std::string&);
    std::string untranslate(std::string&);
};

// Swaps first and last words every two words until at center
// This seems random, but importantly, it is reversable
std::string JumblerTranslator::translate(std::string& message) {
    // Break message into words
    std::vector<std::string> words = vectorizeWords(message);
    size_t wordsSize = words.size();

    // Swap first and last words, every two words, until at center
    for(size_t i = 0; i < wordsSize / 2; i += 2) {
        std::swap(words[i], words[wordsSize - i - 1]);
    }

    return unvectorizeWords(words);
}

std::string JumblerTranslator::untranslate(std::string& message) {
    // Since jumbler only uses predictable swaps
    // The message can be reversed simply by running it through the translate function again
    return translate(message);
}

#endif
