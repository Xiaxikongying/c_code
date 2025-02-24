#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Device
{
    int x, y, w;
};

struct Weapon
{
    int e, h;
};

// 比较函数
bool cmpD(const Device &a, const Device &b)
{
    return a.x < b.x;
}

bool comW(const Weapon &a, const Weapon &b)
{
    return a.e < b.e;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<Device> ds(n);
    vector<Weapon> ws(m);

    for (int i = 0; i < n; ++i)
        cin >> ds[i].x >> ds[i].y >> ds[i].w;
    
    for (int j = 0; j < m; ++j)
        cin >> ws[j].e >> ws[j].h;
    

    // 按照x排序
    sort(ds.begin(), ds.end(), cmpD);
    sort(ws.begin(), ws.end(), comW);

    int to_en = 0;

    for (const auto &weapon : ws)
    {
        int e = weapon.e;
        int h = weapon.h;
        if (e > k)
            continue;

        // 查找所有可能影响的减速装置
        for (const auto &device : ds)
        {
            if ((device.x <= e && e <= device.x + device.w) && device.y <= h)
            {
                to_en++;
            }
        }
    }
    cout << to_en << endl;
    system("pause");
    return 0;
}
