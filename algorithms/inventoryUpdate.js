function updateInventory(arr1, arr2) {
    let newArr = arr1;

    arr2.forEach((ele) => {
        let found = false;

        arr1.forEach((ele2, index2) => {
            if(ele2[1] === ele[1]) {
                newArr[index2][0] += ele[0];
                found = true;
            };
        })

        if (!found) {
            newArr.push(ele);
        }
    })

    newArr = newArr.sort((a, b) => {
        if(a[1] < b[1]){
            return -1
        } 
		
        if (a[1] > b[1]) {
            return 1
        };
		
		return 0
    })

    return newArr;
}

const curInv = [
    [21, "Bowling Ball"],
    [2, "Dirty Sock"],
    [1, "Hair Pin"],
    [5, "Microphone"]
];

const newInv = [
    [2, "Hair Pin"],
    [3, "Half-Eaten Apple"],
    [67, "Bowling Ball"],
    [7, "Toothpaste"]
];

console.log(updateInventory(curInv, newInv));