let Queue = function() {
  this.data = [];
};

Queue.prototype.add = function(val) {
  this.data.push(val);
};

Queue.prototype.top = function() {
  if (this.data.length <= 0) {
    // console.log('Empty queue!');
    return null;
  } else {
    return this.data[0];
  }
};

Queue.prototype.pop = function() {
  if (this.data.length <= 0) {
    // console.log('Empty queue!');
    return `Empty queue!`;
  } else {
    let val = this.data.shift();
    return val;
  }
};

Queue.prototype.size = function() {
  return this.data.length;
};

Queue.prototype.isEmpty = function() {
  if (this.data.length === 0) {
    return true;
  } else {
    return false;
  }
};

module.exports = Queue;
