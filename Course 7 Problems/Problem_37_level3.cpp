#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString(string message)
{
    string str;
    cout << message << endl;
    getline(cin, str);
    return str;
}

vector <string> Split(string sen, char delim)
{
    vector <string> words;
    sen.append(string(1,delim));
    int wordStart = 0;
    int counter = 0;
    for (int i = 0; i < sen.length(); i++)
    {
        if (sen[wordStart] == delim)
            wordStart++;
        else if (sen[i] == delim && sen[wordStart] != delim)
        {
             words.push_back(sen.substr(wordStart, i - wordStart));
             wordStart = i+1;
             counter++;
        }
    }
    return words;
}

vector <string> SplitTeacherWay(string sentence, string delim)
{
    vector <string> words;
    int pos;
    string word;
    while ((pos = sentence.find(delim)) != std::string::npos)
    {
        word = sentence.substr(0, pos);
        if (word != "")
            words.push_back(word);
        sentence.erase(0, pos + delim.length());
    }
    if (word != "")
        words.push_back(sentence);
    return words;
}

void PrintSentenceInfo(vector <string>& words,int wordsCount)
{
    cout << "Tokens = " << wordsCount << endl;
    for (const string& word : words)
    {
        cout << word << endl;
    }
}

int main() {

    string sentence = ReadString("Please Enter Your Sentence : ");

    vector <string> words = SplitTeacherWay(sentence, " ");
    
    PrintSentenceInfo(words, words.size());

    return 0;
}