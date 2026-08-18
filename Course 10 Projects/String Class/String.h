#pragma once
#include <iostream>
#include <vector>
using namespace std;
class String
{
private:
	string _Value;
public:
	String()
	{
		_Value = "";
	}

	String(string Value)
	{
		_Value = Value;
	}

	void setValue(string Value)
	{
		_Value = Value;
	}

	string getValue()
	{
		return _Value;
	}

	static short Length(const String& word)
	{
		return word._Value.length();
	}

	short Length()
	{
		return Length(*this);
	}

	static short CountWords(string S1)
	{
		short pos;
		short counter = 0;
		while ((pos = S1.find(" ")) != string::npos)
		{
			if (S1 != "")
			{
				counter++;
				S1.erase(0, pos + 1);
			}
		}
		if (S1 != "")
			counter++;
		return counter;
	}

	short CountWords()
	{
		return CountWords(_Value);
	}

	/*static void ToLowerCase(string& word)
	{
		string lowWord = "";
		for (int i = 0; i < word.length(); i++)
		{
			char current = word[i];
			if (current >= 65 && current <= 90)
			{
				lowWord += current + 32;
			}
			else
				lowWord += current;
		}
		word = lowWord;
	}

	static void ToUpperCase(string& word)
	{
		string upCase = "";
		for (int i = 0; i < word.length(); i++)
		{
			char current = word[i];
			if (current >= 97 && current <= 122)
			{
				upCase += current - 32;
			}
			else
				upCase += current;
		}
		word = upCase;
	}

	void ToLowerCase()
	{
		ToLowerCase(_Value);
	}

	void ToUpperCase()
	{
		ToUpperCase(_Value);
	}*/


	static string ToLowerCase(string word)
	{
		string lowWord = "";
		for (int i = 0; i < word.length(); i++)
		{
			char current = word[i];
			if (current >= 65 && current <= 90)
			{
				lowWord += current + 32;
			}
			else
				lowWord += current;
		}
		return lowWord;
	}

	static String ToLowerCase(String word)
	{
		String lowWord ("");
		for (int i = 0; i < word._Value.length(); i++)
		{
			char current = word._Value[i];
			if (current >= 65 && current <= 90)
			{
				lowWord._Value += current + 32;
			}
			else
				lowWord._Value += current;
		}
		return lowWord;
	}

	static String ToUpperCase(String word)
	{
		String upcase("");
		for (int i = 0; i < word._Value.length(); i++)
		{
			char current = word._Value[i];
			if (current >= 97 && current <= 122)
			{
				upcase._Value += current - 32;
			}
			else
				upcase._Value += current;
		}
		return upcase;
	}

	static string ToUpperCase(string word)
	{
		string upWord = "";
		for (int i = 0; i < word.length(); i++)
		{
			char current = word[i];
			if (current >= 97 && current <= 122)
			{
				upWord += current - 32;
			}
			else
				upWord += current;
		}
		return upWord;
	}

	String ToLowerCase()
	{
		return ToLowerCase(*this);
	}

	String ToUpperCase()
	{
		return ToUpperCase(*this);
	}


	static vector <string> Split(const String& sentence,string delimeter)
	{
		vector <string> words;
		short pos;
		short deLen = delimeter.length();
		string word;
		String newSen = sentence;
		while ((pos = newSen._Value.find(delimeter)) != string::npos)
		{
			if (newSen._Value != "")
			{
				word = newSen._Value.substr(0, pos);
				newSen._Value.erase(0, pos + deLen);
				words.push_back(word);
			}
		}
		if (newSen._Value != "")
			words.push_back(newSen._Value);
		return words;
	}

	vector <string> Split(string delimeter)
	{
		return Split(*this, delimeter);
	}

	static String TrimLeft(const String& word)
	{
		String newWord = word;
		for (int i = 0; i < newWord._Value.length(); i++)
		{
			if (newWord._Value[i] != ' ')
			{
				newWord._Value = newWord._Value.substr(i);
				break;
			}
		}
		return newWord;
	}

	String TrimLeft()
	{
		return TrimLeft(*this);
	}

	static String TrimRight(const String& word)
	{
		String newWord = word;
		int i = word._Value.length() - 1;
		while (i >= 0 && newWord._Value[i] == ' ' && newWord._Value.empty() == false)
		{ 
			newWord._Value.pop_back();
			i--;
		}
		
		return newWord;
	}

	String TrimRight()
	{
		return TrimRight(*this);
	}

	static String Trim(const String& word)
	{
		return TrimLeft(TrimRight(word));
	}

	String Trim()
	{
		return Trim(*this);
	}

	static String UpperCaseForFirstChar(const String& sen)
	{
		short wordStart = 0;
		String newSen = sen;
		newSen._Value.append(" ");

		for (int i = 0; i < newSen._Value.length(); i++)
		{
			if (newSen._Value.at(wordStart) == ' ')
				wordStart++;
			else if (sen._Value.at(i) == ' ')
			{
				newSen._Value.at(wordStart) = toupper(newSen._Value.at(wordStart));
				wordStart = i + 1;
			}
		}
		newSen._Value.pop_back();
		return newSen;
	}

	String UpperCaseForFirstChar()
	{
		return UpperCaseForFirstChar(*this);
	}

