/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkInclusion = function(s1, s2) {
    let m=s1.length,n=s2.length;
    if(m>n) return false;
    let ct = [];
    for(let i in s1){
        ct[s1.charCodeAt(i)-97] = (ct[s1.charCodeAt(i)-97]||0) + 1;
    }
    let cur=[];

    for(let i=0; i<m; i++){
        cur[s2.charCodeAt(i)-97] = (cur[s2.charCodeAt(i)-97]||0) + 1;
    }

    let check = (cur,ct)=>{
        for(let i in ct){
            if(cur[i]!=ct[i]) return false;
        }
        return true;
    };

    if(check(cur,ct)) return true;
    for(let i=m; i<n; i++){
        cur[s2.charCodeAt(i)-97] = (cur[s2.charCodeAt(i)-97]||0) + 1;
        cur[s2.charCodeAt(i-m)-97] = (cur[s2.charCodeAt(i-m)-97] - 1);
        if(check(cur,ct)) return true;
    }

    return false;
};