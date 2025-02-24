#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void display_tag(input_iterator_tag)
{
    cout << "input_iterator_tag" << endl;
}
void display_tag(output_iterator_tag)
{
    cout << "output_iterator_tag" << endl;
}
void display_tag(forward_iterator_tag)
{
    cout << "forward_iterator_tag" << endl;
}
void display_tag(bidirectional_iterator_tag)
{
    cout << "bidirectional_iterator_tag" << endl;
}
void display_tag(random_access_iterator_tag)
{
    cout << "random_access_iterator_tag" << endl;
}

template <typename I>
void display_category(I ite)
{
    typename iterator_traits<I>::iterator_category cagy;
    display_tag(cagy);
}

int main()
{
    display_category(vector<int>::iterator());
    cout << typeid(iterator_traits<vector<int>::iterator>::iterator_category).name() << endl;
    display_category(list<int>::iterator());
    display_category(deque<int>::iterator());
    display_category(set<int>::iterator());
    display_category(map<int, int>::iterator());
    display_category(unordered_set<int>::iterator());
    display_category(unordered_map<int, int>::iterator());

    display_category(istream_iterator<int>());
    display_category(ostream_iterator<int>(cout, ""));
    vector<int> vec;
    sort(vec.begin(), vec.end());
    list<int> lis;
    sort(lis.begin(), lis.end());
    /*
    int a = 0;
    decltype(a) b = 0;
    cout << typeid(int).name() << endl;
    */

    system("pause");
    return 0;
}
/*

  template<typename _RandomAccessIterator, typename _Compare>
    inline void
    __sort(_RandomAccessIterator __first, _RandomAccessIterator __last,
       _Compare __comp)
    {
      if (__first != __last)
    {
      std::__introsort_loop(__first, __last,
                std::__lg(__last - __first) * 2,
                __comp);
      std::__final_insertion_sort(__first, __last, __comp);
    }
    }
*/
