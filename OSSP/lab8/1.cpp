#include <bits/stdc++.h>
using namespace std;
int pageFaults(int pages[], int n, int capacity)
{
    unordered_set<int> s;
    unordered_map<int, int> indexes;
    int page_faults = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.size() < capacity)
        {
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);
                page_faults++;
            }
            indexes[pages[i]] = i;
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int lru = INT_MAX, val;
                for (auto it = s.begin(); it != s.end(); it++)
                {
                    if (indexes[*it] < lru)
                    {
                        lru = indexes[*it];
                        val = *it;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                page_faults++;
            }
            indexes[pages[i]] = i;
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