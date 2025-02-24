#include <iostream>
#include <string>
using namespace std;

template <typename... vals>
class Mytuple;

template <>
class Mytuple<>
{
};

template <typename Head, typename... Tail>
class Mytuple<Head, Tail...> : private Mytuple<Tail...>
{
public:
   Head m_head;
   Mytuple() {}
   Mytuple(Head v, Tail... vals) : m_head(v), Mytuple<Tail...>(vals...) {}

   Head GetHead() { return m_head; }
   Mytuple<Tail...> GetTail() { return *this; }
};

int main()
{
   Mytuple<int, float, string> t(6, 2.3, "hello");
   cout << t.GetHead() << endl;
   cout << t.GetTail().GetHead() << endl;
   cout << t.GetTail().GetTail().GetHead() << endl;
   system("pause");
   return 0;
}
