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

vector <string> Split(string sen, string delim)
{
    vector <string> words;
    sen.append(delim);
    int wordStart = 0;
    int deLen = delim.length();
    for (int i = 0; i < sen.length(); i++)
    {
        if (sen.compare(wordStart, deLen, delim) == 0)
        {
            wordStart += deLen;
            if (i < wordStart) i = wordStart;
        }
        else if (sen.compare(i,deLen,delim) == 0 && sen.compare(wordStart,deLen,delim) != 0)
        {
            words.push_back(sen.substr(wordStart, i - wordStart));
            wordStart = i + deLen;
            i = wordStart;

        }
    }
    return words;
}

string Join(vector <string>& words, string delim)
{
    string sentence;
    if (words.empty())
        return "";
    for (string& word : words)
    {
        sentence += word + delim;
    }
    for(int i = 0; i < delim.length(); i++)
        sentence.pop_back();
    return sentence;
}

string JoinTeacherWayIHope(vector <string>& words, string delim)
{
    if (words.empty())
        return "";
    int deLen = delim.length();
    string sen;
    vector <string>::iterator iter;

    for (iter = words.begin(); iter != words.end(); iter++)
    {
        sen += *iter + delim;
    }
    for (int i = 0; i < deLen; i++)
    {
        sen.pop_back();
    }
    return sen;
}

void PrintSentenceInfo(vector <string>& words, int wordsCount)
{
    cout << "Tokens = " << wordsCount << endl;
    for (const string& word : words)
    {
        cout << word << endl;
    }
}

int main() {

    string sentence = ReadString("Enter Sentence : ");

    vector <string> words = Split(sentence, ",,,");

    string joinedSentence = JoinTeacherWayIHope(words, "|||");

    cout << "Vector After join : " << joinedSentence << endl;

    return 0;
}