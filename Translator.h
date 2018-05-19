#ifndef TRANSLATOR_H
#define TRANSLATOR_H

// Parent class for all possible Translators

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

class Translator {
public:
    virtual std::string getLanguage() { return "No Language"; }
    virtual std::string translate(std::string&) { return "Translation error."; }
    virtual std::string untranslate(std::string&) { return "Translation error."; }
    virtual std::vector<std::string> vectorizeWords(std::string&);
    virtual std::string unvectorizeWords(std::vector<std::string>&);
    virtual std::string findAndReplaceWords(std::string&, std::unordered_map<std::string, std::string>&);
};

// Breaks the message into words (space delimited) and puts words into vector
std::vector<std::string> Translator::vectorizeWords(std::string& message) {
    // Make stream, which will delimit by spaces
    std::stringstream ms(message);

    // Create vector of stream of words
    std::istream_iterator<std::string> begin(ms);
    std::istream_iterator<std::string> end;
    std::vector<std::string> words(begin, end);
    return words;
}

// Concatenates all the words, delimited by spaces, into a string
std::string Translator::unvectorizeWords(std::vector<std::string>& words) {
    // Concatenate new words into output string
    std::string output;
    for (auto const& w : words) {
        output += w + ' ';
    }

    // Return string, cutting out the extra space at the end
    return output.substr(0, output.size() - 1);
}

// Takes in a message and a find and replace legend
// Uses legend to find matches and replace with the specified values
std::string Translator::findAndReplaceWords(std::string& message, std::unordered_map<std::string, std::string>& legend) {
    std::vector<std::string> words = vectorizeWords(message);
    std::unordered_map<std::string, std::string>::iterator it;
    for (size_t i = 0; i < words.size(); i++) {
        it = legend.find(words[i]);
        if (it != legend.end()) {
            words[i] = it->second;
        }
    }
    return unvectorizeWords(words);
}

#endif
