/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((res, rej) => {
        if(functions.length === []){
            resolve([]);
            return;
        }
        const result = new Array(functions.length).fill(null);
        let resolveCount = 0;
        
        functions.forEach(async (ele, idx) => {
            try {
                const subresult = await ele();
                result[idx] = subresult;
                resolveCount++;
                if(resolveCount === functions.length) {
                    res(result);
                }
            } catch(err) {
                rej(err);
            }
        });
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */