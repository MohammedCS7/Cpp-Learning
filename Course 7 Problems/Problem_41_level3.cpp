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

//void PrintSentenceReversed(string sentence)
//{
//    int wordEnd = sentence.length()-1;
//    int wordStart = wordEnd;
//    
//    for (int i = sentence.length()-1; i >= 0; i--)
//    {
//        if (sentence[wordEnd] == ' ')
//        {
//            wordEnd--;
//            continue;
//        }
//        if (wordEnd < wordStart)
//            wordStart = wordEnd;
//        if (sentence[wordStart] != ' ')
//        {
//            wordStart--;
//        }
//        else
//        {
//            cout << sentence.substr(wordStart + 1, wordEnd - wordStart + 1) << " ";
//            wordEnd = wordStart;
//        }
//    }
//}
//
//string FillArrayWithWords(string words[],int length, string sentence, string delim)
//{
//    int wordStart = 0;
//    int deLen = delim.length();
//    for (int i = 0; i < length; i++)
//    {
//        if (sentence.compare(wordStart, deLen, delim) == 0)
//        {
//            wordStart += deLen;
//            if (i < wordStart) i = wordStart;
//        }
//        else if (sentence.compare(i, deLen, delim) == 0 && sentence.compare(wordStart, deLen, delim) != 0)
//        {
//            words[i] = sentence.substr(wordStart, i - wordStart);
//            wordStart += i + deLen;
//            i = wordStart;
//        }
//    }
//}

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
        else if (sen.compare(i, deLen, delim) == 0 && sen.compare(wordStart, deLen, delim) != 0)
        {
            words.push_back(sen.substr(wordStart, i - wordStart));
            wordStart = i + deLen;
            i = wordStart;

        }
    }
    return words;
}

string GetWordsReversed(const vector <string>& words)
{
    if (words.empty())
        return "";
    
    int size = words.size() - 2;
    string sen = words.at(size+1);
    if (size == -1)
        return sen;
    for (int i = size; i >= 0; i--)
    {
        sen += " " + words.at(i);
    }
    return sen;
}

string GetWordsReversedTeacherMethod(string str)
{
    vector <string> words = Split(str, " ");
    vector <string>::iterator iter = words.end();
    string str2;
    while (iter != words.begin())
    {
        --iter;
        str2 += *iter + " ";
    }
    str2.pop_back();
    return str2;
}

int main() {

    string sen = ReadString("Enter String : ");

    

    cout << "String after reversed words : " << endl;
    cout << GetWordsReversedTeacherMethod(sen) << endl;


    return 0;
}