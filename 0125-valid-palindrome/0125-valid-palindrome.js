/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    
         const cleanedStr = s.toLowerCase().replace(/[^a-z0-9]/g, '');
  let reversedStr = '';
  for (let i = cleanedStr.length - 1; i >= 0; i--) {
    reversedStr += cleanedStr[i];
  }
  return cleanedStr === reversedStr;
        
    
    
};