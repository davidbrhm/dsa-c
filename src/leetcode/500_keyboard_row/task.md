# 500. Keyboard Row

Given an array of strings `words`, return *the words that can be typed using letters of the alphabet on only one row of American keyboard*.

In the **American keyboard**:

* The first row consists of characters `"qwertyuiop"`.
* The second row consists of characters `"asdfghjkl"`.
* The third row consists of characters `"zxcvbnm"`.

---

### Example 1:

**Input:** `words = ["Hello","Alaska","Dad","Peace"]`

**Output:** `["Alaska","Dad"]`

### Example 2:

**Input:** `words = ["omk"]`

**Output:** `[]`

### Example 3:

**Input:** `words = ["adsdf","sddf"]`

**Output:** `["adsdf","sddf"]`

---

### Constraints:

* $1 \le words.length \le 20$
* $1 \le words[i].length \le 10$
* `words[i]` consists of English letters (both lowercase and uppercase).