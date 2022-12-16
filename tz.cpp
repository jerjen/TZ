#include <iostream>
#include <string>
#include <fstream>


using namespace std;

void output(string out);

int main()
{
    setlocale(LC_ALL, "ru");
    string out1 = "out1.txt";
    string out2 = "out2.txt";
    string out3 = "out3.txt";

    
    output(out1);
    output(out2);
    output(out3);
}


void output(string out)
{
    ofstream fout;
    ifstream fin;
    fin.exceptions(ifstream::badbit);
    string input = "input.txt";
    fout.open(input, ofstream::app);
    try
    {
        fin.open(out);
        cout << "open" << endl;
        string str;
        char ch;
        fout << "\n" << out << endl;
        while (fin.get(ch))
        {
            if (ch == 33)
            {
                fout << "\n";
                fout << ch << endl;

            }
            else
            {
                fout << ch;
            }

        }
    }
    catch (const std::exception & ex)
    {
        cout << ex.what() << endl;
        cout << "Ошибка открытия файла" << endl;
    }
    fin.close();
    fout.close();
}