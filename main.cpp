#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

void binaryToString(istream& in, ostream& out) {
    string input;
    getline(in, input, '\n');
    stringstream ss(input);
    string binary, result;
    while (ss >> binary) {
        for (int i = 0; i < binary.length(); i += 8) {
            bitset<8> bits(binary.substr(i, i + 8));
            char c = bits.to_ulong();
            result += c;
        }
    }
    out << result << endl;
}

void stringToBinary(istream& in, ostream& out) {
    string input, result;
    getline(in, input, '\n');
    for (char c : input) {
        bitset<8> bits(c);
        result += bits.to_string();
        result += " ";
    }
    out << result << endl;
}

bool processFile(ifstream& in, ofstream& out) {
    string inFile, outFile;
            cin >> inFile;
            in.open(inFile);
            if (!in.is_open()) {
                cout << "Error opening file." << endl;
                return false;
            }
            cin >> outFile;
            out.open(outFile);
            return true;
}

void menuLoop() {
    while (1) {
        cout << "Welcome to binary to string converter!" << endl;
        cout << "Options:" << endl;
        cout << "Enter b <binary number> to convert binary to string." << endl;
        cout << "Enter s <string> to convert string to binary." << endl;
        cout << "Enter fb <filename> <outfile> to convert txt file with binary numbers to string." << endl;
        cout << "Enter fs <filename> <outfile> to convert txt file with string to binary." << endl;
        cout << "Enter h to print these options again." << endl;
        cout << "Enter # to quit." << endl;

        string command;
        ifstream in;
        ofstream out;
        cin >> command;
        if (command == "#") {
            return;
        } else if (command == "b") {
            binaryToString(cin, cout);
        } else if (command == "s") {
            stringToBinary(cin, cout);
        } else if (command == "fb") {
            if (!processFile(in, out)) {
                continue;
            }
            binaryToString(in, out);
            in.close();
            out.close();
        } else if (command == "fs") {
            if (!processFile(in, out)) {
                continue;
            }
            stringToBinary(in, out);
            in.close();
            out.close();
        }
    }
}

int main() {
    menuLoop();
    return 0;
}