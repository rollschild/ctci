let Queue = function() {
  this.data = [];
};

Queue.prototype.push = function(value) {
  this.data.push(value);
};

Queue.prototype.pop = function() {
  if (this.data.length <= 0) {
    return `queue is empty!`;
  } else {
    let topValue = this.data.shift();
    return topValue;
  }
};

Queue.prototype.top = function() {
  if (this.data.length <= 0) {
    return null;
  } else {
    return this.data[0];
  }
};

Queue.prototype.size = function() {
  return this.data.length;
};

Queue.prototype.isEmpty = function() {
  return this.data.length === 0;
}

module.exports = Queue;
