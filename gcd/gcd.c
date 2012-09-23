int gcd (int* value, int u, int v) {
  if (value == 0) return 1;
  if (u < 1) return 1;
  if (v < 1) return 1;

  while (u > 0) {
    if (u < v) {
      *value = u;
      u = v;
      v = *value;
    }
    u = u - v;
  }
  *value = v;

  return 0;
}
