#include <iostream>
#include <string>
#include <vector>

using namespace std;

class OpenHashTable
{
  private:
    vector<string> table = vector<string>(8);
    vector<bool> deleted = vector<bool>(8, false);
    size_t elementCount = 0;

    const size_t a = 7;

    size_t _HashHorner(const string &str, size_t _M) const;
    size_t _LinearHash(const string &str, const vector<string> &_table) const;
    size_t _QuadHash(const string &str, const vector<string> &_table) const;
    size_t _DoubleHash(const string &str, const vector<string> &_table) const;
    size_t _DoubleHashNotEven(const string &str, const vector<string> &_table) const;
    size_t _Hash(const string &str, const vector<string> &_table) const;

    bool _isCompleted(size_t curCapacity);
    void _reHashofTable();

    void print() const
    {
        cout << "--------Print--------" << endl;
        for (auto el : table)
        {
            if (el != "")
                cout << el << " " << _Hash(el, table) << endl;
        }
    }

  public:
    bool Add(const string &str);
    bool Delete(const string &str);
    bool Find(const string &str) const;
};

bool OpenHashTable::Add(const string &str)
{
    size_t _M = table.size();
    auto hash = _Hash(str, table);
    if (table[hash].size())
    {
        if (!deleted[hash])
            return false;
        else
        {
            deleted[hash] = false;
            return true;
        }
    }

    auto curCapacity = _M;
    if (_isCompleted(curCapacity))
    {
        _M = table.size();
        hash = _Hash(str, table);
    }

    table[hash] = move(str);
    deleted[hash] = false;
    elementCount++;
    return true;
}

size_t OpenHashTable::_Hash(const string &str, const vector<string> &_table) const
{
    size_t hash = _LinearHash(str, _table);
    // size_t hash = _QuadHash(str, table);
    // size_t hash = _DoubleHash(str, _table);

    return hash;
}

size_t OpenHashTable::_LinearHash(const string &str, const vector<string> &_table) const
{
    auto _M = _table.size();
    auto hash = _HashHorner(str, _M);

    for (size_t i = 1; _table[hash].size() && _table[hash] != str; ++i)
    {
        hash = (hash + i) % _M;
    }
    return hash;
}

size_t OpenHashTable::_QuadHash(const string &str, const vector<string> &_table) const
{
    auto _M = _table.size();
    auto hash = _HashHorner(str, _M);

    for (size_t i = 1; _table[hash].size() && _table[hash] != str; ++i)
    {
        hash = (hash + i * i) % _M;
    }
    return hash;
}

size_t OpenHashTable::_DoubleHash(const string &str, const vector<string> &_table) const
{
    auto _M = _table.size();
    auto hash = _HashHorner(str, _M);

    for (; _table[hash].size() && _table[hash] != str;)
    {
        hash = (hash + _DoubleHashNotEven(str, _table)) % _M;
    }
    return hash;
}

size_t OpenHashTable::_DoubleHashNotEven(const string &str, const vector<string> &_table) const
{
    auto _M = _table.size();
    return 1 + _HashHorner(str, _M);
}

size_t OpenHashTable::_HashHorner(const string &str, size_t _M) const
{
    size_t hash = str[0];

    for (size_t i = 1, strSize = str.size(); i < strSize; ++i)
    {
        hash = (hash * a + str[i]) % _M;
    }

    return hash;
}

bool OpenHashTable::_isCompleted(size_t curCapacity)
{
    if (4ULL * (elementCount + 1ULL) >= 3ULL * curCapacity)
    {
        _reHashofTable();
        return true;
    }
    return false;
}

void OpenHashTable::_reHashofTable()
{
    auto curCapacity = table.size();
    auto newCapacity = curCapacity << 2;

    vector<string> newTable(newCapacity);

    for (size_t i = 0; i < curCapacity; ++i)
    {
        if (!deleted[i] && table[i].size())
        {
            auto newHash = _Hash(table[i], newTable);
            newTable[newHash] = move(table[i]);
        }
    }
    table = std::move(newTable);
    deleted = vector<bool>(newCapacity, false);
    elementCount = 0;
}

bool OpenHashTable::Find(const string &str) const
{
    auto hash = _Hash(str, table);
    return table[hash].size() && !deleted[hash];
}

bool OpenHashTable::Delete(const string &str)
{
    auto hash = _Hash(str, table);
    if (table[hash].size() && !deleted[hash])
        return deleted[hash] = true;
    return false;
}

/*

+ a
+ b
+ c
+ d
+ e
+ f
+ g
+ h
+ i
+ k
+ l
+ m
+ n
+ o
+ p
+ r
+ s
+ t
? a
? b
? c
? d
? e
? f
? g
? h
? i
? k
? l
? m
? n
? o
? p
? r
? s
? t

+ aa
+ bb
+ cc
+ dd
+ ee
+ ff
+ gg
+ hh
+ ii
+ kk
+ ll
+ mm
+ nn
+ oo
+ pp
+ rr
+ ss
+ tt
? aa
? bb
? cc
? dd
? ee
? ff
? gg
? hh
? ii
? kk
? ll
? mm
? nn
? oo
? pp
? rr
? ss
? tt
*/

int main()
{
    // ios_base::sync_with_stdio(false);
    OpenHashTable table;
    char operant;
    string str;

    vector<bool> answer;
    while (cin >> operant >> str)
    {
        switch (operant)
        {
            case '+': answer.push_back(table.Add(str)); break;
            case '-': answer.push_back(table.Delete(str)); break;
            case '?': answer.push_back(table.Find(str)); break;
            default: cout << "Wrong input" << endl;
        }
    }
    for (auto el : answer)
        if (el)
            cout << "OK" << endl;
        else
        {
            cout << "FAIL" << endl;
        }
    return 0;
}

/*
------------Waste lands---------------





  */