	static String LowerCaseForFirstChar(const String& sen)
	{
		short wordStart = 0;
		String newSen = sen;
		newSen._Value.append(" ");

		for (int i = 0; i < newSen._Value.length(); i++)
		{
			if (newSen._Value.at(wordStart) == ' ')
				wordStart++;
			else if (sen._Value.at(i) == ' ')
			{
				newSen._Value.at(wordStart) = tolower(newSen._Value.at(wordStart));
				wordStart = i + 1;
			}
		}
		newSen._Value.pop_back();
		return newSen;
	}

	String LowerCaseForFirstChar()
	{
		return LowerCaseForFirstChar(*this);
	}

	static String UpperCaseForAllSentence(const String& sen)
	{
		String newSen = sen;
		for (int i = 0; i < newSen._Value.length(); i++)
		{
			newSen._Value.at(i) = toupper(newSen._Value.at(i));
		}
		return newSen;
	}

	String UpperCaseForAllSentence()
	{
		return UpperCaseForAllSentence(*this);
	}

	static char InvertCharCase(char ch)
	{
		if (ch >= 65 && ch <= 90)
			return ch + 32;
		else if (ch >= 97 && ch <= 122)
			return ch - 32;
		else
			return ch;
	}

	static String InvertSentenceCase(const String& sen)
	{
		String newSen = sen;
		for (int i = 0; i < newSen._Value.length(); i++)
		{
			newSen._Value.at(i) = InvertCharCase(newSen._Value.at(i));
		}
		return newSen;
	}

	String InvertSentenceCase()
	{
		return InvertSentenceCase(*this);
	}

	static short CountSmallLetters(const String& sen)
	{
		short smallCounter = 0;
		for (int i = 0; i < sen._Value.length(); i++)
		{
			if (islower(sen._Value.at(i)))
				smallCounter++;
		}
		return smallCounter;
	}

	short CountSmallLetters()
	{
		return CountSmallLetters(*this);
	}

	static short CountCapitalLetters(const String& sen)
	{
		short capitalCounter = 0;
		for (int i = 0; i < sen._Value.length(); i++)
		{
			if (isupper(sen._Value.at(i)))
				capitalCounter++;
		}
		return capitalCounter;
	}

	short CountCapitalLetters()
	{
		return CountCapitalLetters(*this);
	}

	static short CountSpecificLetter(const String& sen, const char& ch)
	{
		short count = 0;
		for (int i = 0; i < sen._Value.length(); i++)
		{
			if (sen._Value[i] == ch)
				count++;
		}
		return count;
	}

	short CountSpecificLetter(const char& ch)
	{
		return CountSpecificLetter(*this,ch);
	}

	static bool IsVowel(const char& ch)
	{
		char vowels[] = { 'a','A','e','E','i','I','o','O','u','U' };
		for (int i = 0; i < 10; i++)
		{
			if (ch == vowels[i])
				return true;
		}
		return false;
	}

	static short CountVowels(const String& sen)
	{
		short vowelCounter = 0;
		for (int i = 0; i < sen._Value.length(); i++)
		{
			if (IsVowel(sen._Value.at(i)))
				vowelCounter++;
		}
		return vowelCounter;
	}

	short CountVowels()
	{
		return CountVowels(*this);
	}

	static String Join(vector <string>& words, string delimeter)
	{
		String newSen("");

		if (words.empty())
			return newSen;

		newSen._Value.append(words[0]);

		if (words.size() == 1)
			return newSen;

		vector <string>::iterator iter;

		for (iter = words.begin() + 1; iter != words.end(); ++iter)
		{
			newSen._Value += delimeter + *iter;
		}

		return newSen;
	}

	String Join(string delimeter = " ")
	{
		vector <string> words = Split(*this, " ");
		return Join(words, delimeter);
	}

	static String Join(const string words[], int length, string delimeter)
	{
		String joinedString("");
		if (length == 0)
			return joinedString;
		joinedString._Value += words[0];
		if (length == 1)
			return joinedString;
		for (int i = 1; i < length; i++)
		{
			joinedString._Value += delimeter + words[i];
		}
		return joinedString;
	}

	static String ReverseSentence(vector <string>& words)
	{
		String revSen(" ");

		vector <string> revWords;

		vector <string>::iterator iter;

		for (iter = words.end(); iter > words.begin();)
		{
			--iter;
			revWords.push_back(*iter);
		}

		return Join(revWords, " ");
	}

	String ReverseSentence()
	{
		vector <string> words = Split(" ");
		return ReverseSentence(words);
	}

	static String Replace(const String& sen, string old, string update,bool isCaseSensitive = true)
	{
		vector <string> words = Split(sen, " ");
		string newSen = "";
		for (string& word : words)
		{
			if (isCaseSensitive && word == old)
			{
				word = update;
				break;
			}
			else if (!isCaseSensitive && ToLowerCase(word) == ToLowerCase(old))
			{
				word = update;
				break;
			}
		}
		return Join(words, " ");
	}

	String Replace(string old, string update, bool isCaseSensitive = true)
	{
		return Replace(*this, old, update, isCaseSensitive);
	}

	static String RemovePunc(const String& sen)
	{
		String newSen = sen;
		for (int i = 0; i < newSen._Value.length();)
		{
			if (ispunct(newSen._Value.at(i)))
				newSen._Value.replace(i, 1, "");
			else
				i++;
		}
		return newSen;
	}

	String RemovePunc()
	{
		return RemovePunc(*this);
	}

	__declspec(property(get = getValue, put = setValue)) string Value;
};

