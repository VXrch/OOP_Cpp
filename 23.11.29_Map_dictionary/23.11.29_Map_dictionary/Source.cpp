#include <iostream>
#include <map>
#include <list>
#include <string>
#include <fstream>

using namespace std;

class Dictionary
{
    string name;
    map<string, list<string>> words;

public:

    Dictionary(string name) : name(name) {}

    void Print()const
    {
        cout << "Dictionary " << name << endl;
        for (auto pair : words)
        {
            cout << pair.first << " - ";
            for (string t : pair.second)
            {
                cout << t << " , ";
            }
            cout << endl;
        }
    }

    void InsertWord(string word, initializer_list<string> translate) // add new word with translations
    {
        words.insert(make_pair(word, list<string>(translate)));
    }
    void AddTranslation(string word, string translate) // add translationyo concrete word
    {
        words[word].push_back(translate);
    }
    bool IsExist(string word) // Is exist this word in map
    {
        return words.find(word) != words.end();
    }

    friend ostream& operator << (ostream& out, const Dictionary& d);
    friend istream& operator >> (istream& in, Dictionary& d);
};

ostream& operator << (ostream& out, const Dictionary& d)
{
    out << d.name << endl;
    for (auto pair : d.words)
    {
        out << pair.first << endl;
        for (string t : pair.second)
        {
            out << t << endl;
        }
        out << "|" << endl;
    }
    return out;
}
istream& operator >> (istream& in, Dictionary& d)
{
    string end = "|";
    //in >> d.name;
    getline(in, d.name);
    while (!in.eof())
    {
        string word;
        getline(in, word);
        if (word.empty())break;
        list<string> list;
        string translate = end;

        do
        {
            getline(in, translate);
            if (translate != end)
                list.push_back(translate);

        } while (translate != end);
        d.words.insert(make_pair(word, list));
    }

    return in;
}

void ReadFromFile(Dictionary& read)
{
    ifstream in("Dictionary.txt");
    in >> read;
    in.close();
}
void WriteToFile(Dictionary& read)
{
    ofstream out("Dictionary.txt");
    out << read;
    out.close();
}

void AddTranslation(Dictionary& dict)
{
    dict.Print();

    string input = "";
    cout << "Enter word to add translate : "; getline(cin, input);

    if (dict.IsExist(input))
    {
        string translate = "";
        cout << "Enter translation of this word : "; getline(cin, translate);

        dict.AddTranslation(input, translate);
    }
    else
    {
        cout << "This word doesn't exist!" << endl;
    }
}
void AddWord(Dictionary& dict)
{
    dict.Print();

    string input = "";
    cout << "Enter word to add: "; getline(cin, input);

    if (!dict.IsExist(input))
    {
        string translate = "";
        cout << "Enter translation of this word : "; getline(cin, translate);
        if (translate != "")
        {
            dict.AddTranslation(input, translate);
        }
    }
    else
    {
        cout << "This word is alredy exist!" << endl;
    }
}

int main()
{
    int numb = 0;
    int choice;
    bool ext = false;

    Dictionary dict("");

    while (!ext)
    {
        numb = 0;

        cout << "_-_-_-_-_-_-_-_-|  WELCOME TO DICTIONARY  |-_-_-_-_-_-_-_" << endl;
        cout << "[" << numb << "] - EXIT" << endl; numb++;
        cout << "[" << numb << "] - Read dictionary from file" << endl; numb++;
        cout << "[" << numb << "] - Write dictionary to file" << endl; numb++;
        cout << "[" << numb << "] - Print dictionary" << endl; numb++;
        cout << "[" << numb << "] - Add new word" << endl; numb++;
        cout << "[" << numb << "] - Add translation to word" << endl; numb++;
        cout << " (/00)/ ---> "; cin >> choice;

        switch (choice)
        {
        case 0: cout << "BYE!" << endl; ext = true; break;
        case 1: ReadFromFile(dict); break;
        case 2: WriteToFile(dict); break;
        case 3: dict.Print(); break;
        case 4: AddWord(dict); break;
        case 5: AddTranslation(dict); break;
        default: cout << "Wrongn number!" << endl; break;
        }
        system("pause");
        system("cls");
    }

    //Dictionary dict("English-Ukrainian");
    //dict.InsertWord("run", { "bigtu","zapustutu","keruvatu" });
    //dict.InsertWord("make",  {"robutu","vurib","forma"} );
    //dict.InsertWord("mind", { "dumka","rozum","gluzd" });
    //dict.InsertWord("bad", { "podano","amoralnuy","zipsovanuy","brudkuy" });

    
    //// cin.ignore();

    //if (!dict.IsExist(input))
    //    cout << "Word not found!" << endl;
    //else
    //{
    //    string translate = "";
    //    do
    //    {
    //        cout << "Enter translate : ";
    //        getline(cin, translate);
    //        if(!translate.empty())
    //            dict.AddTranslation(input, translate);

    //    } while (!translate.empty());
    //}
    //dict.Print();

    //ofstream out("Dictionary.txt");
    //out << dict;
    //out.close();
    
    /*
    map<string, list<string>> dic;

    string word = "run";
    list<string> meanings = list<string>({ "bigtu","zapustutu","keruvatu" });
    dic.insert(make_pair(word, meanings));
    dic.insert(make_pair("make", list<string>({"robutu","vurib","forma"})));
    dic.insert(make_pair("mind", list<string>({"dumka","rozum","gluzd"})));
    dic.insert(make_pair("ride", list<string>({"yizdutu","katania","oblava"})));
    dic.insert(make_pair("bad", list<string>({"podano","amoralnuy","zipsovanuy","brudkuy"})));


    for (string str : dic["mind"])
    {
        cout << str << " ";
    }
    cout << endl;


    string input = "";
    cout << "Enter word to add translate : ";
    getline(cin, input);
   // cin.ignore();

    if (dic.find(input) == dic.end())
        cout << "Word not found!" << endl;
    else
    {
        string translate = "";
        do
        {
            cout << "Enter translate : ";
            getline(cin, translate);

            dic[input].push_back(translate);

        } while (!translate.empty());
    }

    for (string str : dic[input])
    {
        cout << str << " ";
    }
    cout << endl;
    */


}
