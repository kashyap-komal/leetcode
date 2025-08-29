/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    const res={};
    arr1.map((val)=>res[val.id]=val)
    arr2.map((val)=>res[val.id]={...(res[val.id]?? {}),...val})
    return Object.values(res)
    
};