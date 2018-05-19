#ifndef PIRATE_TRANSLATOR_H
#define PIRATE_TRANSLATOR_H

// Pirate Translator replaces certain words in your message with common pirate phrases

#include "Translator.h"

class PirateTranslator : public Translator {
public:
    PirateTranslator();
    std::string getLanguage() { return "Pirate"; }
    std::string translate(std::string&);
    std::string untranslate(std::string&);
private:
    std::unordered_map<std::string, std::string> translateLegend = {
        { "hello", "ahoy" },
        { "sir", "matey" },
        { "madam", "proud-beauty" },
        { "you", "ye" },
        { "is", "be" },
        { "are", "ar" },
        { "my", "me" },
        { "your", "yer" },
        { "a", "a-briny" },
        { "where", "whar" },
    };
    std::unordered_map<std::string, std::string> untranslateLegend;
    std::vector<std::string> prefixes = {
        "Scurvy!",
        "Arrr!",
        "Yarrr!",
    };
};

PirateTranslator::PirateTranslator() {
    for (std::pair<std::string, std::string> entry : translateLegend) {
        untranslateLegend.insert({entry.second, entry.first});
    }
    for (auto p : prefixes) {
        untranslateLegend.insert({p, ""});
    }
}

std::string PirateTranslator::translate(std::string& message) {
    return prefixes.at(rand() % prefixes.size()) + " " + findAndReplaceWords(message, translateLegend);
}

std::string PirateTranslator::untranslate(std::string& message) {
    std::string output = findAndReplaceWords(message, untranslateLegend);
    return output.substr(1, output.size());
}

#endif
