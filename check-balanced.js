// THIS IS A WRONG SOLUTION
function treeNode(val) {
  this.value = 0;
  this.left = null;
  this.right = null;
};

function checkBalanced(node) {
  return Math.abs(checkHeight(node.left, 1) - checkHeight(node.right, 1)) <= 1;
};

function checkHeight(node, depth) {
  if (node === null) {
    return depth - 1;
  }
  if (node.left === null && node.right === null) {
    return depth;
  } else if (node.left === null) {
    return checkHeight(node.right, depth + 1);
  } else if (node.right === null) {
    return checkHeight(node.left, depth + 1);
  } else {
    let heightLeft = checkHeight(node.left, depth + 1);
    let heightRight = checkHeight(node.right, depth + 1);
    return Math.max(heightLeft, heightRight);
  }
};

let root = new treeNode(2);

root.left = new treeNode(4);
root.right = new treeNode(1);
root.left.left = new treeNode(6);
root.left.right = new treeNode(5);
root.right.right = new treeNode(3);
root.right.right.right = new treeNode(7);
// root.right.right.right.left = new treeNode(-1);
console.log(checkBalanced(root));
