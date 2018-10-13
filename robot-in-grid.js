function robotInGrid(grid) {
  if (grid.length === 0) {
    return false;
  }
  if (grid[0].length === 0) {
    return false;
  }
  let cache = new Set();
  let path = [];
  if (crawl(grid, grid.length-1, grid[0].length-1, cache, path)) {
    return path;
  }

  return false;
}


function crawl(grid, r, c, cache, path) {
  if (r < 0 || c < 0 || !grid[r][c]) {
    return false;
  }
  
  if (cache.has([r, c])) {
    return false;
  }

  let atTopLeft = (r == 0) && (c == 0);

  if (atTopLeft 
      || crawl(grid, r - 1, c, cache, path) 
      || crawl(grid, r, c - 1, cache, path)) {
    path.push([r, c]);
    cache.add([r, c]);
    return true;
  } else {
    cache.add([r, c]);
    return false;
  }
};

// TEST
let grid = [
  [1, 0, 1, 0, 1, 1],
  [1, 1, 0, 1, 0, 0],
  [0, 1, 1, 1, 1, 1],
];

console.log(robotInGrid(grid));

/** Result should be:
 * 0, 0 -> 1, 0 -> 1, 1 -> 2, 1 -> 2, 2 -> 2, 3 -> 2, 4 -> 2, 5
 *
 *
 */
