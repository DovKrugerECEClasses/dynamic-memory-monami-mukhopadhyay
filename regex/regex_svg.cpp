/*
Author: Xingyuan Guo & Monami Mukhopadhyay
Program: Regex
*/

// Reference:
// https://www.ibm.com/developerworks/community/blogs/5894415f-be62-4bc0-81c5-3956e82276f3/entry/regular_expression_in_c_11_14?lang=en
// http://cpprocks.com/files/c++11-regex-cheatsheet.pdf
// https://medium.com/factory-mind/regex-tutorial-a-simple-cheatsheet-by-examples-649dc1c3f285

using namespace std;

#include <iostream>
#include <regex>
#include <string>
#include <fstream>


// regex_match - match regex to an entire char sequence
// regex_search - match regex to any part of a char sequence
// regex_replace - replace occurrences of a regex with formatted replacement text
// regex_iterator - iterates thru all regex matches within a char sequence

void remove_tspan() {

    string start_0 = "<tspan";
    string ends = "</tspan>";

    //std::regex base_regex_0(start_0 + "(.*)" + ">" + "(.*)" + ends);
    std::regex base_regex_0(start_0 + "(.*?)" + ">");
    std::regex base_regex_1(start_0 + "(.*)" + "/>");
    std::regex base_regex_2(ends);

    ofstream outFile("replaced.svg");
    ifstream file("test.svg");
    std::string line;
    while (std::getline(file, line)) {
        line = std::regex_replace(line, base_regex_0, " ");
        line = std::regex_replace(line, base_regex_1, " ");
        line = std::regex_replace(line, base_regex_2, " ");

        outFile << line << '\n';
    }
}


void round_off() {

    ifstream infile("replaced.svg");
    ofstream outfile("roundoff.svg");
    string line;
    while (getline(infile, line)) {
        regex e("([\"\\:][0-9]+\\.[0-9])[0-9]*");
        smatch match;
        string newline = line;
        while (regex_search(line, match, e)) {
            for (auto x:match) {
                string replacement = "$1";
                newline = regex_replace(newline, e, replacement);
            }
            line = match.suffix().str();
        }
        outfile << newline << endl;
    }
}


int main() {
    remove_tspan();
    round_off();
    return 0;
}
