// O(n)

function fibonacci(n) {
  let cache = [];
  cache.push(0);
  cache.push(1);
  return fibo(n, cache);
};

function fibo(n, cache) {
  if (n === 0 || n === 1) {
    return n;
  }

  if (cache[n] === undefined) {
    cache[n] = fibo(n - 1, cache) + fibo(n - 2, cache);
  }

  return cache[n];
}

// TEST
console.log("5: ", fibonacci(5));
console.log("6: ", fibonacci(6));
console.log("4: ", fibonacci(4));
console.log("2: ", fibonacci(2));
console.log("1: ", fibonacci(1));
console.log("7: ", fibonacci(7));

