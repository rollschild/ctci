// Naive way: O(3^n)
// 1, 2, or 3 steps each time
function tripleStep(n) {
  if (n <= 0) {
    return 0;
  }
  if (n === 1 || n === 2) {
    return n;
  }
  if (n === 3) {
    return 4;
  }

  return tripleStep(n - 1) + tripleStep(n - 2) + tripleStep(n - 3);
}

console.log(tripleStep(4));
console.log(tripleStep(5));
