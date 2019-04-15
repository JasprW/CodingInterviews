#include <iostream>
using namespace std;

bool isNumeric(char *string)
{
    bool hasE = false;
    int sign1 = 0, sign2 = 0, dem = 0, e = 0;
    for (int i = 0; *(string + i) != 0; i++)
    {
        if (*(string + i) == '+' || *(string + i) == '-')
        {
            if (i == 0)
            {
                sign1 = *(string + i) == '+' ? 1 : -1;
            }
            else if (*(string + i - 1) == 'e' || *(string + i - 1) == 'E')
            {
                sign2 = *(string + i) == '+' ? 1 : -1;
            }
            else
            {
                return false;
            }
        }
        else if (*(string + i) == 'E' || *(string + i) == 'e')
        {
            if (hasE)
            {
                return false;
            }
            else
            {
                hasE = true;
                e = i;
            }
            continue;
        }
        else if (*(string + i) == '.')
        {
            if (dem)
            {
                return false;
            }
            else
            {
                dem = i;
            }
            continue;
        }
        else if (!(*(string + i) >= '0' && *(string + i) <= '9'))
        {
            return false;
        }
    }
    if (dem && e && dem > e)
    {
        return false;
    }
    if (hasE && *(string + e + 1) == 0)
    {
        return false;
    }
    return true;
}

int main()
{
    char *string = "100";
    cout << (isNumeric(string) ? "True" : "False");
}