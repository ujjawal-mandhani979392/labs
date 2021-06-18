#include <bits/stdc++.h>
using namespace std;

int main()
{
    string msg = "KeEp smiLinG, beCause liFe is a beAutiful tHing";
    int mic = -1;
    string cipher = "";
    for (int i = 0; i < msg.length(); i++)
    {
        if (msg[i] == ' ')
            continue;
        mic++;
        if (msg[i] >= 65 && msg[i] <= 90)
        {
            cipher += char(int(65 + (msg[i] - 3) % 26)); //this is error try correcting logic
        }
        else if (mic % 5 == 0)
        {
            cipher += msg[i];
        }
    }
    cout << cipher.c_str() << endl;
    return 0;
}