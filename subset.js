function subset(arr) {
  return traverse(arr, arr.length);
}

function traverse(arr, index) {
  let allSubsets = [];
  if (index === 0) {
    allSubsets.push([]);
    return allSubsets;
  }

  // index !== 0
  allSubsets = traverse(arr, index - 1);
  let moreSubsets = traverse(arr, index - 1);
  moreSubsets.forEach(function(sub){
    sub.push(arr[index - 1]);
  });
  allSubsets = allSubsets.concat(moreSubsets);
  return allSubsets;
}

let someSet = [0, 1, 2];

console.log(subset(someSet));
