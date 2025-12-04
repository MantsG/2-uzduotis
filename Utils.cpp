#include "Utils.h"
#include <algorithm>
#include <cctype>

using std::string;
using std::vector;


bool naturalCompare(const string& a, const string& b){
    size_t i=0, j=0;
    while(i < a.size() && j < b.size()){
        if(std::isdigit(static_cast<unsigned char>(a[i])) && std::isdigit(static_cast<unsigned char>(b[j]))){
            size_t i2 = i;
            while(i2 < a.size() && std::isdigit(static_cast<unsigned char>(a[i2]))) ++i2;
            size_t j2 = j;
            while(j2 < b.size() && std::isdigit(static_cast<unsigned char>(b[j2]))) ++j2;

            int numA = 0;
            for(size_t k=i; k<i2; ++k) numA = numA*10 + (a[k]-'0');
            int numB = 0;
            for(size_t k=j; k<j2; ++k) numB = numB*10 + (b[k]-'0');

            if(numA != numB) return numA < numB;
            i = i2;
            j = j2;
        } else{
            if(a[i] != b[j]) return a[i] < b[j];
            i++; j++;
        }
    }
    return a.size() < b.size();
}

double median(vector<int> &v){
    if(v.empty()) return 0.0;
    vector<int> laik=v;
    std::sort(laik.begin(), laik.end());
    int n = static_cast<int>(laik.size());
    if(n % 2 == 1)
        return static_cast<double>(laik[n/2]);
    else
        return (laik[n/2-1] + laik[n/2]) / 2.0;
}
