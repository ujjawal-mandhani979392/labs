#include <bits/stdc++.h>
using namespace std;
int pageFaults(int pages[], int n, int capacity)
{
    unordered_set<int> s;
    queue<int> indexes;
    int page_faults = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.size() < capacity)
        {
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);
                page_faults++;
                indexes.push(pages[i]);
            }
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int val = indexes.front();
                indexes.pop();
                s.erase(val);
                s.insert(pages[i]);
                indexes.push(pages[i]);
                page_faults++;
            }
        }
    }
    return page_faults;
}
int main()
{
    int pages[] = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;
    cout << pageFaults(pages, n, capacity) << endl;
    capacity = 4;
    cout << pageFaults(pages, n, capacity) << endl;
    capacity = 5;
    cout << pageFaults(pages, n, capacity) << endl;
    capacity = 6;
    cout << pageFaults(pages, n, capacity) << endl;
    capacity = 7;
    cout << pageFaults(pages, n, capacity) << endl;
    return 0;
}