// Copyright 2021 NNTU-CS
int countPairs1(int *array, int size, int target) {
  int total = 0;

  for (int a = 0; a < size - 1; ++a) {
    for (int b = a + 1; b < size; ++b) {
      if (array[a] + array[b] == target) {
        ++total;
      }
    }
  }

  return total;
}

int countPairs2(int *array, int size, int target) {
  int total = 0;
  int right = size - 1;

  while (right > 0) {
    if (array[right] > target) {
      --right;
    } else {
      break;
    }
  }

  for (int a = 0; a < size; ++a) {
    for (int b = right; b > a; --b) {
      if (array[a] + array[b] == target) {
        ++total;
      }
    }
  }

  return total;
}

int Step(int *array, int left, int right, int key) {
  int firstMatch = -1;
  int l = left;
  int r = right;

  while (l <= r) {
    int mid = l + (r - l) / 2;

    if (array[mid] >= key) {
      r = mid - 1;
      if (array[mid] == key) {
        firstMatch = mid;
      }
    } else {
      l = mid + 1;
    }
  }

  if (firstMatch == -1) {
    return 0;
  }

  int lastMatch = firstMatch;
  l = firstMatch;
  r = right;

  while (l <= r) {
    int mid = l + (r - l) / 2;

    if (array[mid] <= key) {
      l = mid + 1;
      if (array[mid] == key) {
        lastMatch = mid;
      }
    } else {
      r = mid - 1;
    }
  }

  return lastMatch - firstMatch + 1;
}

int countPairs3(int *array, int size, int target) {
  int total = 0;

  for (int i = 0; i < size; ++i) {
    total += Step(array, i + 1, size - 1, target - array[i]);
  }

  return total;
}
