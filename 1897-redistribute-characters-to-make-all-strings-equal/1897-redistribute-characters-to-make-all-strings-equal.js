/**
 * @param {string[]} words
 * @return {boolean}
 */
var makeEqual = function(words) {
      let totalCharacters = 0;
    let mp = new Map();

    for (let str of words) {
        for (let ch of str) {
            totalCharacters++;
            mp.set(ch, (mp.get(ch) || 0) + 1);
        }
    }

    if (totalCharacters % words.length !== 0) {
        return false;
    }

    for (let [key, value] of mp) {
        if (value % words.length !== 0) {
            return false;
        }
    }

    return true;
};