/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(a) {
    let ct=0,element=1e9+1;
    for(let i in a){
        if(a[i]===element) ct++;
        else{
            if(ct) ct--;
            else{
                element=a[i];
                ct++;
            }
        }
    }
    ct=0;
    for(let i in a){
        if(a[i]===element) ct++;
    }
    if(ct>=Math.floor(a.length/2)) return element;
    return -1;
};