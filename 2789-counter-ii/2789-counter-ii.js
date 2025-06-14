/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    const initial = init;
    let curr = init;
    const func = {
        increment: () => {
            return ++curr;
        },
        decrement: () => {  
            return --curr;
        },
        reset: () => {
            curr = initial;
            return curr;
        }
    }
    return func;
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */