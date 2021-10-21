/* function that splits an array (first argument) into groups the length of size (second argument) 
 * and returns them as a two-dimensional array.
 */
function chunkArrayInGroups(arr, size) {
  let tempArr = [];
	let k=0;
	let len = arr.length;
	
	for(let a=0; a < len/2; a++){		    
		tempArr[k] = arr.splice(0, size);
		k++; 
	}
	
	let b = tempArr.length-1; 
	while (tempArr[b] == ""){
		tempArr.pop();
		b--;
	}
	arr = tempArr;
		
  return arr;
}

//should return [[0, 1, 2, 3], [4, 5, 6, 7], [8]]
console.log(chunkArrayInGroups([0, 1, 2, 3, 4, 5, 6, 7, 8], 4));