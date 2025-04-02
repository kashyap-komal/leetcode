/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let c=init;
    // return {
    //     increment:()=> ++c,
    //     reset:()=>c=init,
    //     decrement:()=>--c,
    // }

    function increment(){
        return ++c
    }
    function reset()
    {
        return (c=init)
    }
    function decrement()
    {
        return --c
    }

    return {increment,reset,decrement}
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */