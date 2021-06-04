#include <string>
#include <iostream>
#include <string.h>

using namespace std;

class StudentName
{

private:
    string *arrNames;
    int numOfNames = 0;

public:
    StudentName(string name)
    {

        int numOfSpaces = 0, index;
        for (int i = 0; i < name.size(); i++)
        {
            if (name[i] == ' ')
            {
                numOfSpaces++;
            }
        }

        if (numOfSpaces < 2)
        {
            arrNames = new string[3];
        }
        else
        {
            arrNames = new string[numOfSpaces + 1];
        }

        string subName = "";
        numOfNames = 0;
        for (int i = 0; i < name.length(); ++i)
        {
            if (name[i] != ' ')
            {
                subName += name[i];
            }
            else
            {
                arrNames[numOfNames++] = subName;
                subName = "";
            }
        }

        if (subName != "")
        {
            arrNames[numOfNames++] = subName;
        }

        if (numOfSpaces == 0)
        {
            arrNames[1] = arrNames[0];
            arrNames[2] = arrNames[0];
            numOfNames += 2;
        }
        else if (numOfSpaces == 1)
        {
            arrNames[2] = arrNames[1];
            numOfNames++;
        }
    }

    void print()
    {
        for (int i = 0; i < numOfNames; i++)
        {
            cout << i + 1 << ") " << arrNames[i] << endl;
        }
    }

    bool Replace(int i, int j)
    {
        if (i > numOfNames || j > numOfNames || i < 1 || j < 1)
        {
            return false;
        }
        else
        {
            string temp = arrNames[i - 1];
            arrNames[i - 1] = arrNames[j - 1];
            arrNames[j - 1] = temp;
            return true;
        }
    }

    ~StudentName()
    {
        delete[] arrNames;
    }
};

void testCase(string name, int i, int j)
{
    cout << "Input: \nName: " << name << endl
         << "I: " << i << endl
         << "J: " << j << endl;
    StudentName studentName(name);
    cout << "Output: \n";
    cout << (studentName.Replace(i, j) ? "True" : "False") << endl;
    studentName.print();
}
int main()
{
    testCase("Noura Ashraf", 1, 3);
    testCase("Sama Khalifa Sohaila Mahmoud Noura Ashraf Sherif", 1, 4);
    testCase("Noura", 1, 2);
    testCase("Sohaila Mahmoud", 2, 1);
    testCase("Noura Ashraf", 5, 1);
    testCase("Samaa Khalifa", 3, 5);
    testCase("Noura Sherif", 2, 0);
    return 0;
}
