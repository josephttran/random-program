function solution(S, K) {
    let newStr = S;
    let len = K;
    let M = 0;
    
    // string to uppercase   
    newStr = newStr.toUpperCase();  
    
    /* if S length less than or equal k then return S. */
    if (newStr.length <= len) {
        return newStr;
    }    
    
    /* format license key  */  
    let myRegex = /-/g; // search for dashes
    
    M = newStr.match(myRegex).length + 1; //M+1 group

    newStr = newStr.replace(/-/g, ""); //remove all dash
    
    let strArr = []
    strArr = newStr.split('');
    strArr = strArr.reverse();
    strArr = strArr.map((ele, i) => {
        if (i !== 0 && ((i + 1) % len === 0) && (i + 1 !== newStr.length)) {
            return '-' + ele;
        }
        return ele;
    })
    
    strArr = strArr.reverse();    
    newStr = strArr.join('');
    
    return newStr;
}