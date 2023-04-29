seq = [3, 2, 1, 8, 6, 9, 7, 12, 11, 20, 4, 13, 21];

function LIS(sequence) {
  const n = sequence.length;
  const lengths = new Array(n);
  const indexes = new Array(n);
  let maxLength = 0;
  let maxIndex = 0;

  for (let i = 0; i < n; i++) {
    lengths[i] = 1;
    indexes[i] = -1;

    for (let j = 0; j < i; j++) {
      if (sequence[j] < sequence[i] && lengths[j] + 1 > lengths[i]) {
        lengths[i] = lengths[j] + 1;
        indexes[i] = j;
      }
    }

    if (lengths[i] > maxLength) {
      maxLength = lengths[i];
      maxIndex = i;
    }
  }

  const result = new Array(maxLength);
  let i = maxIndex;

  while (i >= 0) {
    result[--maxLength] = sequence[i];
    i = indexes[i];
  }

  return result;
}

console.log(LIS(seq));
