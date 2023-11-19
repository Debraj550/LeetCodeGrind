/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    try {
        //const [a, b] = await Promise.all([promise1, promise2]);
        const a = await promise1;
        const b = await promise2;
        return a + b; 
    } catch(err) {
        consoloe.log(err);
        throw err;
    }
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */