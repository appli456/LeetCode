/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var characterReplacement = function(s, k) {
    var count_map = {},
        start = 0,
        max_count = 0,
        result = 0;

    for(var end = 0; end < s.length; ++end) {
        // character map: mark max substring
        if(count_map.hasOwnProperty(s[end])) {
            count_map[s[end]]++;
        } else {
            count_map[s[end]] = 1;
        }

        max_count = Math.max(max_count, count_map[s[end]]);

        while(end - start - max_count + 1 > k) {
            count_map[s[start]]--;

            for(var key in count_map) {
                if (count_map.hasOwnProperty(key)) {
                    max_count = Math.max(max_count, count_map[key]);
                }
            }

            start++;
        }

        result = Math.max(result, end - start + 1);
    }

    return result;
};