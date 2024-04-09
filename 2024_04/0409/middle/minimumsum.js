var minimumSum = num => {
    var numArray = num.toString().split('').sort();
    return (parseInt(numArray[0]) * 10 + parseInt(numArray[2])) + (parseInt(numArray[1]) * 10 + parseInt(numArray[3]));
};
