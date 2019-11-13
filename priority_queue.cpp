#include <iostream>
#include <set>

using namespace std;

template <class Type>
class custom_compare
{
public:
    bool operator()(const Type& lhs, const Type& rhs)
    {
        return lhs.first > rhs.first;
    }
};
template <class Type>
class priority_queue
{
private:
    multiset<Type, custom_compare<Type> > ms;
public:
    priority_queue()
    {
    }
    virtual ~priority_queue()
    {
        ms.clear();
    }
    bool empty()
    {
        return ms.empty();
    }
    size_t size()
    {
        return ms.size();
    }
    const Type& top()
    {
        auto citer = ms.cbegin();
        if (citer != ms.cend())
        {
            return *citer;
        }
    }
    void push(const Type &val)
    {
        ms.insert(val);
    }
    void pop()
    {
        if (ms.begin() != ms.end())
        {
            ms.erase(ms.begin());
        }
    }
};
int main(int argc, char **argv)
{
    priority_queue< pair<int,int> > pq;

    int priority[] = {3, 1, 2, 4, 5, 1, 3, 2, 3, 4, 1, 2, 5, 1, 3, 2, 1, 1};
    int data[]     = {8, 23, 6, 12, 9, 5, 7, 3, 0, 4, 52, 8, 56, 34, 547, 9, 46, 19};
    for (int i = 0; i < sizeof(priority)/sizeof(int); i++)
    {
        cout << "push: [priority : " << priority[i] << "][data : " << data[i] << "]" << endl;
        pq.push(make_pair(priority[i], data[i]));
    }
    for (int i = 0; i < sizeof(priority)/sizeof(int); i++)
    {
        cout << "top : [priority : " << pq.top().first << "][data : " << pq.top().second << "]" << endl;
        pq.pop();
    }
    return 0;
}
