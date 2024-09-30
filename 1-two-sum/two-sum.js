/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, k) {
    let n=nums.length;
    let a=[];
    for(let i in nums){
        a.push([nums[i],Number(i)]);
    }

    a.sort(([a1,a2],[b1,b2])=> {
        if(a1==b1) return a2-b2;
        return a1-b1;
    });

    let i=0,j=n-1;
    while(i<j){
        if(a[i][0]+a[j][0]===k) return [a[i][1],a[j][1]];
        else if(a[i][0]+a[j][0]>k) j--;
        else i++;
    }

    return [n,1];
};