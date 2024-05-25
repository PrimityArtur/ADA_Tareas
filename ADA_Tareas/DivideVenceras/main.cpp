#include <iostream>
#include <vector>

void prints(std::vector<int> s) {
  for (int i = 0; i < s.size(); i++) {
    std::cout << s[i] << " ";
  }
  std::cout << std::endl;
}

void vorazDevolverCambio(int p, std::vector<int> s, std::vector<int> c) {
  int actual = 0;
  int j = c.size() - 1;

  while (actual != p) {
    for (; c[j] > (p - actual) && j >= 0; j--) {
    }

    if (j == -1) {
      std::cout << "No se puede devolver cambio" << std::endl;
      return;
    }
    s[j] = (p - actual) / c[j];
    actual += c[j] * s[j];
  }
  std::cout << "cambio = " << p << std::endl;
  prints(c);
  prints(s);
}

int main() {
  std::vector<int> m = {100, 50, 20, 10, 2, 1, 7};
  std::vector<int> s(m.size());
  int cambio = 180;

  vorazDevolverCambio(cambio, s, m);
}
