#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    int x = (1 + (double)brown / 4) + sqrt(pow(1 + (double)brown / 4, 2) - brown - yellow);
    int y = (yellow + brown) / x;
    return {x, y};
}