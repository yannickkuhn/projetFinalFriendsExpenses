/*
 * LineReader.cpp
 *
 *  Created on: 20 mars 2014
 *      Author: Yannick
 */

#include "LineReader.hpp"


LineReader::LineReader(string iText) {
	_text = iText;
}

// setters and getters

void LineReader::setText(const string& iText) {
	_text = iText;
}

const string& LineReader::getText() const {
	return _text;
}

// methods

unsigned int LineReader::wordCount() {
    unsigned int aCount = 0;
    char *aWord = 0;
    char aDelimiters[] = " :.!\"#$%&'()*+,-/;<=>?@[]\\^_`{|}~\n\t\r";
    // Cf. http://www.cplusplus.com/reference/cctype/
    // for the list of characters

    char aText[_text.length() + 1];
    strcpy(aText, _text.c_str());

    aWord = strtok(aText, aDelimiters);
    while (aWord) {
        aCount++;
        aWord = strtok(0, aDelimiters);
    }
    return aCount;
}

vector<string> LineReader::splitWord(char *iDelimiter) {
    vector<string> aWords;
    char *aWord = 0;
    //char aDelimiters[] = " :.!\"#$%&'()*+,-/;<=>?@[]\\^_`{|}~\n\t\r";
    // Cf. http://www.cplusplus.com/reference/cctype/
    // for the list of characters

    char aText[_text.length() + 1];
    strcpy(aText, _text.c_str());

    aWord = strtok(aText, iDelimiter);
    while (aWord) {
    	aWords.push_back(aWord);
        aWord = strtok(0, iDelimiter);
    }
    return aWords;
}

