// let Queue = require("./queue.js");

let Node = function(value) {
  this.value = value;
  this.left = null;
  this.right = null;
}

function minimalTree(arr) {
  if (arr.length <= 0) {
    return null;
  }
  return insert(arr, 0, arr.length-1);
}

function insert(arr, left, right) {
  if (arr.length <= 0) {
    return null;
  }
  if (left > right) {
    return null;
  }
  let pivot = Math.floor((left + right) / 2);
  let node = new Node(arr[pivot]);
  node.left = insert(arr, left, pivot - 1);
  node.right = insert(arr, pivot + 1, right);

  return node;
}

function dfsPrint(node) {
  if (node === null) {
    return;
  }

  console.log(node.value);
  dfsPrint(node.left);
  dfsPrint(node.right);
}

let vec = [0, 1, 2, 3, 4, 5, 6, 7, 8];
dfsPrint(minimalTree(vec));
