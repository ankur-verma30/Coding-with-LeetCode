/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
     var inital_value=n;
    
    return function() {
        return inital_value++;
        
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */