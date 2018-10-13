function magicIndex(arr) {
  if (arr.length <= 0) {
    return null;
  }

  return search(arr, 0, arr.length - 1);
};

function search(arr, left, right) {
  if (left > right) {
    return null;
  }

  let pivot = Math.floor((left + right) / 2);
  if (arr[pivot] == pivot) {
    return pivot;
  }
  
  if (arr[pivot] > pivot){
    return search(arr, pivot + 1, right);
  } else {
    return search(arr, left, pivot - 1);
  }
}

// TEST
//         0, 1, 2, 3, 4, 5, 6, 7, 8, 9
let arr = [9, 8, 7, 6, 4, 2, 1];
console.log(magicIndex(arr), 4);
