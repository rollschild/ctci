
function tripleStep(n) {
  let cache = [];
  return cal(n, cache);
}

function cal(n, cache) {
  if (n < 0) {
    return 0;
  }

  if (n === 0) {
    return 0;
  }
  if (n === 1) {
    return 1;
  }
  if (n === 2) {
    return 2;
  }
  if (n === 3) {
    return 4;
  }

  if (cache[n] === undefined) {
    cache[n] = cal(n - 1, cache) + cal(n - 2, cache) + cal(n - 3, cache);
  }

  return cache[n];
}

console.log(tripleStep(1), 1);
console.log(tripleStep(2), 2);
console.log(tripleStep(3), 4);
console.log(tripleStep(4), 7);
console.log(tripleStep(5), 13);
