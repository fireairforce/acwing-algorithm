vector<int>::iterator unique(vector<int> &a) {
  int j = 0;
  for (int i = 0;i < a.size(); i ++) {
    if (!i || a[i] != a[i - 1]) {
      a[j ++ ] = a[i];
    }
  }
  return a.begin() + j;
}
