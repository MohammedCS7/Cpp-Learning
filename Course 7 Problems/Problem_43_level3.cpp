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

vector <string> SplitString(string sen, string delim)
{
    vector <string> words;
    short pos = 0;
    string word;
    while ((pos = sen.find(delim)) != string::npos)
    {
        word = sen.substr(0, pos);
        if (word != "")
            words.push_back(word);
        sen.erase(0, pos + delim.length());
    }
    if (sen != "")
        words.push_back(sen);
    return words;
}

string JoinString(vector <string>& words, string delim)
{
    if (words.empty())
        return "";
    string str;
    for (string& word : words)
    {
        str += word + delim;
    }
    str.pop_back();
    return str;
}

string LowerWord(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        word[i] = tolower(word[i]);
    }
    return word;
}

string ReplaceWord(vector <string>& words, string old, string update,bool isCaseSensitve = true)
{
        for (string& word : words)
        {
            (isCaseSensitve) ? word = (word == old) ? update : word : word = (LowerWord(word) == LowerWord(old)) ? update : word;
        }
        return JoinString(words, " ");
}

string ReplaceWord(string sen, string old, string update,bool isCaseSensitive = true)
{
    string words;
    sen.append(" ");
    short wordStart = 0;
    for (size_t i = 0; i < sen.length();i++)
    {
        if (sen[wordStart] == ' ')
            wordStart++;
        else if (sen[i] == ' ' && sen[wordStart] != ' ' && isCaseSensitive)
        {
            if (sen.substr(wordStart, i - wordStart) == old)
                words += update + " ";
            else
                words += sen.substr(wordStart, i - wordStart) + " ";
            wordStart = i;
        }
        else if (sen[i] == ' ' && sen[wordStart] != ' ' && !isCaseSensitive)
        {
            if (sen.substr(wordStart, i - wordStart) == old || LowerWord(sen.substr(wordStart, i - wordStart)) == LowerWord(old))
                words += update + " ";
            else
                words += sen.substr(wordStart, i - wordStart) + " ";
            wordStart = i;
        }
    }
    words.pop_back();
    return words;
}

int main() {

    string sen = ReadString("Enter String : ");

    string old = ReadString("What do u Want to Replace : ");
    string update = ReadString("What do u Want to Replace it with : ");

    vector <string> words = SplitString(sen, " ");

    cout << "String after Replace Case Sensitive : " << endl;
    cout << ReplaceWord(words,old,update) << endl;

    cout << "String after Replace Not Case Sensitive : " << endl;
    cout << ReplaceWord(words, old, update,0) << endl;


    return 0;
}