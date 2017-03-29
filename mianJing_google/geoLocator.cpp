//a file with IP ranges that are mapped to cities.  The format of each line: startIP, endIP, cityName.  Let’s say that we want to geolocate a user’s IP address.  Write a fast lookup function that takes an Input of an IP address, and outputs its associated cityName..1point3acres缃�
//startIP, endIP, cityName
//1.1.1.0, 1.1.1.255, CityA
//2.2.2.0, 2.2.2.255, CityB.
//
//For example:
//input 2.2.2.2, output CityB.


///
//把ip 地址转换成一个整数（32位），每个城市都在一个区间里。
// O(n) n: 城市数量
///

#include <iostream>
#include <vector>

#define N 26
using namespace std;

