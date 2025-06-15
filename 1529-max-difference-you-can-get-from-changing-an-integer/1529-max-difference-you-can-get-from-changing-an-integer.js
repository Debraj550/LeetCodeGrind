var maxDiff = function (num) {
    const replace = (s, x, y) => s.split(x).join(y);
    let minNum = num.toString();
    let maxNum = num.toString();

    for (let digit of maxNum) {
        if (digit !== "9") {
            maxNum = replace(maxNum, digit, "9");
            break;
        }
    }

    for (let i = 0; i < minNum.length; ++i) {
        let digit = minNum[i];
        if (i === 0) {
            if (digit !== "1") {
                minNum = replace(minNum, digit, "1");
                break;
            }
        } else {
            if (digit !== "0" && digit !== minNum[0]) {
                minNum = replace(minNum, digit, "0");
                break;
            }
        }
    }

    return parseInt(maxNum) - parseInt(minNum);
};