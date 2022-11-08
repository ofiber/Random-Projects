#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <map>
#include <cctype>

using namespace std;

int main()
{
    map<char, int> count;

    char letter = 'a';

    for(int i = 0; i < 26; i++)
    {
        count.insert(pair<char, int>(letter + i, 0));
    }


    ifstream din;
    ofstream dout;

    dout.open("res.txt");

    din.open("beemovie.txt");

    string line;

    while(getline(din, line))
    {
        if(line.length() == 0)
        {
            continue;
        }
        else
        {
            int len = line.length();
            int x = 0;

            while(x < len)
            {

                if(line[x] != ' ' && line[x] != '\n' && line[x] != '-' && line[x] != '.' && line[x] != ',' && line[x] != '\''
                && line[x] != '\"' && line[x] != '-' && line[x] != ':' && line[x] != '!' && line[x] != '?')
                {
                    char c = tolower(line[x]);
                    count[c] += 1;

                    dout << c << endl;
                }

                x++;
            }
        }
    }

    din.close();
    dout.close();

    map<char, int>::iterator itr;

    for(itr = count.begin(); itr != count.end(); ++itr)
    {
        cout << itr->first << " - " << itr->second << endl;
    }

    return 0;
}