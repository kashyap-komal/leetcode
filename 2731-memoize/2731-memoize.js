/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const cache={};//stores previosly computed res
    return function(...args) {
        const key=JSON.stringify(args); //converts arguments to striing key
        if(key in cache)
        {
            return cache[key]; //check if it already in cache then resturn cached res
        }
        const res=fn.apply(this,args);    //call original function with args
        cache[key]=res; //store res in cache
        return res; //return cache;/
        
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */