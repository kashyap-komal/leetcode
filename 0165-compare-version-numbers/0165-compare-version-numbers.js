/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
    const v1=version1.split(".").map(Number)
    const v2=version2.split(".").map(Number)

    const maxlength= Math.max(v1.length,v2.length);
    for(let i=0;i<maxlength;i++)
    {
        const n1=v1[i] || 0;
        const n2=v2[i] || 0;

        if(n1<n2)
        return -1;
        else if(n1>n2)
        return 1;
        
    }
    return 0;

    
};