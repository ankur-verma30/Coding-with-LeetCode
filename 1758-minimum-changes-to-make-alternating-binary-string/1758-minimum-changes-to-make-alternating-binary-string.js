/**
 * @param {string} s
 * @return {number}
 */
var minOperations = function(s) {
    let count = 0;

    for (let i = 1; i < s.length; i++) {
        if (s[i - 1] === s[i]) {
            if (s[i - 1] === '0') {
                s = s.substring(0, i) + '1' + s.substring(i + 1);
                count++;
            } else if (s[i - 1] === '1') {
                s = s.substring(0, i) + '0' + s.substring(i + 1);
                count++;
            }
        }
    }

    return Math.min(count, s.length - count);
};