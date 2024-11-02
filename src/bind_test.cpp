#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
  vector<double> w;
  for (unsigned i = 0; i < 5; ++i) w.push_back(i);
  double sum_w = accumulate(w.begin(), w.end(), 0.0);

  cout << "original w:";
  for (unsigned i = 0; i < w.size(); ++i) cout << w[i] << " ";
  cout << endl;
  cout << "sum_w: " << sum_w << endl;

//   vector<double> w1(w);
//   cout << "deprecated bind2nd w: ";
//   transform(w1.begin(), w1.end(), w1.begin(), bind2nd(divides<double>(), sum_w));
//   for (unsigned i = 0; i < w1.size(); ++i) cout << w1[i] << " ";
//   cout << endl;

  cout << "bind w: ";
  std::transform(w.begin(), w.end(), w.begin(),
                 std::bind(std::divides<double>(), std::placeholders::_1,
                 sum_w));
  for(unsigned i = 0; i < w.size(); ++i) cout << w[i] << " ";
  cout << endl;

  return 0;
}