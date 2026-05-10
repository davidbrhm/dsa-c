# 1797. Design Authentication Manager

There is an authentication system that works with expiration times. It handles tokens together with their `tokenId` and `currentTime`.

Implement the `AuthenticationManager` class:

* **`AuthenticationManager(int timeToLive)`**: Constructs the `AuthenticationManager` and sets the `timeToLive`.
* **`generate(string tokenId, int currentTime)`**: Generates a new token with the given `tokenId` at the given `currentTime` in seconds. This token will expire after `timeToLive` seconds, i.e., at `currentTime + timeToLive`.
* **`renew(string tokenId, int currentTime)`**: Renews the unexpired token with the given `tokenId` at the given `currentTime` in seconds. If that token exists and has not expired, its expiration time is updated to be `currentTime + timeToLive`. If there is no such token or the token has expired, nothing happens.
* **`countUnexpiredTokens(int currentTime)`**: Returns the number of unexpired tokens at the given `currentTime`.

Note that a token expires at time `t` if `t <= currentTime`. That is, if a token expires at time 42, and `currentTime` is 42, the token is considered expired.

---

### Example 1:

[Image showing AuthenticationManager operations]

**Input** `["AuthenticationManager", "renew", "generate", "countUnexpiredTokens", "generate", "renew", "renew", "countUnexpiredTokens"]`

`[[5], ["aaa", 1], ["aaa", 2], [6], ["bbb", 7], ["aaa", 8], ["bbb", 10], [15]]`

**Output** `[null, null, null, 1, null, null, null, 0]`

**Explanation** `AuthenticationManager am = new AuthenticationManager(5); // timeToLive = 5`

`am.renew("aaa", 1); // No token exists with tokenId "aaa" at time 1, so nothing happens.`

`am.generate("aaa", 2); // Token "aaa" generated at time 2, expires at time 7.`

`am.countUnexpiredTokens(6); // At time 6, token "aaa" is the only unexpired token. Return 1.`

`am.generate("bbb", 7); // Token "bbb" generated at time 7, expires at time 12.`

`am.renew("aaa", 8); // Token "aaa" expired at time 7, so it cannot be renewed. Nothing happens.`

`am.renew("bbb", 10); // Token "bbb" is unexpired at time 10, so it is renewed until 15.`

`am.countUnexpiredTokens(15); // At time 15, token "bbb" expires, so no tokens are unexpired. Return 0.`

---

### Constraints:

* $1 \le timeToLive \le 10^8$
* $1 \le currentTime \le 10^8$
* $1 \le tokenId.length \le 5$
* `tokenId` consists only of lowercase letters.
* All calls to `generate`, `renew`, and `countUnexpiredTokens` have `currentTime` values in **non-decreasing** order.
* At most 2000 calls will be made to all functions combined.